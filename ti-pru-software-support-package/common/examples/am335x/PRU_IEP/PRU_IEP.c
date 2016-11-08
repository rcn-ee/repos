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
#include <pru_iep.h>
#include "rsc_table_pru.h"

volatile register uint32_t __R30;
volatile register uint32_t __R31;

void main(void)
{
	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	/* Disable counter */
	CT_IEP.TMR_GLB_CFG_bit.CNT_EN = 0;

	/* Reset Count register */
	CT_IEP.TMR_CNT = 0x0;

	/* Clear overflow status register */
	CT_IEP.TMR_GLB_STS_bit.CNT_OVF = 0x1;

	/* Set compare value */
	CT_IEP.TMR_CMP0 = 0x77359400; // 10 seconds @ 200MHz

	/* Clear compare status */
	CT_IEP.TMR_CMP_STS_bit.CMP_HIT = 0xFF;

	/* Disable compensation */
	CT_IEP.TMR_COMPEN_bit.COMPEN_CNT = 0x0;

	/* Enable CMP0 and reset on event */
	CT_IEP.TMR_CMP_CFG_bit.CMP0_RST_CNT_EN = 0x1;
	CT_IEP.TMR_CMP_CFG_bit.CMP_EN = 0x1;

	/* Clear the status of all interrupts */
	CT_INTC.SECR0 = 0xFFFFFFFF;
	CT_INTC.SECR1 = 0xFFFFFFFF;

	/* Enable counter */
	CT_IEP.TMR_GLB_CFG = 0x11;

	/* Poll until R31.31 is set */
	do {
		while ((__R31 & 0x80000000) == 0) {
		}
		/* Verify that the IEP is the source of the interrupt */
	} while ((CT_INTC.SECR0 & (1 << 7)) == 0);

	/* Disable counter */
	CT_IEP.TMR_GLB_CFG_bit.CNT_EN = 0x0;

	/* Disable Compare0 */
	CT_IEP.TMR_CMP_CFG = 0x0;

	/* Clear Compare status */
	CT_IEP.TMR_CMP_STS = 0xFF;

	/* Clear the status of the interrupt */
	CT_INTC.SECR0 = (1 << 7);

	/* Halt the PRU core */
	__halt();
}

