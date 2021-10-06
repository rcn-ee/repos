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

#ifndef _PRU_CTRL_H_
#define _PRU_CTRL_H_

/* PRU CTRL register set */
typedef struct {

	/* PRU_CTRL_CONTROL register bit field */
	union {
		volatile uint32_t CONTROL;

		volatile struct {
			uint32_t SOFT_RST_N : 1; // 0
			uint32_t PDSP_ENABLE : 1; // 1
			uint32_t PDSP_SLEEPING : 1; // 2
			uint32_t COUNTER_ENABLE : 1; // 3
			uint32_t RESTART : 1; // 4
			uint32_t rsvd5 : 3; // 7:5
			uint32_t SINGLE_STEP : 1; // 8
			uint32_t rsvd9 : 5; // 13:9
			uint32_t BIG_ENDIAN : 1; // 14
			uint32_t PDSP_STATE : 1; // 15
			uint32_t PCOUNTER_RST_VAL : 16; // 31:16
		} CONTROL_bit;
	}; // 0x0

	/* PRU_CTRL_STATUS register bit field */
	union {
		volatile uint32_t STATUS;

		volatile struct {
			uint32_t PCOUNTER : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} STATUS_bit;
	}; // 0x4

	/* PRU_CTRL_WAKEUP_ENABLE register bit field */
	union {
		volatile uint32_t WAKEUP_ENABLE;

		volatile struct {
			uint32_t BITWISE_ENABLES : 32; // 31:0
		} WAKEUP_ENABLE_bit;
	}; // 0x8

	/* PRU_CTRL_CYCLE_COUNT register bit field */
	union {
		volatile uint32_t CYCLE_COUNT;

		volatile struct {
			uint32_t CYCLECOUNT : 32; // 31:0
		} CYCLE_COUNT_bit;
	}; // 0xc

	/* PRU_CTRL_STALL_COUNT register bit field */
	union {
		volatile uint32_t STALL_COUNT;

		volatile struct {
			uint32_t STALLCOUNT : 32; // 31:0
		} STALL_COUNT_bit;
	}; // 0x10

	uint8_t rsvd14[12]; // 0x14 - 0x1f

	/* PRU_CTRL_CONSTANT_TABLE_BLOCK_INDEX_0 register bit field */
	union {
		volatile uint32_t CONSTANT_TABLE_BLOCK_INDEX_0;

		volatile struct {
			uint32_t C24_BLK_INDEX : 8; // 7:0
			uint32_t rsvd8 : 8; // 15:8
			uint32_t C25_BLK_INDEX : 8; // 23:16
			uint32_t rsvd24 : 8; // 31:24
		} CONSTANT_TABLE_BLOCK_INDEX_0_bit;
	}; // 0x20

	/* PRU_CTRL_CONSTANT_TABLE_BLOCK_INDEX_1 register bit field */
	union {
		volatile uint32_t CONSTANT_TABLE_BLOCK_INDEX_1;

		volatile struct {
			uint32_t C26_BLK_INDEX : 8; // 7:0
			uint32_t rsvd8 : 8; // 15:8
			uint32_t C27_BLK_INDEX : 8; // 23:16
			uint32_t rsvd24 : 8; // 31:24
		} CONSTANT_TABLE_BLOCK_INDEX_1_bit;
	}; // 0x24

	/* PRU_CTRL_CONSTANT_TABLE_PROG_PTR_0 register bit field */
	union {
		volatile uint32_t CONSTANT_TABLE_PROG_PTR_0;

		volatile struct {
			uint32_t C28_POINTER : 16; // 15:0
			uint32_t C29_POINTER : 16; // 31:16
		} CONSTANT_TABLE_PROG_PTR_0_bit;
	}; // 0x28

	/* PRU_CTRL_CONSTANT_TABLE_PROG_PTR_1 register bit field */
	union {
		volatile uint32_t CONSTANT_TABLE_PROG_PTR_1;

		volatile struct {
			uint32_t C30_POINTER : 16; // 15:0
			uint32_t C31_POINTER : 16; // 31:16
		} CONSTANT_TABLE_PROG_PTR_1_bit;
	}; // 0x2c

} ctrl;

volatile __far ctrl CT_PRU0_CTRL __attribute__((cregister("PRU0_CTRL", near), peripheral));
volatile __far ctrl CT_PRU1_CTRL __attribute__((cregister("PRU1_CTRL", near), peripheral));
volatile __far ctrl CT_RTU0_CTRL __attribute__((cregister("RTU0_CTRL", near), peripheral));
volatile __far ctrl CT_RTU1_CTRL __attribute__((cregister("RTU1_CTRL", near), peripheral));
volatile __far ctrl CT_TX_PRU0_CTRL __attribute__((cregister("TX_PRU0_CTRL", near), peripheral));
volatile __far ctrl CT_TX_PRU1_CTRL __attribute__((cregister("TX_PRU1_CTRL", near), peripheral));

#endif /* _PRU_CTRL_H_ */

