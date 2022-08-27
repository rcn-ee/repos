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
#ifndef _COBALT_POWERPC_ASM_UAPI_FPTEST_H
#define _COBALT_POWERPC_ASM_UAPI_FPTEST_H

#ifndef __NO_FPRS__		/* i.e. has FPU, not SPE */

static inline void fp_regs_set(int features, unsigned int val)
{
	unsigned long long fpval = val;

	__asm__ __volatile__("lfd	0, %0\n"
			     "	fmr	1, 0\n"
			     "	fmr	2, 0\n"
			     "	fmr	3, 0\n"
			     "	fmr	4, 0\n"
			     "	fmr	5, 0\n"
			     "	fmr	6, 0\n"
			     "	fmr	7, 0\n"
			     "	fmr	8, 0\n"
			     "	fmr	9, 0\n"
			     "	fmr	10, 0\n"
			     "	fmr	11, 0\n"
			     "	fmr	12, 0\n"
			     "	fmr	13, 0\n"
			     "	fmr	14, 0\n"
			     "	fmr	15, 0\n"
			     "	fmr	16, 0\n"
			     "	fmr	17, 0\n"
			     "	fmr	18, 0\n"
			     "	fmr	19, 0\n"
			     "	fmr	20, 0\n"
			     "	fmr	21, 0\n"
			     "	fmr	22, 0\n"
			     "	fmr	23, 0\n"
			     "	fmr	24, 0\n"
			     "	fmr	25, 0\n"
			     "	fmr	26, 0\n"
			     "	fmr	27, 0\n"
			     "	fmr	28, 0\n"
			     "	fmr	29, 0\n"
			     "	fmr	30, 0\n"
			     "	fmr	31, 0\n"::"m"(fpval));
}

#define FPTEST_REGVAL(n) {						\
    	unsigned long long t;						\
	__asm__ __volatile__("	stfd	" #n ", %0" : "=m" (t));	\
	e[n] = (unsigned)t;						\
	}

static inline unsigned int fp_regs_check(int features, unsigned int val,
					 int (*report)(const char *fmt, ...))
{
	unsigned int i, result = val;
	unsigned int e[32];

	FPTEST_REGVAL(0);
	FPTEST_REGVAL(1);
	FPTEST_REGVAL(2);
	FPTEST_REGVAL(3);
	FPTEST_REGVAL(4);
	FPTEST_REGVAL(5);
	FPTEST_REGVAL(6);
	FPTEST_REGVAL(7);
	FPTEST_REGVAL(8);
	FPTEST_REGVAL(9);
	FPTEST_REGVAL(10);
	FPTEST_REGVAL(11);
	FPTEST_REGVAL(12);
	FPTEST_REGVAL(13);
	FPTEST_REGVAL(14);
	FPTEST_REGVAL(15);
	FPTEST_REGVAL(16);
	FPTEST_REGVAL(17);
	FPTEST_REGVAL(18);
	FPTEST_REGVAL(19);
	FPTEST_REGVAL(20);
	FPTEST_REGVAL(21);
	FPTEST_REGVAL(22);
	FPTEST_REGVAL(23);
	FPTEST_REGVAL(24);
	FPTEST_REGVAL(25);
	FPTEST_REGVAL(26);
	FPTEST_REGVAL(27);
	FPTEST_REGVAL(28);
	FPTEST_REGVAL(29);
	FPTEST_REGVAL(30);
	FPTEST_REGVAL(31);

	for (i = 0; i < 32; i++)
		if (e[i] != val) {
			report("r%d: %u != %u\n", i, e[i], val);
			result = e[i];
		}

	return result;
}

#else	/* __NO_FPRS__ */

static inline void fp_regs_set(int features, unsigned int val) { }

static inline unsigned int fp_regs_check(int features, unsigned int val,
					 int (*report)(const char *fmt, ...))
{
	return val;
}

#endif	/* __NO_FPRS__ */

#endif /* !_COBALT_POWERPC_ASM_UAPI_FPTEST_H */
