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
#ifndef _XENOMAI_ALCHEMY_EVENT_H
#define _XENOMAI_ALCHEMY_EVENT_H

#include <stdint.h>
#include <alchemy/timer.h>
#include <alchemy/compat.h>

/**
 * @addtogroup alchemy_event
 * @{
 */

/** Creation flags. */
#define EV_PRIO  0x1	/* Pend by task priority order. */
#define EV_FIFO  0x0	/* Pend by FIFO order. */

/** Operation flags. */
#define EV_ANY  0x1	/* Disjunctive wait. */
#define EV_ALL  0x0	/* Conjunctive wait. */

struct RT_EVENT {
	uintptr_t handle;
};

typedef struct RT_EVENT RT_EVENT;

/**
 * @brief Event status descriptor
 * @anchor RT_EVENT_INFO
 *
 * This structure reports various static and runtime information about
 * an event flag group, returned by a call to rt_event_inquire().
 */
struct RT_EVENT_INFO {
	/**
	 * Current value of the event flag group.
	 */
	unsigned int value;
	/**
	 * Number of tasks currently waiting for events.
	 */
	int nwaiters;
	/**
	 * Name of event flag group.
	 */
	char name[XNOBJECT_NAME_LEN];
};

typedef struct RT_EVENT_INFO RT_EVENT_INFO;

#ifdef __cplusplus
extern "C" {
#endif

CURRENT_DECL(int, rt_event_create(RT_EVENT *event,
				  const char *name,
				  unsigned int ivalue,
				  int mode));

int rt_event_delete(RT_EVENT *event);

CURRENT_DECL(int, rt_event_signal(RT_EVENT *event,
				  unsigned int mask));

int rt_event_wait_timed(RT_EVENT *event,
			unsigned int mask,
			unsigned int *mask_r,
			int mode,
			const struct timespec *abs_timeout);

#ifndef __XENO_COMPAT__

static inline
int rt_event_wait_until(RT_EVENT *event,
			unsigned int mask, unsigned int *mask_r,
			int mode, RTIME timeout)
{
	struct timespec ts;
	return rt_event_wait_timed(event, mask, mask_r, mode,
				   alchemy_abs_timeout(timeout, &ts));
}

static inline
int rt_event_wait(RT_EVENT *event,
		  unsigned int mask, unsigned int *mask_r,
		  int mode, RTIME timeout)
{
	struct timespec ts;
	return rt_event_wait_timed(event, mask, mask_r, mode,
				   alchemy_rel_timeout(timeout, &ts));
}

#endif	/* !__XENO_COMPAT__ */

CURRENT_DECL(int, rt_event_clear(RT_EVENT *event,
				 unsigned int mask,
				 unsigned int *mask_r));

int rt_event_inquire(RT_EVENT *event,
		     RT_EVENT_INFO *info);

int rt_event_bind(RT_EVENT *event,
		  const char *name, RTIME timeout);

int rt_event_unbind(RT_EVENT *event);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_EVENT_H */
