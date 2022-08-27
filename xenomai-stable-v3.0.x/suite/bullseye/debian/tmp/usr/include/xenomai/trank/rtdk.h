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
#ifndef _XENOMAI_TRANK_RTDK_H
#define _XENOMAI_TRANK_RTDK_H

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void rt_print_auto_init(int enable)
{
	/* stdio support is automatically enabled by libcobalt. */
}

static inline void rt_print_cleanup(void) { }

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_RTDK_H */
