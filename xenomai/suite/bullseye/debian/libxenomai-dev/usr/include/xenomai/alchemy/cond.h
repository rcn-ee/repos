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
#ifndef _XENOMAI_ALCHEMY_COND_H
#define _XENOMAI_ALCHEMY_COND_H

#include <stdint.h>
#include <alchemy/timer.h>
#include <alchemy/mutex.h>

/**
 * @addtogroup alchemy_cond
 * @{
 */

struct RT_COND {
	uintptr_t handle;
};

typedef struct RT_COND RT_COND;

/**
 * @brief Condition variable status descriptor
 * @anchor RT_CONF_INFO
 *
 * This structure reports various static and runtime information about
 * a condition variable, returned by a call to rt_cond_inquire().
 */
struct RT_COND_INFO {
	/**
	 * Name of condition variable.
	 */
	char name[XNOBJECT_NAME_LEN];
};

typedef struct RT_COND_INFO RT_COND_INFO;

#ifdef __cplusplus
extern "C" {
#endif

int rt_cond_create(RT_COND *cond,
		   const char *name);

int rt_cond_delete(RT_COND *cond);

int rt_cond_signal(RT_COND *cond);

int rt_cond_broadcast(RT_COND *cond);

int rt_cond_wait_timed(RT_COND *cond,
		       RT_MUTEX *mutex,
		       const struct timespec *abs_timeout);
static inline
int rt_cond_wait_until(RT_COND *cond, RT_MUTEX *mutex, RTIME timeout)
{
	struct timespec ts;
	return rt_cond_wait_timed(cond, mutex,
				  alchemy_abs_timeout(timeout, &ts));
}

static inline
int rt_cond_wait(RT_COND *cond, RT_MUTEX *mutex, RTIME timeout)
{
	struct timespec ts;
	return rt_cond_wait_timed(cond, mutex,
				  alchemy_rel_timeout(timeout, &ts));
}

int rt_cond_inquire(RT_COND *cond,
		    RT_COND_INFO *info);

int rt_cond_bind(RT_COND *cond,
		 const char *name, RTIME timeout);

int rt_cond_unbind(RT_COND *cond);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_COND_H */
