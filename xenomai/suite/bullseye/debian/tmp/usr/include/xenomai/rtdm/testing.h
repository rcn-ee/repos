/**
 * @file
 * Real-Time Driver Model for Xenomai, testing device profile header
 *
 * @note Copyright (C) 2005 Jan Kiszka <jan.kiszka@web.de>
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
 * along with Xenomai; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#ifndef _RTDM_TESTING_H
#define _RTDM_TESTING_H

#include <rtdm/rtdm.h>
#include <rtdm/uapi/testing.h>

/**
 * @ingroup rtdm_profiles
 * @defgroup rtdm_testing Testing Devices
 *
 * This group of devices is intended to provide in-kernel testing
 * results.  Feel free to comment on this profile via the Xenomai
 * mailing list <xenomai@xenomai.org> or directly to the author
 * <jan.kiszka@web.de>.
 *
 * @b Profile @b Revision: 2
 * @n
 * @n
 * @par Device Characteristics
 * @ref rtdm_driver_flags "Device Flags": @c RTDM_NAMED_DEVICE @n
 * @n
 * @ref rtdm_driver_profile "Device Class": @c RTDM_CLASS_TESTING @n
 * @n
 *
 * @par Supported Operations
 * @b Open @n
 * @coretags{secondary-only}
 * Specific return values: none @n
 * @n
 * @b Close @n
 * @coretags{secondary-only}
 * Specific return values: none @n
 * @n
 * @b IOCTL @n
 * @coretags{task-unrestricted}. See @ref TSTIOCTLs below @n
 * Specific return values: see @ref TSTIOCTLs below @n
 */

#endif /* _RTDM_TESTING_H */
