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

#ifndef _COPPERPLATE_DEBUG_H
#define _COPPERPLATE_DEBUG_H

#include <boilerplate/debug.h>

#ifdef CONFIG_XENO_DEBUG

struct threadobj;

#define debug(__fmt, __args...)						\
	do {								\
		struct threadobj *__thobj = threadobj_current();	\
		if (__thobj == NULL ||					\
		    (__thobj->status & __THREAD_S_DEBUG) != 0)		\
		  __debug(__thobj ? __thobj->name : NULL, __fmt, ##__args); \
	} while (0)

#else /* !CONFIG_XENO_DEBUG */

#define debug(fmt, args...)  do { } while (0)

#endif /* !CONFIG_XENO_DEBUG */

#endif /* _COPPERPLATE_DEBUG_H */
