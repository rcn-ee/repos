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

#ifndef _COPPERPLATE_SEMOBJ_H
#define _COPPERPLATE_SEMOBJ_H

#include <boilerplate/compiler.h>
#include <copperplate/reference.h>

struct semobj_waitentry {
	pid_t pid;
	char name[32];
};

#ifdef CONFIG_XENO_COBALT

#include <semaphore.h>

struct semobj_corespec {
	sem_t sem;
};

#else  /* CONFIG_XENO_MERCURY */

#include <copperplate/syncobj.h>

struct semobj_corespec {
	struct syncobj sobj;
	int flags;
	int value;
};

#endif /* CONFIG_XENO_MERCURY */

struct semobj {
	struct semobj_corespec core;
	fnref_type(void (*)(struct semobj *smobj)) finalizer;
};

#define SEMOBJ_PRIO	0x1
#define SEMOBJ_PULSE	0x2
#define SEMOBJ_WARNDEL	0x4

#ifdef __cplusplus
extern "C" {
#endif

int semobj_init(struct semobj *smobj,
		int flags, int value,
		fnref_type(void (*)(struct semobj *smobj)) finalizer);

int semobj_destroy(struct semobj *smobj);

void semobj_uninit(struct semobj *smobj);

int semobj_post(struct semobj *smobj);

int semobj_broadcast(struct semobj *smobj);

int semobj_wait(struct semobj *smobj,
		const struct timespec *timeout) __must_check;

int semobj_getvalue(struct semobj *smobj, int *sval);

int semobj_inquire(struct semobj *smobj, size_t waitsz,
		   struct semobj_waitentry *waitlist,
		   int *val_r);

#ifdef __cplusplus
}
#endif

#endif /* _COPPERPLATE_SEMOBJ_H */
