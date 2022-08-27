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
#ifndef _XENOMAI_ALCHEMY_BUFFER_H
#define _XENOMAI_ALCHEMY_BUFFER_H

#include <stdint.h>
#include <alchemy/timer.h>

/**
 * @addtogroup alchemy_buffer
 * @{
 */

/** Creation flags. */
#define B_PRIO  0x1	/* Pend by task priority order. */
#define B_FIFO  0x0	/* Pend by FIFO order. */

struct RT_BUFFER {
	uintptr_t handle;
};

typedef struct RT_BUFFER RT_BUFFER;

/**
 * @brief Buffer status descriptor
 * @anchor RT_BUFFER_INFO
 *
 * This structure reports various static and runtime information about
 * a real-time buffer, returned by a call to rt_buffer_inquire().
 */
struct RT_BUFFER_INFO {
	/**
	 * Number of tasks waiting on the read side of the buffer for
	 * input data.
	 */
	int iwaiters;
	/**
	 * Number of tasks waiting on the write side of the buffer for
	 * sending out data.
	 */
	int owaiters;
	/**
	 * Overall size of buffer (in bytes).
	 */
	size_t totalmem;
	/**
	 * Amount of memory currently available for holding more data.
	 */
	size_t availmem;
	/**
	 * Name of the buffer.
	 */
	char name[XNOBJECT_NAME_LEN];
};

typedef struct RT_BUFFER_INFO RT_BUFFER_INFO;

#ifdef __cplusplus
extern "C" {
#endif

int rt_buffer_create(RT_BUFFER *bf,
		     const char *name,
		     size_t bufsz,
		     int mode);

int rt_buffer_delete(RT_BUFFER *bf);

ssize_t rt_buffer_write_timed(RT_BUFFER *bf,
			      const void *ptr, size_t size,
			      const struct timespec *abs_timeout);

static inline
ssize_t rt_buffer_write_until(RT_BUFFER *bf,
			      const void *ptr, size_t size,
			      RTIME timeout)
{
	struct timespec ts;
	return rt_buffer_write_timed(bf, ptr, size,
				     alchemy_abs_timeout(timeout, &ts));
}

static inline
ssize_t rt_buffer_write(RT_BUFFER *bf,
			const void *ptr, size_t size,
			RTIME timeout)
{
	struct timespec ts;
	return rt_buffer_write_timed(bf, ptr, size,
				     alchemy_rel_timeout(timeout, &ts));
}

ssize_t rt_buffer_read_timed(RT_BUFFER *bf,
			     void *ptr, size_t size,
			     const struct timespec *abs_timeout);

static inline
ssize_t rt_buffer_read_until(RT_BUFFER *bf,
			     void *ptr, size_t size,
			     RTIME timeout)
{
	struct timespec ts;
	return rt_buffer_read_timed(bf, ptr, size,
				    alchemy_abs_timeout(timeout, &ts));
}

static inline
ssize_t rt_buffer_read(RT_BUFFER *bf,
		       void *ptr, size_t size,
		       RTIME timeout)
{
	struct timespec ts;
	return rt_buffer_read_timed(bf, ptr, size,
				    alchemy_rel_timeout(timeout, &ts));
}

int rt_buffer_clear(RT_BUFFER *bf);

int rt_buffer_inquire(RT_BUFFER *bf,
		      RT_BUFFER_INFO *info);

int rt_buffer_bind(RT_BUFFER *bf,
		   const char *name, RTIME timeout);

int rt_buffer_unbind(RT_BUFFER *bf);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_BUFFER_H */
