/**
 * @file
 * Real-Time Driver Model for Xenomai, serial device profile header
 *
 * @note Copyright (C) 2005-2007 Jan Kiszka <jan.kiszka@web.de>
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
#ifndef _RTDM_SERIAL_H
#define _RTDM_SERIAL_H

#include <rtdm/rtdm.h>
#include <rtdm/uapi/serial.h>

/**
 * @ingroup rtdm_profiles
 * @defgroup rtdm_serial Serial Devices
 *
 * This is the common interface a RTDM-compliant serial device has to
 * provide.  Feel free to comment on this profile via the Xenomai
 * mailing list <xenomai@xenomai.org> or directly to the author
 * <jan.kiszka@web.de>.
 *
 * @b Profile @b Revision: 3
 * @n
 * @n
 * @par Device Characteristics
 * @ref rtdm_driver_flags "Device Flags": @c RTDM_NAMED_DEVICE, @c RTDM_EXCLUSIVE @n
 * @n
 * @ref rtdm_driver_profile "Device Class": @c RTDM_CLASS_SERIAL @n
 * @n
 * Device Name: @c "/dev/rtdm/rtser<N>", N >= 0 @n
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
 * @coretags{task-unrestricted}. See @ref SERIOCTLs "below" @n
 * Specific return values: see @ref SERIOCTLs "below" @n
 * @n
 * @b Read @n
 * @coretags{mode-unrestricted}
 * Specific return values:
 * - -ETIMEDOUT
 * - -EINTR (interrupted explicitly or by signal)
 * - -EAGAIN (no data available in non-blocking mode)
 * - -EBADF (device has been closed while reading)
 * - -EIO (hardware error or broken bit stream)
 * .
 * @n
 * @b Write @n
 * @coretags{mode-unrestricted}
 * Specific return values:
 * - -ETIMEDOUT
 * - -EINTR (interrupted explicitly or by signal)
 * - -EAGAIN (no data written in non-blocking mode)
 * - -EBADF (device has been closed while writing)
 */

#endif /* !_RTDM_SERIAL_H */
