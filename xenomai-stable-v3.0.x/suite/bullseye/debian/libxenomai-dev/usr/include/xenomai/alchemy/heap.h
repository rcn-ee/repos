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
#ifndef _XENOMAI_ALCHEMY_HEAP_H
#define _XENOMAI_ALCHEMY_HEAP_H

#include <stdint.h>
#include <alchemy/timer.h>

/**
 * @addtogroup alchemy_heap
 * @{
 */

/** Creation flags. */
#define H_PRIO    0x1	/* Pend by task priority order. */
#define H_FIFO    0x0	/* Pend by FIFO order. */
#define H_SINGLE  0x4	/* Manage as single-block area. */

struct RT_HEAP {
	uintptr_t handle;
};

typedef struct RT_HEAP RT_HEAP;

/**
 * @brief Heap status descriptor
 * @anchor RT_HEAP_INFO
 *
 * This structure reports various static and runtime information about
 * a real-time heap, returned by a call to rt_heap_inquire().
 */
struct RT_HEAP_INFO {
	/**
	 * Number of tasks waiting for available memory in
	 * rt_heap_alloc().
	 */
	int nwaiters;
	/**
	 * Creation mode flags as given to rt_heap_create().
	 */
	int mode;
	/**
	 * Size of heap (in bytes) as given to rt_heap_create(). The
	 * maximum amount of memory available from this heap may be
	 * larger, due to internal padding.
	 */
	size_t heapsize;
	/**
	 * Maximum amount of memory available from the heap. This
	 * value accounts for the overhead of internal data structures
	 * required to maintain the heap.
	 */
	size_t usablemem;
	/**
	 * Amount of heap memory currently consumed. info.usablemem -
	 * info.usedmem computes the current amount of free memory in
	 * the relevant heap.
	 */
	size_t usedmem;
	/**
	 * Name of heap.
	 */
	char name[XNOBJECT_NAME_LEN];
};

typedef struct RT_HEAP_INFO RT_HEAP_INFO;

#ifdef __cplusplus
extern "C" {
#endif

int rt_heap_create(RT_HEAP *heap,
		   const char *name,
		   size_t heapsize,
		   int mode);

int rt_heap_delete(RT_HEAP *heap);

int rt_heap_alloc_timed(RT_HEAP *heap,
			size_t size,
			const struct timespec *abs_timeout,
			void **blockp);

static inline
int rt_heap_alloc_until(RT_HEAP *heap,
			size_t size, RTIME timeout, void **blockp)
{
	struct timespec ts;
	return rt_heap_alloc_timed(heap, size,
				   alchemy_abs_timeout(timeout, &ts),
				   blockp);
}

static inline
int rt_heap_alloc(RT_HEAP *heap,
		  size_t size, RTIME timeout, void **blockp)
{
	struct timespec ts;
	return rt_heap_alloc_timed(heap, size,
				   alchemy_rel_timeout(timeout, &ts),
				   blockp);
}

int rt_heap_free(RT_HEAP *heap,
		 void *block);

int rt_heap_inquire(RT_HEAP *heap,
		    RT_HEAP_INFO *info);

int rt_heap_bind(RT_HEAP *heap,
		 const char *name,
		 RTIME timeout);

int rt_heap_unbind(RT_HEAP *heap);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_HEAP_H */
