/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
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
#pragma GCC system_header
#include_next <pthread.h>

#ifndef _XENOMAI_TRANK_POSIX_PTHREAD_H
#define _XENOMAI_TRANK_POSIX_PTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Set the mode of the current thread (compatibility service)
 *
 * This service is a non-portable extension of the POSIX interface.
 *
 * @param clrmask set of bits to be cleared;
 *
 * @param setmask set of bits to be set.
 *
 * @param mode_r If non-NULL, @a mode_r must be a pointer to a memory
 * location which will be written upon success with the previous set
 * of active mode bits. If NULL, the previous set of active mode bits
 * will not be returned.
 *
 * @return 0 on success;
 * @return an error number if:
 * - EINVAL, some bit in @a clrmask or @a setmask is invalid.
 *
 * @note Setting @a clrmask and @a setmask to zero leads to a nop,
 * only returning the previous mode if @a mode_r is a valid address.
 *
 * @deprecated This service is an alias to pthread_setmode_np() for
 * source compatibility with Xenomai 2.x.
 */
static inline int pthread_set_mode_np(int clrmask, int setmask,
				      int *mask_r)
{
	return pthread_setmode_np(clrmask, setmask, mask_r);
}

/**
 * Set a thread name (compatibility service)
 *
 * This service set to @a name, the name of @a thread. This name is
 * used for displaying information in /proc/xenomai/sched.
 *
 * This service is a non-portable extension of the POSIX interface.
 *
 * @param thread target thread;
 *
 * @param name name of the thread.
 *
 * @return 0 on success;
 * @return an error number if:
 * - ESRCH, @a thread is invalid.
 *
 * @deprecated This service is an alias to pthread_setname_np() for
 * source compatibility with Xenomai 2.x.
 */
static inline int pthread_set_name_np(pthread_t thread,
				      const char *name)
{
	return pthread_setname_np(thread, name);
}

int pthread_make_periodic_np(pthread_t thread,
			     struct timespec *starttp,
			     struct timespec *periodtp);

int pthread_wait_np(unsigned long *overruns_r);

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_POSIX_PTHREAD_H */
