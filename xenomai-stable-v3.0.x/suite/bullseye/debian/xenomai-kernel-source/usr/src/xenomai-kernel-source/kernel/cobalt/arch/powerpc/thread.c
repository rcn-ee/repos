/*
 * Copyright (C) 2001,2002,2003,2004 Philippe Gerum <rpm@xenomai.org>.
 *
 * 64-bit PowerPC adoption
 *   copyright (C) 2005 Taneli Vähäkangas and Heikki Lindholm
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

#include <linux/sched.h>
#include <linux/ipipe.h>
#include <linux/mm.h>
#include <asm/mmu_context.h>
#include <cobalt/kernel/thread.h>

asmlinkage struct task_struct *
_switch(struct thread_struct *prev, struct thread_struct *next);

void xnarch_switch_to(struct xnthread *out, struct xnthread *in)
{
	struct xnarchtcb *out_tcb = &out->tcb, *in_tcb = &in->tcb;
	struct mm_struct *prev_mm, *next_mm;
	struct task_struct *next;

	next = in_tcb->core.host_task;
	prev_mm = out_tcb->core.active_mm;

	next_mm = in_tcb->core.mm;
	if (next_mm == NULL) {
		in_tcb->core.active_mm = prev_mm;
		enter_lazy_tlb(prev_mm, next);
	} else {
		ipipe_switch_mm_head(prev_mm, next_mm, next);
		/*
		 * We might be switching back to the root thread,
		 * which we preempted earlier, shortly after "current"
		 * dropped its mm context in the do_exit() path
		 * (next->mm == NULL). In that particular case, the
		 * kernel expects a lazy TLB state for leaving the mm.
		 */
		if (next->mm == NULL)
			enter_lazy_tlb(prev_mm, next);
	}

	hard_local_irq_disable();
	_switch(out_tcb->core.tsp, in_tcb->core.tsp);
}

#ifdef CONFIG_XENO_ARCH_FPU

asmlinkage void __asm_init_fpu(struct thread_struct *ts);

asmlinkage void __asm_save_fpu(struct thread_struct *ts);

asmlinkage void __asm_restore_fpu(struct thread_struct *ts);

asmlinkage void __asm_disable_fpu(void);

asmlinkage void __asm_enable_fpu(void);

#if !defined(CONFIG_SMP) && LINUX_VERSION_CODE < KERNEL_VERSION(4,4,0)
#define get_fpu_owner(cur) last_task_used_math
#else /* CONFIG_SMP */
#define get_fpu_owner(cur) ({					\
    struct task_struct * _cur = (cur);                          \
    ((_cur->thread.regs && (_cur->thread.regs->msr & MSR_FP))   \
     ? _cur : NULL);                                            \
})
#endif /* CONFIG_SMP */

static void xnarch_enable_fpu(struct xnthread *thread)
{
	struct xnarchtcb *tcb = xnthread_archtcb(thread);
	struct task_struct *task = tcb->core.host_task;

	if (task && task != tcb->core.user_fpu_owner)
		__asm_disable_fpu();
	else
		__asm_enable_fpu();
}

static void do_save_fpu(struct xnthread *thread)
{
	struct xnarchtcb *tcb = xnthread_archtcb(thread);

	if (tcb->fpup) {
		__asm_save_fpu(tcb->fpup);

		if (tcb->core.user_fpu_owner &&
		    tcb->core.user_fpu_owner->thread.regs)
			tcb->core.user_fpu_owner->thread.regs->msr &= ~(MSR_FP|MSR_FE0|MSR_FE1);
	}
}

static void xnarch_restore_fpu(struct xnthread *thread)
{
	struct xnarchtcb *tcb = xnthread_archtcb(thread);
	struct thread_struct *ts;
	struct pt_regs *regs;

	if (tcb->fpup) {
		__asm_restore_fpu(tcb->fpup);
		/*
		 * Note: Only enable FP in MSR, if it was enabled when
		 * we saved the fpu state.
		 */
		if (tcb->core.user_fpu_owner) {
			ts = &tcb->core.user_fpu_owner->thread;
			regs = ts->regs;
			if (regs) {
				regs->msr &= ~(MSR_FE0|MSR_FE1);
				regs->msr |= (MSR_FP|ts->fpexc_mode);
			}
		}
	}
	/*
	 * FIXME: We restore FPU "as it was" when Xenomai preempted Linux,
	 * whereas we could be much lazier.
	 */
	if (tcb->core.host_task &&
	    tcb->core.host_task != tcb->core.user_fpu_owner)
		__asm_disable_fpu();
}

void xnarch_switch_fpu(struct xnthread *from, struct xnthread *to)
{
	if (from == to || 
		xnarch_fpu_ptr(xnthread_archtcb(from)) == 
		xnarch_fpu_ptr(xnthread_archtcb(to))) {
		xnarch_enable_fpu(to);
		return;
	}
	
	if (from)
		do_save_fpu(from);
	
	xnarch_restore_fpu(to);
}

void xnarch_leave_root(struct xnthread *root)
{
	struct xnarchtcb *rootcb = xnthread_archtcb(root);
	rootcb->core.user_fpu_owner = get_fpu_owner(rootcb->core.host_task);
	/* So that do_save_fpu() operates on the right FPU area. */
	rootcb->fpup = rootcb->core.user_fpu_owner ?
		&rootcb->core.user_fpu_owner->thread : NULL;
}

void xnarch_init_root_tcb(struct xnthread *thread)
{
	struct xnarchtcb *tcb = &thread->tcb;
	tcb->fpup = NULL;
}

void xnarch_init_shadow_tcb(struct xnthread *thread)
{
	struct xnarchtcb *tcb = &thread->tcb;
	tcb->fpup = &tcb->core.host_task->thread;
}

#endif /* CONFIG_XENO_ARCH_FPU */
