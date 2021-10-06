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

#ifndef _PRU_ECC_AGGR_H_
#define _PRU_ECC_AGGR_H_

/* PRU ECC AGGR register set */
typedef struct {

	/* PRU_ECC_AGGR_rev register bit field */
	union {
		volatile uint32_t rev;

		volatile struct {
			uint32_t revmin : 6; // 5:0
			uint32_t custom : 2; // 7:6
			uint32_t revmaj : 3; // 10:8
			uint32_t revrtl : 5; // 15:11
			uint32_t module_id : 12; // 27:16
			uint32_t bu : 2; // 29:28
			uint32_t scheme : 2; // 31:30
		} rev_bit;
	}; // 0x0

	uint8_t rsvd4[4]; // 0x4 - 0x7

	/* PRU_ECC_AGGR_vector register bit field */
	union {
		volatile uint32_t vector;

		volatile struct {
			uint32_t ecc_vector : 11; // 10:0
			uint32_t rsvd11 : 4; // 14:11
			uint32_t rd_svbus : 1; // 15
			uint32_t rd_svbus_address : 8; // 23:16
			uint32_t rd_svbus_done : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} vector_bit;
	}; // 0x8

	/* PRU_ECC_AGGR_stat register bit field */
	union {
		volatile uint32_t stat;

		volatile struct {
			uint32_t num_rams : 11; // 10:0
			uint32_t rsvd11 : 21; // 31:11
		} stat_bit;
	}; // 0xc

	uint8_t rsvd10[44]; // 0x10 - 0x3b

	/* PRU_ECC_AGGR_sec_eoi_reg register bit field */
	union {
		volatile uint32_t sec_eoi_reg;

		volatile struct {
			uint32_t eoi_wr : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} sec_eoi_reg_bit;
	}; // 0x3c

	/* PRU_ECC_AGGR_sec_status_reg0 register bit field */
	union {
		volatile uint32_t sec_status_reg0;

		volatile struct {
			uint32_t pr1_dram0_pend : 1; // 0
			uint32_t pr1_dram1_pend : 1; // 1
			uint32_t pr1_pdsp0_iram_pend : 1; // 2
			uint32_t pr1_pdsp1_iram_pend : 1; // 3
			uint32_t pr1_ram_pend : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_pend : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_pend : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} sec_status_reg0_bit;
	}; // 0x40

	uint8_t rsvd44[60]; // 0x44 - 0x7f

	/* PRU_ECC_AGGR_sec_enable_set_reg0 register bit field */
	union {
		volatile uint32_t sec_enable_set_reg0;

		volatile struct {
			uint32_t pr1_dram0_enable_set : 1; // 0
			uint32_t pr1_dram1_enable_set : 1; // 1
			uint32_t pr1_pdsp0_iram_enable_set : 1; // 2
			uint32_t pr1_pdsp1_iram_enable_set : 1; // 3
			uint32_t pr1_ram_enable_set : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_enable_set : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_enable_set : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} sec_enable_set_reg0_bit;
	}; // 0x80

	uint8_t rsvd84[60]; // 0x84 - 0xbf

	/* PRU_ECC_AGGR_sec_enable_clr_reg0 register bit field */
	union {
		volatile uint32_t sec_enable_clr_reg0;

		volatile struct {
			uint32_t pr1_dram0_enable_clr : 1; // 0
			uint32_t pr1_dram1_enable_clr : 1; // 1
			uint32_t pr1_pdsp0_iram_enable_clr : 1; // 2
			uint32_t pr1_pdsp1_iram_enable_clr : 1; // 3
			uint32_t pr1_ram_enable_clr : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_enable_clr : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_enable_clr : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} sec_enable_clr_reg0_bit;
	}; // 0xc0

	uint8_t rsvdc4[120]; // 0xc4 - 0x13b

	/* PRU_ECC_AGGR_ded_eoi_reg register bit field */
	union {
		volatile uint32_t ded_eoi_reg;

		volatile struct {
			uint32_t eoi_wr : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} ded_eoi_reg_bit;
	}; // 0x13c

	/* PRU_ECC_AGGR_ded_status_reg0 register bit field */
	union {
		volatile uint32_t ded_status_reg0;

		volatile struct {
			uint32_t pr1_dram0_pend : 1; // 0
			uint32_t pr1_dram1_pend : 1; // 1
			uint32_t pr1_pdsp0_iram_pend : 1; // 2
			uint32_t pr1_pdsp1_iram_pend : 1; // 3
			uint32_t pr1_ram_pend : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_pend : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_pend : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} ded_status_reg0_bit;
	}; // 0x140

	uint8_t rsvd144[60]; // 0x144 - 0x17f

	/* PRU_ECC_AGGR_ded_enable_set_reg0 register bit field */
	union {
		volatile uint32_t ded_enable_set_reg0;

		volatile struct {
			uint32_t pr1_dram0_enable_set : 1; // 0
			uint32_t pr1_dram1_enable_set : 1; // 1
			uint32_t pr1_pdsp0_iram_enable_set : 1; // 2
			uint32_t pr1_pdsp1_iram_enable_set : 1; // 3
			uint32_t pr1_ram_enable_set : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_enable_set : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_enable_set : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} ded_enable_set_reg0_bit;
	}; // 0x180

	uint8_t rsvd184[60]; // 0x184 - 0x1bf

	/* PRU_ECC_AGGR_ded_enable_clr_reg0 register bit field */
	union {
		volatile uint32_t ded_enable_clr_reg0;

		volatile struct {
			uint32_t pr1_dram0_enable_clr : 1; // 0
			uint32_t pr1_dram1_enable_clr : 1; // 1
			uint32_t pr1_pdsp0_iram_enable_clr : 1; // 2
			uint32_t pr1_pdsp1_iram_enable_clr : 1; // 3
			uint32_t pr1_ram_enable_clr : 1; // 4
			uint32_t pr1_rtu0_iram_ecc_enable_clr : 1; // 5
			uint32_t pr1_rtu1_iram_ecc_enable_clr : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} ded_enable_clr_reg0_bit;
	}; // 0x1c0

	uint8_t rsvd1c4[60]; // 0x1c4 - 0x1ff

	/* PRU_ECC_AGGR_aggr_enable_set register bit field */
	union {
		volatile uint32_t aggr_enable_set;

		volatile struct {
			uint32_t parity : 1; // 0
			uint32_t timeout : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} aggr_enable_set_bit;
	}; // 0x200

	/* PRU_ECC_AGGR_aggr_enable_clr register bit field */
	union {
		volatile uint32_t aggr_enable_clr;

		volatile struct {
			uint32_t parity : 1; // 0
			uint32_t timeout : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} aggr_enable_clr_bit;
	}; // 0x204

	/* PRU_ECC_AGGR_aggr_status_set register bit field */
	union {
		volatile uint32_t aggr_status_set;

		volatile struct {
			uint32_t parity : 2; // 1:0
			uint32_t timeout : 2; // 3:2
			uint32_t rsvd4 : 28; // 31:4
		} aggr_status_set_bit;
	}; // 0x208

	/* PRU_ECC_AGGR_aggr_status_clr register bit field */
	union {
		volatile uint32_t aggr_status_clr;

		volatile struct {
			uint32_t parity : 2; // 1:0
			uint32_t timeout : 2; // 3:2
			uint32_t rsvd4 : 28; // 31:4
		} aggr_status_clr_bit;
	}; // 0x20c

} eccAggr;

#define PRU0_ECC_AGGR (*((volatile eccAggr*)0x0bf00000))
#define PRU1_ECC_AGGR (*((volatile eccAggr*)0x0bf01000))
#define PRU2_ECC_AGGR (*((volatile eccAggr*)0x0bf02000))

#endif /* _PRU_ECC_AGGR_H_ */

