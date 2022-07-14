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

#include <linux/sched.h>
#include <linux/ipipe.h>
#include <linux/mm.h>
#include <asm/mmu_context.h>
#include <cobalt/kernel/thread.h>

asmlinkage void
__asm_switch_context(struct thread_struct *prev,
		     struct thread_struct *next);

asmlinkage int __asm_defer_switch_p(void);

#ifdef CONFIG_MPU

static inline
void mpu_switch(struct xnarchtcb *out_tcb, struct xnarchtcb *in_tcb)
{
	struct mm_struct *prev_mm, *next_mm;
	struct task_struct *next;

	next = in_tcb->core.host_task;
	prev_mm = out_tcb->core.active_mm;

	next_mm = in_tcb->core.mm;
	if (next_mm == NULL)
		in_tcb->core.active_mm = prev_mm;
	else
		ipipe_switch_mm_head(prev_mm, next_mm, next);
}

#else /* !CONFIG_MPU */

static inline
void mpu_switch(struct xnarchtcb *out_tcb, struct xnarchtcb *in_tcb)
{
}

#endif /* CONFIG_MPU */

void xnarch_switch_to(struct xnthread *out, struct xnthread *in)
{
	struct xnarchtcb *out_tcb = &out->tcb, *in_tcb = &in->tcb;
	mpu_switch(out_tcb, in_tcb);
	__asm_switch_context(out_tcb->core.tsp, in_tcb->core.tsp);
}

int xnarch_escalate(void)
{
	/* The following Blackfin-specific check is likely the most
	 * braindamage stuff we need to do for this arch, i.e. deferring
	 * Xenomai's rescheduling procedure whenever:

	 * 1. ILAT tells us that a deferred syscall (EVT15) is
	 * pending, so that we don't later execute this syscall over
	 * the wrong thread context. This could happen whenever a
	 * user-space task (plain or Xenomai) gets preempted by a high
	 * priority interrupt right after the deferred syscall event
	 * is raised (EVT15) but before the evt_system_call ISR could
	 * run. In case of deferred Xenomai rescheduling, the pending
	 * rescheduling opportunity will be checked at the beginning
	 * of Xenomai's handle_head_syscall() which intercepts any
	 * incoming syscall, and we know it will happen shortly after.
	 *
	 * 2. the context we will switch back to belongs to the Linux
	 * kernel code, so that we don't inadvertently cause the CPU
	 * to switch to user operating mode as a result of returning
	 * from an interrupt stack frame over the incoming thread
	 * through RTI. In the latter case, the preempted kernel code
	 * will be diverted shortly before resumption in order to run
	 * the rescheduling procedure (see __ipipe_irq_tail_hook).
	 */

	if (__asm_defer_switch_p()) {
		__ipipe_lock_root();
		return 1;
	}

	if (ipipe_root_p) {
		ipipe_raise_irq(cobalt_pipeline.escalate_virq);
		__ipipe_unlock_root();
		return 1;
	}

	__ipipe_unlock_root();

	return 0;
}
