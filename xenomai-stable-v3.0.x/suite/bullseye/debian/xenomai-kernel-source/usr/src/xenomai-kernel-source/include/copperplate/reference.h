/*
 * Copyright (C) 2010 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COPPERPLATE_REFERENCE_H
#define _COPPERPLATE_REFERENCE_H

#include <boilerplate/limits.h>
#include <boilerplate/scope.h>
#include <boilerplate/setup.h>

#define libcopperplate_tag  0	/* Library tag - unique and constant. */
#define libcopperplate_cbi  1	/* Callback binary interface level. */

#ifdef CONFIG_XENO_PSHARED
/*
 * Layout of a function reference handle in shared memory (32-bit
 * value):
 *
 * xxHHHHHHHHHHHHHHHHHHHHLLLLLPPPPP
 *
 * where: 'P' => function index in the per-library array
 *        'L' => library tag
 *        'H' => symbol hash value (symname + cbi)
 *        'x' => unassigned
 *
 * NOTE: handle value -1 is kept for representing a NULL function
 * pointer; bit #31 should remain unassigned and cleared for this
 * purpose.
 */

struct __fnref {
	void (*fn)(void);
	unsigned int hash;
};

#define __refvar(l, s)		__ ## l ## __ref__ ## s
#define __refmangle(l, h, p)	(((h & 0xfffff) << 10)|((l & 0x1f) << 5)|(p & 0x1f))
#define __refhash(r)		(((r) >> 10) & 0xfffffU)
#define __reftag(r)		(((r) >> 5) & 0x1f)
#define __refpos(r)		((r) & 0x1f)
#define __refchk(v, r)							\
	({								\
		int __tag = __reftag(r), __pos = __refpos(r);		\
		typeof(v) __p = (typeof(v))__fnrefs[__tag][__pos].fn;	\
		assert(__fnrefs[__tag][__pos].hash == __refhash(r));	\
		assert(__p != NULL);					\
		__p;							\
	})
#define fnref_type(t)		int
#define fnref_null		-1
static inline int __fnref_nofn(void *fnaddr)
{
	return fnaddr == NULL;
}
#define fnref_put(l, s)		(__fnref_nofn((void *)(s)) ? fnref_null : __refvar(l, s))
#define fnref_get(v, r)		((v) = (r) < 0 ? NULL :	__refchk(v, r))
#define fnref_register(l, s)						\
	int __refvar(l, s);						\
	static void __early_ctor __ifnref_ ## s(void)			\
	{								\
		__refvar(l, s) = __fnref_register(#l, l ## _tag,	\
						  l ## _cbi,		\
						  #s, (void (*)(void))s); \
	}
#define fnref_declare(l, s)	extern int __refvar(l, s)

#define MAX_FNLIBS  16		/* max=32 */
#define MAX_FNREFS  16		/* max=32 */

extern struct __fnref __fnrefs[MAX_FNLIBS][MAX_FNREFS];

int __fnref_register(const char *libname,
		     int libtag, int cbirev,
		     const char *symname, void (*fn)(void));

#else /* !CONFIG_XENO_PSHARED */

#define fnref_type(t)		__typeof__(t)
#define fnref_null		NULL
#define fnref_put(l, s)		(s)
#define fnref_get(v, r)		((v) = (r))
#define fnref_register(l, s)
#define fnref_declare(l, s)

#endif /* !CONFIG_XENO_PSHARED */

#endif /* _COPPERPLATE_REFERENCE_H */
