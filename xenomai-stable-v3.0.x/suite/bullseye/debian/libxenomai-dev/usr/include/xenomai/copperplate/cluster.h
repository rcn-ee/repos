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

#ifndef _COPPERPLATE_CLUSTER_H
#define _COPPERPLATE_CLUSTER_H

#include <boilerplate/hash.h>
#include <copperplate/syncobj.h>

#ifdef CONFIG_XENO_PSHARED

struct clusterobj {
	pid_t cnode;
	struct hashobj hobj;
};

struct dictionary {
	struct hash_table table;
	struct hashobj hobj;
};

struct cluster {
	struct dictionary *d;
};

struct syndictionary {
	struct hash_table table;
	struct syncobj sobj;
	struct hashobj hobj;
};

struct syncluster {
	struct syndictionary *d;
};

struct pvclusterobj {
	struct pvhashobj hobj;
};

struct pvcluster {
	struct pvhash_table table;
};

struct pvsyncluster {
	struct pvcluster c;
	struct syncobj sobj;
};

static inline
const void *clusterobj_key(const struct clusterobj *cobj)
{
	return __memptr(__main_heap, cobj->hobj.key);
}

static inline
size_t clusterobj_keylen(const struct clusterobj *cobj)
{
	return cobj->hobj.len;
}

static inline
pid_t clusterobj_cnode(const struct clusterobj *cobj)
{
	return cobj->cnode;
}

static inline
const void *pvclusterobj_key(const struct pvclusterobj *cobj)
{
	return cobj->hobj.key;
}

static inline
size_t pvclusterobj_keylen(const struct pvclusterobj *cobj)
{
	return cobj->hobj.len;
}

static inline
pid_t pvclusterobj_cnode(const struct pvclusterobj *cobj)
{
	return -1;
}

#else /* !CONFIG_XENO_PSHARED */

struct clusterobj {
	struct pvhashobj hobj;
};

struct cluster {
	struct pvhash_table table;
};

struct syncluster {
	struct cluster c;
	struct syncobj sobj;
};

#define pvclusterobj  clusterobj
#define pvcluster     cluster
#define pvsyncluster  syncluster

static inline
const void *clusterobj_key(const struct pvclusterobj *cobj)
{
	return cobj->hobj.key;
}

static inline
size_t clusterobj_keylen(const struct pvclusterobj *cobj)
{
	return cobj->hobj.len;
}

static inline
pid_t clusterobj_cnode(const struct pvclusterobj *cobj)
{
	return -1;
}

static inline
const void *pvclusterobj_key(const struct pvclusterobj *cobj)
{
	return clusterobj_key(cobj);
}

static inline
size_t pvclusterobj_keylen(const struct pvclusterobj *cobj)
{
	return clusterobj_keylen(cobj);
}

static inline
pid_t pvclusterobj_cnode(const struct pvclusterobj *cobj)
{
	return clusterobj_cnode(cobj);
}

#endif /* !CONFIG_XENO_PSHARED */

struct syncluster_wait_struct {
	union {
		dref_type(char *) name_ref;
		const char *name;
	};
};

#ifdef __cplusplus
extern "C" {
#endif

int pvcluster_init(struct pvcluster *c, const char *name);

void pvcluster_destroy(struct pvcluster *c);

int pvcluster_addobj(struct pvcluster *c, const char *name,
		     struct pvclusterobj *cobj);

int pvcluster_addobj_dup(struct pvcluster *c, const char *name,
			 struct pvclusterobj *cobj);

int pvcluster_delobj(struct pvcluster *c,
		     struct pvclusterobj *cobj);

struct pvclusterobj *pvcluster_findobj(struct pvcluster *c,
				       const char *name);

int pvcluster_walk(struct pvcluster *c,
		   int (*walk)(struct pvcluster *c,
			       struct pvclusterobj *cobj));
  
int pvsyncluster_init(struct pvsyncluster *sc, const char *name);

void pvsyncluster_destroy(struct pvsyncluster *sc);

int pvsyncluster_addobj(struct pvsyncluster *sc, const char *name,
			struct pvclusterobj *cobj);

int pvsyncluster_delobj(struct pvsyncluster *sc,
			struct pvclusterobj *cobj);

int pvsyncluster_findobj(struct pvsyncluster *sc,
			 const char *name,
			 const struct timespec *timeout,
			 struct pvclusterobj **cobjp) __must_check;

#ifdef CONFIG_XENO_PSHARED

int cluster_init(struct cluster *c, const char *name);

int cluster_addobj(struct cluster *c, const char *name,
		   struct clusterobj *cobj);

int cluster_addobj_dup(struct cluster *c, const char *name,
		       struct clusterobj *cobj);

int cluster_delobj(struct cluster *c,
		   struct clusterobj *cobj);

struct clusterobj *cluster_findobj(struct cluster *c,
				   const char *name);

int cluster_walk(struct cluster *c,
		 int (*walk)(struct cluster *c,
			     struct clusterobj *cobj));

int syncluster_init(struct syncluster *sc, const char *name);

int syncluster_addobj(struct syncluster *sc, const char *name,
		      struct clusterobj *cobj);

int syncluster_delobj(struct syncluster *sc,
		      struct clusterobj *cobj);

int syncluster_findobj(struct syncluster *sc,
		       const char *name,
		       const struct timespec *timeout,
		       struct clusterobj **cobjp) __must_check;

#else /* !CONFIG_XENO_PSHARED */

static inline int cluster_init(struct cluster *c, const char *name)
{
	return pvcluster_init(c, name);
}

static inline int cluster_addobj(struct cluster *c, const char *name,
				 struct clusterobj *cobj)
{
	return pvcluster_addobj(c, name, cobj);
}

static inline int cluster_addobj_dup(struct cluster *c, const char *name,
				     struct clusterobj *cobj)
{
	return pvcluster_addobj_dup(c, name, cobj);
}

static inline int cluster_delobj(struct cluster *c,
				 struct clusterobj *cobj)
{
	return pvcluster_delobj(c, cobj);
}

static inline struct clusterobj *cluster_findobj(struct cluster *c,
						 const char *name)
{
	return pvcluster_findobj(c, name);
}

static inline int cluster_walk(struct cluster *c,
			       int (*walk)(struct cluster *c,
					   struct clusterobj *cobj))
{
	return pvcluster_walk(c, walk);
}

static inline int syncluster_init(struct syncluster *sc,
				  const char *name)
{
	return pvsyncluster_init(sc, name);
}

static inline int syncluster_addobj(struct syncluster *sc,
				    const char *name,
				    struct clusterobj *cobj)
{
	return pvsyncluster_addobj(sc, name, cobj);
}

static inline int syncluster_delobj(struct syncluster *sc,
				    struct clusterobj *cobj)
{
	return pvsyncluster_delobj(sc, cobj);
}

static inline  __must_check
int syncluster_findobj(struct syncluster *sc,
		       const char *name,
		       const struct timespec *timeout,
		       struct clusterobj **cobjp)
{
	return pvsyncluster_findobj(sc, name, timeout, cobjp);
}

#endif /* !CONFIG_XENO_PSHARED */

#ifdef __cplusplus
}
#endif

#endif /* _COPPERPLATE_CLUSTER_H */
