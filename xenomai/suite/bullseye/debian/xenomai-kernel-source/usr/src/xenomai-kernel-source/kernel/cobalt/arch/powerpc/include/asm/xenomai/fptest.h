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
#ifndef _COBALT_POWERPC_ASM_FPTEST_H
#define _COBALT_POWERPC_ASM_FPTEST_H

#include <linux/errno.h>
#include <linux/printk.h>
#include <asm/xenomai/uapi/fptest.h>

static inline int fp_kernel_supported(void)
{
/*
 * CAUTION: some architectures have a hardware FP unit, but a
 * restricted set of supported FP instructions. Those may enable
 * CONFIG_MATH_EMULATION and MATH_EMULATION_HW_UNIMPLEMENTED at the
 * same time to provide an emulation of the missing instruction set.
 */
#ifdef CONFIG_PPC_FPU
	return 1;
#else
#ifdef CONFIG_MATH_EMULATION
	printk_once(XENO_WARNING "kernel-based FPU support is disabled\n");
#endif	/* !CONFIG_MATH_EMULATION */
	return 0;
#endif	/* !CONFIG_PPC_FPU */
}

static inline int fp_linux_begin(void)
{
	return -ENOSYS;
}

static inline void fp_linux_end(void)
{
}

static inline int fp_detect(void)
{
	return 0;
}

#endif /* !_COBALT_POWERPC_ASM_FPTEST_H */
