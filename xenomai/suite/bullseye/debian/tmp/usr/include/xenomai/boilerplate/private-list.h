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

#ifndef _BOILERPLATE_PRIVATE_LIST_H
#define _BOILERPLATE_PRIVATE_LIST_H

#ifndef _BOILERPLATE_LIST_H
#error "Do not include this file directly. Use <boilerplate/list.h> instead."
#endif

struct pvholder {
	struct pvholder *next;
	struct pvholder *prev;
};

struct pvlistobj {
	struct pvholder head;
};

#define PRIVATE_LIST_INITIALIZER(__name) \
	{ .head = { .next = &((__name).head), .prev = &((__name).head) } }

#define DEFINE_PRIVATE_LIST(__name) \
	struct pvlistobj __name = PRIVATE_LIST_INITIALIZER(__name)

static inline void initpvh(struct pvholder *holder)
{
	holder->next = holder;
	holder->prev = holder;
}

static inline void atpvh(struct pvholder *head, struct pvholder *holder)
{
	/* Inserts the new element right after the heading one. */
	holder->prev = head;
	holder->next = head->next;
	holder->next->prev = holder;
	head->next = holder;
}

static inline void dtpvh(struct pvholder *holder)
{
	holder->prev->next = holder->next;
	holder->next->prev = holder->prev;
}

static inline void pvlist_init(struct pvlistobj *list)
{
	initpvh(&list->head);
}

static inline void pvholder_init(struct pvholder *holder)
{
	initpvh(holder);
}

/*
 * XXX: pvholder_init() is mandatory if you later want to use this
 * predicate.
 */
static inline int pvholder_linked(const struct pvholder *holder)
{
	return !(holder->prev == holder->next &&
		 holder->prev == holder);
}

static inline void pvlist_prepend(struct pvholder *holder, struct pvlistobj *list)
{
	atpvh(&list->head, holder);
}

static inline void pvlist_append(struct pvholder *holder, struct pvlistobj *list)
{
	atpvh(list->head.prev, holder);
}

static inline void pvlist_insert(struct pvholder *next, struct pvholder *prev)
{
	atpvh(prev, next);
}

static inline void pvlist_join(struct pvlistobj *lsrc, struct pvlistobj *ldst)
{
	struct pvholder *headsrc = lsrc->head.next;
	struct pvholder *tailsrc = lsrc->head.prev;
	struct pvholder *headdst = &ldst->head;

	headsrc->prev->next = tailsrc->next;
	tailsrc->next->prev = headsrc->prev;
	headsrc->prev = headdst;
	tailsrc->next = headdst->next;
	headdst->next->prev = tailsrc;
	headdst->next = headsrc;
}

static inline void pvlist_remove(struct pvholder *holder)
{
	dtpvh(holder);
}

static inline void pvlist_remove_init(struct pvholder *holder)
{
	dtpvh(holder);
	initpvh(holder);
}

static inline int pvlist_empty(const struct pvlistobj *list)
{
	return list->head.next == &list->head;
}

static inline struct pvholder *pvlist_pop(struct pvlistobj *list)
{
	struct pvholder *holder = list->head.next;
	pvlist_remove(holder);
	return holder;
}

static inline int pvlist_heading_p(const struct pvholder *holder,
				   const struct pvlistobj *list)
{
	return list->head.next == holder;
}

#define pvlist_entry(ptr, type, member)				\
	container_of(ptr, type, member)

#define pvlist_first_entry(list, type, member)			\
	pvlist_entry((list)->head.next, type, member)

#define pvlist_last_entry(list, type, member)			\
	pvlist_entry((list)->head.prev, type, member)

#define pvlist_prev_entry(pos, list, member)				\
	({								\
		typeof(*pos) *__prev = NULL;				\
		if ((list)->head.next != &(pos)->member)		\
			__prev = pvlist_entry((pos)->member.prev,	\
					      typeof(*pos), member);	\
		__prev;							\
	})

#define pvlist_next_entry(pos, list, member)				\
	({								\
		typeof(*pos) *__next = NULL;				\
		if ((list)->head.prev != &(pos)->member)		\
			__next = pvlist_entry((pos)->member.next,	\
					      typeof(*pos), member);	\
		__next;							\
	})

#define pvlist_pop_entry(list, type, member) ({				\
			struct pvholder *__holder = pvlist_pop(list);	\
			pvlist_entry(__holder, type, member); })

#define pvlist_for_each(pos, list)					\
	for (pos = (list)->head.next;					\
	     pos != &(list)->head; pos = (pos)->next)

#define pvlist_for_each_reverse(pos, list)				\
	for (pos = (list)->head.prev;					\
	     pos != &(list)->head; pos = (pos)->prev)

#define pvlist_for_each_safe(pos, tmp, list)				\
	for (pos = (list)->head.next,					\
		     tmp = (pos)->next;					\
	     pos != &(list)->head;					\
	     pos = tmp, tmp = (pos)->next)

#define pvlist_for_each_entry(pos, list, member)			\
	for (pos = pvlist_entry((list)->head.next,			\
			      typeof(*pos), member);			\
	     &(pos)->member != &(list)->head;				\
	     pos = pvlist_entry((pos)->member.next,			\
			      typeof(*pos), member))

#define pvlist_for_each_entry_safe(pos, tmp, list, member)		\
	for (pos = pvlist_entry((list)->head.next,			\
			      typeof(*pos), member),			\
		     tmp = pvlist_entry((pos)->member.next,		\
				      typeof(*pos), member);		\
	     &(pos)->member != &(list)->head;				\
	     pos = tmp, tmp = pvlist_entry((pos)->member.next,		\
					 typeof(*pos), member))

#define pvlist_for_each_entry_reverse(pos, list, member)		\
	for (pos = pvlist_entry((list)->head.prev,			\
			      typeof(*pos), member);			\
	     &pos->member != &(list)->head;				\
	     pos = pvlist_entry(pos->member.prev,			\
			      typeof(*pos), member))

#define pvlist_for_each_entry_reverse_safe(pos, tmp, list, member)	\
	for (pos = pvlist_entry((list)->head.prev,			\
			      typeof(*pos), member),			\
		     tmp = pvlist_entry((pos)->member.prev,		\
				      typeof(*pos), member);		\
	     &(pos)->member != &(list)->head;				\
	     pos = tmp, tmp = pvlist_entry((pos)->member.prev,		\
					 typeof(*pos), member))

#endif /* !_BOILERPLATE_PRIVATE_LIST_H */
