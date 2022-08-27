/*
 * Copyright (C) 2015 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_TUNABLES_H
#define _COBALT_TUNABLES_H

#include <boilerplate/tunables.h>
#include <sys/cobalt.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int __cobalt_main_prio;

extern int __cobalt_print_bufsz;

extern int __cobalt_print_bufcount;

extern int __cobalt_print_syncdelay;

static inline define_config_tunable(main_prio, int, prio)
{
	__cobalt_main_prio = prio;
}

static inline read_config_tunable(main_prio, int)
{
	return __cobalt_main_prio;
}

static inline define_config_tunable(print_buffer_size, int, size)
{
	__cobalt_print_bufsz = size;
}

static inline read_config_tunable(print_buffer_size, int)
{
	return __cobalt_print_bufsz;
}

static inline define_config_tunable(print_buffer_count, int, count)
{
	__cobalt_print_bufcount = count;
}

static inline read_config_tunable(print_buffer_count, int)
{
	return __cobalt_print_bufcount;
}

static inline define_config_tunable(print_sync_delay, int, delay_ms)
{
	__cobalt_print_syncdelay = delay_ms;
}

static inline read_config_tunable(print_sync_delay, int)
{
	return __cobalt_print_syncdelay;
}

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_TUNABLES_H */
