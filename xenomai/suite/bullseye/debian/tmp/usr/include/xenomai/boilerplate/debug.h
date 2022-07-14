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
#ifndef _BOILERPLATE_DEBUG_H
#define _BOILERPLATE_DEBUG_H

#include <stdint.h>
#include <stddef.h>
#include <xeno_config.h>

#ifdef CONFIG_XENO_DEBUG

#include <pthread.h>
#include <boilerplate/compiler.h>

static inline int must_check(void)
{
	return 1;
}

struct error_frame {
	int retval;
	int lineno;
	const char *fn;
	const char *file;
	struct error_frame *next;
};

struct backtrace_data {
	const char *name;
	struct error_frame *inner;
	pthread_mutex_t lock;
	char eundef[16];
};

#ifdef __cplusplus
extern "C" {
#endif

void backtrace_init_context(struct backtrace_data *btd,
			    const char *name);

void backtrace_destroy_context(struct backtrace_data *btd);

void backtrace_dump(struct backtrace_data *btd);

void backtrace_log(int retval, const char *fn,
		   const char *file, int lineno);

void backtrace_check(void);

void __debug(const char *name, const char *fmt, ...);

char *__get_error_buf(size_t *sizep);

void debug_init(void);

#ifdef __cplusplus
}
#endif

#define __bt(__exp)						\
	({							\
		typeof(__exp) __ret = (__exp);			\
		if (unlikely(__ret < 0))			\
			backtrace_log((int)__ret, __FUNCTION__,	\
				      __FILE__, __LINE__);	\
		__ret;						\
	})

#define __bterrno(__exp)					\
	({							\
		typeof(__exp) __ret = (__exp);			\
		if (unlikely(__ret < 0))			\
			backtrace_log(-errno, __FUNCTION__,	\
				      __FILE__, __LINE__);	\
		__ret;						\
	})

#else /* !CONFIG_XENO_DEBUG */

static inline int must_check(void)
{
	return 0;
}

struct backtrace_data {
};

#define __bt(__exp)			(__exp)

#define __bterrno(__exp)		(__exp)

#define backtrace_init_context(btd, name)	\
	do { (void)(btd); (void)(name); } while (0)

#define backtrace_destroy_context(btd)	\
	do { (void)(btd); } while (0)

#define backtrace_dump(btd)		\
	do { (void)(btd); } while (0)

#define backtrace_check()		\
	do { } while (0)
/*
 * XXX: We have no thread-private backtrace context in non-debug mode,
 * so there is a potential race if multiple threads want to write to
 * this buffer. This looks acceptable though, since this is primarily
 * a debug feature, and the race won't damage the system anyway.
 */
#define __get_error_buf(sizep)			\
	({					\
		static char __buf[16];		\
		*(sizep) = sizeof(__buf);	\
		__buf;				\
	})

#define debug_init()	do { } while (0)

#endif /* !CONFIG_XENO_DEBUG */

static inline int bad_pointer(const void *ptr)
{
	return ptr == NULL || ((intptr_t)ptr & (sizeof(intptr_t)-1)) != 0;
}

#endif /* _BOILERPLATE_DEBUG_H */
