/**
 * @file
 * @note Copyright (C) 2006 Wolfgang Grandegger <wg@grandegger.com>
 *
 * @note Copyright (C) 2005, 2006 Sebastian Smolorz
 *                         <Sebastian.Smolorz@stud.uni-hannover.de>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#ifndef _RTDM_CAN_H
#define _RTDM_CAN_H

#include <net/if.h>
#include <rtdm/rtdm.h>
#include <rtdm/uapi/can.h>

/**
 * @ingroup rtdm_profiles
 * @defgroup rtdm_can CAN Devices
 *
 * This is the common interface a RTDM-compliant CAN device has to provide.
 * Feel free to report bugs and comments on this profile to the "Socketcan"
 * mailing list (Socketcan-core@lists.berlios.de) or directly to the authors
 * (wg@grandegger.com or Sebastian.Smolorz@stud.uni-hannover.de).
 *
 * @b Profile @b Revision: 2
 * @n
 * @n
 * @par Device Characteristics
 * @n
 * @ref rtdm_driver_flags "Device Flags": @c RTDM_PROTOCOL_DEVICE @n
 * @n
 * @ref rtdm_driver.protocol_family "Protocol Family": @c PF_CAN @n
 * @n
 * @ref rtdm_driver.socket_type "Socket Type": @c SOCK_RAW @n
 * @n
 * @ref rtdm_driver_profile "Device Class": @c RTDM_CLASS_CAN @n
 * @n
 *
 * @par Supported Operations
 * @n
 * @b Socket @n
 * @coretags{secondary-only}
 * @n
 * Specific return values:
 * - -EPROTONOSUPPORT (Protocol is not supported by the driver.
 *                     See @ref CAN_PROTO "CAN protocols"
 *                     for possible protocols.)
 * .
 * @n
 * @n
 * @b Close @n
 * Blocking calls to any of the @ref Send or @ref Recv "Receive" functions
 * will be unblocked when the socket is closed and return with an error. @n
 * @n
 * @coretags{secondary-only}
 * @n
 * Specific return values: none @n
 * @n
 * @n
 * @b IOCTL @n
 * @coretags{task-unrestricted}. see @ref CANIOCTLs "below"
 * Specific return values: see @ref CANIOCTLs "below" @n
 * @n
 * @n
 * @anchor Bind
 * @b Bind @n
 * Binds a socket to one or all CAN devices (see struct sockaddr_can). If
 * a filter list has been defined with setsockopt (see @ref Sockopts),
 * it will be used upon reception of CAN frames to decide whether the
 * bound socket will receive a frame. If no filter has been defined, the
 * socket will receive @b all CAN frames on the specified interface(s). @n
 * @n
 * Binding to special interface index @c 0 will make the socket receive
 * CAN frames from all CAN interfaces. @n
 * @n
 * Binding to an interface index is also relevant for the @ref Send functions
 * because they will transmit a message over the interface the socket is
 * bound to when no socket address is given to them. @n
 * @n
 * @n
 * @coretags{secondary-only}
 * @n
 * Specific return values:
 * - -EFAULT (It was not possible to access user space memory area at the
 *            specified address.)
 * - -ENOMEM (Not enough memory to fulfill the operation)
 * - -EINVAL (Invalid address family, or invalid length of address structure)
 * - -ENODEV (Invalid CAN interface index)
 * - -ENOSPC (No enough space for filter list)
 * - -EBADF  (Socket is about to be closed)
 * - -EAGAIN (Too many receivers. Old binding (if any) is still active.
 *            Close some sockets and try again.)
 * .
 * @n
 * @n
 * @anchor Sockopts
 * <b>Setsockopt, Getsockopt</b>@n
 * These functions allow to set and get various socket options. Currently,
 * only CAN raw sockets are supported. @n
 * @n
 * Supported Levels and Options:
 * @n
 * - Level @b SOL_CAN_RAW : CAN RAW protocol (see @ref CAN_RAW)
 *   - Option @ref CAN_RAW_FILTER : CAN filter list
 *   - Option @ref CAN_RAW_ERR_FILTER : CAN error mask
 *   - Option @ref CAN_RAW_LOOPBACK : CAN TX loopback to local sockets
 *   .
 * .
 * @n
 * @coretags{task-unrestricted}
 * Specific return values: see links to options above. @n
 * @n
 * @n
 * @anchor Recv
 * <b>Recv, Recvfrom, Recvmsg</b> @n
 * These functions receive CAN messages from a socket. Only one
 * message per call can be received, so only one buffer with the correct length
 * must be passed. For @c SOCK_RAW, this is the size of struct can_frame. @n
 * @n
 * Unlike a call to one of the @ref Send functions, a Recv function will not
 * return with an error if an interface is down (due to bus-off or setting
 * of stop mode) or in sleep mode. Moreover, in such a case there may still
 * be some CAN messages in the socket buffer which could be read out
 * successfully. @n
 * @n
 * It is possible to receive a high precision timestamp with every CAN
 * message. The condition is a former instruction to the socket via
 * @ref RTCAN_RTIOC_TAKE_TIMESTAMP. The timestamp will be copied to the
 * @c msg_control buffer of <TT>struct msghdr</TT> if it points to a valid
 * memory location with size of @ref nanosecs_abs_t. If this
 * is a NULL pointer the timestamp will be discarded silently. @n
 * @n
 * @b Note: A @c msg_controllen of @c 0 upon completion of the function call
 *          indicates that no timestamp is available for that message.
 * @n
 * @n
 * Supported Flags [in]:
 * - MSG_DONTWAIT (By setting this flag the operation will only succeed if
 *                 it would not block, i.e. if there is a message in the
 *                 socket buffer. This flag takes precedence over a timeout
 *                 specified by @ref RTCAN_RTIOC_RCV_TIMEOUT.)
 * - MSG_PEEK     (Receive a message but leave it in the socket buffer. The
 *                 next receive operation will get that message again.)
 * .
 * @n
 * Supported Flags [out]: none @n
 * @n
 * @coretags{mode-unrestricted}
 * @n
 * Specific return values:
 * - Non-negative value (Indicating the successful reception of a CAN message.
 *   For @c SOCK_RAW, this is the size of struct can_frame regardless of
 *   the actual size of the payload.)
 * - -EFAULT (It was not possible to access user space memory area at one
 *            of the specified addresses.)
 * - -EINVAL (Unsupported flag detected, or invalid length of socket address
 *            buffer, or invalid length of message control buffer)
 * - -EMSGSIZE (Zero or more than one iovec buffer passed, or buffer too
 *              small)
 * - -EAGAIN (No data available in non-blocking mode)
 * - -EBADF (Socket was closed.)
 * - -EINTR (Operation was interrupted explicitly or by signal.)
 * - -ETIMEDOUT (Timeout)
 * .
 * @n
 * @n
 * @anchor Send
 * <b>Send, Sendto, Sendmsg</b> @n
 * These functions send out CAN messages. Only one message per call can
 * be transmitted, so only one buffer with the correct length must be passed.
 * For @c SOCK_RAW, this is the size of struct can_frame. @n
 * @n
 * The following only applies to @c SOCK_RAW: If a socket address of
 * struct sockaddr_can is given, only @c can_ifindex is used. It is also
 * possible to omit the socket address. Then the interface the socket is
 * bound to will be used for sending messages. @n
 * @n
 * If an interface goes down (due to bus-off or setting of stop mode) all
 * senders that were blocked on this interface will be woken up. @n
 * @n
 * @n
 * Supported Flags:
 * - MSG_DONTWAIT (By setting this flag the transmit operation will only
 *                 succeed if it would not block. This flag takes precedence
 *                 over a timeout specified by @ref RTCAN_RTIOC_SND_TIMEOUT.)
 * .
 * @coretags{mode-unrestricted}
 * @n
 * Specific return values:
 * - Non-negative value equal to given buffer size (Indicating the
 *   successful completion of the function call. See also note.)
 * - -EOPNOTSUPP (MSG_OOB flag is not supported.)
 * - -EINVAL (Unsupported flag detected @e or: Invalid length of socket
 *            address @e or: Invalid address family @e or: Data length code
 *            of CAN frame not between 0 and 15 @e or: CAN standard frame has
 *            got an ID not between 0 and 2031)
 * - -EMSGSIZE (Zero or more than one buffer passed or invalid size of buffer)
 * - -EFAULT (It was not possible to access user space memory area at one
 *            of the specified addresses.)
 * - -ENXIO (Invalid CAN interface index - @c 0 is not allowed here - or
 *           socket not bound or rather bound to all interfaces.)
 * - -ENETDOWN (Controller is bus-off or in stopped state.)
 * - -ECOMM (Controller is sleeping)
 * - -EAGAIN (Cannot transmit without blocking but a non-blocking
 *            call was requested.)
 * - -EINTR (Operation was interrupted explicitly or by signal)
 * - -EBADF (Socket was closed.)
 * - -ETIMEDOUT (Timeout)
 * .
 * @b Note: A successful completion of the function call does not implicate a
 *          successful transmission of the message.
 *
 * @{
 *
 * @anchor CANutils @name CAN example and utility programs
 * @{
 * @example rtcanconfig.c
 * @example rtcansend.c
 * @example rtcanrecv.c
 * @example can-rtt.c
 * @}
 *
 * @}
 */
#endif /* !_RTDM_CAN_H */
