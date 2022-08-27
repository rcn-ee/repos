/*
 * Copyright (C) 2010 Philippe Gerum <rpm@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Xenomai is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xenomai; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include <linux/types.h>
#include <linux/ipipe.h>
#include <linux/vmalloc.h>
#include <cobalt/kernel/thread.h>
#include <cobalt/uapi/syscall.h>
#include <asm/ptrace.h>

static void *mayday;
#ifdef CONFIG_XENO_ARCH_SYS3264
static void *mayday_compat;
#endif

static inline void setup_mayday32(void *page)
{
	/*
	 * We want this code to appear at the top of the MAYDAY page:
	 *
	 *	b8 2b 02 00 0c		mov    $<mux_code>,%eax
	 *      cd 80			int    $0x80
	 *	0f 0b			ud2a
	 *
	 * We intentionally don't mess with EFLAGS here, so that we
	 * don't have to save/restore it in handle/fixup code.
	 */
	static const struct __attribute__ ((__packed__)) {
		struct __attribute__ ((__packed__)) {
			u8 op;
			u32 imm;
		} mov_eax;
		u16 syscall;
		u16 bug;
	} code = {
		.mov_eax = {
			.op = 0xb8,
			.imm = __xn_syscode(sc_cobalt_mayday)
		},
		.syscall = 0x80cd,
		.bug = 0x0b0f,
	};

	memcpy(page, &code, sizeof(code));

	/* no cache flush required. */
}

static inline void setup_mayday64(void *page)
{
	/*
	 * We want this code to appear at the top of the MAYDAY page:
	 *
	 *      50                      push   %rax
	 *      41 53                   push   %r11
	 *      51                      push   %rcx
	 *	b8 2b 02 00 0c		mov    $<mux_code>,%eax
	 *	0f 05			syscall
	 *      59                      pop     %rcx
	 *      41 5b                   pop     %r11
	 *      48 87 04 24             xchg    %rax,(%rsp)
	 *      c3                      retq
	 *
	 * The flow for a MAYDAY diversion on x86_64 is as follows:
	 *
	 * [runaway code]
	 *      <watchdog/timer IRQ entry>
	 *             [%orig_rip = %rip, %rip = &mayday_page] ; handle_mayday
	 *      <watchdog/timer IRQ exit>
	 *
	 * [mayday_page trampoline]
	 *      <MAYDAY syscall>             ; relax + fixup_mayday
	 *             [%rax = %orig_rip]
         *      ret-to-runaway-code
	 *
	 * [runaway code]
	 *      ...
	 *
	 * We must take care of preserving %rcx and %r11 which are
	 * clobbered by the kernel when handling a syscall in long
	 * mode. This is required because the runaway thread code did
	 * not actually plan for running the MAYDAY syscall - we
	 * forced it to do so, by diverting the return path of the
	 * watchdog/timer IRQ which preempted it.
	 *
	 * On x86_64, we want the MAYDAY syscall to return to us, so
	 * that we can restore the clobbered registers, prior to
	 * branching back to the user code. fixup_mayday ensures that
	 * the original %rip is returned from the MAYDAY syscall in
	 * %rax, therefore we have to save the latter across the
	 * syscall as well.
	 *
	 * In addition, we intentionally don't mess with EFLAGS here,
	 * so that we don't have to save/restore it in handle/fixup
	 * code.
	 */
	static const struct __attribute__ ((__packed__)) {
		u8 push_rax;
		u16 push_r11;
		u8 push_rcx;
		struct __attribute__ ((__packed__)) {
			u8 op;
			u32 imm;
		} mov_eax;
		u16 syscall;
		u8 pop_rcx;
		u16 pop_r11;
		struct __attribute__ ((__packed__)) {
			u16 op;
			u16 spec;
		} xchg_rax_tos;
		u8 retq;
	} code = {
		.push_rax = 0x50,
		.push_r11 = 0x5341,
		.push_rcx = 0x51,
		.mov_eax = {
			.op = 0xb8,
			.imm = __xn_syscode(sc_cobalt_mayday)
		},
		.syscall = 0x050f,
		.pop_rcx = 0x59,
		.pop_r11 = 0x5b41,
		.xchg_rax_tos = {
			.op = 0x8748,
			.spec = 0x2404
		},
		.retq = 0xc3,
	};

	memcpy(page, &code, sizeof(code));

	/* no cache flush required. */
}

int xnarch_init_mayday(void)
{
	mayday = vmalloc(PAGE_SIZE);
	if (mayday == NULL)
		return -ENOMEM;

#ifdef CONFIG_X86_32
	setup_mayday32(mayday);
#else
	setup_mayday64(mayday);
#ifdef CONFIG_XENO_ARCH_SYS3264
	mayday_compat = vmalloc(PAGE_SIZE);
	if (mayday_compat == NULL) {
		vfree(mayday);
		return -ENOMEM;
	}
	setup_mayday32(mayday_compat);
#endif
#endif
	return 0;
}

void xnarch_cleanup_mayday(void)
{
	vfree(mayday);
#ifdef CONFIG_XENO_ARCH_SYS3264
	vfree(mayday_compat);
#endif
}

void *xnarch_get_mayday_page(void)
{
#if defined(CONFIG_X86_32) || !defined(CONFIG_XENO_ARCH_SYS3264)
	return mayday;
#else
	return test_thread_flag(TIF_IA32) ? mayday_compat : mayday;
#endif
}

void xnarch_handle_mayday(struct xnarchtcb *tcb, struct pt_regs *regs,
			  unsigned long tramp)
{
	tcb->mayday.ip = regs->ip;
	tcb->mayday.ax = regs->ax;
	regs->ip = tramp;
}

void xnarch_fixup_mayday(struct xnarchtcb *tcb, struct pt_regs *regs)
{
#ifdef CONFIG_X86_64
	if (IS_ENABLED(CONFIG_XENO_ARCH_SYS3264) &&
		test_thread_flag(TIF_IA32)) {
		regs->ip = tcb->mayday.ip;
		regs->ax = tcb->mayday.ax;
	} else
		regs->ax = tcb->mayday.ip;
#else
	regs->ip = tcb->mayday.ip;
	regs->ax = tcb->mayday.ax;
#endif
}
