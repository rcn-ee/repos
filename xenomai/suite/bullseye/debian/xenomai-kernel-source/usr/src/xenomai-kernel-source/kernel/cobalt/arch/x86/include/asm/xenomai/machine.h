/**
 * Copyright (C) 2007-2012 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_X86_ASM_MACHINE_H
#define _COBALT_X86_ASM_MACHINE_H

#include <linux/compiler.h>

static inline __attribute_const__ unsigned long ffnz(unsigned long ul)
{
#ifdef __i386__
	__asm__("bsfl %1, %0":"=r,r" (ul) : "r,?m" (ul));
#else
	__asm__("bsfq %1, %0":"=r" (ul) : "rm" (ul));
#endif
	return ul;
}

#define XNARCH_HOST_TICK_IRQ	__ipipe_hrtimer_irq

long strncpy_from_user_nocheck(char *dst,
			       const char __user *src,
			       long count);

/* Read this last to enable default settings. */
#include <asm-generic/xenomai/machine.h>

#endif /* !_COBALT_X86_ASM_MACHINE_H */
