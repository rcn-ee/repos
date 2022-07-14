/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
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
#ifndef _COBALT_KERNEL_SCHED_RT_H
#define _COBALT_KERNEL_SCHED_RT_H

#ifndef _COBALT_KERNEL_SCHED_H
#error "please don't include cobalt/kernel/sched-rt.h directly"
#endif

/**
 * @addtogroup cobalt_core_sched
 * @{
 */

/*
 * Global priority scale for Xenomai's core scheduling class,
 * available to SCHED_COBALT members.
 */
#define XNSCHED_CORE_MIN_PRIO	0
#define XNSCHED_CORE_MAX_PRIO	259
#define XNSCHED_CORE_NR_PRIO	\
	(XNSCHED_CORE_MAX_PRIO - XNSCHED_CORE_MIN_PRIO + 1)

/*
 * Priority range for SCHED_FIFO, and all other classes Cobalt
 * implements except SCHED_COBALT.
 */
#define XNSCHED_FIFO_MIN_PRIO	1
#define XNSCHED_FIFO_MAX_PRIO	256

#if XNSCHED_CORE_NR_PRIO > XNSCHED_CLASS_WEIGHT_FACTOR ||	\
  (defined(CONFIG_XENO_OPT_SCALABLE_SCHED) &&			\
   XNSCHED_CORE_NR_PRIO > XNSCHED_MLQ_LEVELS)
#error "XNSCHED_MLQ_LEVELS is too low"
#endif

extern struct xnsched_class xnsched_class_rt;

static inline void __xnsched_rt_requeue(struct xnthread *thread)
{
	xnsched_addq(&thread->sched->rt.runnable, thread);
}

static inline void __xnsched_rt_enqueue(struct xnthread *thread)
{
	xnsched_addq_tail(&thread->sched->rt.runnable, thread);
}

static inline void __xnsched_rt_dequeue(struct xnthread *thread)
{
	xnsched_delq(&thread->sched->rt.runnable, thread);
}

static inline void __xnsched_rt_setparam(struct xnthread *thread,
					 const union xnsched_policy_param *p)
{
	thread->cprio = p->rt.prio;
	if (!xnthread_test_state(thread, XNBOOST)) {
#ifdef CONFIG_XENO_OPT_SCHED_WEAK
		xnthread_clear_state(thread, XNWEAK);
#else
		if (thread->cprio)
			xnthread_clear_state(thread, XNWEAK);
		else
			xnthread_set_state(thread, XNWEAK);
#endif
	}
}

static inline void __xnsched_rt_getparam(struct xnthread *thread,
					 union xnsched_policy_param *p)
{
	p->rt.prio = thread->cprio;
}

static inline void __xnsched_rt_trackprio(struct xnthread *thread,
					  const union xnsched_policy_param *p)
{
	if (p)
		__xnsched_rt_setparam(thread, p);
	else
		thread->cprio = thread->bprio;
}

static inline void __xnsched_rt_forget(struct xnthread *thread)
{
}

static inline int xnsched_rt_init_thread(struct xnthread *thread)
{
	return 0;
}

#ifdef CONFIG_XENO_OPT_SCHED_CLASSES
struct xnthread *xnsched_rt_pick(struct xnsched *sched);
#else
static inline struct xnthread *xnsched_rt_pick(struct xnsched *sched)
{
	return xnsched_getq(&sched->rt.runnable);
}
#endif

void xnsched_rt_tick(struct xnsched *sched);

/** @} */

#endif /* !_COBALT_KERNEL_SCHED_RT_H */
