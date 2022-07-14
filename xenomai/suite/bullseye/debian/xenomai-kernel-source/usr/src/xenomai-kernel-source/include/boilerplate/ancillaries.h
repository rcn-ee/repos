/*
 * Copyright (C) 2013 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _BOILERPLATE_ANCILLARIES_H
#define _BOILERPLATE_ANCILLARIES_H

#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <sched.h>
#include <string.h>

struct error_frame;

#define ONE_BILLION  1000000000

void __namecpy_requires_character_array_as_destination(void);

#define namecpy(__dst, __src)						\
	({								\
		if (!__builtin_types_compatible_p(typeof(__dst), char[])) \
			__namecpy_requires_character_array_as_destination();	\
		strncpy((__dst), __src, sizeof(__dst));			\
		__dst[sizeof(__dst) - 1] = '\0';			\
		__dst;							\
	 })

#define early_panic(__fmt, __args...)		\
	__early_panic(__func__, __fmt, ##__args)

#define panic(__fmt, __args...)			\
	__panic(__func__, __fmt, ##__args)

#ifdef __cplusplus
extern "C" {
#endif

void __printout(const char *name,
		const char *header,
		const char *fmt, va_list ap);

void __noreturn __early_panic(const char *fn,
			      const char *fmt, ...);

void __noreturn ___panic(const char *fn,
			 const char *name,
			 const char *fmt, va_list ap);

void __noreturn __panic(const char *fn,
			const char *fmt, ...);

void __warning(const char *name,
	       const char *fmt, va_list ap);

void early_warning(const char *fmt, ...);

void warning(const char *fmt, ...);

void __notice(const char *name,
	      const char *fmt, va_list ap);

void early_notice(const char *fmt, ...);

void notice(const char *fmt, ...);

void __boilerplate_init(void);

const char *symerror(int errnum);

void error_hook(struct error_frame *ef);

int get_static_cpu_count(void);

int get_online_cpu_set(cpu_set_t *cpuset);
  
int get_realtime_cpu_set(cpu_set_t *cpuset);

int get_current_cpu(void);
	
pid_t get_thread_pid(void);

char *lookup_command(const char *cmd);

size_t get_mem_size(const char *arg);

extern const char *config_strings[];

extern pthread_mutex_t __printlock;

#ifdef __cplusplus
}
#endif

#endif /* _BOILERPLATE_ANCILLARIES_H */
