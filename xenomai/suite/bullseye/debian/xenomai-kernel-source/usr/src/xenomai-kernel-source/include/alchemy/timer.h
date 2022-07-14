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
#ifndef _XENOMAI_ALCHEMY_TIMER_H
#define _XENOMAI_ALCHEMY_TIMER_H

#include <stddef.h>
#include <copperplate/clockobj.h>

/**
 * @addtogroup alchemy_timer
 * @{
 */

typedef ticks_t RTIME;

typedef sticks_t SRTIME;

#define TM_INFINITE  0
#define TM_NOW       0
#define TM_NONBLOCK  ((RTIME)-1ULL)

/**
 * @brief Timer status descriptor
 * @anchor RT_TIMER_INFO
 *
 * This structure reports information about the Alchemy clock,
 * returned by a call to rt_timer_inquire().
 */
typedef struct rt_timer_info {
	/**
	 * Clock resolution in nanoseconds.
	 */
	RTIME period;
	/**
	 * Current monotonic date expressed in clock ticks. The
	 * duration of a tick depends on the Alchemy clock resolution
	 * for the process (see --alchemy-clock-resolution option,
	 * defaults to 1 nanosecond).
	 */
	RTIME date;
} RT_TIMER_INFO;

extern struct clockobj alchemy_clock;

#define alchemy_abs_timeout(__t, __ts)					\
	({								\
		(__t) == TM_INFINITE ? NULL :				\
		(__t) == TM_NONBLOCK ?					\
		({ (__ts)->tv_sec = (__ts)->tv_nsec = 0; (__ts); }) :	\
		({ clockobj_ticks_to_timespec(&alchemy_clock, (__t), (__ts)); \
			(__ts); });					\
	})

#define alchemy_rel_timeout(__t, __ts)					\
	({								\
		(__t) == TM_INFINITE ? NULL :				\
		(__t) == TM_NONBLOCK ?					\
		({ (__ts)->tv_sec = (__ts)->tv_nsec = 0; (__ts); }) :	\
		({ clockobj_ticks_to_timeout(&alchemy_clock, (__t), (__ts)); \
			(__ts); });					\
	})

static inline
int alchemy_poll_mode(const struct timespec *abs_timeout)
{
	return abs_timeout &&
		abs_timeout->tv_sec == 0 &&
		abs_timeout->tv_nsec == 0;
}

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @fn RTIME rt_timer_read(void)
 * @brief Return the current system time.
 *
 * Return the current time maintained by the Xenomai core clock.
 *
 * @return The current time expressed in clock ticks (see note).
 *
 * @apitags{unrestricted}
 *
 * @note The @a time value is a multiple of the Alchemy clock
 * resolution (see --alchemy-clock-resolution option, defaults to 1
 * nanosecond).
 */
static inline RTIME rt_timer_read(void)
{
	return clockobj_get_time(&alchemy_clock);
}

SRTIME rt_timer_ns2ticks(SRTIME ns);

SRTIME rt_timer_ticks2ns(SRTIME ticks);

RTIME rt_timer_read(void);

void rt_timer_inquire(RT_TIMER_INFO *info);

void rt_timer_spin(RTIME ns);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _ALCHEMY_TIMER_H */
