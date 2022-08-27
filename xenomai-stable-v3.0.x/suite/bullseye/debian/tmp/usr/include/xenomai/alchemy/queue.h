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
#ifndef _XENOMAI_ALCHEMY_QUEUE_H
#define _XENOMAI_ALCHEMY_QUEUE_H

#include <stdint.h>
#include <alchemy/timer.h>

/**
 * @addtogroup alchemy_queue
 * @{
 */

/** Creation flags. */
#define Q_PRIO  0x1	/* Pend by task priority order. */
#define Q_FIFO  0x0	/* Pend by FIFO order. */

#define Q_UNLIMITED 0	/* No size limit. */

/*
 * Operation flags.
 */
#define Q_NORMAL     0x0
#define Q_URGENT     0x1
#define Q_BROADCAST  0x2

struct RT_QUEUE {
	uintptr_t handle;
};

typedef struct RT_QUEUE RT_QUEUE;

/**
 * @brief Queue status descriptor
 * @anchor RT_QUEUE_INFO
 *
 * This structure reports various static and runtime information about
 * a real-time queue, returned by a call to rt_queue_inquire().
 */
struct RT_QUEUE_INFO {
	/**
	 * Number of tasks currently waiting on the queue for
	 * messages.
	 */
	int nwaiters;
	/**
	 * Number of messages pending in queue.
	 */
	int nmessages;
	/**
	 * Queue mode bits, as given to rt_queue_create().
	 */
	int mode;
	/**
	 * Maximum number of messages in queue, zero if unlimited.
	 */
	size_t qlimit;
	/**
	 * Size of memory pool for holding message buffers (in bytes).
	 */
	size_t poolsize;
	/**
	 * Amount of memory consumed from the buffer pool.
	 */
	size_t usedmem;
	/**
	 * Name of message queue.
	 */
	char name[XNOBJECT_NAME_LEN];
};

typedef struct RT_QUEUE_INFO RT_QUEUE_INFO;

#ifdef __cplusplus
extern "C" {
#endif

int rt_queue_create(RT_QUEUE *queue,
		    const char *name,
		    size_t poolsize, size_t qlimit, int mode);

int rt_queue_delete(RT_QUEUE *queue);

void *rt_queue_alloc(RT_QUEUE *queue,
		     size_t size);

int rt_queue_free(RT_QUEUE *queue,
		  void *buf);

int rt_queue_send(RT_QUEUE *queue,
		  const void *buf, size_t size, int mode);

int rt_queue_write(RT_QUEUE *queue,
		   const void *buf, size_t size, int mode);

ssize_t rt_queue_receive_timed(RT_QUEUE *queue,
			       void **bufp,
			       const struct timespec *abs_timeout);

static inline
ssize_t rt_queue_receive_until(RT_QUEUE *queue,
			       void **bufp, RTIME timeout)
{
	struct timespec ts;
	return rt_queue_receive_timed(queue, bufp,
				      alchemy_abs_timeout(timeout, &ts));
}

static inline
ssize_t rt_queue_receive(RT_QUEUE *queue,
			 void **bufp, RTIME timeout)
{
	struct timespec ts;
	return rt_queue_receive_timed(queue, bufp,
				      alchemy_rel_timeout(timeout, &ts));
}

ssize_t rt_queue_read_timed(RT_QUEUE *queue,
			    void *buf, size_t size,
			    const struct timespec *abs_timeout);

static inline
ssize_t rt_queue_read_until(RT_QUEUE *queue,
			    void *buf, size_t size, RTIME timeout)
{
	struct timespec ts;
	return rt_queue_read_timed(queue, buf, size,
				   alchemy_abs_timeout(timeout, &ts));
}

static inline
ssize_t rt_queue_read(RT_QUEUE *queue,
		      void *buf, size_t size, RTIME timeout)
{
	struct timespec ts;
	return rt_queue_read_timed(queue, buf, size,
				   alchemy_rel_timeout(timeout, &ts));
}

int rt_queue_flush(RT_QUEUE *queue);

int rt_queue_inquire(RT_QUEUE *queue,
		     RT_QUEUE_INFO *info);

int rt_queue_bind(RT_QUEUE *queue,
		  const char *name,
		  RTIME timeout);

int rt_queue_unbind(RT_QUEUE *queue);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_QUEUE_H */
