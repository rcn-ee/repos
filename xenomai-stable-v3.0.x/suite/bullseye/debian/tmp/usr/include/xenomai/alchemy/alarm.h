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
#ifndef _XENOMAI_ALCHEMY_ALARM_H
#define _XENOMAI_ALCHEMY_ALARM_H

#include <stdint.h>
#include <alchemy/timer.h>
#include <alchemy/compat.h>

/**
 * @addtogroup alchemy_alarm
 * @{
 */

struct RT_ALARM {
	uintptr_t handle;
};

typedef struct RT_ALARM RT_ALARM;

/**
 * @brief Alarm status descriptor
 * @anchor RT_ALARM_INFO
 *
 * This structure reports various static and runtime information about
 * a real-time alarm, returned by a call to rt_alarm_inquire().
 */
struct RT_ALARM_INFO {
	/**
	 * Number of past expiries.
	 */
	unsigned long expiries;
	/**
	 * Name of alarm object.
	 */
	char name[XNOBJECT_NAME_LEN];
	/**
	 * Active flag.
	 */
	int active;
};

typedef struct RT_ALARM_INFO RT_ALARM_INFO;

#ifdef __cplusplus
extern "C" {
#endif

CURRENT_DECL(int, rt_alarm_create(RT_ALARM *alarm,
				  const char *name,
				  void (*handler)(void *arg),
				  void *arg));

CURRENT_DECL(int, rt_alarm_delete(RT_ALARM *alarm));

int rt_alarm_start(RT_ALARM *alarm,
		   RTIME value,
		   RTIME interval);

int rt_alarm_stop(RT_ALARM *alarm);

int rt_alarm_inquire(RT_ALARM *alarm,
		     RT_ALARM_INFO *info);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_ALARM_H */
