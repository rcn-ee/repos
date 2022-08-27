/**
 *   Copyright &copy; 2005 Philippe Gerum.
 *
 *   Xenomai is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation, Inc., 675 Mass Ave,
 *   Cambridge MA 02139, USA; either version 2 of the License, or (at
 *   your option) any later version.
 *
 *   Xenomai is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Xenomai; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *   02111-1307, USA.
 */
#ifndef _COBALT_BLACKFIN_ASM_MACHINE_H
#define _COBALT_BLACKFIN_ASM_MACHINE_H

#include <linux/compiler.h>
#include <linux/linkage.h>
#include <linux/bitops.h>

#define XNARCH_HOST_TICK_IRQ	__ipipe_hrtimer_irq

static inline __attribute_const__ unsigned long ffnz(unsigned long ul)
{
	return ffs(ul) - 1;
}

#include <asm-generic/xenomai/machine.h>

#endif /* !_COBALT_BLACKFIN_ASM_MACHINE_H */
