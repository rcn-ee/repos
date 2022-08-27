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
#ifndef _MERCURY_BOILERPLATE_TRACE_H
#define _MERCURY_BOILERPLATE_TRACE_H

#include <errno.h>

static inline int xntrace_max_begin(unsigned long v)
{
	return -ENOSYS;
}

static inline int xntrace_max_end(unsigned long v)
{
	return -ENOSYS;
}

static inline int xntrace_max_reset(void)
{
	return -ENOSYS;
}

static inline int xntrace_user_start(void)
{
	return -ENOSYS;
}

static inline int xntrace_user_stop(unsigned long v)
{
	return -ENOSYS;
}

static inline int xntrace_user_freeze(unsigned long v, int once)
{
	return -ENOSYS;
}

static inline int xntrace_special(unsigned char id, unsigned long v)
{
	return -ENOSYS;
}

static inline int xntrace_special_u64(unsigned char id, unsigned long long v)
{
	return -ENOSYS;
}

#endif /* _MERCURY_BOILERPLATE_TRACE_H */
