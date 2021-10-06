/*
 * Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
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
/* No INTC map needed for PRU1. INTC setup is handled in PRU0 intc_map_0.h */

volatile register uint32_t __R30;
volatile register uint32_t __R31;

typedef struct {
	uint32_t reg5;
	uint32_t reg6;
	uint32_t reg7;
	uint32_t reg8;
	uint32_t reg9;
	uint32_t reg10;
} bufferData;

bufferData dmemBuf;

/* Define interrupts */
#define PRU1_TO_PRU0_INTERRUPT (18)
#define PRU0_TO_PRU1_INTERRUPT (19)

void main(void)
{
	bufferData buf;

	/*
	 * Trigger System Events (sysevt) 16 - 31 by writing to r31:
	 *   pru<n>_r31_vec_valid + pru<n>_r31_vec[3:0]
	 *   = (1 << 5) + vector output
	 *   = 32 + (sysevt - 16)
	 *   = 16 + sysevt
	 * Reference AM64x TRM section for more:
	 * "Real-Time Status Interface Mapping (R31): Interrupt Events Input"
	 */

	/*
	 * Let PRU0 know that PRU1 is initialized.
	 * PRU0 firmware clears SECR registers before it starts polling for
	 * interrupts. So make sure to load PRU0 firmware before loading PRU1
	 * firmware.
	 */
	__R31 = PRU1_TO_PRU0_INTERRUPT+16;

	/*
	 * Poll until R31.31 (PRU1 interrupt) is set.
         * This signals PRU0 has loaded the registers into the scratchpad.
	 */
	while ((__R31 & (1<<31)) == 0) {
	}

	/*
	 * For more on passing broadside data between ICSSG cores, reference the
	 * AM64x Technical Reference Manual (TRM). In particular,
	 * - table "Hardware Module Broadside ID Mapping"
	 * - section "PRU_ICSSG Scratch Pad Memory"
	 */

	/*
	 * Transfer (XFR) registers R5-R10 from PRU0 to PRU1
	 * SPAD Bank0 is shared between PRU1/0. Broadside ID = 10
	 */
	__xin(10, 5, 0, buf);

	/* Store register values back into DRAM */
	dmemBuf = buf;

	/* Halt the PRU core */
	__halt();
}
