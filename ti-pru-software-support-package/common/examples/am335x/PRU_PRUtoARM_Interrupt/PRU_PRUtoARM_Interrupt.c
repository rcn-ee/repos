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
#include <pru_intc.h>
#include <pru_ctrl.h>
#include "resource_table_empty.h"

volatile register uint32_t __R30;
volatile register uint32_t __R31;

/* Mapping Constant table register to variable */
volatile far uint32_t CT_DDR __attribute__((cregister("DDR", near), peripheral));

/* PRU-to-ARM interrupt */
#define PRU0_ARM_INTERRUPT (19+16)

#define HOST_NUM	2
#define CHAN_NUM	2

void main(void)
{
	uint32_t *pDdr = (uint32_t *) &CT_DDR;

	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	// Globally enable host interrupts
	CT_INTC.GER = 0x1;

	/* Clear any pending PRU-generated events */
	__R31 = 0x00000000;

	/* Start preparing message for host - make sure it's not 0xB */
	pDdr[1] = 0x0001;

	/* Enable Host interrupt 2 */
	CT_INTC.HIEISR |= HOST_NUM;

	/* Map channel 2 to host 2 */
	CT_INTC.HMR0_bit.HINT_MAP_2 = HOST_NUM;

	/* Map PRU0_ARM_INTERRUPT (event 19) to channel 2 */
	CT_INTC.CMR4_bit.CH_MAP_19 = CHAN_NUM;

	/* Ensure PRU0_ARM_INTERRUPT is cleared */
	CT_INTC.SICR = (PRU0_ARM_INTERRUPT - 16);

	/* Enable PRU0_ARM_INTERRUPT */
	CT_INTC.EISR = (PRU0_ARM_INTERRUPT - 16);

	/* Ensure CT_DDR (C31) is pointing to start of DDR memory (0x80000000) */
	PRU0_CTRL.CTPPR1_bit.C31_BLK_POINTER = 0x0;

	/* Write value of 0xB which Host will read after receiving the interrupt */
	pDdr[1] = 0xB;

	/* Halt the PRU */
	__halt();
}

