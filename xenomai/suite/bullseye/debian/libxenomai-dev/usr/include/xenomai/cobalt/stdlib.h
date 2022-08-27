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
#include_next <stdlib.h>

#ifndef _COBALT_STDLIB_H
#define _COBALT_STDLIB_H

/* Re-read in case we came from selective __need* block. */
#include_next <stdlib.h>
#include <cobalt/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

COBALT_DECL(void, free(void *ptr));

COBALT_DECL(void *, malloc(size_t size));

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* !_COBALT_STDLIB_H */
