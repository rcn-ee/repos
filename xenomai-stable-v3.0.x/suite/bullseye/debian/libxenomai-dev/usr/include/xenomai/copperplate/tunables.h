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
#ifndef _COPPERPLATE_TUNABLES_H
#define _COPPERPLATE_TUNABLES_H

#include <boilerplate/tunables.h>

struct copperplate_setup_data {
	const char *session_root;
	const char *session_label;
	const char *registry_root;
	int no_registry;
	int shared_registry;
	size_t mem_pool;
	gid_t session_gid;
};

#ifdef __cplusplus
extern "C" {
#endif

extern struct copperplate_setup_data __copperplate_setup_data;

define_config_tunable(session_label, const char *, label);

static inline read_config_tunable(session_label, const char *)
{
	return __copperplate_setup_data.session_label;
}

static inline define_config_tunable(registry_root, const char *, root)
{
	__copperplate_setup_data.registry_root = root;
}

static inline read_config_tunable(registry_root, const char *)
{
	return __copperplate_setup_data.registry_root;
}

static inline define_config_tunable(no_registry, int, noreg)
{
	__copperplate_setup_data.no_registry = noreg;
}

static inline read_config_tunable(no_registry, int)
{
	return __copperplate_setup_data.no_registry;
}

static inline define_config_tunable(shared_registry, int, shared)
{
	__copperplate_setup_data.shared_registry = shared;
}

static inline read_config_tunable(shared_registry, int)
{
	return __copperplate_setup_data.shared_registry;
}

static inline define_config_tunable(mem_pool_size, size_t, size)
{
	__copperplate_setup_data.mem_pool = size;
}

static inline read_config_tunable(mem_pool_size, size_t)
{
	return __copperplate_setup_data.mem_pool;
}

static inline define_config_tunable(session_gid, gid_t, gid)
{
	__copperplate_setup_data.session_gid = gid;
}

static inline read_config_tunable(session_gid, gid_t)
{
	return __copperplate_setup_data.session_gid;
}

#ifdef __cplusplus
}
#endif

#endif /* !_COPPERPLATE_TUNABLES_H */
