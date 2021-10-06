/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _PRU_RAT_SLICE_H_
#define _PRU_RAT_SLICE_H_

/* PRU RAT SLICE register set */
typedef struct {

	/* PRU_RAT_SLICE_pid register bit field */
	union {
		volatile uint32_t pid;

		volatile struct {
			uint32_t minor : 6; // 5:0
			uint32_t custom : 2; // 7:6
			uint32_t major : 3; // 10:8
			uint32_t rtl : 5; // 15:11
			uint32_t func : 12; // 27:16
			uint32_t bu : 2; // 29:28
			uint32_t scheme : 2; // 31:30
		} pid_bit;
	}; // 0x0

	/* PRU_RAT_SLICE_config register bit field */
	union {
		volatile uint32_t config;

		volatile struct {
			uint32_t regions : 8; // 7:0
			uint32_t addrs : 8; // 15:8
			uint32_t addr_width : 8; // 23:16
			uint32_t rsvd24 : 8; // 31:24
		} config_bit;
	}; // 0x4

	uint8_t rsvd8[2044]; // 0x8 - 0x803

	/* PRU_RAT_SLICE_destination_id register bit field */
	union {
		volatile uint32_t destination_id;

		volatile struct {
			uint32_t dest_id : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} destination_id_bit;
	}; // 0x804

	uint8_t rsvd808[24]; // 0x808 - 0x81f

	/* PRU_RAT_SLICE_exception_logging_control register bit field */
	union {
		volatile uint32_t exception_logging_control;

		volatile struct {
			uint32_t disable_f : 1; // 0
			uint32_t disable_intr : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} exception_logging_control_bit;
	}; // 0x820

	/* PRU_RAT_SLICE_exception_logging_header0 register bit field */
	union {
		volatile uint32_t exception_logging_header0;

		volatile struct {
			uint32_t dest_id : 8; // 7:0
			uint32_t src_id : 16; // 23:8
			uint32_t type_f : 8; // 31:24
		} exception_logging_header0_bit;
	}; // 0x824

	/* PRU_RAT_SLICE_exception_logging_header1 register bit field */
	union {
		volatile uint32_t exception_logging_header1;

		volatile struct {
			uint32_t rsvd0 : 16; // 15:0
			uint32_t code : 8; // 23:16
			uint32_t group : 8; // 31:24
		} exception_logging_header1_bit;
	}; // 0x828

	/* PRU_RAT_SLICE_exception_logging_data0 register bit field */
	union {
		volatile uint32_t exception_logging_data0;

		volatile struct {
			uint32_t addr_l : 32; // 31:0
		} exception_logging_data0_bit;
	}; // 0x82c

	/* PRU_RAT_SLICE_exception_logging_data1 register bit field */
	union {
		volatile uint32_t exception_logging_data1;

		volatile struct {
			uint32_t addr_h : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} exception_logging_data1_bit;
	}; // 0x830

	/* PRU_RAT_SLICE_exception_logging_data2 register bit field */
	union {
		volatile uint32_t exception_logging_data2;

		volatile struct {
			uint32_t priv_id : 8; // 7:0
			uint32_t secure : 1; // 8
			uint32_t priv : 1; // 9
			uint32_t cacheable : 1; // 10
			uint32_t debug : 1; // 11
			uint32_t read : 1; // 12
			uint32_t write : 1; // 13
			uint32_t rsvd14 : 2; // 15:14
			uint32_t routeid : 12; // 27:16
			uint32_t rsvd28 : 4; // 31:28
		} exception_logging_data2_bit;
	}; // 0x834

	/* PRU_RAT_SLICE_exception_logging_data3 register bit field */
	union {
		volatile uint32_t exception_logging_data3;

		volatile struct {
			uint32_t bytecnt : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} exception_logging_data3_bit;
	}; // 0x838

	uint8_t rsvd83c[4]; // 0x83c - 0x83f

	/* PRU_RAT_SLICE_exception_pend_set register bit field */
	union {
		volatile uint32_t exception_pend_set;

		volatile struct {
			uint32_t pend_set : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} exception_pend_set_bit;
	}; // 0x840

	/* PRU_RAT_SLICE_exception_pend_clear register bit field */
	union {
		volatile uint32_t exception_pend_clear;

		volatile struct {
			uint32_t pend_clr : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} exception_pend_clear_bit;
	}; // 0x844

	/* PRU_RAT_SLICE_exception_enable_set register bit field */
	union {
		volatile uint32_t exception_enable_set;

		volatile struct {
			uint32_t enable_set : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} exception_enable_set_bit;
	}; // 0x848

	/* PRU_RAT_SLICE_exception_enable_clear register bit field */
	union {
		volatile uint32_t exception_enable_clear;

		volatile struct {
			uint32_t enable_clr : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} exception_enable_clear_bit;
	}; // 0x84c

	/* PRU_RAT_SLICE_eoi_reg register bit field */
	union {
		volatile uint32_t eoi_reg;

		volatile struct {
			uint32_t eoi_wr : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} eoi_reg_bit;
	}; // 0x850

} ratSlice;

volatile __far ratSlice CT_RAT0 __attribute__ ((cregister("PRU_RTU_RAT0", far), peripheral));
volatile __far ratSlice CT_RAT1 __attribute__ ((cregister("PRU_RTU_RAT1", far), peripheral));

#endif /* _PRU_RAT_SLICE_H_ */

