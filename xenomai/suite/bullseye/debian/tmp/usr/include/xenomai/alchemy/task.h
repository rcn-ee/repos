/*
 * Copyright (C) 2011 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _XENOMAI_ALCHEMY_TASK_H
#define _XENOMAI_ALCHEMY_TASK_H

#include <sys/types.h>
#include <stdint.h>
#include <xeno_config.h>
#include <boilerplate/list.h>
#include <copperplate/threadobj.h>
#include <alchemy/timer.h>
#include <alchemy/compat.h>

/**
 * @addtogroup alchemy_task
 * @{
 */

/** Task priorities. */
#define T_LOPRIO  0
#define T_HIPRIO  99

/** Task mode bits. */
#define T_LOCK		__THREAD_M_LOCK
/** Cobalt only, nop over Mercury. */
#define T_WARNSW	__THREAD_M_WARNSW
#define T_CONFORMING	__THREAD_M_CONFORMING
#define T_JOINABLE	__THREAD_M_SPARE0

struct RT_TASK {
	uintptr_t handle;
	pthread_t thread;
};

typedef struct RT_TASK RT_TASK;

struct RT_TASK_MCB {
	int flowid;
	int opcode;
	union {
		dref_type(void *) __dref;
		void *data;
	};
	ssize_t size;
};

typedef struct RT_TASK_MCB RT_TASK_MCB;

/**
 * @brief Task status descriptor
 * @anchor RT_TASK_INFO
 *
 * This structure reports various static and runtime information about
 * a real-time task, returned by a call to rt_task_inquire().
 */
struct RT_TASK_INFO {
	/**
	 * Task priority.
	 */
	int prio;
	/**
	 * Task status.
	 */
	struct threadobj_stat stat;
	/**
	 * Name of task.
	 */
	char name[XNOBJECT_NAME_LEN];
	/**
	 * Host pid.
	 */
	pid_t pid;
};

typedef struct RT_TASK_INFO RT_TASK_INFO;

#define NO_ALCHEMY_TASK	((RT_TASK){ 0, 0 })

#ifdef __cplusplus
extern "C" {
#endif

CURRENT_DECL(int, rt_task_create(RT_TASK *task,
				 const char *name,
				 int stksize,
				 int prio,
				 int mode));

int rt_task_delete(RT_TASK *task);

int rt_task_set_affinity(RT_TASK *task,
			 const cpu_set_t *cpus);

int rt_task_start(RT_TASK *task,
		  void (*entry)(void *arg),
		  void *arg);

CURRENT_DECL(int, rt_task_spawn(RT_TASK *task, const char *name,
				int stksize, int prio, int mode,
				void (*entry)(void *arg),
				void *arg));

int rt_task_shadow(RT_TASK *task,
		   const char *name,
		   int prio,
		   int mode);

int rt_task_join(RT_TASK *task);

CURRENT_DECL(int, rt_task_set_periodic(RT_TASK *task,
				       RTIME idate, RTIME period));

int rt_task_wait_period(unsigned long *overruns_r);

int rt_task_sleep(RTIME delay);

int rt_task_sleep_until(RTIME date);

int rt_task_same(RT_TASK *task1, RT_TASK *task2);

int rt_task_suspend(RT_TASK *task);

int rt_task_resume(RT_TASK *task);

RT_TASK *rt_task_self(void);

int rt_task_set_priority(RT_TASK *task, int prio);

int rt_task_set_mode(int clrmask, int setmask,
		     int *mode_r);

int rt_task_yield(void);

int rt_task_unblock(RT_TASK *task);

int rt_task_slice(RT_TASK *task, RTIME quantum);

int rt_task_inquire(RT_TASK *task,
		    RT_TASK_INFO *info);

ssize_t rt_task_send_timed(RT_TASK *task,
			   RT_TASK_MCB *mcb_s, RT_TASK_MCB *mcb_r,
			   const struct timespec *abs_timeout);

static inline
ssize_t rt_task_send_until(RT_TASK *task,
			   RT_TASK_MCB *mcb_s, RT_TASK_MCB *mcb_r,
			   RTIME timeout)
{
	struct timespec ts;
	return rt_task_send_timed(task, mcb_s, mcb_r,
				  alchemy_abs_timeout(timeout, &ts));
}

static inline
ssize_t rt_task_send(RT_TASK *task,
		     RT_TASK_MCB *mcb_s, RT_TASK_MCB *mcb_r,
		     RTIME timeout)
{
	struct timespec ts;
	return rt_task_send_timed(task, mcb_s, mcb_r,
				  alchemy_rel_timeout(timeout, &ts));
}

int rt_task_receive_timed(RT_TASK_MCB *mcb_r,
			  const struct timespec *abs_timeout);

static inline
int rt_task_receive_until(RT_TASK_MCB *mcb_r, RTIME timeout)
{
	struct timespec ts;
	return rt_task_receive_timed(mcb_r,
				     alchemy_abs_timeout(timeout, &ts));
}

static inline
int rt_task_receive(RT_TASK_MCB *mcb_r, RTIME timeout)
{
	struct timespec ts;
	return rt_task_receive_timed(mcb_r,
				     alchemy_rel_timeout(timeout, &ts));
}

int rt_task_reply(int flowid,
		  RT_TASK_MCB *mcb_s);

int rt_task_bind(RT_TASK *task,
		 const char *name, RTIME timeout);

int rt_task_unbind(RT_TASK *task);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_TASK_H */
