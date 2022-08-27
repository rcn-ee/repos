/*
 * Copyright (C) 2001,2002,2003,2004 Philippe Gerum <rpm@xenomai.org>.
 *
 * 64-bit PowerPC adoption
 *   copyright (C) 2005 Taneli Vähäkangas and Heikki Lindholm
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
#ifndef _COBALT_POWERPC_ASM_SYSCALL_H
#define _COBALT_POWERPC_ASM_SYSCALL_H

#include <linux/errno.h>
#include <linux/ptrace.h>
#include <asm-generic/xenomai/syscall.h>

/*
 * Cobalt and Linux syscall numbers can be fetched from GPR0, masking
 * out the __COBALT_SYSCALL_BIT marker.
 */
#define __xn_reg_sys(__regs)	((__regs)->gpr[0])
#define __xn_syscall_p(__regs)	(__xn_reg_sys(__regs) & __COBALT_SYSCALL_BIT)
#define __xn_syscall(__regs)	(__xn_reg_sys(__regs) & ~__COBALT_SYSCALL_BIT)

#define __xn_reg_rval(__regs)	((__regs)->gpr[3])
#define __xn_reg_arg1(__regs)	((__regs)->gpr[3])
#define __xn_reg_arg2(__regs)	((__regs)->gpr[4])
#define __xn_reg_arg3(__regs)	((__regs)->gpr[5])
#define __xn_reg_arg4(__regs)	((__regs)->gpr[6])
#define __xn_reg_arg5(__regs)	((__regs)->gpr[7])
#define __xn_reg_pc(__regs)	((__regs)->nip)
#define __xn_reg_sp(__regs)	((__regs)->gpr[1])

/*
 * Root syscall number with predicate (valid only if
 * !__xn_syscall_p(__regs)).
 */
#define __xn_rootcall_p(__regs, __code)			\
	({						\
		*(__code) = __xn_syscall(__regs);	\
		*(__code) < NR_syscalls;		\
	})

static inline void __xn_error_return(struct pt_regs *regs, int v)
{
	/*
	 * We currently never set the SO bit for marking errors, even
	 * if we always test it upon syscall return.
	 */
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

#endif /* !_COBALT_POWERPC_ASM_SYSCALL_H */
