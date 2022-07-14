/**
 * @file
 * @note Copyright (C) 2005, 2006 Jan Kiszka <jan.kiszka@web.de>
 * @note Copyright (C) 2005 Joerg Langenberg <joerg.langenberg@gmx.net>
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
#ifndef _RTDM_RTDM_H
#define _RTDM_RTDM_H

#include <linux/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <unistd.h>
#include <boilerplate/wrappers.h>

/**
 * @defgroup rtdm RTDM
 *
 * The Real-Time Driver Model (RTDM) provides a unified interface to
 * both users and developers of real-time device
 * drivers. Specifically, it addresses the constraints of mixed
 * RT/non-RT systems like Xenomai. RTDM conforms to POSIX
 * semantics (IEEE Std 1003.1) where available and applicable.
 *
 * @b API @b Revision: 8
 */

/**
 * @ingroup rtdm
 * @defgroup rtdm_user_api RTDM User API
 *
 * Application interface to RTDM services
 *
 * This is the upper interface of RTDM provided to application
 * programs both in kernel and user space. Note that certain functions
 * may not be implemented by every device. Refer to the @ref
 * rtdm_profiles "Device Profiles" for precise information.
 */

#include <rtdm/uapi/rtdm.h>

#endif /* !_RTDM_RTDM_H */
