/*
 *  * Copyright (C) 2008 Niklaus Giger <niklaus.giger@member.fsf.org>.
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

#ifndef _XENOMAI_VXWORKS_RNGLIB_H
#define _XENOMAI_VXWORKS_RNGLIB_H

#include <vxworks/types.h>

typedef uintptr_t RING_ID;

#ifdef __cplusplus
extern "C" {
#endif

RING_ID rngCreate(int nbytes);

void rngDelete(RING_ID ringId);

void rngFlush(RING_ID ringId);

int rngBufGet(RING_ID rngId, char *buffer, int maxbytes);

int rngBufPut(RING_ID rngId, char *buffer, int nbytes);

BOOL rngIsEmpty(RING_ID ringId);

BOOL rngIsFull(RING_ID ringId);

int rngFreeBytes(RING_ID ringId);

int rngNBytes(RING_ID ringId);

void rngPutAhead(RING_ID ringId, char byte, int offset);

void rngMoveAhead(RING_ID ringId, int n);

#ifdef __cplusplus
}
#endif

#endif	/* !_XENOMAI_VXWORKS_RNGLIB_H */
