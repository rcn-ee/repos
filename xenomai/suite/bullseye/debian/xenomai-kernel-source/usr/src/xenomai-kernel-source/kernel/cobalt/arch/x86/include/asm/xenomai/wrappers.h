/*
 * Copyright (C) 2005 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_X86_ASM_WRAPPERS_H
#define _COBALT_X86_ASM_WRAPPERS_H

#include <asm-generic/xenomai/wrappers.h> /* Read the generic portion. */

#define __get_user_inatomic __get_user
#define __put_user_inatomic __put_user

#if LINUX_VERSION_CODE > KERNEL_VERSION(4,9,108) && \
    LINUX_VERSION_CODE < KERNEL_VERSION(4,10,0)
#define IPIPE_X86_FPU_EAGER
#endif
#if LINUX_VERSION_CODE > KERNEL_VERSION(4,4,137) && \
    LINUX_VERSION_CODE < KERNEL_VERSION(4,5,0)
#define IPIPE_X86_FPU_EAGER
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0)
#define IPIPE_X86_FPU_EAGER
#endif


#if LINUX_VERSION_CODE < KERNEL_VERSION(4,2,0)
#include <asm/i387.h>
#include <asm/fpu-internal.h>
#else
#include <asm/fpu/internal.h>
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(4,0,0)

static inline void kernel_fpu_disable(void)
{
	__thread_clear_has_fpu(current);
}

static inline void kernel_fpu_enable(void)
{
}

static inline bool kernel_fpu_disabled(void)
{
	return __thread_has_fpu(current) == 0 && (read_cr0() & X86_CR0_TS) == 0;
}
#endif /* linux < 4.1.0 */

#endif /* _COBALT_X86_ASM_WRAPPERS_H */
