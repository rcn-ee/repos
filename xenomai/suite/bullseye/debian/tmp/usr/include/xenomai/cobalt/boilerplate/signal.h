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
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#ifndef _COBALT_BOILERPLATE_SIGNAL_H
#define _COBALT_BOILERPLATE_SIGNAL_H

#include <cobalt/signal.h>

/* Generates reserved signal numbers for Boilerplate/Copperplate. */
#define __SIGRSVD(n)	(SIGRTMIN + 8 + (n))

#define SIGAGENT	__SIGRSVD(0) /* Request to remote agent */
#define SIGPERIOD	__SIGRSVD(1) /* Periodic signal */

/* Generates private signal numbers for clients, up to SIGRTMAX. */
#define __SIGPRIV(n)	__SIGRSVD(8 + (n))

#define SIGSAFE_LOCK_ENTRY(__safelock)					\
  	do {								\
		push_cleanup_lock(__safelock);				\
		write_lock(__safelock);

#define SIGSAFE_LOCK_EXIT(__safelock)					\
		write_unlock(__safelock);				\
		pop_cleanup_lock(&__safelock);				\
	} while (0)

#endif /* _COBALT_BOILERPLATE_SIGNAL_H */
