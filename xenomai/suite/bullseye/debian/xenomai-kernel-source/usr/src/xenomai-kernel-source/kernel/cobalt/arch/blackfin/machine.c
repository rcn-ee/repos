/**
 *   Copyright (C) 2005-2012 Philippe Gerum.
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
#include <cobalt/kernel/sched.h>
#include <asm/xenomai/machine.h>

static unsigned long mach_blackfin_calibrate(void)
{
	return 20;	/* 20 clock cycles */
}

static void schedule_deferred(void)
{
	xnsched_run();
}

static int mach_blackfin_late_init(void)
{
	/*
	 * We hook the rescheduling handler late in the init sequence
	 * to prevent the race below from happening:
	 *
	 * mach_setup() ...
	 *    IRQ/syscall
	 *        => irq_tail_hook
	 *           => xnsched_run()
	 *    ...
	 * xenomai_init()
	 *
	 * in which case, we would spuriously call xnsched_run()
	 * before the scheduler slot is initialized.
	 */
	__ipipe_irq_tail_hook = (unsigned long)schedule_deferred;

	return 0;
}

static void mach_blackfin_cleanup(void)
{
	__ipipe_irq_tail_hook = 0;
	smp_mb();
}

static const char *const fault_labels[] = {
	[1] = "Single step",
	[4] = "TAS",
	[17] = "Performance Monitor Overflow",
	[33] = "Undefined instruction",
	[34] = "Illegal instruction",
	[36] = "Data access misaligned",
	[35] = "DCPLB fault",
	[37] = "Unrecoverable event",
	[38] = "DCPLB fault",
	[39] = "DCPLB fault",
	[40] = "Watchpoint",
	[42] = "Instruction fetch misaligned",
	[41] = "Undef",
	[43] = "ICPLB fault",
	[44] = "ICPLB fault",
	[45] = "ICPLB fault",
	[46] = "Illegal resource",
	[47] = NULL
};

struct cobalt_machine cobalt_machine = {
	.name = "blackfin",
	.init = NULL,
	.late_init = mach_blackfin_late_init,
	.cleanup = mach_blackfin_cleanup,
	.calibrate = mach_blackfin_calibrate,
	.prefault = NULL,
	.fault_labels = fault_labels,
};
