/**
 *   Generic arithmetic/conversion routines.
 *   Copyright &copy; 2005 Stelian Pop.
 *   Copyright &copy; 2005 Gilles Chanteperdrix.
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
#ifndef _COBALT_ARITH_H
#define _COBALT_ARITH_H

#include <stddef.h>
#include <endian.h>

#if __BYTE_ORDER == __BIG_ENDIAN
#define endianstruct { unsigned int _h; unsigned int _l; }
#else /* __BYTE_ORDER == __LITTLE_ENDIAN */
#define endianstruct { unsigned int _l; unsigned int _h; }
#endif /* __BYTE_ORDER == __LITTLE_ENDIAN */

static inline unsigned xnarch_do_div(unsigned long long *a, unsigned d)
{
	unsigned int r = *a % d;
	*a /= d;

	return r;
}

#define do_div(a, d) xnarch_do_div(&(a), (d))

#include <asm/xenomai/features.h>
#include <asm/xenomai/uapi/arith.h>

#endif /* !_COBALT_ARITH_H */
