/*
 * Copyright (C) 2006 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
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
#include_next <signal.h>

#ifndef _COBALT_SIGNAL_H
#define _COBALT_SIGNAL_H

/* Re-read in case we came from selective __need* block. */
#include_next <signal.h>
#include <cobalt/wrappers.h>
#include <cobalt/uapi/signal.h>

#ifndef sigev_notify_thread_id
#define sigev_notify_thread_id	 _sigev_un._tid
#endif

#ifdef __cplusplus
extern "C" {
#endif

int cobalt_sigshadow_handler(int sig, siginfo_t *si,
			     void *ctxt);

void cobalt_sigdebug_handler(int sig, siginfo_t *si,
			     void *context);

COBALT_DECL(int, sigpending(sigset_t *set));

COBALT_DECL(int, sigwait(const sigset_t *set, int *sig));

COBALT_DECL(int, sigwaitinfo(const sigset_t *set, siginfo_t *si));

COBALT_DECL(int, sigtimedwait(const sigset_t *set, siginfo_t *si,
			      const struct timespec *timeout));

COBALT_DECL(int, kill(pid_t pid, int sig));

COBALT_DECL(int, sigqueue(pid_t pid, int sig,
			  const union sigval value));

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_SIGNAL_H */
