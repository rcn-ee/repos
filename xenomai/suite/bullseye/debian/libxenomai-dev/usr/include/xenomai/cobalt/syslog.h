/*
 * Copyright (C) 2006 Gilles Chanteperdrix <gilles.chanteperdrix@xenomai.org>.
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
#include_next <syslog.h>

#ifndef _COBALT_SYSLOG_H
#define _COBALT_SYSLOG_H

#include <stdarg.h>
#include <xeno_config.h>
#include <cobalt/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

COBALT_DECL(void, syslog(int priority, const char *fmt, ...));

COBALT_DECL(void, vsyslog(int priority,
			  const char *fmt, va_list ap));

#ifdef CONFIG_XENO_FORTIFY

COBALT_DECL(void, __vsyslog_chk(int priority, int level,
				const char *fmt, va_list ap));

COBALT_DECL(void, __syslog_chk(int pri, int flag,
			       const char *fmt, ...));

#endif /* CONFIG_XENO_FORTIFY */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_COBALT_SYSLOG_H */
