/*
 * Copyright (C) 2004-2013 Philippe Gerum.
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
#ifndef _COBALT_POWERPC_ASM_THREAD_H
#define _COBALT_POWERPC_ASM_THREAD_H

#include <asm-generic/xenomai/thread.h>

struct xnarchtcb {
	struct xntcb core;
#ifdef CONFIG_XENO_ARCH_FPU
	struct thread_struct *fpup;
#define xnarch_fpu_ptr(tcb)     ((tcb)->fpup)
#else
#define xnarch_fpu_ptr(tcb)     NULL
#endif
	struct {
		unsigned long nip;
		unsigned long r0;
	} mayday;
};

#define xnarch_fault_regs(d)	((d)->regs)
#define xnarch_fault_trap(d)    ((unsigned int)(d)->regs->trap)
#define xnarch_fault_code(d)    ((d)->regs->dar)
#define xnarch_fault_pc(d)      ((d)->regs->nip)
#define xnarch_fault_pc(d)      ((d)->regs->nip)
#define xnarch_fault_fpu_p(d)   0
#define xnarch_fault_pf_p(d)   ((d)->exception == IPIPE_TRAP_ACCESS)
#define xnarch_fault_bp_p(d)   ((current->ptrace & PT_PTRACED) &&	\
				((d)->exception == IPIPE_TRAP_IABR ||	\
				 (d)->exception == IPIPE_TRAP_SSTEP ||	\
				 (d)->exception == IPIPE_TRAP_DEBUG))
#define xnarch_fault_notify(d) (xnarch_fault_bp_p(d) == 0)

static inline void xnarch_enter_root(struct xnthread *root) { }

#ifdef CONFIG_XENO_ARCH_FPU

void xnarch_init_root_tcb(struct xnthread *thread);

void xnarch_init_shadow_tcb(struct xnthread *thread);

void xnarch_leave_root(struct xnthread *root);

#else  /* !CONFIG_XENO_ARCH_FPU */

static inline void xnarch_init_root_tcb(struct xnthread *thread) { }
static inline void xnarch_init_shadow_tcb(struct xnthread *thread) { }
static inline void xnarch_leave_root(struct xnthread *root) { }

#endif  /* !CONFIG_XENO_ARCH_FPU */

static inline int 
xnarch_handle_fpu_fault(struct xnthread *from, 
			struct xnthread *to, struct ipipe_trap_data *d)
{
	return 0;
}

static inline int xnarch_escalate(void)
{
	if (ipipe_root_p) {
		ipipe_raise_irq(cobalt_pipeline.escalate_virq);
		return 1;
	}

	return 0;
}

void xnarch_switch_to(struct xnthread *out, struct xnthread *in);

void xnarch_switch_fpu(struct xnthread *from, struct xnthread *thread);

#endif /* !_COBALT_POWERPC_ASM_THREAD_H */
