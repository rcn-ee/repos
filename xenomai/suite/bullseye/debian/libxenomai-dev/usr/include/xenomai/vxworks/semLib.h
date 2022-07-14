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

#ifndef _XENOMAI_VXWORKS_SEMLIB_H
#define _XENOMAI_VXWORKS_SEMLIB_H

#include <vxworks/types.h>

#define SEM_Q_FIFO           0x0
#define SEM_Q_PRIORITY       0x1
#define SEM_DELETE_SAFE      0x4
#define SEM_INVERSION_SAFE   0x8

typedef uintptr_t SEM_ID;

typedef enum {
    SEM_EMPTY =0,
    SEM_FULL
} SEM_B_STATE;

#ifdef __cplusplus
extern "C" {
#endif

STATUS semGive(SEM_ID sem_id);

STATUS semTake(SEM_ID sem_id, int timeout);

STATUS semFlush(SEM_ID sem_id);

STATUS semDelete(SEM_ID sem_id);

SEM_ID semBCreate(int flags, SEM_B_STATE state);

SEM_ID semMCreate(int flags);

SEM_ID semCCreate(int flags, int count);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_SEMLIB_H */
