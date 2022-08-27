/*
 * Copyright (C) 2005 Philippe Gerum <rpm@xenomai.org>.
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
#pragma GCC system_header
#include_next <pthread.h>

#ifndef _COBALT_PTHREAD_H
#define _COBALT_PTHREAD_H

#include <boilerplate/libc.h>
#include <cobalt/wrappers.h>
#include <cobalt/uapi/thread.h>

typedef struct pthread_attr_ex {
	pthread_attr_t std;
	struct {
		int personality;
		int sched_policy;
		struct sched_param_ex sched_param;
	} nonstd;
} pthread_attr_ex_t;

#ifdef __cplusplus
extern "C" {
#endif

COBALT_DECL(int, pthread_attr_init(pthread_attr_t *attr));

COBALT_DECL(int, pthread_create(pthread_t *ptid_r,
				const pthread_attr_t *attr,
				void *(*start) (void *),
				void *arg));

COBALT_DECL(int, pthread_getschedparam(pthread_t thread,
				       int *policy,
				       struct sched_param *param));

COBALT_DECL(int, pthread_setschedparam(pthread_t thread,
				       int policy,
				       const struct sched_param *param));

COBALT_DECL(int, pthread_mutex_init(pthread_mutex_t *mutex,
				    const pthread_mutexattr_t *attr));

COBALT_DECL(int, pthread_mutex_destroy(pthread_mutex_t *mutex));

COBALT_DECL(int, pthread_mutex_lock(pthread_mutex_t *mutex));

COBALT_DECL(int, pthread_mutex_timedlock(pthread_mutex_t *mutex,
					 const struct timespec *to));

COBALT_DECL(int, pthread_mutex_trylock(pthread_mutex_t *mutex));

COBALT_DECL(int, pthread_mutex_unlock(pthread_mutex_t *mutex));

COBALT_DECL(int, pthread_cond_init (pthread_cond_t *cond,
				    const pthread_condattr_t *attr));

COBALT_DECL(int, pthread_cond_destroy(pthread_cond_t *cond));

COBALT_DECL(int, pthread_cond_wait(pthread_cond_t *cond,
				   pthread_mutex_t *mutex));

COBALT_DECL(int, pthread_cond_timedwait(pthread_cond_t *cond,
					pthread_mutex_t *mutex,
					const struct timespec *abstime));

COBALT_DECL(int, pthread_cond_signal(pthread_cond_t *cond));

COBALT_DECL(int, pthread_cond_broadcast(pthread_cond_t *cond));

COBALT_DECL(int, pthread_kill(pthread_t ptid, int sig));

COBALT_DECL(int, pthread_join(pthread_t ptid, void **retval));

#ifndef pthread_yield
/*
 * linuxthreads wraps pthread_yield() to sched_yield() via a
 * preprocessor macro, which confuses the compiler with
 * COBALT_DECL(). Since Cobalt also routes pthread_yield() to its own
 * sched_yield() implementation internally, we can live with this
 * wrapping.
 */
COBALT_DECL(int, pthread_yield(void));
#endif

int pthread_setmode_np(int clrmask, int setmask,
		       int *mask_r);

COBALT_DECL(int, pthread_setname_np(pthread_t thread, const char *name));

int pthread_create_ex(pthread_t *ptid_r,
		      const pthread_attr_ex_t *attr_ex,
		      void *(*start)(void *),
		      void *arg);

int pthread_getschedparam_ex(pthread_t ptid,
			     int *pol,
			     struct sched_param_ex *par);

int pthread_setschedparam_ex(pthread_t ptid,
			     int pol,
			     const struct sched_param_ex *par);

int pthread_attr_init_ex(pthread_attr_ex_t *attr_ex);

int pthread_attr_destroy_ex(pthread_attr_ex_t *attr_ex);

int pthread_attr_setschedpolicy_ex(pthread_attr_ex_t *attr_ex,
				   int policy);

int pthread_attr_getschedpolicy_ex(const pthread_attr_ex_t *attr_ex,
				   int *policy);

int pthread_attr_setschedparam_ex(pthread_attr_ex_t *attr_ex,
				  const struct sched_param_ex *param_ex);

int pthread_attr_getschedparam_ex(const pthread_attr_ex_t *attr_ex,
				  struct sched_param_ex *param_ex);

int pthread_attr_getinheritsched_ex(const pthread_attr_ex_t *attr_ex,
				    int *inheritsched);

int pthread_attr_setinheritsched_ex(pthread_attr_ex_t *attr_ex,
				    int inheritsched);

int pthread_attr_getdetachstate_ex(const pthread_attr_ex_t *attr_ex,
				   int *detachstate);

int pthread_attr_setdetachstate_ex(pthread_attr_ex_t *attr_ex,
				   int detachstate);

int pthread_attr_setdetachstate_ex(pthread_attr_ex_t *attr_ex,
				   int detachstate);

int pthread_attr_getstacksize_ex(const pthread_attr_ex_t *attr_ex,
				 size_t *stacksize);

int pthread_attr_setstacksize_ex(pthread_attr_ex_t *attr_ex,
				 size_t stacksize);

int pthread_attr_getscope_ex(const pthread_attr_ex_t *attr_ex,
			     int *scope);

int pthread_attr_setscope_ex(pthread_attr_ex_t *attr_ex,
			     int scope);

int pthread_attr_getpersonality_ex(const pthread_attr_ex_t *attr_ex,
				   int *personality);

int pthread_attr_setpersonality_ex(pthread_attr_ex_t *attr_ex,
				   int personality);
#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_PTHREAD_H */
