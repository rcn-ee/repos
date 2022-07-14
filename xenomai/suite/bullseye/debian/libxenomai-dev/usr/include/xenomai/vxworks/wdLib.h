/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
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
 *
 * This file satisfies the references within the emulator code
 * mimicking a VxWorks-like API built upon the copperplate library.
 *
 * VxWorks is a registered trademark of Wind River Systems, Inc.
 */

#ifndef _XENOMAI_VXWORKS_WDLIB_H
#define _XENOMAI_VXWORKS_WDLIB_H

#include <vxworks/types.h>

typedef uintptr_t WDOG_ID;

#ifdef __cplusplus
extern "C" {
#endif

WDOG_ID wdCreate(void);

STATUS wdDelete(WDOG_ID wdog_id);

STATUS wdStart(WDOG_ID wdog_id,
	       int delay,
	       void (*handler)(long),
	       long arg);

STATUS wdCancel(WDOG_ID wdog_id);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_WDLIB_H */
