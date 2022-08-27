/*
 * Copyright (C) 2006 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
 * Copyright (C) 2007 Jan Kiszka <jan.kiszka@web.de>.
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
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#pragma GCC system_header
#include_next <stdio.h>

#ifndef _COBALT_STDIO_H
#define _COBALT_STDIO_H

#include <stddef.h>
#include <stdarg.h>
#include <xeno_config.h>
#include <cobalt/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

COBALT_DECL(int, vfprintf(FILE *stream, const char *fmt, va_list args));

#ifdef CONFIG_XENO_FORTIFY

COBALT_DECL(int, __vfprintf_chk(FILE *stream, int level,
				const char *fmt, va_list ap));

COBALT_DECL(int, __vprintf_chk(int flag,
			       const char *fmt, va_list ap));

COBALT_DECL(int, __printf_chk(int flag, const char *fmt, ...));

COBALT_DECL(int, __fprintf_chk(FILE *fp, int flag, const char *fmt, ...));

int __rt_vfprintf_chk(FILE *stream, int level,
		      const char *fmt, va_list args);

void __rt_vsyslog_chk(int priority, int level,
		      const char *fmt, va_list args);

#endif	/* CONFIG_XENO_FORTIFY */

COBALT_DECL(int, vprintf(const char *fmt, va_list args));

COBALT_DECL(int, fprintf(FILE *stream, const char *fmt, ...));

COBALT_DECL(int, printf(const char *fmt, ...));

COBALT_DECL(int, puts(const char *s));

COBALT_DECL(int, fputs(const char *s, FILE *stream));

#ifndef putchar
COBALT_DECL(int, putchar(int c));
#else
static inline int __real_putchar(int c)
{
	return putchar(c);
}
int __wrap_putchar(int c);
int __cobalt_putchar(int c);
#undef putchar
#define putchar putchar
#endif

#ifndef fputc
COBALT_DECL(int, fputc(int c, FILE *stream));
#else
static inline int __real_fputc(int c, FILE *stream)
{
	return fputc(c, stream);
}
int __wrap_fputc(int c, FILE *stream);
int __cobalt_fputc(int c, FILE *stream);
#undef fputc
#define fputc fputc
#endif

COBALT_DECL(size_t,
	    fwrite(const void *ptr, size_t sz, size_t nmemb, FILE *stream));

COBALT_DECL(int, fclose(FILE *stream));

int rt_vfprintf(FILE *stream, const char *format, va_list args);

int rt_vprintf(const char *format, va_list args);

int rt_fprintf(FILE *stream, const char *format, ...);

int rt_printf(const char *format, ...);

int rt_puts(const char *s);

int rt_fputs(const char *s, FILE *stream);

int rt_fputc(int c, FILE *stream);

int rt_putchar(int c);

size_t rt_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

void rt_syslog(int priority, const char *format, ...);

void rt_vsyslog(int priority, const char *format, va_list args);

int rt_print_init(size_t buffer_size, const char *name);

const char *rt_print_buffer_name(void);

void rt_print_flush_buffers(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_COBALT_STDIO_H */
