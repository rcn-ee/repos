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
#include <asm/cacheflush.h>
#include <asm/ptrace.h>

static void *mayday;

static inline void setup_mayday(void *page)
{
	/*
	 * We want this code to appear at the top of the MAYDAY page:
	 *
	 * 3c 00 0b 00	lis     r0,mux_code@h
	 * 60 00 02 2b	ori     r0,r0,mux_code@l
	 * 44 00 00 02	sc
	 * 00 b0 0b 00  .long	0x00b00b00 <illegal insn>
	 *
	 * We don't mess with CCR here, so no need to save/restore it
	 * in handle/fixup code.
	 */
	u32 mux, insn[4];

	mux = __xn_syscode(sc_cobalt_mayday);
	insn[0] = 0x3c000000 | (mux >> 16);
	insn[1] = 0x60000000 | (mux & 0xffff);
	insn[2] = 0x44000002;
	insn[3] = 0x00b00b00;
	memcpy(page, insn, sizeof(insn));

	flush_dcache_range((unsigned long)page,
			   (unsigned long)page + sizeof(insn));
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
	tcb->mayday.nip = regs->nip;
	tcb->mayday.r0 = regs->gpr[0];
	regs->nip = tramp;
}

void xnarch_fixup_mayday(struct xnarchtcb *tcb,
			 struct pt_regs *regs)
{
	regs->nip = tcb->mayday.nip;
	regs->gpr[0] = tcb->mayday.r0;
}
