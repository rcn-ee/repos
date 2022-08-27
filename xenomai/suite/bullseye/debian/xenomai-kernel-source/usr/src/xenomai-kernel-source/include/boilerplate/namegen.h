/*
 * Copyright (C) 2017 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _BOILERPLATE_NAMEGEN_H
#define _BOILERPLATE_NAMEGEN_H

#include <boilerplate/atomic.h>

struct name_generator {
	const char *radix;
	int length;
	atomic_t serial;
};

#define DEFINE_NAME_GENERATOR(__name, __radix, __type, __member)	\
	struct name_generator __name = {				\
		.radix = __radix,					\
		.length = sizeof ((__type *)0)->__member,		\
		.serial = ATOMIC_INIT(0),				\
	}

#ifdef __cplusplus
extern "C" {
#endif

char *generate_name(char *buf, const char *radix,
		    struct name_generator *ngen);

#ifdef __cplusplus
}
#endif

#endif /* _BOILERPLATE_NAMEGEN_H */
