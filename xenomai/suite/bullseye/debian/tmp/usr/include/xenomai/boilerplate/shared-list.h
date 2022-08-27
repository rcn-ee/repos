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
#ifndef _BOILERPLATE_SHARED_LIST_H
#define _BOILERPLATE_SHARED_LIST_H

#ifndef _BOILERPLATE_LIST_H
#error "Do not include this file directly. Use <boilerplate/list.h> instead."
#endif

#define __hoff(h, a)  __memoff(h, a)
#define __hptr(h, v)  ((struct holder *)__memptr(h, v))
#define __hchk(h, a)  __memchk(h, a)

struct holder {
	dref_type(struct holder *) next;
	dref_type(struct holder *) prev;
};

struct listobj {
	struct holder head;
};

static inline void __inith_nocheck(void *heap, struct holder *holder)
{
	holder->next = __hoff(heap, holder);
	holder->prev = __hoff(heap, holder);
}

static inline void __inith(void *heap, struct holder *holder)
{
	assert(__hchk(heap, holder));
	__inith_nocheck(heap, holder);
}

static inline void inith(struct holder *holder)
{
	__inith(__main_heap, holder);
}

static inline void __ath(void *heap, struct holder *head,
			 struct holder *holder)
{
	/* Inserts the new element right after the heading one. */
	holder->prev = __hoff(heap, head);
	holder->next = head->next;
	__hptr(heap, holder->next)->prev = __hoff(heap, holder);
	head->next = __hoff(heap, holder);
}

static inline void ath(struct holder *head, struct holder *holder)
{
	__ath(__main_heap, head, holder);
}

static inline void __dth(void *heap, struct holder *holder)
{
	__hptr(heap, holder->prev)->next = holder->next;
	__hptr(heap, holder->next)->prev = holder->prev;
}

static inline void dth(struct holder *holder)
{
	__dth(__main_heap, holder);
}

static inline void __list_init(void *heap, struct listobj *list)
{
	__inith(heap, &list->head);
}

static inline void __list_init_nocheck(void *heap, struct listobj *list)
{
	__inith_nocheck(heap, &list->head);
}

static inline void list_init(struct listobj *list)
{
	__list_init(__main_heap, list);
}

static inline void __holder_init(void *heap, struct holder *holder)
{
	__inith(heap, holder);
}

static inline void __holder_init_nocheck(void *heap, struct holder *holder)
{
	__inith_nocheck(heap, holder);
}

static inline void holder_init(struct holder *holder)
{
	inith(holder);
}

static inline int __holder_linked(void *heap, const struct holder *holder)
{
	return !(holder->prev == holder->next &&
		 holder->prev == __hoff(heap, holder));
}

/*
 * XXX: holder_init() is mandatory if you later want to use this
 * predicate.
 */
static inline int holder_linked(const struct holder *holder)
{
	return __holder_linked(__main_heap, holder);
}

static inline void __list_prepend(void *heap, struct holder *holder,
				  struct listobj *list)
{
	__ath(heap, &list->head, holder);
}

static inline void list_prepend(struct holder *holder, struct listobj *list)
{
	__list_prepend(__main_heap, holder, list);
}

static inline void __list_append(void *heap, struct holder *holder,
				 struct listobj *list)
{
	__ath(heap, __hptr(heap, list->head.prev), holder);
}

static inline void list_append(struct holder *holder, struct listobj *list)
{
	__list_append(__main_heap, holder, list);
}

static inline void __list_insert(void *heap, struct holder *next, struct holder *prev)
{
	__ath(heap, prev, next);
}

static inline void list_insert(struct holder *next, struct holder *prev)
{
	__list_insert(__main_heap, next, prev);
}

static inline void __list_join(void *heap, struct listobj *lsrc,
			       struct listobj *ldst)
{
	struct holder *headsrc = __hptr(heap, lsrc->head.next);
	struct holder *tailsrc = __hptr(heap, lsrc->head.prev);
	struct holder *headdst = &ldst->head;

	__hptr(heap, headsrc->prev)->next = tailsrc->next;
	__hptr(heap, tailsrc->next)->prev = headsrc->prev;
	headsrc->prev = __hoff(heap, headdst);
	tailsrc->next = headdst->next;
	__hptr(heap, headdst->next)->prev = __hoff(heap, tailsrc);
	headdst->next = __hoff(heap, headsrc);
}

static inline void list_join(struct listobj *lsrc, struct listobj *ldst)
{
	__list_join(__main_heap, lsrc, ldst);
}

static inline void __list_remove(void *heap, struct holder *holder)
{
	__dth(heap, holder);
}

static inline void list_remove(struct holder *holder)
{
	__list_remove(__main_heap, holder);
}

static inline void __list_remove_init(void *heap, struct holder *holder)
{
	__dth(heap, holder);
	__inith(heap, holder);
}

static inline void list_remove_init(struct holder *holder)
{
	__list_remove_init(__main_heap, holder);
}

static inline int __list_empty(void *heap, const struct listobj *list)
{
	return list->head.next == __hoff(heap, &list->head);
}

static inline int list_empty(const struct listobj *list)
{
	return __list_empty(__main_heap, list);
}

static inline struct holder *__list_pop(void *heap, struct listobj *list)
{
	struct holder *holder = __hptr(heap, list->head.next);
	__list_remove(heap, holder);
	return holder;
}

static inline struct holder *list_pop(struct listobj *list)
{
	return __list_pop(__main_heap, list);
}

static inline int __list_heading_p(void *heap, const struct holder *holder,
				   const struct listobj *list)
{
	return list->head.next == __hoff(heap, holder);
}

static inline int list_heading_p(const struct holder *holder,
				 const struct listobj *list)
{
	return __list_heading_p(__main_heap, holder, list);
}

#define list_entry(ptr, type, member)				\
	container_of(ptr, type, member)

#define __list_first_entry(heap, list, type, member)		\
	list_entry(__hptr((heap), (list)->head.next), type, member)

#define list_first_entry(list, type, member)			\
	__list_first_entry(__main_heap, list, type, member)

#define __list_last_entry(heap, list, type, member)		\
	list_entry(__hptr((heap), (list)->head.prev), type, member)

#define list_last_entry(list, type, member)			\
	__list_last_entry(__main_heap, list, type, member)

#define __list_prev_entry(heap, pos, list, member)			\
	({								\
		typeof(*pos) *__prev = NULL;				\
		if ((list)->head.next != __hoff(heap, &(pos)->member))	\
			__prev = list_entry(__hptr((heap),		\
			   (pos)->member.prev), typeof(*pos), member);	\
		__prev;							\
	})

#define list_prev_entry(pos, list, member)				\
	__list_prev_entry(__main_heap, pos, list, member)

#define __list_next_entry(heap, pos, list, member)			\
	({								\
		typeof(*pos) *__next = NULL;				\
		if ((list)->head.prev != __hoff(heap, &(pos)->member))	\
			__next = list_entry(__hptr((heap),		\
			   (pos)->member.next), typeof(*pos), member);	\
		__next;							\
	})

#define list_next_entry(pos, list, member)				\
	__list_next_entry(__main_heap, pos, list, member)

#define __list_pop_entry(heap, list, type, member) ({			\
			struct holder *__holder = __list_pop((heap), list); \
			list_entry(__holder, type, member); })

#define list_pop_entry(list, type, member)				\
	__list_pop_entry(__main_heap, list, type, member)

#define __list_for_each(heap, pos, list)				\
	for (pos = __hptr((heap), (list)->head.next);			\
	     pos != &(list)->head; pos = __hptr((heap), (pos)->next))

#define list_for_each(pos, list)					\
	__list_for_each(__main_heap, pos, list)

#define __list_for_each_reverse(heap, pos, list)			\
	for (pos = __hptr((heap), (list)->head.prev);			\
	     pos != &(list)->head; pos = __hptr((heap), (pos)->prev))

#define list_for_each_reverse(pos, list)				\
	__list_for_each_reverse(__main_heap, pos, list)

#define __list_for_each_safe(heap, pos, tmp, list)			\
	for (pos = __hptr((heap), (list)->head.next),			\
		     tmp = __hptr((heap), (pos)->next);			\
	     pos != &(list)->head;					\
	     pos = tmp, tmp = __hptr((heap), (pos)->next))

#define list_for_each_safe(pos, tmp, list)				\
	__list_for_each_safe(__main_heap, pos, tmp, list)

#define __list_for_each_entry(heap, pos, list, member)			\
	for (pos = list_entry(__hptr((heap), (list)->head.next),	\
			      typeof(*pos), member);			\
	     &(pos)->member != &(list)->head;				\
	     pos = list_entry(__hptr((heap), (pos)->member.next),	\
			      typeof(*pos), member))

#define list_for_each_entry(pos, list, member)				\
	__list_for_each_entry(__main_heap, pos, list, member)

#define __list_for_each_entry_safe(heap, pos, tmp, list, member)	\
	for (pos = list_entry(__hptr((heap), (list)->head.next),	\
			      typeof(*pos), member),			\
		     tmp = list_entry(__hptr((heap), (pos)->member.next), \
				      typeof(*pos), member);		\
	     &(pos)->member != &(list)->head;				\
	     pos = tmp, tmp = list_entry(__hptr((heap), (pos)->member.next), \
					 typeof(*pos), member))

#define __list_for_each_entry_reverse_safe(heap, pos, tmp, list, member) \
	for (pos = list_entry(__hptr((heap), (list)->head.prev),	\
			      typeof(*pos), member),			\
		     tmp = list_entry(__hptr((heap), (pos)->member.prev), \
				      typeof(*pos), member);		\
	     &(pos)->member != &(list)->head;				\
	     pos = tmp, tmp = list_entry(__hptr((heap), (pos)->member.prev), \
					 typeof(*pos), member))

#define list_for_each_entry_safe(pos, tmp, list, member)		\
	__list_for_each_entry_safe(__main_heap, pos, tmp, list, member)

#define __list_for_each_entry_reverse(heap, pos, list, member)		\
	for (pos = list_entry(__hptr((heap), (list)->head.prev),	\
			      typeof(*pos), member);			\
	     &pos->member != &(list)->head;				\
	     pos = list_entry(__hptr((heap), pos->member.prev),		\
			      typeof(*pos), member))

#define list_for_each_entry_reverse(pos, list, member)			\
	__list_for_each_entry_reverse(__main_heap, pos, list, member)

#define list_for_each_entry_reverse_safe(pos, tmp, list, member)	\
	__list_for_each_entry_reverse_safe(__main_heap, pos, tmp, list, member)

#endif /* !_BOILERPLATE_SHARED_LIST_H */
