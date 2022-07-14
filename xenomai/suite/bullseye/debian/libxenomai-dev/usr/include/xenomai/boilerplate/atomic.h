/**
 *   Copyright &copy; 2011 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
 *   Copyright &copy; 2013 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _BOILERPLATE_ATOMIC_H
#define _BOILERPLATE_ATOMIC_H

#include <xeno_config.h>

typedef struct { int v; } atomic_t;

typedef struct { long v; } atomic_long_t;

#define ATOMIC_INIT(__n) { (__n) }

static inline long atomic_long_read(const atomic_long_t *ptr)
{
	return ptr->v;
}

static inline void atomic_long_set(atomic_long_t *ptr, long v)
{
	ptr->v = v;
}

static inline int atomic_read(const atomic_t *ptr)
{
	return ptr->v;
}

static inline void atomic_set(atomic_t *ptr, long v)
{
	ptr->v = v;
}

#ifndef atomic_cmpxchg
#define atomic_cmpxchg(__ptr, __old, __new)  \
	__sync_val_compare_and_swap(&(__ptr)->v, __old, __new)
#endif

#ifndef atomic_sub_fetch
#define atomic_sub_fetch(__ptr, __n)	\
	__sync_sub_and_fetch(&(__ptr)->v, __n)
#endif

#ifndef atomic_add_fetch
#define atomic_add_fetch(__ptr, __n)	\
	__sync_add_and_fetch(&(__ptr)->v, __n)
#endif

#ifdef CONFIG_SMP
#ifndef smp_mb
#define smp_mb()	__sync_synchronize()
#endif
#ifndef smp_rmb
#define smp_rmb()	smp_mb()
#endif
#ifndef smp_wmb
#define smp_wmb()	smp_mb()
#endif
#else  /* !CONFIG_SMP */
#define smp_mb()	do { } while (0)
#define smp_rmb()	do { } while (0)
#define smp_wmb()	do { } while (0)
#endif /* !CONFIG_SMP */

#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

#define compiler_barrier()	__asm__ __volatile__("": : :"memory")

#ifndef cpu_relax
#define cpu_relax() __sync_synchronize()
#endif

#endif /* _BOILERPLATE_ATOMIC_H */
