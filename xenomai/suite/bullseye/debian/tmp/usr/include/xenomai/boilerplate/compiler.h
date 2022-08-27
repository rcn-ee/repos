/*
 * Copyright (C) 2013 Philippe Gerum <rpm@xenomai.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#ifndef _BOILERPLATE_COMPILER_H
#define _BOILERPLATE_COMPILER_H

#include <stddef.h>

#define container_of(ptr, type, member)					\
	({								\
		const __typeof__(((type *)0)->member) *__mptr = (ptr);	\
		(type *)((char *)__mptr - offsetof(type, member));	\
	})

#define __stringify_1(x...)	#x
#define __stringify(x...)	__stringify_1(x)

#ifndef likely
#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)
#endif

#ifndef __noreturn
#define __noreturn	__attribute__((__noreturn__))
#endif

#ifndef __must_check
#define __must_check	__attribute__((__warn_unused_result__))
#endif

#ifndef __weak
#define __weak		__attribute__((__weak__))
#endif

#ifndef __maybe_unused
#define __maybe_unused	__attribute__((__unused__))
#endif

#ifndef __aligned
#define __aligned(__n)	__attribute__((aligned (__n)))
#endif

#ifndef __deprecated
#define __deprecated	__attribute__((__deprecated__))
#endif

#ifdef __cplusplus
extern "C" {
#endif
	
void __invalid_operand_size(void);

#define __ctz(__v)							\
	({								\
		int __ret;						\
		if (!__v)						\
			__ret = sizeof(__v) * 8;			\
		else							\
			switch (sizeof(__v)) {				\
			case sizeof(int):				\
				__ret = __builtin_ctz((unsigned int)__v); \
				break;					\
			case sizeof(long long):				\
				__ret = __builtin_ctzll(__v);		\
				break;					\
			default:					\
				__invalid_operand_size();		\
			}						\
		__ret;							\
	})

#define xenomai_count_leading_zeros(__v)				\
	({								\
		int __ret;						\
		if (!__v)						\
			__ret = sizeof(__v) * 8;			\
		else							\
			switch (sizeof(__v)) {				\
			case sizeof(int):				\
				__ret = __builtin_clz((unsigned int)__v); \
				break;					\
			case sizeof(long long):				\
				__ret = __builtin_clzll(__v);		\
				break;					\
			default:					\
				__invalid_operand_size();		\
			}						\
		__ret;							\
	})
	
#ifdef __cplusplus
}
#endif
	
#endif /* _BOILERPLATE_COMPILER_H */
