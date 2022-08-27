/*
 * Copyright (C) 2010 Philippe Gerum <rpm@xenomai.org>.
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

#ifndef _BOILERPLATE_LOCK_H
#define _BOILERPLATE_LOCK_H

#include <pthread.h>
#include <boilerplate/wrappers.h>
#include <boilerplate/debug.h>

/*
 * CANCEL_DEFER/RESTORE() should enclose any emulator code prior to
 * holding a lock, or invoking inner boilerplate/copperplate services
 * (which usually do so), to change the system state. A proper cleanup
 * handler should be pushed prior to acquire such lock.
 *
 * Those macros ensure that cancellation type is switched to deferred
 * mode while the section is traversed, then restored to its original
 * value upon exit.
 *
 * WARNING: inner services MAY ASSUME that cancellability is deferred
 * for the caller, so you really want to define protected sections as
 * required in the higher interface layers.
 */
struct service {
	int cancel_type;
};

#ifdef CONFIG_XENO_ASYNC_CANCEL

#define CANCEL_DEFER(__s)					\
	do {								\
		pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,		\
				      &(__s).cancel_type);		\
	} while (0)

#define CANCEL_RESTORE(__s)					\
	do {								\
		pthread_setcanceltype((__s).cancel_type, NULL);		\
		backtrace_check();					\
	} while (0)

#else  /* !CONFIG_XENO_ASYNC_CANCEL */

#define CANCEL_DEFER(__s)	do { (void)(__s); } while (0)

#define CANCEL_RESTORE(__s)	do { } while (0)

#endif  /* !CONFIG_XENO_ASYNC_CANCEL */

struct cleanup_block {
	pthread_mutex_t *lock;
	void (*handler)(void *arg);
	void *arg;
};

#define __push_cleanup_args(__cb, __lock, __fn, __arg)	\
	((__cb)->lock = (__lock)),			\
	((__cb)->handler = (void (*)(void *))(__fn)),	\
	((__cb)->arg = (__arg))

#define push_cleanup_handler(__cb, __lock, __fn, __arg)			\
	pthread_cleanup_push((void (*)(void *))__run_cleanup_block,	\
			     (__push_cleanup_args(__cb, __lock, __fn, __arg), (__cb)))

#define pop_cleanup_handler(__cb)	\
	pthread_cleanup_pop(0)

#define push_cleanup_lock(__lock)	\
	pthread_cleanup_push((void (*)(void *))__RT(pthread_mutex_unlock), (__lock))

#define pop_cleanup_lock(__lock)	\
	pthread_cleanup_pop(0)

#ifdef CONFIG_XENO_DEBUG
int __check_cancel_type(const char *locktype);
#else
#define __check_cancel_type(__locktype)				\
	({ (void)__locktype; 0; })
#endif

#define __do_lock(__lock, __op)					\
	({							\
		int __ret;					\
		__ret = -__RT(pthread_mutex_##__op(__lock));	\
		__ret;						\
	})

#define __do_lock_nocancel(__lock, __type, __op)			\
	({								\
		__bt(__check_cancel_type(#__op "_nocancel"));		\
		__do_lock(__lock, __op);				\
	})

#define __do_unlock(__lock)					\
	({							\
		int __ret;					\
		__ret = -__RT(pthread_mutex_unlock(__lock));	\
		__ret;						\
	})
/*
 * Macros to enter/leave critical sections within inner
 * routines. Actually, they are mainly aimed at self-documenting the
 * code, by specifying basic assumption(s) about the code being
 * traversed. In effect, they are currently aliases to the standard
 * pthread_mutex_* API, except for the _safe form.
 *
 * The _nocancel suffix indicates that no cancellation point is
 * traversed by the protected code, therefore we don't need any
 * cleanup handler since we are guaranteed to run in deferred cancel
 * mode after CANCEL_DEFER(). A runtime check is inserted in
 * debug mode, which triggers when cancellability is not in deferred
 * mode while an attempt is made to acquire a _nocancel lock.
 *
 * read/write_lock() forms must be enclosed within the scope of a
 * cleanup handler since the protected code may reach cancellation
 * points. push_cleanup_lock() is a simple shorthand to push
 * pthread_mutex_unlock as the cleanup handler.
 */
#define read_lock(__lock)			\
	__do_lock(__lock, lock)

#define read_trylock(__lock)			\
	__do_lock(__lock, trylock)

#define read_lock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, read_lock, lock)

#define read_trylock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, read_trylock, trylock)

#define read_unlock(__lock)			\
	__do_unlock(__lock)

#define write_lock(__lock)			\
	__do_lock(__lock, lock)

#define write_trylock(__lock)			\
	__do_lock(__lock, trylock)

#define write_lock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, write_lock, lock)

#define write_trylock_nocancel(__lock)		\
	__do_lock_nocancel(__lock, write_trylock, trylock)

#define write_unlock(__lock)			\
	__do_unlock(__lock)

#define __do_lock_safe(__lock, __state, __op)				\
	({								\
		int __ret, __oldstate;					\
		__bt(__check_cancel_type(#__op "_safe"));		\
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &__oldstate); \
		__ret = -__RT(pthread_mutex_##__op(__lock));		\
		if (__ret)						\
			pthread_setcancelstate(__oldstate, NULL);	\
		__state = __oldstate;					\
		__ret;							\
	})

#define __do_unlock_safe(__lock, __state)				\
	({								\
		int __ret, __restored_state = __state;			\
		__ret = -__RT(pthread_mutex_unlock(__lock));		\
		pthread_setcancelstate(__restored_state, NULL);		\
		__ret;							\
	})

/*
 * The _safe call form is available when undoing the changes from an
 * update section upon cancellation using a cleanup handler is not an
 * option (e.g. too complex), or in situations where the protected
 * code shall fully run; in such cases, cancellation is disabled
 * throughout the section.
 */

#define write_lock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, lock)

#define write_trylock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, trylock)

#define write_unlock_safe(__lock, __state)	\
	__do_unlock_safe(__lock, __state)

#define read_lock_safe(__lock, __state)	\
	__do_lock_safe(__lock, __state, lock)

#define read_unlock_safe(__lock, __state)	\
	__do_unlock_safe(__lock, __state)

#ifdef CONFIG_XENO_DEBUG
#define mutex_type_attribute PTHREAD_MUTEX_ERRORCHECK
#else
#define mutex_type_attribute PTHREAD_MUTEX_NORMAL
#endif

#ifdef __cplusplus
extern "C" {
#endif

void __run_cleanup_block(struct cleanup_block *cb);

#ifdef __cplusplus
}
#endif

#endif /* _BOILERPLATE_LOCK_H */
