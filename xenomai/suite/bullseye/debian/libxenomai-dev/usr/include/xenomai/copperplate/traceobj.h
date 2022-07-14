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
 */

#ifndef _COPPERPLATE_TRACEOBJ_H
#define _COPPERPLATE_TRACEOBJ_H

#include <pthread.h>

struct threadobj;

struct traceobj {
	pthread_mutex_t lock;
	pthread_cond_t join;
	const char *label;
	int nr_marks;
	int cur_mark;
	struct tracemark *marks;
	int nr_threads;
};

#define traceobj_assert(trobj, cond)					\
do {									\
	int __ret = (cond);						\
	if (!__ret)							\
		__traceobj_assert_failed(trobj, __FILE__, __LINE__, __STRING(cond)); \
} while(0)

#define traceobj_check(__trobj, __status, __expected)			\
do {									\
	if (__status != __expected)					\
		__traceobj_check_abort(__trobj, __FILE__, __LINE__, 	\
				       __status, __expected);		\
} while(0)

#define traceobj_check_warn(__trobj, __status, __expected)		\
do {									\
	if (__status != __expected)					\
		__traceobj_check_warn(__trobj, __FILE__, __LINE__, 	\
				      __status, __expected);		\
} while(0)

#define traceobj_mark(trobj, mark)	\
	__traceobj_mark(trobj, __FILE__, __LINE__, mark)

#ifdef __cplusplus
extern "C" {
#endif

int traceobj_init(struct traceobj *trobj,
		  const char *label, int nr_marks);

void traceobj_verify(struct traceobj *trobj, int tseq[], int nr_seq);

void traceobj_destroy(struct traceobj *trobj);

void traceobj_enter(struct traceobj *trobj);

void traceobj_exit(struct traceobj *trobj);

void traceobj_unwind(struct traceobj *trobj);

void traceobj_join(struct traceobj *trobj);

void __traceobj_assert_failed(struct traceobj *trobj,
			      const char *file, int line, const char *cond);

void __traceobj_check_abort(struct traceobj *trobj,
			    const char *file, int line,
			    int received, int expected);

void __traceobj_check_warn(struct traceobj *trobj,
			   const char *file, int line,
			   int received, int expected);
	
void __traceobj_mark(struct traceobj *trobj,
		     const char *file, int line, int mark);

#ifdef __cplusplus
}
#endif

#endif /* _COPPERPLATE_TRACEOBJ_H */
