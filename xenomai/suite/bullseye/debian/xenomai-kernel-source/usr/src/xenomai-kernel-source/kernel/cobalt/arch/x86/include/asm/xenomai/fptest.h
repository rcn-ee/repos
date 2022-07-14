/*
 * Copyright (C) 2006 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
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
#ifndef _COBALT_X86_ASM_FPTEST_H
#define _COBALT_X86_ASM_FPTEST_H

#include <linux/errno.h>
#include <asm/processor.h>
#include <asm/xenomai/wrappers.h>
#include <asm/xenomai/uapi/fptest.h>

static inline int fp_kernel_supported(void)
{
	return 1;
}

static inline int fp_linux_begin(void)
{
#if defined(CONFIG_X86_USE_3DNOW) \
	|| defined(CONFIG_MD_RAID456) || defined(CONFIG_MD_RAID456_MODULE)
	/* Ther kernel uses x86 FPU, we can not also use it in our tests. */
	static int once = 0;
	if (!once) {
		once = 1;
		printk("%s:%d: Warning: Linux is compiled to use FPU in "
		       "kernel-space.\nFor this reason, switchtest can not "
		       "test using FPU in Linux kernel-space.\n",
		       __FILE__, __LINE__);
	}
	return -EBUSY;
#endif /* 3DNow or RAID 456 */
	kernel_fpu_begin();
	/* kernel_fpu_begin() does no re-initialize the fpu context, but
	   fp_regs_set() implicitely expects an initialized fpu context, so
	   initialize it here. */
	__asm__ __volatile__("fninit");
	return 0;
}

static inline void fp_linux_end(void)
{
	kernel_fpu_end();
}

static inline int fp_detect(void)
{
	int features = 0;

#ifndef cpu_has_xmm2
#ifdef cpu_has_sse2
#define cpu_has_xmm2 cpu_has_sse2
#else
#define cpu_has_xmm2 0
#endif
#endif
	if (cpu_has_xmm2)
		features |= __COBALT_HAVE_SSE2;

#ifndef cpu_has_avx
#define cpu_has_avx 0
#endif
	if (cpu_has_avx)
		features |= __COBALT_HAVE_AVX;

	return features;
}

#endif /* _COBALT_X86_ASM_FPTEST_H */
