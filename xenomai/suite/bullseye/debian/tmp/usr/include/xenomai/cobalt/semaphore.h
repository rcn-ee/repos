/*
 * Copyright (C) 2005 Philippe Gerum <rpm@xenomai.org>.
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
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#pragma GCC system_header
#include_next <semaphore.h>

#ifndef _COBALT_SEMAPHORE_H
#define _COBALT_SEMAPHORE_H

#include <boilerplate/atomic.h>
#include <cobalt/uapi/sem.h>
#include <cobalt/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

COBALT_DECL(int, sem_init(sem_t *sem,
			  int pshared,
			  unsigned int value));

COBALT_DECL(int, sem_destroy(sem_t *sem));

COBALT_DECL(int, sem_post(sem_t *sem));

COBALT_DECL(int, sem_wait(sem_t *sem));

COBALT_DECL(int, sem_timedwait(sem_t *sem,
			       const struct timespec *abs_timeout));

COBALT_DECL(int, sem_trywait(sem_t *sem));

COBALT_DECL(int, sem_getvalue(sem_t *sem, int *value));

COBALT_DECL(sem_t *, sem_open(const char *name, int oflags, ...));

COBALT_DECL(int, sem_close(sem_t *sem));

COBALT_DECL(int, sem_unlink(const char *name));

int sem_init_np(sem_t *sem,
		int flags,
		unsigned int value);

int sem_broadcast_np(sem_t *sem);

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_SEMAPHORE_H */
