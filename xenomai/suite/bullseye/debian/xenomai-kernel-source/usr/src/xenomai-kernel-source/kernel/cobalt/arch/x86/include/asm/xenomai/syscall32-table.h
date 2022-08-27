/*
 * Copyright (C) 2014 Philippe Gerum <rpm@xenomai.org>.
 *
 * Xenomai is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
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
#ifndef _COBALT_X86_ASM_SYSCALL32_TABLE_H
#define _COBALT_X86_ASM_SYSCALL32_TABLE_H

/*
 * CAUTION: This file is read verbatim into the main syscall
 * table. Only preprocessor stuff and syscall entries here.
 */

__COBALT_CALL32emu_THUNK(thread_create)
__COBALT_CALL32emu_THUNK(thread_setschedparam_ex)
__COBALT_CALL32emu_THUNK(thread_getschedparam_ex)
__COBALT_CALL32emu_THUNK(sem_open)
__COBALT_CALL32x_THUNK(sem_open)
__COBALT_CALL32emu_THUNK(sem_timedwait)
__COBALT_CALL32emu_THUNK(clock_getres)
__COBALT_CALL32emu_THUNK(clock_gettime)
__COBALT_CALL32emu_THUNK(clock_settime)
__COBALT_CALL32emu_THUNK(clock_nanosleep)
__COBALT_CALL32emu_THUNK(mutex_timedlock)
__COBALT_CALL32emu_THUNK(cond_wait_prologue)
__COBALT_CALL32emu_THUNK(mq_open)
__COBALT_CALL32x_THUNK(mq_open)
__COBALT_CALL32emu_THUNK(mq_getattr)
__COBALT_CALL32x_THUNK(mq_getattr)
__COBALT_CALL32emu_THUNK(mq_timedsend)
__COBALT_CALL32emu_THUNK(mq_timedreceive)
__COBALT_CALL32x_pure_THUNK(mq_timedreceive)
__COBALT_CALL32emu_THUNK(mq_notify)
__COBALT_CALL32x_THUNK(mq_notify)
__COBALT_CALL32emu_THUNK(sched_weightprio)
__COBALT_CALL32emu_THUNK(sched_setconfig_np)
__COBALT_CALL32emu_THUNK(sched_getconfig_np)
__COBALT_CALL32emu_THUNK(sched_setscheduler_ex)
__COBALT_CALL32emu_THUNK(sched_getscheduler_ex)
__COBALT_CALL32emu_THUNK(timer_create)
__COBALT_CALL32x_THUNK(timer_create)
__COBALT_CALL32emu_THUNK(timer_settime)
__COBALT_CALL32emu_THUNK(timer_gettime)
__COBALT_CALL32emu_THUNK(timerfd_settime)
__COBALT_CALL32emu_THUNK(timerfd_gettime)
__COBALT_CALL32emu_THUNK(sigwait)
__COBALT_CALL32x_THUNK(sigwait)
__COBALT_CALL32emu_THUNK(sigtimedwait)
__COBALT_CALL32x_THUNK(sigtimedwait)
__COBALT_CALL32emu_THUNK(sigwaitinfo)
__COBALT_CALL32x_THUNK(sigwaitinfo)
__COBALT_CALL32emu_THUNK(sigpending)
__COBALT_CALL32x_THUNK(sigpending)
__COBALT_CALL32emu_THUNK(sigqueue)
__COBALT_CALL32x_THUNK(sigqueue)
__COBALT_CALL32emu_THUNK(monitor_wait)
__COBALT_CALL32emu_THUNK(event_wait)
__COBALT_CALL32emu_THUNK(select)
__COBALT_CALL32x_THUNK(select)
__COBALT_CALL32emu_THUNK(recvmsg)
__COBALT_CALL32x_THUNK(recvmsg)
__COBALT_CALL32emu_THUNK(sendmsg)
__COBALT_CALL32x_THUNK(sendmsg)
__COBALT_CALL32emu_THUNK(mmap)
__COBALT_CALL32x_THUNK(mmap)
__COBALT_CALL32emu_THUNK(backtrace)
__COBALT_CALL32x_THUNK(backtrace)

#endif /* !_COBALT_X86_ASM_SYSCALL32_TABLE_H */
