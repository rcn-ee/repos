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
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#pragma GCC system_header
#include_next <sys/mman.h>

#ifndef _COBALT_SYS_MMAN_H
#define _COBALT_SYS_MMAN_H

#include <sys/types.h>
#include <cobalt/wrappers.h>

#ifdef __cplusplus
extern "C" {
#endif

COBALT_DECL(void *, mmap(void *addr, size_t length, int prot, int flags,
			 int fd, off_t offset));

COBALT_DECL(void *, mmap64(void *addr, size_t length, int prot, int flags,
			   int fd, off64_t offset));

#ifdef __cplusplus
}
#endif

#endif /* !_COBALT_SYS_MMAN_H */
