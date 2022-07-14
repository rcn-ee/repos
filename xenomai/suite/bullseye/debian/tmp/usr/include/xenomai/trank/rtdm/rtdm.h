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

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */
#ifndef _XENOMAI_TRANK_RTDM_RTDM_H
#define _XENOMAI_TRANK_RTDM_RTDM_H

#include_next <rtdm/rtdm.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RTDM_NO_DEFAULT_USER_API

#define rt_dev_call(__call, __args...)	\
({					\
	int __ret;			\
	__ret = __RT(__call(__args));	\
	__ret < 0 ? -errno : __ret;	\
})

#define rt_dev_open(__args...)		rt_dev_call(open, __args)
#define rt_dev_ioctl(__args...)		rt_dev_call(ioctl, __args)
#define rt_dev_recvfrom(__args...)	rt_dev_call(recvfrom, __args)

static inline int rt_dev_socket(int domain, int type, int protocol)
{
	return rt_dev_call(socket, domain, type, protocol);
}

static inline ssize_t rt_dev_recvmsg(int fd, struct msghdr *msg, int flags)
{
	return rt_dev_call(recvmsg, fd, msg, flags);
}

static inline ssize_t rt_dev_recv(int fd, void *buf, size_t len, int flags)
{
	return rt_dev_call(recvfrom, fd, buf, len, flags, NULL, NULL);
}

static inline ssize_t rt_dev_sendmsg(int fd, const struct msghdr *msg, int flags)
{
	return rt_dev_call(sendmsg, fd, msg, flags);
}

static inline ssize_t rt_dev_sendto(int fd, const void *buf, size_t len,
				    int flags, const struct sockaddr *to,
				    socklen_t tolen)
{
	struct iovec iov;
	struct msghdr msg;

	iov.iov_base = (void *)buf;
	iov.iov_len = len;

	msg.msg_name = (struct sockaddr *)to;
	msg.msg_namelen = tolen;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	msg.msg_control = NULL;
	msg.msg_controllen = 0;

	return rt_dev_call(sendmsg, fd, &msg, flags);
}

static inline ssize_t rt_dev_send(int fd, const void *buf, size_t len,
				  int flags)
{
	return rt_dev_call(sendto, fd, buf, len, flags, NULL, 0);
}

static inline int rt_dev_getsockopt(int fd, int level, int optname,
				    void *optval, socklen_t *optlen)
{
	struct _rtdm_getsockopt_args args = {
		level, optname, optval, optlen
	};

	return rt_dev_call(ioctl, fd, _RTIOC_GETSOCKOPT, &args);
}

static inline int rt_dev_setsockopt(int fd, int level, int optname,
				    const void *optval, socklen_t optlen)
{
	struct _rtdm_setsockopt_args args = {
		level, optname, (void *)optval, optlen
	};

	return rt_dev_call(ioctl, fd, _RTIOC_SETSOCKOPT, &args);
}

static inline int rt_dev_bind(int fd, const struct sockaddr *my_addr,
			      socklen_t addrlen)
{
	struct _rtdm_setsockaddr_args args = { my_addr, addrlen };

	return rt_dev_call(ioctl, fd, _RTIOC_BIND, &args);
}

static inline int rt_dev_connect(int fd, const struct sockaddr *serv_addr,
				 socklen_t addrlen)
{
	struct _rtdm_setsockaddr_args args = { serv_addr, addrlen };

	return rt_dev_call(ioctl, fd, _RTIOC_CONNECT, &args);
}

static inline int rt_dev_listen(int fd, int backlog)
{
	return rt_dev_call(ioctl, fd, _RTIOC_LISTEN, backlog);
}

static inline int rt_dev_accept(int fd, struct sockaddr *addr,
				socklen_t *addrlen)
{
	struct _rtdm_getsockaddr_args args = { addr, addrlen };

	return rt_dev_call(ioctl, fd, _RTIOC_ACCEPT, &args);
}

static inline int rt_dev_getsockname(int fd, struct sockaddr *name,
				     socklen_t *namelen)
{
	struct _rtdm_getsockaddr_args args = { name, namelen };

	return rt_dev_call(ioctl, fd, _RTIOC_GETSOCKNAME, &args);
}

static inline int rt_dev_getpeername(int fd, struct sockaddr *name,
				     socklen_t *namelen)
{
	struct _rtdm_getsockaddr_args args = { name, namelen };

	return rt_dev_call(ioctl, fd, _RTIOC_GETPEERNAME, &args);
}

static inline int rt_dev_shutdown(int fd, int how)
{
	return rt_dev_call(ioctl, fd, _RTIOC_SHUTDOWN, how);
}

static inline int rt_dev_close(int fd)
{
	return rt_dev_call(close, fd);
}

static inline ssize_t rt_dev_write(int fd, const void *buf, size_t len)
{
	return rt_dev_call(write, fd, buf, len);
}

static inline ssize_t rt_dev_read(int fd, void *buf, size_t len)
{
	return rt_dev_call(read, fd, buf, len);
}

#endif /* !RTDM_NO_DEFAULT_USER_API */

#ifdef __cplusplus
}
#endif

#endif /* _XENOMAI_TRANK_RTDM_RTDM_H */
