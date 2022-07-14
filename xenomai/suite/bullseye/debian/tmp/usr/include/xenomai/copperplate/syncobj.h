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

#ifndef _COPPERPLATE_SYNCOBJ_H
#define _COPPERPLATE_SYNCOBJ_H

#include <pthread.h>
#include <time.h>
#include <boilerplate/list.h>
#include <boilerplate/lock.h>
#include <copperplate/reference.h>

/* syncobj->flags */
#define SYNCOBJ_FIFO	0x0
#define SYNCOBJ_PRIO	0x1
#define SYNCOBJ_LOCKED	0x2

/* threadobj->wait_status */
#define SYNCOBJ_FLUSHED		0x1
#define SYNCOBJ_SIGNALED	0x2
#define SYNCOBJ_DRAINWAIT	0x4

#define SYNCOBJ_MAGIC  0xf9f99f9f

struct threadobj;

struct syncstate {
	int state;
};

#ifdef CONFIG_XENO_COBALT

#include <boilerplate/atomic.h>
#include <cobalt/uapi/monitor.h>

struct syncobj_corespec {
	cobalt_monitor_t monitor;
};

#else  /* CONFIG_XENO_MERCURY */

struct syncobj_corespec {
	pthread_mutex_t lock;
	pthread_cond_t drain_sync;
};

#endif /* CONFIG_XENO_MERCURY */

struct syncobj {
	unsigned int magic;
	int flags;
	int wait_count;
	struct listobj grant_list;
	int grant_count;
	struct listobj drain_list;
	int drain_count;
	struct syncobj_corespec core;
	fnref_type(void (*)(struct syncobj *sobj)) finalizer;
};

#define syncobj_for_each_grant_waiter(sobj, pos)		\
	list_for_each_entry(pos, &(sobj)->grant_list, wait_link)

#define syncobj_for_each_grant_waiter_safe(sobj, pos, tmp)	\
	list_for_each_entry_safe(pos, tmp, &(sobj)->grant_list, wait_link)

#define syncobj_for_each_drain_waiter(sobj, pos)		\
	list_for_each_entry(pos, &(sobj)->drain_list, wait_link)

#define syncobj_for_each_drain_waiter_safe(sobj, pos, tmp)	\
	list_for_each_entry_safe(pos, tmp, &(sobj)->drain_list, wait_link)

void __syncobj_cleanup_wait(struct syncobj *sobj,
			    struct threadobj *thobj);

#ifdef CONFIG_XENO_DEBUG

static inline void __syncobj_tag_locked(struct syncobj *sobj)
{
	sobj->flags |= SYNCOBJ_LOCKED;
}

static inline void __syncobj_tag_unlocked(struct syncobj *sobj)
{
	assert(sobj->flags & SYNCOBJ_LOCKED);
	sobj->flags &= ~SYNCOBJ_LOCKED;
}

static inline void __syncobj_check_locked(struct syncobj *sobj)
{
	assert(sobj->flags & SYNCOBJ_LOCKED);
}

#else /* !CONFIG_XENO_DEBUG */

static inline void __syncobj_tag_locked(struct syncobj *sobj)
{
}

static inline void __syncobj_tag_unlocked(struct syncobj *sobj)
{
}

static inline void __syncobj_check_locked(struct syncobj *sobj)
{
}

#endif /* !CONFIG_XENO_DEBUG */

#ifdef __cplusplus
extern "C" {
#endif

int __syncobj_broadcast_drain(struct syncobj *sobj, int reason);

int __syncobj_broadcast_grant(struct syncobj *sobj, int reason);

int syncobj_init(struct syncobj *sobj, clockid_t clk_id, int flags,
		 fnref_type(void (*)(struct syncobj *sobj)) finalizer) __must_check;

int syncobj_wait_grant(struct syncobj *sobj,
		 const struct timespec *timeout,
		 struct syncstate *syns) __must_check;

struct threadobj *syncobj_grant_one(struct syncobj *sobj);

void syncobj_grant_to(struct syncobj *sobj,
		      struct threadobj *thobj);

struct threadobj *syncobj_peek_grant(struct syncobj *sobj);

struct threadobj *syncobj_peek_drain(struct syncobj *sobj);

int syncobj_lock(struct syncobj *sobj,
		 struct syncstate *syns) __must_check;

void syncobj_unlock(struct syncobj *sobj,
		    struct syncstate *syns);

int syncobj_wait_drain(struct syncobj *sobj,
		       const struct timespec *timeout,
		       struct syncstate *syns) __must_check;

int syncobj_destroy(struct syncobj *sobj,
		    struct syncstate *syns);

void syncobj_uninit(struct syncobj *sobj);

static inline int syncobj_grant_wait_p(struct syncobj *sobj)
{
	__syncobj_check_locked(sobj);

	return !list_empty(&sobj->grant_list);
}

static inline int syncobj_count_grant(struct syncobj *sobj)
{
	__syncobj_check_locked(sobj);

	return sobj->grant_count;
}

static inline int syncobj_count_drain(struct syncobj *sobj)
{
	__syncobj_check_locked(sobj);

	return sobj->drain_count;
}

static inline int syncobj_drain_wait_p(struct syncobj *sobj)
{
	__syncobj_check_locked(sobj);

	return !list_empty(&sobj->drain_list);
}

static inline int syncobj_drain(struct syncobj *sobj)
{
	int ret = 0;

	__syncobj_check_locked(sobj);

	if (sobj->drain_count > 0)
		ret = __syncobj_broadcast_drain(sobj, SYNCOBJ_SIGNALED);

	return ret;
}

static inline int syncobj_grant_all(struct syncobj *sobj)
{
	int ret = 0;

	__syncobj_check_locked(sobj);

	if (sobj->grant_count > 0)
		ret = __syncobj_broadcast_grant(sobj, SYNCOBJ_SIGNALED);

	return ret;
}

static inline int syncobj_flush(struct syncobj *sobj)
{
	__syncobj_check_locked(sobj);

	if (sobj->grant_count > 0)
		__syncobj_broadcast_grant(sobj, SYNCOBJ_FLUSHED);

	if (sobj->drain_count > 0)
		__syncobj_broadcast_drain(sobj, SYNCOBJ_FLUSHED);

	return sobj->wait_count;
}

#ifdef __cplusplus
}
#endif

#endif /* _COPPERPLATE_SYNCOBJ_H */
