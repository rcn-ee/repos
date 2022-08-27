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

#ifndef _XENOMAI_VXWORKS_MSGQLIB_H
#define _XENOMAI_VXWORKS_MSGQLIB_H

#include <vxworks/types.h>

typedef uintptr_t MSG_Q_ID;

#define MSG_PRI_NORMAL   0
#define MSG_PRI_URGENT   1

#define MSG_Q_FIFO       0x0
#define MSG_Q_PRIORITY   0x1

#ifdef __cplusplus
extern "C" {
#endif

MSG_Q_ID msgQCreate(int maxMsgs, int maxMsgLength, int options);

STATUS msgQDelete(MSG_Q_ID msgQId);

int msgQNumMsgs(MSG_Q_ID msgQId);

int msgQReceive(MSG_Q_ID msgQId, char *buf, UINT bytes, int timeout);

STATUS msgQSend(MSG_Q_ID msgQId, const char *buf, UINT bytes,
		int timeout, int prio);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_MSGQLIB_H */
