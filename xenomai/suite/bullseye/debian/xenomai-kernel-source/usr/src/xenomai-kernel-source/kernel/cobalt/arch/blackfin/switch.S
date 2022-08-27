/*
 * Copyright (C) 2005 Philippe Gerum.
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

#include <linux/linkage.h>
#include <asm/blackfin.h>
#include <asm/entry.h>
#include <asm/asm-offsets.h>

/*
 * Switch context routine for Xenomai threads.
 *
 * void __asm_switch_context(struct thread_struct *prev, struct thread_struct *next)
 */
ENTRY(___asm_switch_context)

	[--sp] = rets;
	[--sp] = fp;
	[--sp] = ( R7:4, P5:3 );

	p0 = r0;
	p1 = r1;

	/* Save context. */
	p2 = usp;
	[p0+THREAD_USP] = p2;
	[p0+THREAD_KSP] = sp;
	r1.l = switch_point;
	r1.h = switch_point;
	[p0+THREAD_PC] = r1;

	/* Restore context. */
	sp = [p1+THREAD_KSP];
	p0 = [p1+THREAD_USP];
	usp = p0;
	p0 = [p1+THREAD_PC];
	jump (p0);

switch_point:

	( R7:4, P5:3 ) = [sp++];
	fp = [sp++];
	rets = [sp++];
	rts;

/*
 * Check for a reason to block context switching for Xenomai. This may
 * be the case, if:
 *
 * - an event is pending on EVT15 (Blackfin syscalls start as
 * exceptions, which are offloaded to EVT15, and we don't want to
 * change the underlying task context while any syscall is in
 * flight).
 *
 * - more than a single interrupt is pending in IPEND. In such a case,
 * switching context would cause the core to branch back to kernel
 * code without supervisor privileges (due to nested RTIs).
 *
 * int __asm_defer_switch_p(void)
 */

ENTRY(___asm_defer_switch_p)

	p2.l = lo(ILAT);
	p2.h = hi(ILAT);
	r0 = [p2];
	r1 = EVT_IVG15 (z);
	r0 = r0 & r1;
	cc = r0 == 0;
	if !cc jump 1f;
	p2.l = lo(IPEND);
	p2.h = hi(IPEND);
	csync;
	r2 = [p2];
	r1 = LO(~0x13) (Z);
	r0 = r2 & r1;
	cc = r0 == 0;
	if cc jump 1f;
	r1 = 1;
	r1 = r0 - r1;
	r0 = r0 & r1;
1:
	rts
