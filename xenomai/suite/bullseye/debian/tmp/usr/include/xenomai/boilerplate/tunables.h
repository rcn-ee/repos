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
#ifndef _BOILERPLATE_TUNABLES_H
#define _BOILERPLATE_TUNABLES_H

#include <assert.h>
#include <boilerplate/setup.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline int __may_change_config_tunable(void)
{
	return !__config_done;
}

#define __tunable_set_call(__name, __scope)	\
	__assign_ ## __name ## _ ## __scope

#define __tunable_get_call(__name, __scope)	\
	__read_ ## __name ## _ ## __scope

#define __define_tunable(__name, __type, __val, __scope)	\
	void __tunable_set_call(__name, __scope)(__typeof__(__type) __val)

#define __read_tunable(__name, __type, __scope)	\
	__typeof__(__type) __tunable_get_call(__name, __scope)(void)

#define define_config_tunable(__name, __type, __val)	\
	__define_tunable(__name, __type, __val, config)

#define define_runtime_tunable(__name, __type, __val)	\
	__define_tunable(__name, __type, __val, runtime)

#define read_config_tunable(__name, __type)		\
	__read_tunable(__name, __type, config)

#define read_runtime_tunable(__name, __type)		\
	__read_tunable(__name, __type, runtime)

#define set_config_tunable(__name, __val)			\
	do {							\
		assert(__may_change_config_tunable());		\
		__tunable_set_call(__name, config)(__val);	\
	} while (0)

#define get_config_tunable(__name)		\
	__tunable_get_call(__name, config)()

#define set_runtime_tunable(__name, __val)	\
	__tunable_set_call(__name, runtime)(__val)

#define get_runtime_tunable(__name)		\
	__tunable_get_call(__name, runtime)()

static inline define_config_tunable(cpu_affinity, cpu_set_t, cpus)
{
	__base_setup_data.cpu_affinity = cpus;
}

static inline read_config_tunable(cpu_affinity, cpu_set_t)
{
	return __base_setup_data.cpu_affinity;
}

static inline define_config_tunable(no_mlock, int, nolock)
{
	__base_setup_data.no_mlock = nolock;
}

static inline read_config_tunable(no_mlock, int)
{
	return __base_setup_data.no_mlock;
}

static inline define_config_tunable(no_sanity, int, nosanity)
{
	__base_setup_data.no_sanity = nosanity;
}

static inline read_config_tunable(no_sanity, int)
{
	return __base_setup_data.no_sanity;
}

static inline define_runtime_tunable(verbosity_level, int, level)
{
	__base_setup_data.verbosity_level = level;
}

static inline read_runtime_tunable(verbosity_level, int)
{
	return __base_setup_data.verbosity_level;
}

static inline define_runtime_tunable(trace_level, int, level)
{
	__base_setup_data.trace_level = level;
}

static inline read_runtime_tunable(trace_level, int)
{
	return __base_setup_data.trace_level;
}

#ifdef __cplusplus
}
#endif

#endif /* !_BOILERPLATE_TUNABLES_H */
