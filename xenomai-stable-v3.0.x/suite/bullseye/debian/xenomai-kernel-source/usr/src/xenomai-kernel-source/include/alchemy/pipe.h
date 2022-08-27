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
#ifndef _XENOMAI_ALCHEMY_PIPE_H
#define _XENOMAI_ALCHEMY_PIPE_H

#include <stdint.h>
#include <cobalt/uapi/kernel/pipe.h>
#include <alchemy/timer.h>
#include <alchemy/compat.h>

/**
 * @addtogroup alchemy_pipe
 * @{
 */

/** Creation flags. */
#define P_MINOR_AUTO	XNPIPE_MINOR_AUTO

/** Operation flags. */
#define P_URGENT	XNPIPE_URGENT
#define P_NORMAL	XNPIPE_NORMAL

struct RT_PIPE {
	uintptr_t handle;
};

typedef struct RT_PIPE RT_PIPE;

#ifdef __cplusplus
extern "C" {
#endif

CURRENT_DECL(int, rt_pipe_create(RT_PIPE *pipe,
				 const char *name,
				 int minor, size_t poolsize));

int rt_pipe_delete(RT_PIPE *pipe);

ssize_t rt_pipe_read_timed(RT_PIPE *pipe,
			   void *buf, size_t size,
			   const struct timespec *abs_timeout);

static inline
ssize_t rt_pipe_read_until(RT_PIPE *pipe,
			   void *buf, size_t size, RTIME timeout)
{
	struct timespec ts;
	return rt_pipe_read_timed(pipe, buf, size,
				  alchemy_abs_timeout(timeout, &ts));
}

ssize_t rt_pipe_read(RT_PIPE *pipe,
		     void *buf, size_t size, RTIME timeout);

ssize_t rt_pipe_write(RT_PIPE *pipe,
		      const void *buf, size_t size, int mode);

ssize_t rt_pipe_stream(RT_PIPE *pipe,
		       const void *buf, size_t size);

int rt_pipe_bind(RT_PIPE *pipe,
		 const char *name, RTIME timeout);

int rt_pipe_unbind(RT_PIPE *pipe);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _XENOMAI_ALCHEMY_PIPE_H */
