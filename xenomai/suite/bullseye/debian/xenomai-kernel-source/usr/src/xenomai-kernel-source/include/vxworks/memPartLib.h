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

#ifndef _XENOMAI_VXWORKS_MEMPARTLIB_H
#define _XENOMAI_VXWORKS_MEMPARTLIB_H

#include <vxworks/types.h>

typedef uintptr_t PART_ID;

struct wind_part_stats {
	unsigned long numBytesFree;
	unsigned long numBlocksFree;
	unsigned long numBytesAlloc;
	unsigned long numBlocksAlloc;
	unsigned long maxBytesAlloc;
};

typedef struct wind_part_stats MEM_PART_STATS;

#ifdef __cplusplus
extern "C" {
#endif

PART_ID memPartCreate(char *pPool, unsigned int poolSize);

STATUS memPartAddToPool(PART_ID  partId,
			char *pPool, unsigned int poolSize);

void *memPartAlignedAlloc(PART_ID  partId,
			  unsigned int nBytes, unsigned int alignment);

void *memPartAlloc(PART_ID  partId, unsigned int nBytes);

STATUS memPartFree(PART_ID partId, char *pBlock);

void memAddToPool(char *pPool, unsigned int poolSize);

STATUS memPartInfoGet(PART_ID partId,
		      MEM_PART_STATS *ppartStats);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_MEMPARTLIB_H */
