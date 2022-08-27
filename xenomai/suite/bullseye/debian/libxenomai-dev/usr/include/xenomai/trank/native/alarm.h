/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _XENOMAI_TRANK_NATIVE_ALARM_H
#define _XENOMAI_TRANK_NATIVE_ALARM_H

#include <trank/trank.h>
#include <alchemy/alarm.h>

#ifdef __cplusplus
extern "C" {
#endif

COMPAT_DECL(int, rt_alarm_create(RT_ALARM *alarm, const char *name));

COMPAT_DECL(int, rt_alarm_wait(RT_ALARM *alarm));

COMPAT_DECL(int, rt_alarm_delete(RT_ALARM *alarm));

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_NATIVE_ALARM_H */
