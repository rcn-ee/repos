/*
 * Copyright (C) 2013 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
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
#ifndef _COBALT_SYS_TIMERFD_H
#define _COBALT_SYS_TIMERFD_H

#pragma GCC system_header
#include_next <sys/timerfd.h>
#include <cobalt/wrappers.h>
#include <cobalt/uapi/time.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

COBALT_DECL(int, timerfd_create(int clockid, int flags));

COBALT_DECL(int, timerfd_settime(int fd, int flags,
		const struct itimerspec *new_value,
		struct itimerspec *old_value));

COBALT_DECL(int, timerfd_gettime(int fd, struct itimerspec *curr_value));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _COBALT_SYS_TIMERFD_H */
