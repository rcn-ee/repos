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
#ifndef _BOILERPLATE_LIST_H
#define _BOILERPLATE_LIST_H

#include <assert.h>
#include <boilerplate/scope.h>
#include <boilerplate/compiler.h>
#include <boilerplate/shared-list.h>
#include <boilerplate/private-list.h>

/*
 * WARNING: ALL list services are assumed to be free from any POSIX
 * cancellation points by callers, allowing the *_nocancel() locking
 * forms to be used (see boilerplate/lock.h).
 *
 * Please think of this when adding any debug instrumentation invoking
 * printf() and the like.
 */

#endif /* !_BOILERPLATE_LIST_H */
