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
#include_next <time.h>

#ifndef _COBALT_TIME_H
#define _COBALT_TIME_H

/* Re-read in case we came from selective __need* block. */
#include_next <time.h>
#include <cobalt/wrappers.h>
#include <cobalt/uapi/time.h>

#ifdef __cplusplus
extern "C" {
#endif

struct timex;

COBALT_DECL(int, clock_getres(clockid_t clock_id,
			      struct timespec *tp));

COBALT_DECL(int, clock_gettime(clockid_t clock_id,
			       struct timespec *tp));

COBALT_DECL(int, clock_settime(clockid_t clock_id,
			       const struct timespec *tp));

COBALT_DECL(int, clock_nanosleep(clockid_t clock_id,
				 int flags,
				 const struct timespec *rqtp,
				 struct timespec *rmtp));

COBALT_DECL(time_t, time(time_t *t));

COBALT_DECL(int, nanosleep(const struct timespec *rqtp,
			   struct timespec *rmtp));

COBALT_DECL(int, timer_create(clockid_t clockid,
			      const struct sigevent *__restrict__ evp,
			      timer_t * __restrict__ timerid));

COBALT_DECL(int, timer_delete(timer_t timerid));

COBALT_DECL(int, timer_settime(timer_t timerid,
			       int flags,
			       const struct itimerspec *value,
			       struct itimerspec *ovalue));

COBALT_DECL(int, timer_gettime(timer_t timerid,
			       struct itimerspec *value));

COBALT_DECL(int, timer_getoverrun(timer_t timerid));

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_TIME_H */
