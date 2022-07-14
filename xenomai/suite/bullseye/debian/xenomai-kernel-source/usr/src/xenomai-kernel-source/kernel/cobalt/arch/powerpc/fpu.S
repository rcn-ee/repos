/*
 * Copyright (C) 2004-2009 Philippe Gerum.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, Inc., 675 Mass Ave, Cambridge MA 02139,
 * USA; either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <linux/version.h>
#include <asm/processor.h>
#include <asm/cputable.h>
#include <asm/ppc_asm.h>
#include <asm/asm-offsets.h>

#ifdef THREAD_FPSTATE
#define FIXUP_REG_FPSTATE(__reg)	addi	__reg, __reg, THREAD_FPSTATE
#else
/*
 * v3.10 -> v3.13 do not have THREAD_FPSTATE yet, but still
 * define THREAD_FPSCR.
 */
#define FIXUP_REG_FPSTATE(__reg)
#define	FPSTATE_FPSCR(__base)		THREAD_FPSCR(__base)
#endif

/* r3 = &thread_struct (tcb->fpup) */
_GLOBAL(__asm_save_fpu)
	mfmsr	r5
	ori	r5,r5,MSR_FP
	SYNC
	MTMSRD(r5)
	isync
	FIXUP_REG_FPSTATE(r3)
	SAVE_32FPRS(0,r3)
	mffs	fr0
	stfd	fr0,FPSTATE_FPSCR(r3)
	blr

/* r3 = &thread_struct */
_GLOBAL(__asm_init_fpu)
	mfmsr	r5
	ori	r5,r5,MSR_FP|MSR_FE0|MSR_FE1
	SYNC
	MTMSRD(r5)

	/* Fallback wanted. */
	
/* r3 = &thread_struct (tcb->fpup) */
_GLOBAL(__asm_restore_fpu)
	mfmsr	r5
	ori	r5,r5,MSR_FP
	SYNC
	MTMSRD(r5)
	isync
	FIXUP_REG_FPSTATE(r3)
	lfd	fr0,FPSTATE_FPSCR(r3)
	MTFSF_L(fr0)
	REST_32FPRS(0,r3)
	blr

_GLOBAL(__asm_disable_fpu)
	mfmsr	r5
	li	r3,MSR_FP
	andc	r5,r5,r3
	SYNC
	MTMSRD(r5)
	isync
	blr

_GLOBAL(__asm_enable_fpu)
	mfmsr	r5
	ori	r5,r5,MSR_FP
	SYNC
	MTMSRD(r5)
	isync
	blr
