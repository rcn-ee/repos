/*
 * Copyright (C) 2006 Jan Kiszka <jan.kiszka@web.de>.
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
#ifndef _COBALT_TRACE_H
#define _COBALT_TRACE_H

#ifdef __cplusplus
extern "C" {
#endif

int xntrace_max_begin(unsigned long v);

int xntrace_max_end(unsigned long v);

int xntrace_max_reset(void);

int xntrace_user_start(void);

int xntrace_user_stop(unsigned long v);

int xntrace_user_freeze(unsigned long v, int once);

int xntrace_special(unsigned char id, unsigned long v);

int xntrace_special_u64(unsigned char id, unsigned long long v);

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_TRACE_H */
