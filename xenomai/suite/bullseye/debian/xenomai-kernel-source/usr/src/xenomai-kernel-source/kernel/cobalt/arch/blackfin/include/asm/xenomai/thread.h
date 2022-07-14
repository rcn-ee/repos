/*
 * Copyright (C) 2005, 2012 Philippe Gerum <rpm@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
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
#ifndef _COBALT_BLACKFIN_ASM_THREAD_H
#define _COBALT_BLACKFIN_ASM_THREAD_H

#include <asm-generic/xenomai/thread.h>

struct xnarchtcb {
	struct xntcb core;
	struct {
		unsigned long pc;
		unsigned long p0;
		unsigned long r5;
	} mayday;
};

#define xnarch_fpu_ptr(tcb)     NULL

#define xnarch_fault_regs(d)	((d)->regs)
#define xnarch_fault_trap(d)    ((d)->exception)
#define xnarch_fault_code(d)    (0) /* None on this arch. */
#define xnarch_fault_pc(d)      ((d)->regs->retx)
#define xnarch_fault_fpu_p(d)   (0) /* Can't be. */

#define xnarch_fault_pf_p(d)   (0) /* No page faults. */
#define xnarch_fault_bp_p(d)   ((current->ptrace & PT_PTRACED) &&   \
				((d)->exception == VEC_STEP ||	    \
				 (d)->exception == VEC_EXCPT01 ||   \
				 (d)->exception == VEC_WATCH))

#define xnarch_fault_notify(d) (!xnarch_fault_bp_p(d))

void xnarch_switch_to(struct xnthread *out, struct xnthread *in);

int xnarch_escalate(void);

static inline void xnarch_init_root_tcb(struct xnthread *thread) { }
static inline void xnarch_init_shadow_tcb(struct xnthread *thread) { }
static inline void xnarch_enter_root(struct xnthread *root) { }
static inline void xnarch_leave_root(struct xnthread *root) { }
static inline void
xnarch_switch_fpu(struct xnthread *from, struct xnthread *thread)
{ 
}

static inline int 
xnarch_handle_fpu_fault(struct xnthread *from, 
			struct xnthread *to, struct ipipe_trap_data *d)
{
	return 0;
}

#endif /* !_COBALT_BLACKFIN_ASM_THREAD_H */
