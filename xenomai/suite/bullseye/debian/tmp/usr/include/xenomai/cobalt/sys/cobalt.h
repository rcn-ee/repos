/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
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
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#ifndef _COBALT_SYS_COBALT_H
#define _COBALT_SYS_COBALT_H

#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <boilerplate/atomic.h>
#include <boilerplate/list.h>
#include <cobalt/uapi/kernel/synch.h>
#include <cobalt/uapi/kernel/vdso.h>
#include <cobalt/uapi/corectl.h>
#include <cobalt/uapi/mutex.h>
#include <cobalt/uapi/event.h>
#include <cobalt/uapi/monitor.h>
#include <cobalt/uapi/thread.h>
#include <cobalt/uapi/cond.h>
#include <cobalt/uapi/sem.h>
#include <cobalt/ticks.h>

#define cobalt_commit_memory(p) __cobalt_commit_memory(p, sizeof(*p))

struct cobalt_tsd_hook {
	void (*create_tsd)(void);
	void (*delete_tsd)(void);
	struct pvholder next;
};

#ifdef __cplusplus
extern "C" {
#endif

int cobalt_extend(unsigned int magic);

int cobalt_corectl(int request, void *buf, size_t bufsz);

int cobalt_thread_stat(pid_t pid,
		       struct cobalt_threadstat *stat);

int cobalt_serial_debug(const char *fmt, ...);

void __cobalt_commit_memory(void *p, size_t len);

void cobalt_thread_harden(void);

void cobalt_thread_relax(void);

int cobalt_thread_join(pthread_t thread);

pid_t cobalt_thread_pid(pthread_t thread);

int cobalt_thread_mode(void);
  
int cobalt_monitor_init(cobalt_monitor_t *mon,
			clockid_t clk_id, int flags);

int cobalt_monitor_destroy(cobalt_monitor_t *mon);

int cobalt_monitor_enter(cobalt_monitor_t *mon);

int cobalt_monitor_exit(cobalt_monitor_t *mon);

int cobalt_monitor_wait(cobalt_monitor_t *mon, int event,
			const struct timespec *ts);

void cobalt_monitor_grant(cobalt_monitor_t *mon,
			  struct xnthread_user_window *u_window);

int cobalt_monitor_grant_sync(cobalt_monitor_t *mon,
			      struct xnthread_user_window *u_window);

void cobalt_monitor_grant_all(cobalt_monitor_t *mon);

int cobalt_monitor_grant_all_sync(cobalt_monitor_t *mon);

void cobalt_monitor_drain(cobalt_monitor_t *mon);

int cobalt_monitor_drain_sync(cobalt_monitor_t *mon);

void cobalt_monitor_drain_all(cobalt_monitor_t *mon);

int cobalt_monitor_drain_all_sync(cobalt_monitor_t *mon);

int cobalt_event_init(cobalt_event_t *event,
		      unsigned int value,
		      int flags);

int cobalt_event_post(cobalt_event_t *event,
		      unsigned int bits);

int cobalt_event_wait(cobalt_event_t *event,
		      unsigned int bits,
		      unsigned int *bits_r,
		      int mode,
		      const struct timespec *timeout);

unsigned long cobalt_event_clear(cobalt_event_t *event,
				 unsigned int bits);

int cobalt_event_inquire(cobalt_event_t *event,
			 struct cobalt_event_info *info,
			 pid_t *waitlist, size_t waitsz);

int cobalt_event_destroy(cobalt_event_t *event);

int cobalt_sem_inquire(sem_t *sem, struct cobalt_sem_info *info,
		       pid_t *waitlist, size_t waitsz);

int cobalt_sched_weighted_prio(int policy,
			       const struct sched_param_ex *param_ex);

void cobalt_register_tsd_hook(struct cobalt_tsd_hook *th);

void cobalt_assert_nrt(void);

/* Use cobalt_assert_nrt() instead of: */
__deprecated void assert_nrt(void);
__deprecated void assert_nrt_fast(void);

extern int __cobalt_control_bind;

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_SYS_COBALT_H */
