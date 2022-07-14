/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_POWERPC_ASM_UAPI_ARITH_H
#define _COBALT_POWERPC_ASM_UAPI_ARITH_H

#include <asm/xenomai/uapi/features.h>

#ifdef __powerpc64__

#define xnarch_nodiv_ullimd(op, frac, integ) \
	mach_powerpc_nodiv_ullimd((op), (frac), (integ))

static inline __attribute__((__const__)) unsigned long long
mach_powerpc_nodiv_ullimd(const unsigned long long op,
			     const unsigned long long frac,
			     const unsigned rhs_integ)
{
	unsigned long h, l, m;

	__asm__("mulhdu	  %0, %3, %4\n\t"			\
		"mulld	  %1, %3, %4\n\t"			\
		"rlwinm	  %2, %1, 0, 0, 0\n\t"			\
		"sldi	  %2, %2, 1\n\t"			\
		"addc	  %1, %1, %2\n\t"			\
		"addze	  %0, %0\n\t"				\
		"mr	  %2, %5\n\t"				\
		"clrldi	  %2, %2, 32\n\t"			\
		"mulld	  %2, %3, %2\n\t"			\
		"adde	  %0, %0, %2\n\t"			\
		: "=&r"(h), "=&r"(l), "=&r"(m)			\
		: "r"(op), "r"(frac), "r"(rhs_integ) : "cc");	\

	return h;
}

#else /* !__powerpc64__ */

#define xnarch_add96and64(l0, l1, l2, s0, s1)		\
	do {						\
		__asm__ ("addc %2, %2, %4\n\t"		\
			 "adde %1, %1, %3\n\t"		\
			 "addze %0, %0\n\t"		\
			 : "+r"(l0), "+r"(l1), "+r"(l2)	\
			 : "r"(s0), "r"(s1) : "cc");	\
	} while (0)

#endif /* !__powerpc64__ */

#include <cobalt/uapi/asm-generic/arith.h>

#endif /* _COBALT_POWERPC_ASM_UAPI_ARITH_H */
