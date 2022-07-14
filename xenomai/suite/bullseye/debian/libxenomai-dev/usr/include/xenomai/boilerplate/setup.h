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
#ifndef _BOILERPLATE_SETUP_H
#define _BOILERPLATE_SETUP_H

#include <boilerplate/list.h>
#include <boilerplate/wrappers.h>
#include <string.h>
#include <sched.h>

struct base_setup_data {
	cpu_set_t cpu_affinity;
	int no_mlock;
	int no_sanity;
	int verbosity_level;
	int trace_level;
	const char *arg0;
};

struct option;

struct setup_descriptor {
	const char *name;
	int (*tune)(void);
	int (*parse_option)(int optnum, const char *optarg);
	void (*help)(void);
	int (*init)(void);
	const struct option *options;
	struct {
		int id;
		int opt_start;
		int opt_end;
		struct pvholder next;
		int done;
	} __reserved;
};

/*
 * We have three pre-defined constructor priorities:
 *
 * - One for setup calls (__setup_ctor), which are guaranteed to run
 * prior to the bootstrap code. You should use setup calls for
 * implementing initialization hooks which depend on a particular call
 * order. Each Xenomai interface layer is initialized via a dedicated
 * setup call.
 *
 * - A second priority is assigned to early init calls (__early_ctor),
 * which are also guaranteed to run prior to the bootstrap
 * code. Whether such early code runs before OR after any setup code
 * is __UNSPECIFIED__. By design, such code may not invoke any Xenomai
 * service, and generally speaking, should have no dependencies on
 * anything else.
 *
 * - The last priority level is used for the bootstrap code
 * (__bootstrap_ctor), which is guaranteed to run after any
 * setup/early code, provided such bootstrap code is part of the main
 * executable.
 *
 * The guarantees on the init order don't go beyond what is stated
 * here, do NOT assume more than this.
 */
#define __setup_ctor		__attribute__ ((constructor(200)))
#define __early_ctor		__attribute__ ((constructor(210)))
#define __bootstrap_ctor	__attribute__ ((constructor(220)))

#define __setup_call(__name, __id)			\
static __setup_ctor void __declare_ ## __name(void)	\
{							\
	__register_setup_call(&(__name), __id);		\
}

#define core_setup_call(__name)		__setup_call(__name, 0)
#define boilerplate_setup_call(__name)	__setup_call(__name, 1)
#define copperplate_setup_call(__name)	__setup_call(__name, 2)
#define interface_setup_call(__name)	__setup_call(__name, 3)
#define post_setup_call(__name)		__setup_call(__name, 4)
#define user_setup_call(__name)		__setup_call(__name, 5)

#ifdef __cplusplus
extern "C" {
#endif

void __register_setup_call(struct setup_descriptor *p, int id);

extern pid_t __node_id;

extern int __config_done;

extern struct base_setup_data __base_setup_data;

const char *get_program_name(void);

void __trace_me(const char *fmt, ...);

#define trace_me(__fmt, __args...)			\
	do {						\
		if (__base_setup_data.trace_level > 0)	\
			__trace_me(__fmt, ##__args);	\
	} while (0)

#ifdef __cplusplus
}
#endif

#endif /* !_BOILERPLATE_SETUP_H */
