/*
 * Copyright (C) 2001-2010 Philippe Gerum <rpm@xenomai.org>.
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
 * mimicking a pSOS-like API built upon the copperplate library.
 *
 * pSOS and pSOS+ are registered trademarks of Wind River Systems, Inc.
 */

#ifndef _XENOMAI_PSOS_TUNABLES_H
#define _XENOMAI_PSOS_TUNABLES_H

#include <boilerplate/tunables.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int psos_long_names;

static inline define_config_tunable(long_names, int, on)
{
	psos_long_names = on;
}

static inline read_config_tunable(long_names, int)
{
	return psos_long_names;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_XENOMAI_PSOS_TUNABLES_H */
