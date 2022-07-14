/**
 *   Arithmetic/conversion routines for x86.
 *
 *   Copyright &copy; 2005 Gilles Chanteperdrix, 32bit version.
 *   Copyright &copy; 2007 Jan Kiszka, 64bit version.
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
#ifndef _COBALT_X86_ASM_UAPI_ARITH_H
#define _COBALT_X86_ASM_UAPI_ARITH_H
#define _COBALT_X86_ASM_UAPI_ARITH_H

#include <asm/xenomai/uapi/features.h>

#ifdef __i386__

#define xnarch_u64tou32(ull, h, l) ({          \
    unsigned long long _ull = (ull);            \
    (l) = _ull & 0xffffffff;                    \
    (h) = _ull >> 32;                           \
})

#define xnarch_u64fromu32(h, l) ({             \
    unsigned long long _ull;                    \
    asm ( "": "=A"(_ull) : "d"(h), "a"(l));     \
    _ull;                                       \
})

/* const helper for xnarch_uldivrem, so that the compiler will eliminate
   multiple calls with same arguments, at no additionnal cost. */
static inline __attribute__((__const__)) unsigned long long
__mach_x86_32_uldivrem(const unsigned long long ull, const unsigned long d)
{
    unsigned long long ret;
    __asm__ ("divl %1" : "=A,A"(ret) : "r,?m"(d), "A,A"(ull));
    /* Exception if quotient does not fit on unsigned long. */
    return ret;
}

/* Fast long long division: when the quotient and remainder fit on 32 bits. */
static inline unsigned long mach_x86_32_uldivrem(unsigned long long ull,
						 const unsigned d,
						 unsigned long *const rp)
{
    unsigned long q, r;
    ull = __mach_x86_32_uldivrem(ull, d);
    __asm__ ( "": "=d"(r), "=a"(q) : "A"(ull));
    if(rp)
	*rp = r;
    return q;
}
#define xnarch_uldivrem(ull, d, rp) mach_x86_32_uldivrem((ull),(d),(rp))

/* Division of an unsigned 96 bits ((h << 32) + l) by an unsigned 32 bits.
   Building block for ulldiv. */
static inline unsigned long long mach_x86_32_div96by32(const unsigned long long h,
						       const unsigned long l,
						       const unsigned long d,
						       unsigned long *const rp)
{
    unsigned long rh;
    const unsigned long qh = xnarch_uldivrem(h, d, &rh);
    const unsigned long long t = xnarch_u64fromu32(rh, l);
    const unsigned long ql = xnarch_uldivrem(t, d, rp);

    return xnarch_u64fromu32(qh, ql);
}

/* Slow long long division. Uses xnarch_uldivrem, hence has the same property:
   the compiler removes redundant calls. */
static inline unsigned long long
mach_x86_32_ulldiv(const unsigned long long ull,
		   const unsigned d,
		   unsigned long *const rp)
{
    unsigned long h, l;
    xnarch_u64tou32(ull, h, l);
    return mach_x86_32_div96by32(h, l, d, rp);
}
#define xnarch_ulldiv(ull,d,rp) mach_x86_32_ulldiv((ull),(d),(rp))

/* Fast scaled-math-based replacement for long long multiply-divide */
#define xnarch_llmulshft(ll, m, s)					\
({									\
	long long __ret;						\
	unsigned __lo, __hi;						\
									\
	__asm__ (							\
		/* HI = HIWORD(ll) * m */				\
		"mov  %%eax,%%ecx\n\t"					\
		"mov  %%edx,%%eax\n\t"					\
		"imull %[__m]\n\t"					\
		"mov  %%eax,%[__lo]\n\t"				\
		"mov  %%edx,%[__hi]\n\t"				\
									\
		/* LO = LOWORD(ll) * m */				\
		"mov  %%ecx,%%eax\n\t"					\
		"mull %[__m]\n\t"					\
									\
		/* ret = (HI << 32) + LO */				\
		"add  %[__lo],%%edx\n\t"				\
		"adc  $0,%[__hi]\n\t"					\
									\
		/* ret = ret >> s */					\
		"mov  %[__s],%%ecx\n\t"					\
		"shrd %%cl,%%edx,%%eax\n\t"				\
		"shrd %%cl,%[__hi],%%edx\n\t"				\
		: "=A" (__ret), [__lo] "=&r" (__lo), [__hi] "=&r" (__hi) \
		: "A" (ll), [__m] "m" (m), [__s] "m" (s)		\
		: "ecx");						\
	__ret;								\
})

static inline __attribute__((const)) unsigned long long
mach_x86_32_nodiv_ullimd(const unsigned long long op,
			 const unsigned long long frac,
			 unsigned rhs_integ)
{
	register unsigned rl __asm__("ecx");
	register unsigned rm __asm__("esi");
	register unsigned rh __asm__("edi");
	unsigned fracl, frach, opl, oph;
	volatile unsigned integ = rhs_integ;
	register unsigned long long t;

	xnarch_u64tou32(op, oph, opl);
	xnarch_u64tou32(frac, frach, fracl);

	__asm__ ("mov %[oph], %%eax\n\t"
		 "mull %[frach]\n\t"
		 "mov %%eax, %[rm]\n\t"
		 "mov %%edx, %[rh]\n\t"
		 "mov %[opl], %%eax\n\t"
		 "mull %[fracl]\n\t"
		 "mov %%edx, %[rl]\n\t"
		 "shl $1, %%eax\n\t"
		 "adc $0, %[rl]\n\t"
		 "adc $0, %[rm]\n\t"
		 "adc $0, %[rh]\n\t"
		 "mov %[oph], %%eax\n\t"
		 "mull %[fracl]\n\t"
		 "add %%eax, %[rl]\n\t"
		 "adc %%edx, %[rm]\n\t"
		 "adc $0, %[rh]\n\t"
		 "mov %[opl], %%eax\n\t"
		 "mull %[frach]\n\t"
		 "add %%eax, %[rl]\n\t"
		 "adc %%edx, %[rm]\n\t"
		 "adc $0, %[rh]\n\t"
		 "mov %[opl], %%eax\n\t"
		 "mull %[integ]\n\t"
		 "add %[rm], %%eax\n\t"
		 "adc %%edx, %[rh]\n\t"
		 "mov %[oph], %%edx\n\t"
		 "imul %[integ], %%edx\n\t"
		 "add %[rh], %%edx\n\t"
		 : [rl]"=&c"(rl), [rm]"=&S"(rm), [rh]"=&D"(rh), "=&A"(t)
		 : [opl]"m"(opl), [oph]"m"(oph),
		   [fracl]"m"(fracl), [frach]"m"(frach), [integ]"m"(integ)
		 : "cc");

	return t;
}

#define xnarch_nodiv_ullimd(op, frac, integ) \
	mach_x86_32_nodiv_ullimd((op), (frac), (integ))

#else /* x86_64 */

static inline __attribute__((__const__)) long long
mach_x86_64_llimd (long long op, unsigned m, unsigned d)
{
	long long result;

	__asm__ (
		"imul %[m]\n\t"
		"idiv %[d]\n\t"
		: "=a" (result)
		: "a" (op), [m] "r" ((unsigned long long)m),
		  [d] "r" ((unsigned long long)d)
		: "rdx");

	return result;
}
#define xnarch_llimd(ll,m,d) mach_x86_64_llimd((ll),(m),(d))

static inline __attribute__((__const__)) long long
mach_x86_64_llmulshft(long long op, unsigned m, unsigned s)
{
	long long result;

	__asm__ (
		"imulq %[m]\n\t"
		"shrd %%cl,%%rdx,%%rax\n\t"
		: "=a,a" (result)
		: "a,a" (op), [m] "m,r" ((unsigned long long)m),
		  "c,c" (s)
		: "rdx");

	return result;
}
#define xnarch_llmulshft(op, m, s) mach_x86_64_llmulshft((op), (m), (s))

static inline __attribute__((__const__)) unsigned long long
mach_x86_64_nodiv_ullimd(unsigned long long op,
			    unsigned long long frac, unsigned rhs_integ)
{
	register unsigned long long rl __asm__("rax") = frac;
	register unsigned long long rh __asm__("rdx");
	register unsigned long long integ __asm__("rsi") = rhs_integ;
	register unsigned long long t __asm__("r8") = 0x80000000ULL;

	__asm__ ("mulq %[op]\n\t"
		 "addq %[t], %[rl]\n\t"
		 "adcq $0, %[rh]\n\t"
		 "imulq %[op], %[integ]\n\t"
		 "leaq (%[integ], %[rh], 1),%[rl]":
		 [rh]"=&d"(rh), [rl]"+&a"(rl), [integ]"+S"(integ):
		 [op]"D"(op), [t]"r"(t): "cc");

	return rl;
}

#define xnarch_nodiv_ullimd(op, frac, integ) \
	mach_x86_64_nodiv_ullimd((op), (frac), (integ))

#endif /* x86_64 */

#include <cobalt/uapi/asm-generic/arith.h>

#endif /* _COBALT_X86_ASM_UAPI_ARITH_H */
