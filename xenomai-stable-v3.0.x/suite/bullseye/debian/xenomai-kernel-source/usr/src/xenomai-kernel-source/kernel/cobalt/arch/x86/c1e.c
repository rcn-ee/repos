/*
 * Disable Intel automatic promotion to C1E mode.
 * Lifted from drivers/idle/intel_idle.c
 * Copyright (c) 2013, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include <linux/smp.h>
#include <asm/processor.h>
#include <asm/cpu_device_id.h>
#include <asm/msr.h>

#define ICPU(model) \
	{ X86_VENDOR_INTEL, 6, model, X86_FEATURE_MWAIT, 1UL }

static const struct x86_cpu_id c1e_ids[] = {
	ICPU(0x1a),
	ICPU(0x1e),
	ICPU(0x1f),
	ICPU(0x25),
	ICPU(0x2c),
	ICPU(0x2e),
	ICPU(0x2f),
	ICPU(0x2a),
	ICPU(0x2d),
	ICPU(0x3a),
	ICPU(0x3e),
	ICPU(0x3c),
	ICPU(0x3f),
	ICPU(0x45),
	ICPU(0x46),
	ICPU(0x4D),
	{}
};

#undef ICPU

static void c1e_promotion_disable(void *dummy)
{
	unsigned long long msr_bits;

	rdmsrl(MSR_IA32_POWER_CTL, msr_bits);
	msr_bits &= ~0x2;
	wrmsrl(MSR_IA32_POWER_CTL, msr_bits);
}

void mach_x86_c1e_disable(void)
{
	const struct x86_cpu_id *id;

	id = x86_match_cpu(c1e_ids);
	if (id) {
		printk("[Xenomai] disabling automatic C1E state promotion on Intel processor\n");
		/*
		 * cpu uses C1E, disable this feature (copied from
		 * intel_idle driver)
		 */
		on_each_cpu(c1e_promotion_disable, NULL, 1);
	}
}
