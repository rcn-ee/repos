/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
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

#ifndef _COPPERPLATE_THREADOBJ_H
#define _COPPERPLATE_THREADOBJ_H

#include <time.h>
#include <semaphore.h>
#include <signal.h>
#include <pthread.h>
#include <stdint.h>
#include <boilerplate/list.h>
#include <boilerplate/lock.h>
#include <boilerplate/sched.h>
#include <copperplate/clockobj.h>
#include <copperplate/heapobj.h>

#ifdef CONFIG_XENO_COBALT

#include <cobalt/uapi/kernel/types.h>

struct xnthread_user_window;

struct threadobj_corespec {
	xnhandle_t handle;
	union {
		__u32 u_winoff;
		struct xnthread_user_window *u_window;
	};
};

struct threadobj_stat {
	/** Execution time in primary mode (ns). */
	ticks_t xtime;
	/** Current timeout value (ns). */
	ticks_t timeout;
	/** Number of primary->secondary mode switches. */
	uint64_t msw;
	/** Number of context switches. */
	uint64_t csw;
	/** Number of Xenomai syscalls. */
	uint64_t xsc;
	/** Current CPU for thread. */
	int cpu;
	/** Scheduler lock nesting count. */
	int schedlock;
	/** Cobalt thread status bits. */
	unsigned int status;
	/** Number of page faults. */
	uint32_t pf;
};

#define SCHED_CORE  SCHED_COBALT

static inline
void threadobj_save_timeout(struct threadobj_corespec *corespec,
			    const struct timespec *timeout)
{
	/*
	 * We retrieve this information from the nucleus directly via
	 * cobalt_thread_stat().
	 */
}

#ifdef CONFIG_XENO_PSHARED

static inline struct xnthread_user_window *
threadobj_get_window(struct threadobj_corespec *corespec)
{
	extern void *cobalt_umm_shared;
	return (struct xnthread_user_window *)
		((caddr_t)cobalt_umm_shared + corespec->u_winoff);
}

#else /* !CONFIG_XENO_PSHARED */

static inline struct xnthread_user_window *
threadobj_get_window(struct threadobj_corespec *corespec)
{
	return corespec->u_window;
}

#endif /* !CONFIG_XENO_PSHARED */

#else  /* CONFIG_XENO_MERCURY */

#include <sys/time.h>

struct threadobj_corespec {
	pthread_cond_t grant_sync;
	int policy_unlocked;
	struct sched_param_ex schedparam_unlocked;
	timer_t rr_timer;
	/** Timeout reported by sysregd. */
	struct timespec timeout;
#ifdef CONFIG_XENO_WORKAROUND_CONDVAR_PI
	int policy_unboosted;
	struct sched_param_ex schedparam_unboosted;
#endif
};

struct threadobj_stat {
	/** Current timeout value (ns). */
	ticks_t timeout;
	/** Current CPU for thread. */
	int cpu;
	/** Scheduler lock nesting count. */
	int schedlock;
	/** Mercury thread status bits. */
	unsigned int status;
};

#define SCHED_CORE  SCHED_FIFO

static inline
void threadobj_save_timeout(struct threadobj_corespec *corespec,
			    const struct timespec *timeout)
{
	if (timeout)
		corespec->timeout = *timeout;
}

#endif /* CONFIG_XENO_MERCURY */

/*
 * threadobj->status, updated with ->lock held.
 */
#define __THREAD_S_STARTED	(1 << 0)	/* threadobj_start() called. */
#define __THREAD_S_WARMUP	(1 << 1)	/* threadobj_prologue() not called yet. */
#define __THREAD_S_ABORTED	(1 << 2)	/* Cancelled before start. */
#define __THREAD_S_LOCKED	(1 << 3)	/* threadobj_lock() granted (debug only). */
#define __THREAD_S_ACTIVE	(1 << 4)	/* Running user code. */
#define __THREAD_S_SUSPENDED	(1 << 5)	/* Suspended via threadobj_suspend(). */
#define __THREAD_S_SAFE		(1 << 6)	/* TCB release deferred. */
#define __THREAD_S_PERIODIC	(1 << 7)	/* Periodic timer set. */
#define __THREAD_S_DEBUG	(1 << 31)	/* Debug mode enabled. */
/*
 * threadobj->run_state, locklessly updated by "current", merged
 * with ->status bits by threadobj_get_status().
 */
#define __THREAD_S_RUNNING	0
#define __THREAD_S_DORMANT	(1 << 16)
#define __THREAD_S_WAIT		(1 << 17)
#define __THREAD_S_TIMEDWAIT	(1 << 18)
#define __THREAD_S_DELAYED	(1 << 19)
#define __THREAD_S_BREAK	(__THREAD_S_DELAYED|(1 << 20))

/* threadobj mode bits */
#define __THREAD_M_LOCK		(1 << 0) /* Toggle scheduler lock. */
#define __THREAD_M_WARNSW	(1 << 1) /* Toggle switch warning bit. */
#define __THREAD_M_CONFORMING	(1 << 2) /* Switch to conforming mode. */
#define __THREAD_M_SPARE0	(1 << 16)
#define __THREAD_M_SPARE1	(1 << 17)
#define __THREAD_M_SPARE2	(1 << 18)
#define __THREAD_M_SPARE3	(1 << 19)
#define __THREAD_M_SPARE4	(1 << 20)
#define __THREAD_M_SPARE5	(1 << 21)
#define __THREAD_M_SPARE6	(1 << 22)
#define __THREAD_M_SPARE7	(1 << 23)

#define THREADOBJ_IRQCONTEXT    ((struct threadobj *)-2UL)

struct traceobj;
struct syncobj;

struct threadobj {
	unsigned int magic;	/* Must be first. */
	pthread_t ptid;
	pthread_mutex_t lock;

	int schedlock_depth;
	int cancel_state;
	int status;
	int run_state;
	int policy;
	struct sched_param_ex schedparam;
	int global_priority;
	pid_t cnode;
	pid_t pid;
	char name[32];

	void (*finalizer)(struct threadobj *thobj);
	int core_offset;
	int *errno_pointer;
	/* Those members belong exclusively to the syncobj code. */
	struct syncobj *wait_sobj;
	struct holder wait_link;
	int wait_status;
	int wait_prio;
  	dref_type(void *) wait_union;
	size_t wait_size;
	timer_t periodic_timer;

	struct threadobj_corespec core;
	struct timespec tslice;
	pthread_cond_t barrier;
	struct traceobj *tracer;
	sem_t *cancel_sem;
	struct sysgroup_memspec memspec;
	struct backtrace_data btd;
};

struct threadobj_init_data {
	unsigned int magic;
	cpu_set_t affinity;
	int policy;
	struct sched_param_ex param_ex;
	void (*finalizer)(struct threadobj *thobj);
};

extern int threadobj_high_prio;

extern int threadobj_irq_prio;

extern pthread_key_t threadobj_tskey;

#ifdef HAVE_TLS

extern __thread __attribute__ ((tls_model (CONFIG_XENO_TLS_MODEL)))
struct threadobj *__threadobj_current;

static inline void threadobj_set_current(struct threadobj *thobj)
{
	__threadobj_current = thobj;
	pthread_setspecific(threadobj_tskey, thobj);
}

static inline struct threadobj *__threadobj_get_current(void)
{
	return __threadobj_current;
}

#else /* !HAVE_TLS */

static inline void threadobj_set_current(struct threadobj *thobj)
{
	pthread_setspecific(threadobj_tskey, thobj);
}

static inline struct threadobj *__threadobj_get_current(void)
{
	return (struct threadobj *)pthread_getspecific(threadobj_tskey);
}

#endif /* !HAVE_TLS */

static inline struct threadobj *threadobj_current(void)
{
	struct threadobj *thobj = __threadobj_get_current();
	return thobj == NULL || thobj == THREADOBJ_IRQCONTEXT ? NULL : thobj;
}

#ifdef CONFIG_XENO_DEBUG

static inline void __threadobj_tag_locked(struct threadobj *thobj)
{
	thobj->status |= __THREAD_S_LOCKED;
}

static inline void __threadobj_tag_unlocked(struct threadobj *thobj)
{
	assert(thobj->status & __THREAD_S_LOCKED);
	thobj->status &= ~__THREAD_S_LOCKED;
}

static inline void __threadobj_check_locked(struct threadobj *thobj)
{
	assert(thobj->status & __THREAD_S_LOCKED);
}

#else /* !CONFIG_XENO_DEBUG */

static inline void __threadobj_tag_locked(struct threadobj *thobj)
{
}

static inline void __threadobj_tag_unlocked(struct threadobj *thobj)
{
}

static inline void __threadobj_check_locked(struct threadobj *thobj)
{
}

#endif /* !CONFIG_XENO_DEBUG */

#ifdef __cplusplus
extern "C" {
#endif

void *__threadobj_alloc(size_t tcb_struct_size,
			size_t wait_union_size,
			int thobj_offset);

static inline void __threadobj_free(void *p)
{
	xnfree(p);
}

static inline void threadobj_free(struct threadobj *thobj)
{
	__threadobj_free((unsigned char *)thobj - thobj->core_offset);
}

int threadobj_init(struct threadobj *thobj,
		   struct threadobj_init_data *idata) __must_check;

int threadobj_start(struct threadobj *thobj) __must_check;

int threadobj_shadow(struct threadobj *thobj,
		     const char *name);

int threadobj_prologue(struct threadobj *thobj,
		       const char *name);

void threadobj_wait_start(void);

void threadobj_notify_entry(void);

int threadobj_cancel(struct threadobj *thobj);

void threadobj_uninit(struct threadobj *thobj);

int threadobj_suspend(struct threadobj *thobj);

int threadobj_resume(struct threadobj *thobj);

int threadobj_unblock(struct threadobj *thobj);

int __threadobj_lock_sched(struct threadobj *current);

int threadobj_lock_sched(void);

int __threadobj_unlock_sched(struct threadobj *current);

int threadobj_unlock_sched(void);

int threadobj_set_schedparam(struct threadobj *thobj, int policy,
			     const struct sched_param_ex *param_ex);

int threadobj_set_schedprio(struct threadobj *thobj, int priority);

int threadobj_set_mode(int clrmask, int setmask, int *mode_r);

int threadobj_set_periodic(struct threadobj *thobj,
			   const struct timespec *__restrict__ idate,
			   const struct timespec *__restrict__ period);

int threadobj_wait_period(unsigned long *overruns_r) __must_check;

void threadobj_spin(ticks_t ns);

int threadobj_stat(struct threadobj *thobj,
		   struct threadobj_stat *stat);

int threadobj_sleep(const struct timespec *ts);

void threadobj_set_current_name(const char *name);

#ifdef CONFIG_XENO_PSHARED

static inline int threadobj_local_p(struct threadobj *thobj)
{
	extern pid_t __node_id;
	return thobj->cnode == __node_id;
}

#else /* !CONFIG_XENO_PSHARED */

static inline int threadobj_local_p(struct threadobj *thobj)
{
	return 1;
}

#endif	/* !CONFIG_XENO_PSHARED */

void threadobj_init_key(void);

int threadobj_pkg_init(int anon_session);

#ifdef __cplusplus
}
#endif

#define threadobj_alloc(T, __mptr, W)					\
	({								\
		void *__p;						\
		__p = __threadobj_alloc(sizeof(T), sizeof(W), offsetof(T, __mptr)); \
		__p;							\
	})

static inline int threadobj_get_policy(struct threadobj *thobj)
{
	return thobj->policy;
}

static inline int threadobj_get_priority(struct threadobj *thobj)
{
	return thobj->schedparam.sched_priority;
}

static inline void threadobj_copy_schedparam(struct sched_param_ex *param_ex,
					     const struct threadobj *thobj)
{
	*param_ex = thobj->schedparam;
}

static inline int threadobj_lock(struct threadobj *thobj)
{
	int ret;

	ret = write_lock_safe(&thobj->lock, thobj->cancel_state);
	if (ret)
		return ret;

	__threadobj_tag_locked(thobj);

	return 0;
}

static inline int threadobj_trylock(struct threadobj *thobj)
{
	int ret;

	ret = write_trylock_safe(&thobj->lock, thobj->cancel_state);
	if (ret)
		return ret;

	__threadobj_tag_locked(thobj);

	return 0;
}

static inline int threadobj_unlock(struct threadobj *thobj)
{
	__threadobj_check_locked(thobj);
	__threadobj_tag_unlocked(thobj);
	return write_unlock_safe(&thobj->lock, thobj->cancel_state);
}

static inline int threadobj_irq_p(void)
{
	struct threadobj *current = __threadobj_get_current();
	return current == THREADOBJ_IRQCONTEXT;
}

static inline int threadobj_current_p(void)
{
	return threadobj_current() != NULL;
}

static inline int __threadobj_lock_sched_once(struct threadobj *current)
{
	if (current->schedlock_depth == 0)
		return __threadobj_lock_sched(current);

	return -EBUSY;
}

static inline int threadobj_lock_sched_once(void)
{
	struct threadobj *current = threadobj_current();

	if (current->schedlock_depth == 0)
		return threadobj_lock_sched();

	return -EBUSY;
}

static inline void threadobj_yield(void)
{
	__RT(sched_yield());
}

static inline unsigned int threadobj_get_magic(struct threadobj *thobj)
{
	return thobj->magic;
}

static inline void threadobj_set_magic(struct threadobj *thobj,
				       unsigned int magic)
{
	thobj->magic = magic;
}

static inline int threadobj_get_lockdepth(struct threadobj *thobj)
{
	return thobj->schedlock_depth;
}

static inline int threadobj_get_status(struct threadobj *thobj)
{
	return thobj->status | thobj->run_state;
}

static inline int threadobj_get_errno(struct threadobj *thobj)
{
	return *thobj->errno_pointer;
}

#define threadobj_prepare_wait(T)					\
	({								\
		struct threadobj *__thobj = threadobj_current();	\
		assert(__thobj != NULL);				\
		assert(sizeof(typeof(T)) <= __thobj->wait_size);	\
		__mptr(__thobj->wait_union);				\
	})

#define threadobj_finish_wait()		do { } while (0)

static inline void *threadobj_get_wait(struct threadobj *thobj)
{
	return __mptr(thobj->wait_union);
}

static inline const char *threadobj_get_name(struct threadobj *thobj)
{
	return thobj->name;
}

static inline pid_t threadobj_get_pid(struct threadobj *thobj)
{
	return thobj->pid;
}

#ifdef CONFIG_XENO_WORKAROUND_CONDVAR_PI

int threadobj_cond_timedwait(pthread_cond_t *cond,
			     pthread_mutex_t *lock,
			     const struct timespec *timeout);

int threadobj_cond_wait(pthread_cond_t *cond,
			pthread_mutex_t *lock);

int threadobj_cond_signal(pthread_cond_t *cond);

int threadobj_cond_broadcast(pthread_cond_t *cond);

#else

static inline
int threadobj_cond_timedwait(pthread_cond_t *cond,
			     pthread_mutex_t *lock,
			     const struct timespec *timeout)
{
	return __RT(pthread_cond_timedwait(cond, lock, timeout));
}

static inline
int threadobj_cond_wait(pthread_cond_t *cond,
			pthread_mutex_t *lock)
{
	return __RT(pthread_cond_wait(cond, lock));
}

static inline
int threadobj_cond_signal(pthread_cond_t *cond)
{
	return __RT(pthread_cond_signal(cond));
}

static inline
int threadobj_cond_broadcast(pthread_cond_t *cond)
{
	return __RT(pthread_cond_broadcast(cond));
}

#endif /* !CONFIG_XENO_WORKAROUND_CONDVAR_PI */

#endif /* _COPPERPLATE_THREADOBJ_H */
