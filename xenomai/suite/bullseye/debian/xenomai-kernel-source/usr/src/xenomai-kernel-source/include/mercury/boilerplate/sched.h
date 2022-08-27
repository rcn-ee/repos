/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _MERCURY_BOILERPLATE_SCHED_H
#define _MERCURY_BOILERPLATE_SCHED_H

#include <time.h>
#include <sched.h>

struct __sched_rr_param {
	struct timespec __sched_rr_quantum;
};

struct sched_param_ex {
	int sched_priority;
	union {
		struct __sched_rr_param rr;
	} sched_u;
};

#define sched_rr_quantum	sched_u.rr.__sched_rr_quantum

#endif /* _MERCURY_BOILERPLATE_SCHED_H */
