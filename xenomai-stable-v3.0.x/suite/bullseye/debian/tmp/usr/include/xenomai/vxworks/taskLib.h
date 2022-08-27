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
 *
 * This file satisfies the references within the emulator code
 * mimicking a VxWorks-like API built upon the copperplate library.
 *
 * VxWorks is a registered trademark of Wind River Systems, Inc.
 */

#ifndef _XENOMAI_VXWORKS_TASKLIB_H
#define _XENOMAI_VXWORKS_TASKLIB_H

#include <pthread.h>
#include <vxworks/types.h>

/* Task options: none applicable - only there for code compatibility. */
#define VX_UNBREAKABLE   0x0002
#define VX_FP_TASK       0x0008
#define VX_PRIVATE_ENV   0x0080
#define VX_NO_STACK_FILL 0x0100

#define WIND_READY	0x0
#define WIND_SUSPEND	0x1
#define WIND_PEND	0x2
#define WIND_DELAY	0x4
#define WIND_DEAD	0x8
#define WIND_STOP	0x10	/* Never reported. */

typedef uintptr_t TASK_ID;

typedef void (*FUNCPTR)(long arg, ...);

typedef struct WIND_TCB {
	void *opaque;
	int status;
	int safeCnt;
	int flags;
	FUNCPTR entry;
} WIND_TCB;

#ifdef __cplusplus
extern "C" {
#endif

TASK_ID taskSpawn(const char *name,
		  int prio,
		  int flags,
		  int stacksize,
		  FUNCPTR entry,
		  long arg0, long arg1, long arg2, long arg3, long arg4,
		  long arg5, long arg6, long arg7, long arg8, long arg9);

STATUS taskInit(WIND_TCB *pTcb,
		const char *name,
		int prio,
		int flags,
		char * stack __attribute__ ((unused)),
		int stacksize,
		FUNCPTR entry,
		long arg0, long arg1, long arg2, long arg3, long arg4,
		long arg5, long arg6, long arg7, long arg8, long arg9);

STATUS taskActivate(TASK_ID tid);

STATUS taskDelete(TASK_ID tid);

STATUS taskDeleteForce(TASK_ID tid);

STATUS taskSuspend(TASK_ID tid);

STATUS taskResume(TASK_ID tid);

STATUS taskPrioritySet(TASK_ID tid,
		       int prio);

STATUS taskPriorityGet(TASK_ID tid,
		       int *pprio);

void taskExit(int code);

STATUS taskLock(void);

STATUS taskUnlock(void);

TASK_ID taskIdSelf(void);

STATUS taskSafe(void);

STATUS taskUnsafe(void);

STATUS taskDelay(int ticks);

STATUS taskIdVerify(TASK_ID tid);

struct WIND_TCB *taskTcb(TASK_ID tid);

int wind_task_normalize_priority(int wind_prio);

int wind_task_denormalize_priority(int core_prio);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_TASKLIB_H */
