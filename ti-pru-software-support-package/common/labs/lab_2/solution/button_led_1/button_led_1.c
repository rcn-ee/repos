/*
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <pru_cfg.h>
/*TODO: Include intc.h */
#include <pru_intc.h>

volatile register uint32_t __R30;
volatile register uint32_t __R31;

/* Defines */
#define PRU1
#define HOST1_MASK		(0x80000000)
#define PRU0_PRU1_EVT	(16)
/*TODO: Define toggling the BLUE LED */
#define TOGGLE_BLUE		(__R30 ^= (1 << 3))

void main(void)
{
	/* Configure GPI and GPO as Mode 0 (Direct Connect) */
	CT_CFG.GPCFG0 = 0x0000;

	/* Clear GPO pins */
	__R30 &= 0xFFFF0000;

	/* Spin in loop until interrupt on HOST 1 is detected */
	while (1) {
		if (__R31 & HOST1_MASK) {
			TOGGLE_BLUE;
			/* Clear interrupt event */
			CT_INTC.SICR = 16; /*TODO: Clear event 16*/;
			/* Delay to ensure the event is cleared in INTC */
			__delay_cycles(5);
		}
	}
}

