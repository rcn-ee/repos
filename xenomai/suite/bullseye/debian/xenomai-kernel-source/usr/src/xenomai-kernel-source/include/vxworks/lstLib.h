/*
 * Copyright (C) 2008 Philippe Gerum <rpm@xenomai.org>.
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
 * mimicking a VxWorks-like API built upon the copperplate library.
 *
 * VxWorks is a registered trademark of Wind River Systems, Inc.
 */

#ifndef _XENOMAI_VXWORKS_LSTLIB_H
#define _XENOMAI_VXWORKS_LSTLIB_H

#include <boilerplate/list.h>
#include <vxworks/types.h>

typedef struct LIST {
	struct pvlistobj list;
	int count;
} LIST;

typedef struct NODE {
	struct pvholder link;
	struct LIST *list;
} NODE;

static inline void lstInit(LIST *l)
{
	pvlist_init(&l->list);
	l->count = 0;
}

static inline void lstAdd(LIST *l, NODE *n)
{
	pvholder_init(&n->link);
	pvlist_append(&n->link, &l->list);
	n->list = l;
	l->count++;
}

static inline int lstCount(LIST *l)
{
	return l->count;
}

static inline void lstDelete(LIST *l, NODE *n)
{
	pvlist_remove(&n->link);
	n->list = NULL;
	l->count--;
}

static inline NODE *lstFirst(LIST *l)
{
	if (l == NULL || pvlist_empty(&l->list))
		return NULL;

	return pvlist_first_entry(&l->list, struct NODE, link);
}

static inline NODE *lstGet(LIST *l)
{
	struct NODE *n;

	if (l == NULL || pvlist_empty(&l->list))
		return NULL;

	n = pvlist_pop_entry(&l->list, struct NODE, link);
	n->list = NULL;
	l->count--;

	return n;
}

static inline void lstInsert(LIST *l, NODE *nprev, NODE *n)
{
	pvholder_init(&n->link);

	if (nprev == NULL)
		pvlist_prepend(&n->link, &l->list);
	else
		pvlist_insert(&n->link, &nprev->link);

	n->list = l;
	l->count++;
}

static inline NODE *lstLast(LIST *l)
{
	if (l == NULL || pvlist_empty(&l->list))
		return NULL;

	return pvlist_last_entry(&l->list, struct NODE, link);
}

static inline NODE *lstNext(NODE *n)
{
	if (n->list == NULL || &n->link == n->list->list.head.prev)
		return NULL;

	return container_of(n->link.next, struct NODE, link);
}

static inline NODE *lstPrevious(NODE *n)
{
	if (n->list == NULL || &n->link == n->list->list.head.next)
		return NULL;

	return container_of(n->link.prev, struct NODE, link);
}

static inline void lstFree(LIST *l)
{
	lstInit(l);
}

#ifdef __cplusplus
extern "C" {
#endif

void lstExtract(LIST *lsrc, NODE *nstart, NODE *nend, LIST *ldst);

NODE *lstNth(LIST *l, int nodenum);

NODE *lstNStep(NODE *n, int steps);

int lstFind(LIST *l, NODE *n);

void lstConcat(LIST *ldst, LIST *lsrc);

#ifdef __cplusplus
}
#endif

#endif /* !_XENOMAI_VXWORKS_LSTLIB_H */
