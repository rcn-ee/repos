/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_X86_ASM_SYSCALL32_H
#define _COBALT_X86_ASM_SYSCALL32_H

#include <asm/unistd.h>

#ifdef CONFIG_X86_X32

#define __COBALT_X32_BASE		128

#define __COBALT_SYSNR32x(__reg)			\
	({						\
		long __nr = __reg;			\
		if (__nr & __X32_SYSCALL_BIT) {		\
			__nr &= ~__X32_SYSCALL_BIT;	\
			__nr += __COBALT_X32_BASE;	\
		}					\
		__nr;					\
	})

#define __COBALT_COMPAT32x(__reg)			\
	(((__reg) & __X32_SYSCALL_BIT) ? __COBALT_COMPATX_BIT : 0)

#if __NR_COBALT_SYSCALLS > __COBALT_X32_BASE
#error "__NR_COBALT_SYSCALLS > __COBALT_X32_BASE"
#endif

#define __syshand32x__(__name)	((cobalt_syshand)(CoBaLt32x_ ## __name))

#define __COBALT_CALL32x_INITHAND(__handler)	\
	[__COBALT_X32_BASE ... __COBALT_X32_BASE + __NR_COBALT_SYSCALLS-1] = __handler,

#define __COBALT_CALL32x_INITMODE(__mode)	\
	[__COBALT_X32_BASE ... __COBALT_X32_BASE + __NR_COBALT_SYSCALLS-1] = __mode,

/* x32 default entry (no thunk) */
#define __COBALT_CALL32x_ENTRY(__name, __handler)		\
	[sc_cobalt_ ## __name + __COBALT_X32_BASE] = __handler,

/* x32 thunk installation */
#define __COBALT_CALL32x_pure_THUNK(__name)	\
	__COBALT_CALL32x_ENTRY(__name, __syshand32x__(__name))

#define __COBALT_CALL32x_THUNK(__name)	\
	__COBALT_CALL32x_ENTRY(__name, __syshand32emu__(__name))

/* x32 thunk implementation. */
#define COBALT_SYSCALL32x(__name, __mode, __args)	\
	long CoBaLt32x_ ## __name __args

/* x32 thunk declaration. */
#define COBALT_SYSCALL32x_DECL(__name, __args)	\
	long CoBaLt32x_ ## __name __args

#else /* !CONFIG_X86_X32 */

/* x32 support disabled. */

#define __COBALT_SYSNR32x(__reg)	(__reg)

#define __COBALT_COMPAT32x(__reg)	0

#define __COBALT_CALL32x_INITHAND(__handler)

#define __COBALT_CALL32x_INITMODE(__mode)

#define __COBALT_CALL32x_ENTRY(__name, __handler)

#define __COBALT_CALL32x_pure_THUNK(__name)

#define __COBALT_CALL32x_THUNK(__name)

#define COBALT_SYSCALL32x_DECL(__name, __args)

#endif /* !CONFIG_X86_X32 */

#ifdef CONFIG_IA32_EMULATION

#define __COBALT_IA32_BASE		256 /* Power of two. */

#define __COBALT_SYSNR32emu(__reg)					\
	({								\
		long __nr = __reg;					\
		if (in_ia32_syscall())					\
			__nr += __COBALT_IA32_BASE;			\
		__nr;							\
	})

#define __COBALT_COMPAT32emu(__reg)					\
	(in_ia32_syscall() ? __COBALT_COMPAT_BIT : 0)

#if __NR_COBALT_SYSCALLS > __COBALT_IA32_BASE
#error "__NR_COBALT_SYSCALLS > __COBALT_IA32_BASE"
#endif

#define __syshand32emu__(__name)	((cobalt_syshand)(CoBaLt32emu_ ## __name))

#define __COBALT_CALL32emu_INITHAND(__handler)	\
	[__COBALT_IA32_BASE ... __COBALT_IA32_BASE + __NR_COBALT_SYSCALLS-1] = __handler,

#define __COBALT_CALL32emu_INITMODE(__mode)	\
	[__COBALT_IA32_BASE ... __COBALT_IA32_BASE + __NR_COBALT_SYSCALLS-1] = __mode,

/* ia32 default entry (no thunk) */
#define __COBALT_CALL32emu_ENTRY(__name, __handler)		\
	[sc_cobalt_ ## __name + __COBALT_IA32_BASE] = __handler,

/* ia32 thunk installation */
#define __COBALT_CALL32emu_THUNK(__name)	\
	__COBALT_CALL32emu_ENTRY(__name, __syshand32emu__(__name))

/* ia32 thunk implementation. */
#define COBALT_SYSCALL32emu(__name, __mode, __args)	\
	long CoBaLt32emu_ ## __name __args

/* ia32 thunk declaration. */
#define COBALT_SYSCALL32emu_DECL(__name, __args)	\
	long CoBaLt32emu_ ## __name __args

#else /* !CONFIG_IA32_EMULATION */

/* ia32 emulation support disabled. */

#define __COBALT_SYSNR32emu(__reg)	(__reg)

#define __COBALT_COMPAT32emu(__reg)	0

#define __COBALT_CALL32emu_INITHAND(__handler)

#define __COBALT_CALL32emu_INITMODE(__mode)

#define __COBALT_CALL32emu_ENTRY(__name, __handler)

#define __COBALT_CALL32emu_THUNK(__name)

#define COBALT_SYSCALL32emu_DECL(__name, __args)

#endif /* !CONFIG_IA32_EMULATION */

#define __COBALT_CALL32_ENTRY(__name, __handler)	\
	__COBALT_CALL32x_ENTRY(__name, __handler)	\
	__COBALT_CALL32emu_ENTRY(__name, __handler)

#define __COBALT_CALL32_INITHAND(__handler)	\
  	__COBALT_CALL32x_INITHAND(__handler)	\
	__COBALT_CALL32emu_INITHAND(__handler)

#define __COBALT_CALL32_INITMODE(__mode)	\
  	__COBALT_CALL32x_INITMODE(__mode)	\
	__COBALT_CALL32emu_INITMODE(__mode)

/* Already checked for __COBALT_SYSCALL_BIT */
#define __COBALT_CALL32_SYSNR(__reg)				\
	({							\
		long __nr;					\
		__nr = __COBALT_SYSNR32x(__reg);		\
		if (__nr == (__reg))				\
			__nr = __COBALT_SYSNR32emu(__reg);	\
		__nr;						\
	})

#define __COBALT_CALL_COMPAT(__reg)				\
	({							\
		int __ret = __COBALT_COMPAT32x(__reg);		\
		if (__ret == 0)					\
			__ret = __COBALT_COMPAT32emu(__reg);	\
		__ret;						\
	})

#endif /* !_COBALT_X86_ASM_SYSCALL32_H */
