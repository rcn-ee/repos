/*
 * Copyright (C) 2006 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
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
#ifndef _COBALT_X86_ASM_UAPI_FPTEST_H
#define _COBALT_X86_ASM_UAPI_FPTEST_H

#define __COBALT_HAVE_SSE2	0x1
#define __COBALT_HAVE_AVX	0x2

static inline void fp_regs_set(int features, unsigned int val)
{
	unsigned long long vec[4] = { val, 0, val, 0 };
	unsigned i;

	for (i = 0; i < 8; i++)
		__asm__ __volatile__("fildl %0": /* no output */ :"m"(val));

	if (features & __COBALT_HAVE_AVX) {
		__asm__ __volatile__(
			"vmovupd %0,%%ymm0;"
			"vmovupd %0,%%ymm1;"
			"vmovupd %0,%%ymm2;"
			"vmovupd %0,%%ymm3;"
			"vmovupd %0,%%ymm4;"
			"vmovupd %0,%%ymm5;"
			"vmovupd %0,%%ymm6;"
			"vmovupd %0,%%ymm7;"
			: : "m"(vec[0]), "m"(vec[1]), "m"(vec[2]), "m"(vec[3]));
	} else if (features & __COBALT_HAVE_SSE2) {
		__asm__ __volatile__(
			"movupd %0,%%xmm0;"
			"movupd %0,%%xmm1;"
			"movupd %0,%%xmm2;"
			"movupd %0,%%xmm3;"
			"movupd %0,%%xmm4;"
			"movupd %0,%%xmm5;"
			"movupd %0,%%xmm6;"
			"movupd %0,%%xmm7;"
			: : "m"(vec[0]), "m"(vec[1]), "m"(vec[2]), "m"(vec[3]));
	}
}

static inline unsigned int fp_regs_check(int features, unsigned int val,
					 int (*report)(const char *fmt, ...))
{
	unsigned long long vec[8][4];
	unsigned int i, result = val;
	unsigned e[8];

	for (i = 0; i < 8; i++)
		__asm__ __volatile__("fistpl %0":"=m"(e[7 - i]));

	if (features & __COBALT_HAVE_AVX) {
		__asm__ __volatile__(
			"vmovupd %%ymm0,%0;"
			"vmovupd %%ymm1,%1;"
			"vmovupd %%ymm2,%2;"
			"vmovupd %%ymm3,%3;"
			"vmovupd %%ymm4,%4;"
			"vmovupd %%ymm5,%5;"
			"vmovupd %%ymm6,%6;"
			"vmovupd %%ymm7,%7;"
			: "=m" (vec[0][0]), "=m" (vec[1][0]),
			  "=m" (vec[2][0]), "=m" (vec[3][0]),
			  "=m" (vec[4][0]), "=m" (vec[5][0]),
			  "=m" (vec[6][0]), "=m" (vec[7][0]));
	} else if (features & __COBALT_HAVE_SSE2) {
		__asm__ __volatile__(
			"movupd %%xmm0,%0;"
			"movupd %%xmm1,%1;"
			"movupd %%xmm2,%2;"
			"movupd %%xmm3,%3;"
			"movupd %%xmm4,%4;"
			"movupd %%xmm5,%5;"
			"movupd %%xmm6,%6;"
			"movupd %%xmm7,%7;"
			: "=m" (vec[0][0]), "=m" (vec[1][0]),
			  "=m" (vec[2][0]), "=m" (vec[3][0]),
			  "=m" (vec[4][0]), "=m" (vec[5][0]),
			  "=m" (vec[6][0]), "=m" (vec[7][0]));
	}

	for (i = 0; i < 8; i++)
		if (e[i] != val) {
			report("r%d: %u != %u\n", i, e[i], val);
			result = e[i];
		}

	if (features & __COBALT_HAVE_AVX) {
		for (i = 0; i < 8; i++) {
			int error = 0;
			if (vec[i][0] != val) {
				result = vec[i][0];
				error = 1;
			}
			if (vec[i][2] != val) {
				result = vec[i][2];
				error = 1;
			}
			if (error)
				report("ymm%d: %llu/%llu != %u/%u\n",
				       i, (unsigned long long)vec[i][0],
				       (unsigned long long)vec[i][2],
				       val, val);
		}
	} else if (features & __COBALT_HAVE_SSE2) {
		for (i = 0; i < 8; i++)
			if (vec[i][0] != val) {
				report("xmm%d: %llu != %u\n",
				       i, (unsigned long long)vec[i][0], val);
				result = vec[i][0];
			}
	}

	return result;
}

#endif /* _COBALT_X86_ASM_UAPI_FPTEST_H */
