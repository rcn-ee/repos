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

// PRU Core 1
#define PRU1

volatile register uint32_t __R30;
volatile register uint32_t __R31;

/* Defines */
#define PRU0

/* PRU0-to-PRU1 interrupt */
#define PRU0_PRU1_EVT		(16)
#define PRU0_PRU1_TRIGGER	(__R31 = (PRU0_PRU1_EVT - 16) | (1 << 5))

/* SW1 offset */
/*TODO: Define GPI offset for SW1 */

/* INTC configuration
 * We are going to map User event 16 to Host 1
 * PRU1 will then wait for r31 bit 31 (designates Host 1) to go high
 * */
void configIntc(void)
{
	/* Clear any pending PRU-generated events */
	__R31 = 0x00000000;

	/* Map event 16 to channel 1 */
	CT_INTC.CMR4_bit/*TODO: Select correct bit field and enter proper value */;

	/* Map channel 1 to host 1 */
	CT_INTC.HMR0_bit/*TODO: Select correct bit field and enter proper value */;

	/* Ensure event 16 is cleared */
	CT_INTC.SICR = /*TODO: Clear proper event */;

	/* Enable event 16 */
	CT_INTC.EISR = /*TODO: Enable proper event */;

	/* Enable Host interrupt 1 */
	CT_INTC.HIEISR |= /*TODO: Enable proper event */;

	// Globally enable host interrupts
	CT_INTC.GER = /*TODO: Enable global events */;
}

void main(void)
{
	/* Configure GPI and GPO as Mode 0 (Direct Connect) */
	CT_CFG.GPCFG0 = 0x0000;

	/* Clear GPO pins */
	__R30 &= 0xFFFF0000;

	/* Configure INTC */
	configIntc();

	while (1) {
		/* Wait for SW1 to be pressed */
		if ((__R31 & SW1) != SW1) {
			/* Interrupt PRU1, wait 500ms for cheap "debounce" */
			/* TODO: Trigger interrupt - see #defines */
		}
	}
}

