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
#ifndef _XENOMAI_TRANK_NATIVE_EVENT_H
#define _XENOMAI_TRANK_NATIVE_EVENT_H

#include <alchemy/event.h>

#ifdef __cplusplus
extern "C" {
#endif

COMPAT_DECL(int, rt_event_create(RT_EVENT *event, const char *name,
				 unsigned long ivalue, int mode));

COMPAT_DECL(int, rt_event_signal(RT_EVENT *event, unsigned long mask));

COMPAT_DECL(int, rt_event_clear(RT_EVENT *event, unsigned long mask,
				unsigned long *mask_r));

#ifdef __XENO_COMPAT__

static inline
int rt_event_wait_until(RT_EVENT *event,
			unsigned long mask, unsigned long *mask_r,
			int mode, RTIME timeout)
{
	struct timespec ts;
	unsigned int _mask;
	int ret;

	ret = rt_event_wait_timed(event, mask, &_mask, mode,
				  alchemy_abs_timeout(timeout, &ts));
	if (ret)
		return ret;

	*mask_r = _mask;

	return 0;
}

static inline
int rt_event_wait(RT_EVENT *event,
		  unsigned long mask, unsigned long *mask_r,
		  int mode, RTIME timeout)
{
	struct timespec ts;
	unsigned int _mask;
	int ret;

	ret = rt_event_wait_timed(event, mask, &_mask, mode,
				  alchemy_rel_timeout(timeout, &ts));
	if (ret)
		return ret;

	*mask_r = _mask;

	return 0;
}

#endif /* __XENO_COMPAT__ */

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_NATIVE_EVENT_H */
