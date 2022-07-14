/**
 *   Copyright (C) 2004-2006 Philippe Gerum.
 *
 *   64-bit PowerPC adoption
 *     copyright (C) 2005 Taneli Vähäkangas and Heikki Lindholm
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
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *   02111-1307, USA.
 */
#include <linux/stddef.h>
#include <asm/cputable.h>
#include <asm/xenomai/machine.h>

static unsigned long mach_powerpc_calibrate(void)
{
	return 5;	/* 5 clock cycles. */
}

static int mach_powerpc_init(void)
{
#ifdef CONFIG_ALTIVEC
	if (!cpu_has_feature(CPU_FTR_ALTIVEC)) {
		printk("Xenomai: ALTIVEC support enabled in kernel but no hardware found.\n"
		       "         Disable CONFIG_ALTIVEC in the kernel configuration.\n");
		return -ENODEV;
	}
#endif /* CONFIG_ALTIVEC */

	return 0;
}

static const char *const fault_labels[] = {
	[0] = "Data or instruction access",
	[1] = "Alignment",
	[2] = "Altivec unavailable",
	[3] = "Program check exception",
	[4] = "Machine check exception",
	[5] = "Unknown",
	[6] = "Instruction breakpoint",
	[7] = "Run mode exception",
	[8] = "Single-step exception",
	[9] = "Non-recoverable exception",
	[10] = "Software emulation",
	[11] = "Debug",
	[12] = "SPE",
	[13] = "Altivec assist",
	[14] = "Cache-locking exception",
	[15] = "Kernel FP unavailable",
	[16] = NULL
};

struct cobalt_machine cobalt_machine = {
	.name = "powerpc",
	.init = mach_powerpc_init,
	.late_init = NULL,
	.cleanup = NULL,
	.calibrate = mach_powerpc_calibrate,
	.prefault = NULL,
	.fault_labels = fault_labels,
};
