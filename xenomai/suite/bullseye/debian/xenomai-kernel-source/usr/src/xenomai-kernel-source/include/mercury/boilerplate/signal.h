/*
 * Copyright (C) 2013 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _MERCURY_BOILERPLATE_SIGNAL_H
#define _MERCURY_BOILERPLATE_SIGNAL_H

#include <signal.h>

#ifndef sigev_notify_thread_id
#define sigev_notify_thread_id	 _sigev_un._tid
#endif

/* Generates reserved signal numbers for Boilerplate/Copperplate. */
#define __SIGRSVD(n)	(SIGRTMIN + 8 + (n))

#define SIGSUSP		__SIGRSVD(0)	/* Suspend request */
#define SIGRESM		__SIGRSVD(1)	/* Resume request */
#define SIGRELS		__SIGRSVD(2)	/* Syscall abort */
#define SIGRRB		__SIGRSVD(3)	/* Round-robin event */
#define SIGAGENT	__SIGRSVD(4)	/* Request to remote agent */
#define SIGPERIOD	__SIGRSVD(5)	/* Periodic signal */

/* Generates private signal numbers for clients, up to SIGRTMAX. */
#define __SIGPRIV(n)	__SIGRSVD(8 + (n))

#define SIGSAFE_LOCK_ENTRY(__safelock)					\
  	do {								\
		sigset_t __safeset, __oldsafeset;			\
		sigemptyset(&__safeset);				\
		sigaddset(&__safeset, SIGSUSP);				\
		pthread_sigmask(SIG_BLOCK, &__safeset, &__oldsafeset);	\
		push_cleanup_lock(__safelock);				\
		write_lock(__safelock);

#define SIGSAFE_LOCK_EXIT(__safelock)					\
		write_unlock(__safelock);				\
		pop_cleanup_lock(&__safelock);				\
		pthread_sigmask(SIG_SETMASK, &__oldsafeset, NULL);	\
	} while (0)

#endif /* _MERCURY_BOILERPLATE_SIGNAL_H */
