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
#ifndef _XENOMAI_TRANK_NATIVE_TASK_H
#define _XENOMAI_TRANK_NATIVE_TASK_H

#include <errno.h>
#include <alchemy/task.h>
#include <trank/trank.h>
#include <trank/native/types.h>

#define T_FPU    0
#define T_NOSIG  0
#define T_SUSP	 __THREAD_M_SPARE7

/* bit #24 onward are otherwise unused. */
#define T_CPU(cpu) (1 << (24 + (cpu & 7)))
#define T_CPUMASK  0xff000000

#ifdef __cplusplus
extern "C" {
#endif

__deprecated
static inline int rt_task_notify(RT_TASK *task, rt_sigset_t sigs)
{
	trank_warning("in-kernel native API is gone, rebase over RTDM");
	return -ENOSYS;
}

COMPAT_DECL(int, rt_task_create(RT_TASK *task, const char *name,
				int stksize, int prio, int mode));

COMPAT_DECL(int, rt_task_spawn(RT_TASK *task, const char *name,
			       int stksize, int prio, int mode,
			       void (*entry)(void *arg), void *arg));

COMPAT_DECL(int, rt_task_set_periodic(RT_TASK *task,
				      RTIME idate, RTIME period));
#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_NATIVE_TASK_H */
