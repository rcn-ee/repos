/*
 * Copyright (C) 2009,2012 Philippe Gerum <rpm@xenomai.org>.
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
#include <asm/cacheflush.h>
#include <asm/ptrace.h>
#include <asm/bug.h>

static void *mayday;

static inline void setup_mayday(void *page)
{
	/*
	 * We want this code to appear at the top of the MAYDAY page:
	 *
	 * 45 e1 0c 00	  R5.H = 0x1000
	 * 05 e1 2b 02	  R5.L = 0x005e
	 * 05 32	  P0 = R5
	 * a0 00	  EXCPT 0x0
	 * cd ef          <bug opcode>
	 *
	 * We don't mess with ASTAT here, so no need to save/restore
	 * it in handle/fixup code.
	 */
	static const struct __attribute__ ((__packed__)) {
		struct __attribute__ ((__packed__)) {
			u16 op;
			u16 imm;
		} load_r5h;
		struct __attribute__ ((__packed__)) {
			u16 op;
			u16 imm;
		} load_r5l;
		u16 mov_p0;
		u16 syscall;
		u16 bug;
	} code = {
		.load_r5h = {
			.op = 0xe145,
			.imm = __xn_syscode(sc_cobalt_mayday) >> 16
		},
		.load_r5l = {
			.op = 0xe105,
			.imm = __xn_syscode(sc_cobalt_mayday) & 0xffff
		},
		.mov_p0 = 0x3205,
		.syscall = 0x00a0,
		.bug = BFIN_BUG_OPCODE,
	};

	memcpy(page, &code, sizeof(code));

	flush_dcache_range((unsigned long)page,
			   (unsigned long)page + sizeof(code));
}

int xnarch_init_mayday(void)
{
	mayday = vmalloc(PAGE_SIZE);
	if (mayday == NULL)
		return -ENOMEM;

	setup_mayday(mayday);

	return 0;
}

void xnarch_cleanup_mayday(void)
{
	vfree(mayday);
}

void *xnarch_get_mayday_page(void)
{
	return mayday;
}

void xnarch_handle_mayday(struct xnarchtcb *tcb,
			  struct pt_regs *regs,
			  unsigned long tramp)
{
	tcb->mayday.pc = regs->pc;
	tcb->mayday.p0 = regs->p0;
	tcb->mayday.r5 = regs->r5;
	regs->pc = tramp;	/* i.e. RETI */
}

void xnarch_fixup_mayday(struct xnarchtcb *tcb, struct pt_regs *regs)
{
	regs->pc = tcb->mayday.pc;
	regs->p0 = tcb->mayday.p0;
	regs->r5 = tcb->mayday.r5;
}
