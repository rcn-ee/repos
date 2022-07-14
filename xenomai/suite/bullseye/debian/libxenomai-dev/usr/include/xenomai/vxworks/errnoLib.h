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

#ifndef _XENOMAI_VXWORKS_ERRNOLIB_H
#define _XENOMAI_VXWORKS_ERRNOLIB_H

#include <errno.h>
#include <vxworks/taskLib.h>

#define OK	0
#define ERROR	(-1)

#define WIND_TASK_ERR_BASE	0x00030000
#define WIND_MEM_ERR_BASE	0x00110000
#define WIND_SEM_ERR_BASE	0x00160000
#define WIND_OBJ_ERR_BASE	0x003d0000
#define WIND_MSGQ_ERR_BASE	0x00410000
#define WIND_INT_ERR_BASE	0x00430000

#define S_objLib_OBJ_ID_ERROR		(WIND_OBJ_ERR_BASE + 0x0001)
#define S_objLib_OBJ_UNAVAILABLE	(WIND_OBJ_ERR_BASE + 0x0002)
#define S_objLib_OBJ_DELETED		(WIND_OBJ_ERR_BASE + 0x0003)
#define S_objLib_OBJ_TIMEOUT		(WIND_OBJ_ERR_BASE + 0x0004)
#define S_objLib_OBJ_NO_METHOD		(WIND_OBJ_ERR_BASE + 0x0005)

#define S_taskLib_NAME_NOT_FOUND	(WIND_TASK_ERR_BASE + 0x0065)
#define S_taskLib_TASK_HOOK_TABLE_FULL	(WIND_TASK_ERR_BASE + 0x0066)
#define S_taskLib_TASK_HOOK_NOT_FOUND	(WIND_TASK_ERR_BASE + 0x0067)
#define S_taskLib_ILLEGAL_PRIORITY	(WIND_TASK_ERR_BASE + 0x006d)

#define S_semLib_INVALID_STATE		(WIND_SEM_ERR_BASE + 0x0065)
#define S_semLib_INVALID_OPTION		(WIND_SEM_ERR_BASE + 0x0066)
#define S_semLib_INVALID_QUEUE_TYPE	(WIND_SEM_ERR_BASE + 0x0067)
#define S_semLib_INVALID_OPERATION	(WIND_SEM_ERR_BASE + 0x0068)

#define S_msgQLib_INVALID_MSG_LENGTH		(WIND_MSGQ_ERR_BASE + 0x0001)
#define S_msgQLib_NON_ZERO_TIMEOUT_AT_INT_LEVEL	(WIND_MSGQ_ERR_BASE + 0x0002)
#define S_msgQLib_INVALID_QUEUE_TYPE		(WIND_MSGQ_ERR_BASE + 0x0003)

#define S_intLib_NOT_ISR_CALLABLE	(WIND_INT_ERR_BASE + 0x0001)

#define S_memLib_NOT_ENOUGH_MEMORY	(WIND_MEM_ERR_BASE + 0x0001)
#define S_memLib_INVALID_NBYTES		(WIND_MEM_ERR_BASE + 0x0002)

#ifdef __cplusplus
extern "C" {
#endif

void printErrno(int status);

STATUS errnoSet(int status);

int errnoGet(void);

int errnoOfTaskGet(TASK_ID task_id);

STATUS errnoOfTaskSet(TASK_ID task_id, int status);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_ERRNOLIB_H */
