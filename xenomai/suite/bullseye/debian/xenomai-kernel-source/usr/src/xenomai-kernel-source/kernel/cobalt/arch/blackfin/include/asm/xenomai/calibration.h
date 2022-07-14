/*
 * Copyright (C) 2005 Philippe Gerum <rpm@xenomai.org>.
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
#ifndef _COBALT_BLACKFIN_ASM_CALIBRATION_H
#define _COBALT_BLACKFIN_ASM_CALIBRATION_H

static inline void xnarch_get_latencies(struct xnclock_gravity *p)
{
#if CONFIG_XENO_OPT_TIMING_SCHEDLAT != 0
#define __sched_latency CONFIG_XENO_OPT_TIMING_SCHEDLAT
#elif defined(CONFIG_BF533)
#define __sched_latency 5000
#elif defined(CONFIG_BF537)
#define __sched_latency 4800
#elif defined(CONFIG_BF53x)
#define __sched_latency 5000
#elif defined(CONFIG_BF538)
#define __sched_latency 5000
#elif defined(CONFIG_BF561)
#define __sched_latency 4500
#elif defined(CONFIG_BF609)
#define __sched_latency 5500
#elif defined(CONFIG_BF54x)
#define __sched_latency 5000
#elif defined(CONFIG_BF52x)
#define __sched_latency 7000
#elif defined(CONFIG_BF51x)
#define __sched_latency 6000
#elif defined(CONFIG_BF60x)
#define __sched_latency 5500
#else
#error "unsupported Blackfin processor"
#endif
	p->user = __sched_latency;
	p->kernel = CONFIG_XENO_OPT_TIMING_KSCHEDLAT;
	p->irq = CONFIG_XENO_OPT_TIMING_IRQLAT;
}

#undef __sched_latency

#endif /* !_COBALT_BLACKFIN_ASM_CALIBRATION_H */
