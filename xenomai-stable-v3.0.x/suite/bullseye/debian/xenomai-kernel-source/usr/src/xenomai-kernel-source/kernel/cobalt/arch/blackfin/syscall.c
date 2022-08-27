/*
 * Copyright (C) 2005, 2012 Philippe Gerum <rpm@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Xenomai is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Xenomai; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#include <asm/xenomai/syscall.h>

int xnarch_local_syscall(unsigned long a1, unsigned long a2,
			 unsigned long a3, unsigned long a4,
			 unsigned long a5)
{
	unsigned long r;

	switch (a1) {
	case __xn_lsys_xchg:

		/* lsys_xchg(ptr,newval,&oldval) */
		r = xchg((unsigned long *)a2, a3);
		__xn_put_user(r, (unsigned long *)a4);
		break;

	default:
		return -ENOSYS;
	}

	return 0;
}
