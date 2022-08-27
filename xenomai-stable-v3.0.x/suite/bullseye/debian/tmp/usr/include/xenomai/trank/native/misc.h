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
#ifndef _XENOMAI_TRANK_NATIVE_MISC_H
#define _XENOMAI_TRANK_NATIVE_MISC_H

#include <stdint.h>
#include <errno.h>
#include <trank/trank.h>

#define IORN_IOPORT  0
#define IORN_IOMEM   0

typedef struct rt_ioregion {
} RT_IOREGION;

#ifdef __cplusplus
extern "C" {
#endif

__deprecated
static inline int rt_io_get_region(RT_IOREGION *iorn,
				   const char *name,
				   uint64_t start,
				   uint64_t len,
				   int flags)
{
	trank_warning("service should be provided by a RTDM driver");
	return -ENOSYS;
}

__deprecated
int rt_io_put_region(RT_IOREGION *iorn)
{
	trank_warning("service should be provided by a RTDM driver");
	return -ENOSYS;
}

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_NATIVE_MISC_H */
