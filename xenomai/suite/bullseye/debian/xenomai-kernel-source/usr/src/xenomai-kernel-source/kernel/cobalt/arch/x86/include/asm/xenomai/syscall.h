/*
 * Copyright (C) 2001-2014 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_X86_ASM_SYSCALL_H
#define _COBALT_X86_ASM_SYSCALL_H

#include <linux/errno.h>
#include <asm/ptrace.h>
#include <asm-generic/xenomai/syscall.h>

/*
 * Cobalt and Linux syscall numbers can be fetched from ORIG_AX,
 * masking out the __COBALT_SYSCALL_BIT marker. Make sure to offset
 * the number by __COBALT_X32_BASE for Cobalt 32-bit compat syscalls
 * only.
 */
#define __xn_reg_sys(regs)    ((regs)->orig_ax)
#define __xn_reg_rval(regs)   ((regs)->ax)
#ifdef __i386__
#define __xn_reg_arg1(regs)   ((regs)->bx)
#define __xn_reg_arg2(regs)   ((regs)->cx)
#define __xn_reg_arg3(regs)   ((regs)->dx)
#define __xn_reg_arg4(regs)   ((regs)->si)
#define __xn_reg_arg5(regs)   ((regs)->di)
#else /* x86_64 */
#define __xn_reg_arg1(regs)   ((regs)->di)
#define __xn_reg_arg2(regs)   ((regs)->si)
#define __xn_reg_arg3(regs)   ((regs)->dx)
#define __xn_reg_arg4(regs)   ((regs)->r10)
#define __xn_reg_arg5(regs)   ((regs)->r8)
#endif /* x86_64 */
#define __xn_reg_pc(regs)     ((regs)->ip)
#define __xn_reg_sp(regs)     ((regs)->sp)

#define __xn_syscall_p(regs)  (__xn_reg_sys(regs) & __COBALT_SYSCALL_BIT)
#ifdef CONFIG_XENO_ARCH_SYS3264
#define __xn_syscall(regs)    __COBALT_CALL32_SYSNR(__xn_reg_sys(regs)	\
				    & ~__COBALT_SYSCALL_BIT)
#else
#define __xn_syscall(regs)    (__xn_reg_sys(regs) & ~__COBALT_SYSCALL_BIT)
#endif

/*
 * Root syscall number with predicate (valid only if
 * !__xn_syscall_p(__regs)).
 */
#define __xn_rootcall_p(__regs, __code)			\
	({						\
		*(__code) = __xn_reg_sys(__regs);	\
		*(__code) < ipipe_root_nr_syscalls(current_thread_info()); \
	})

static inline void __xn_error_return(struct pt_regs *regs, int v)
{
	__xn_reg_rval(regs) = v;
}

static inline void __xn_status_return(struct pt_regs *regs, long v)
{
	__xn_reg_rval(regs) = v;
}

static inline int __xn_interrupted_p(struct pt_regs *regs)
{
	return __xn_reg_rval(regs) == -EINTR;
}

static inline
int xnarch_local_syscall(unsigned long a1, unsigned long a2,
			 unsigned long a3, unsigned long a4,
			 unsigned long a5)
{
	return -ENOSYS;
}

#endif /* !_COBALT_X86_ASM_SYSCALL_H */
