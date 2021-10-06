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

#ifndef _PRU_IEP_H_
#define _PRU_IEP_H_

/* PRU IEP register set */
typedef struct {

	/* PRU_IEP_global_cfg_reg register bit field */
	union {
		volatile uint32_t global_cfg_reg;

		volatile struct {
			uint32_t cnt_enable : 1; // 0
			uint32_t rsvd1 : 3; // 3:1
			uint32_t default_inc : 4; // 7:4
			uint32_t cmp_inc : 12; // 19:8
			uint32_t rsvd20 : 12; // 31:20
		} global_cfg_reg_bit;
	}; // 0x0

	/* PRU_IEP_global_status_reg register bit field */
	union {
		volatile uint32_t global_status_reg;

		volatile struct {
			uint32_t cnt_ovf : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} global_status_reg_bit;
	}; // 0x4

	/* PRU_IEP_compen_reg register bit field */
	union {
		volatile uint32_t compen_reg;

		volatile struct {
			uint32_t compen_cnt : 23; // 22:0
			uint32_t rsvd23 : 9; // 31:23
		} compen_reg_bit;
	}; // 0x8

	/* PRU_IEP_slow_compen_reg register bit field */
	union {
		volatile uint32_t slow_compen_reg;

		volatile struct {
			uint32_t slow_compen_cnt : 32; // 31:0
		} slow_compen_reg_bit;
	}; // 0xc

	/* PRU_IEP_count_reg0 register bit field */
	union {
		volatile uint32_t count_reg0;

		volatile struct {
			uint32_t count_lo : 32; // 31:0
		} count_reg0_bit;
	}; // 0x10

	/* PRU_IEP_count_reg1 register bit field */
	union {
		volatile uint32_t count_reg1;

		volatile struct {
			uint32_t count_hi : 32; // 31:0
		} count_reg1_bit;
	}; // 0x14

	/* PRU_IEP_cap_cfg_reg register bit field */
	union {
		volatile uint32_t cap_cfg_reg;

		volatile struct {
			uint32_t cap_en : 10; // 9:0
			uint32_t cap_async_en : 8; // 17:10
			uint32_t ext_cap_en : 6; // 23:18
			uint32_t rsvd24 : 8; // 31:24
		} cap_cfg_reg_bit;
	}; // 0x18

	/* PRU_IEP_cap_status_reg register bit field */
	union {
		volatile uint32_t cap_status_reg;

		volatile struct {
			uint32_t cap_valid : 11; // 10:0
			uint32_t rsvd11 : 5; // 15:11
			uint32_t cap_raw : 8; // 23:16
			uint32_t rsvd24 : 8; // 31:24
		} cap_status_reg_bit;
	}; // 0x1c

	/* PRU_IEP_capr0_reg0 register bit field */
	union {
		volatile uint32_t capr0_reg0;

		volatile struct {
			uint32_t capr0_0 : 32; // 31:0
		} capr0_reg0_bit;
	}; // 0x20

	/* PRU_IEP_capr0_reg1 register bit field */
	union {
		volatile uint32_t capr0_reg1;

		volatile struct {
			uint32_t capr0_1 : 32; // 31:0
		} capr0_reg1_bit;
	}; // 0x24

	/* PRU_IEP_capr1_reg0 register bit field */
	union {
		volatile uint32_t capr1_reg0;

		volatile struct {
			uint32_t capr1_0 : 32; // 31:0
		} capr1_reg0_bit;
	}; // 0x28

	/* PRU_IEP_capr1_reg1 register bit field */
	union {
		volatile uint32_t capr1_reg1;

		volatile struct {
			uint32_t capr1_1 : 32; // 31:0
		} capr1_reg1_bit;
	}; // 0x2c

	/* PRU_IEP_capr2_reg0 register bit field */
	union {
		volatile uint32_t capr2_reg0;

		volatile struct {
			uint32_t capr2_0 : 32; // 31:0
		} capr2_reg0_bit;
	}; // 0x30

	/* PRU_IEP_capr2_reg1 register bit field */
	union {
		volatile uint32_t capr2_reg1;

		volatile struct {
			uint32_t capr2_1 : 32; // 31:0
		} capr2_reg1_bit;
	}; // 0x34

	/* PRU_IEP_capr3_reg0 register bit field */
	union {
		volatile uint32_t capr3_reg0;

		volatile struct {
			uint32_t capr3_0 : 32; // 31:0
		} capr3_reg0_bit;
	}; // 0x38

	/* PRU_IEP_capr3_reg1 register bit field */
	union {
		volatile uint32_t capr3_reg1;

		volatile struct {
			uint32_t capr3_1 : 32; // 31:0
		} capr3_reg1_bit;
	}; // 0x3c

	/* PRU_IEP_capr4_reg0 register bit field */
	union {
		volatile uint32_t capr4_reg0;

		volatile struct {
			uint32_t capr4_0 : 32; // 31:0
		} capr4_reg0_bit;
	}; // 0x40

	/* PRU_IEP_capr4_reg1 register bit field */
	union {
		volatile uint32_t capr4_reg1;

		volatile struct {
			uint32_t capr4_1 : 32; // 31:0
		} capr4_reg1_bit;
	}; // 0x44

	/* PRU_IEP_capr5_reg0 register bit field */
	union {
		volatile uint32_t capr5_reg0;

		volatile struct {
			uint32_t capr5_0 : 32; // 31:0
		} capr5_reg0_bit;
	}; // 0x48

	/* PRU_IEP_capr5_reg1 register bit field */
	union {
		volatile uint32_t capr5_reg1;

		volatile struct {
			uint32_t capr5_1 : 32; // 31:0
		} capr5_reg1_bit;
	}; // 0x4c

	/* PRU_IEP_capr6_reg0 register bit field */
	union {
		volatile uint32_t capr6_reg0;

		volatile struct {
			uint32_t capr6_0 : 32; // 31:0
		} capr6_reg0_bit;
	}; // 0x50

	/* PRU_IEP_capr6_reg1 register bit field */
	union {
		volatile uint32_t capr6_reg1;

		volatile struct {
			uint32_t capr6_1 : 32; // 31:0
		} capr6_reg1_bit;
	}; // 0x54

	/* PRU_IEP_capf6_reg0 register bit field */
	union {
		volatile uint32_t capf6_reg0;

		volatile struct {
			uint32_t capf6_0 : 32; // 31:0
		} capf6_reg0_bit;
	}; // 0x58

	/* PRU_IEP_capf6_reg1 register bit field */
	union {
		volatile uint32_t capf6_reg1;

		volatile struct {
			uint32_t capf6_1 : 32; // 31:0
		} capf6_reg1_bit;
	}; // 0x5c

	/* PRU_IEP_capr7_reg0 register bit field */
	union {
		volatile uint32_t capr7_reg0;

		volatile struct {
			uint32_t capr7_0 : 32; // 31:0
		} capr7_reg0_bit;
	}; // 0x60

	/* PRU_IEP_capr7_reg1 register bit field */
	union {
		volatile uint32_t capr7_reg1;

		volatile struct {
			uint32_t capr7_1 : 32; // 31:0
		} capr7_reg1_bit;
	}; // 0x64

	/* PRU_IEP_capf7_reg0 register bit field */
	union {
		volatile uint32_t capf7_reg0;

		volatile struct {
			uint32_t capf7_0 : 32; // 31:0
		} capf7_reg0_bit;
	}; // 0x68

	/* PRU_IEP_capf7_reg1 register bit field */
	union {
		volatile uint32_t capf7_reg1;

		volatile struct {
			uint32_t capf7_1 : 32; // 31:0
		} capf7_reg1_bit;
	}; // 0x6c

	/* PRU_IEP_cmp_cfg_reg register bit field */
	union {
		volatile uint32_t cmp_cfg_reg;

		volatile struct {
			uint32_t cmp0_rst_cnt_en : 1; // 0
			uint32_t cmp_en : 16; // 16:1
			uint32_t shadow_en : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} cmp_cfg_reg_bit;
	}; // 0x70

	/* PRU_IEP_cmp_status_reg register bit field */
	union {
		volatile uint32_t cmp_status_reg;

		volatile struct {
			uint32_t cmp_status : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} cmp_status_reg_bit;
	}; // 0x74

	/* PRU_IEP_cmp0_reg0 register bit field */
	union {
		volatile uint32_t cmp0_reg0;

		volatile struct {
			uint32_t cmp0_0 : 32; // 31:0
		} cmp0_reg0_bit;
	}; // 0x78

	/* PRU_IEP_cmp0_reg1 register bit field */
	union {
		volatile uint32_t cmp0_reg1;

		volatile struct {
			uint32_t cmp0_1 : 32; // 31:0
		} cmp0_reg1_bit;
	}; // 0x7c

	/* PRU_IEP_cmp1_reg0 register bit field */
	union {
		volatile uint32_t cmp1_reg0;

		volatile struct {
			uint32_t cmp1_0 : 32; // 31:0
		} cmp1_reg0_bit;
	}; // 0x80

	/* PRU_IEP_cmp1_reg1 register bit field */
	union {
		volatile uint32_t cmp1_reg1;

		volatile struct {
			uint32_t cmp1_1 : 32; // 31:0
		} cmp1_reg1_bit;
	}; // 0x84

	/* PRU_IEP_cmp2_reg0 register bit field */
	union {
		volatile uint32_t cmp2_reg0;

		volatile struct {
			uint32_t cmp2_0 : 32; // 31:0
		} cmp2_reg0_bit;
	}; // 0x88

	/* PRU_IEP_cmp2_reg1 register bit field */
	union {
		volatile uint32_t cmp2_reg1;

		volatile struct {
			uint32_t cmp2_1 : 32; // 31:0
		} cmp2_reg1_bit;
	}; // 0x8c

	/* PRU_IEP_cmp3_reg0 register bit field */
	union {
		volatile uint32_t cmp3_reg0;

		volatile struct {
			uint32_t cmp3_0 : 32; // 31:0
		} cmp3_reg0_bit;
	}; // 0x90

	/* PRU_IEP_cmp3_reg1 register bit field */
	union {
		volatile uint32_t cmp3_reg1;

		volatile struct {
			uint32_t cmp3_1 : 32; // 31:0
		} cmp3_reg1_bit;
	}; // 0x94

	/* PRU_IEP_cmp4_reg0 register bit field */
	union {
		volatile uint32_t cmp4_reg0;

		volatile struct {
			uint32_t cmp4_0 : 32; // 31:0
		} cmp4_reg0_bit;
	}; // 0x98

	/* PRU_IEP_cmp4_reg1 register bit field */
	union {
		volatile uint32_t cmp4_reg1;

		volatile struct {
			uint32_t cmp4_1 : 32; // 31:0
		} cmp4_reg1_bit;
	}; // 0x9c

	/* PRU_IEP_cmp5_reg0 register bit field */
	union {
		volatile uint32_t cmp5_reg0;

		volatile struct {
			uint32_t cmp5_0 : 32; // 31:0
		} cmp5_reg0_bit;
	}; // 0xa0

	/* PRU_IEP_cmp5_reg1 register bit field */
	union {
		volatile uint32_t cmp5_reg1;

		volatile struct {
			uint32_t cmp5_1 : 32; // 31:0
		} cmp5_reg1_bit;
	}; // 0xa4

	/* PRU_IEP_cmp6_reg0 register bit field */
	union {
		volatile uint32_t cmp6_reg0;

		volatile struct {
			uint32_t cmp6_0 : 32; // 31:0
		} cmp6_reg0_bit;
	}; // 0xa8

	/* PRU_IEP_cmp6_reg1 register bit field */
	union {
		volatile uint32_t cmp6_reg1;

		volatile struct {
			uint32_t cmp6_1 : 32; // 31:0
		} cmp6_reg1_bit;
	}; // 0xac

	/* PRU_IEP_cmp7_reg0 register bit field */
	union {
		volatile uint32_t cmp7_reg0;

		volatile struct {
			uint32_t cmp7_0 : 32; // 31:0
		} cmp7_reg0_bit;
	}; // 0xb0

	/* PRU_IEP_cmp7_reg1 register bit field */
	union {
		volatile uint32_t cmp7_reg1;

		volatile struct {
			uint32_t cmp7_1 : 32; // 31:0
		} cmp7_reg1_bit;
	}; // 0xb4

	/* PRU_IEP_rxipg0_reg register bit field */
	union {
		volatile uint32_t rxipg0_reg;

		volatile struct {
			uint32_t rx_ipg0 : 16; // 15:0
			uint32_t rx_min_ipg0 : 16; // 31:16
		} rxipg0_reg_bit;
	}; // 0xb8

	/* PRU_IEP_rxipg1_reg register bit field */
	union {
		volatile uint32_t rxipg1_reg;

		volatile struct {
			uint32_t rx_ipg1 : 16; // 15:0
			uint32_t rx_min_ipg1 : 16; // 31:16
		} rxipg1_reg_bit;
	}; // 0xbc

	/* PRU_IEP_cmp8_reg0 register bit field */
	union {
		volatile uint32_t cmp8_reg0;

		volatile struct {
			uint32_t cmp8_0 : 32; // 31:0
		} cmp8_reg0_bit;
	}; // 0xc0

	/* PRU_IEP_cmp8_reg1 register bit field */
	union {
		volatile uint32_t cmp8_reg1;

		volatile struct {
			uint32_t cmp8_1 : 32; // 31:0
		} cmp8_reg1_bit;
	}; // 0xc4

	/* PRU_IEP_cmp9_reg0 register bit field */
	union {
		volatile uint32_t cmp9_reg0;

		volatile struct {
			uint32_t cmp9_0 : 32; // 31:0
		} cmp9_reg0_bit;
	}; // 0xc8

	/* PRU_IEP_cmp9_reg1 register bit field */
	union {
		volatile uint32_t cmp9_reg1;

		volatile struct {
			uint32_t cmp9_1 : 32; // 31:0
		} cmp9_reg1_bit;
	}; // 0xcc

	/* PRU_IEP_cmp10_reg0 register bit field */
	union {
		volatile uint32_t cmp10_reg0;

		volatile struct {
			uint32_t cmp10_0 : 32; // 31:0
		} cmp10_reg0_bit;
	}; // 0xd0

	/* PRU_IEP_cmp10_reg1 register bit field */
	union {
		volatile uint32_t cmp10_reg1;

		volatile struct {
			uint32_t cmp10_1 : 32; // 31:0
		} cmp10_reg1_bit;
	}; // 0xd4

	/* PRU_IEP_cmp11_reg0 register bit field */
	union {
		volatile uint32_t cmp11_reg0;

		volatile struct {
			uint32_t cmp11_0 : 32; // 31:0
		} cmp11_reg0_bit;
	}; // 0xd8

	/* PRU_IEP_cmp11_reg1 register bit field */
	union {
		volatile uint32_t cmp11_reg1;

		volatile struct {
			uint32_t cmp11_1 : 32; // 31:0
		} cmp11_reg1_bit;
	}; // 0xdc

	/* PRU_IEP_cmp12_reg0 register bit field */
	union {
		volatile uint32_t cmp12_reg0;

		volatile struct {
			uint32_t cmp12_0 : 32; // 31:0
		} cmp12_reg0_bit;
	}; // 0xe0

	/* PRU_IEP_cmp12_reg1 register bit field */
	union {
		volatile uint32_t cmp12_reg1;

		volatile struct {
			uint32_t cmp12_1 : 32; // 31:0
		} cmp12_reg1_bit;
	}; // 0xe4

	/* PRU_IEP_cmp13_reg0 register bit field */
	union {
		volatile uint32_t cmp13_reg0;

		volatile struct {
			uint32_t cmp13_0 : 32; // 31:0
		} cmp13_reg0_bit;
	}; // 0xe8

	/* PRU_IEP_cmp13_reg1 register bit field */
	union {
		volatile uint32_t cmp13_reg1;

		volatile struct {
			uint32_t cmp13_1 : 32; // 31:0
		} cmp13_reg1_bit;
	}; // 0xec

	/* PRU_IEP_cmp14_reg0 register bit field */
	union {
		volatile uint32_t cmp14_reg0;

		volatile struct {
			uint32_t cmp14_0 : 32; // 31:0
		} cmp14_reg0_bit;
	}; // 0xf0

	/* PRU_IEP_cmp14_reg1 register bit field */
	union {
		volatile uint32_t cmp14_reg1;

		volatile struct {
			uint32_t cmp14_1 : 32; // 31:0
		} cmp14_reg1_bit;
	}; // 0xf4

	/* PRU_IEP_cmp15_reg0 register bit field */
	union {
		volatile uint32_t cmp15_reg0;

		volatile struct {
			uint32_t cmp15_0 : 32; // 31:0
		} cmp15_reg0_bit;
	}; // 0xf8

	/* PRU_IEP_cmp15_reg1 register bit field */
	union {
		volatile uint32_t cmp15_reg1;

		volatile struct {
			uint32_t cmp15_1 : 32; // 31:0
		} cmp15_reg1_bit;
	}; // 0xfc
} iep;

// start the extended structure here
typedef struct {

	/* PRU_IEP_count_reset_val_reg0 register bit field */
	union {
		volatile uint32_t count_reset_val_reg0;

		volatile struct {
			uint32_t reset_val_0 : 32; // 31:0
		} count_reset_val_reg0_bit;
	}; // 0x100

	/* PRU_IEP_count_reset_val_reg1 register bit field */
	union {
		volatile uint32_t count_reset_val_reg1;

		volatile struct {
			uint32_t reset_val_1 : 32; // 31:0
		} count_reset_val_reg1_bit;
	}; // 0x104

	/* PRU_IEP_pwm_reg register bit field */
	union {
		volatile uint32_t pwm_reg;

		volatile struct {
			uint32_t pwm0_rst_cnt_en : 1; // 0
			uint32_t pwm0_hit : 1; // 1
			uint32_t pwm3_rst_cnt_en : 1; // 2
			uint32_t pwm3_hit : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} pwm_reg_bit;
	}; // 0x108

	/* PRU_IEP_capr0_bi_reg0 register bit field */
	union {
		volatile uint32_t capr0_bi_reg0;

		volatile struct {
			uint32_t capr0_0 : 32; // 31:0
		} capr0_bi_reg0_bit;
	}; // 0x10c

	/* PRU_IEP_capr0_bi_reg1 register bit field */
	union {
		volatile uint32_t capr0_bi_reg1;

		volatile struct {
			uint32_t capr0_1 : 32; // 31:0
		} capr0_bi_reg1_bit;
	}; // 0x110

	/* PRU_IEP_capr1_bi_reg0 register bit field */
	union {
		volatile uint32_t capr1_bi_reg0;

		volatile struct {
			uint32_t capr1_0 : 32; // 31:0
		} capr1_bi_reg0_bit;
	}; // 0x114

	/* PRU_IEP_capr1_bi_reg1 register bit field */
	union {
		volatile uint32_t capr1_bi_reg1;

		volatile struct {
			uint32_t capr1_1 : 32; // 31:0
		} capr1_bi_reg1_bit;
	}; // 0x118

	/* PRU_IEP_capr2_bi_reg0 register bit field */
	union {
		volatile uint32_t capr2_bi_reg0;

		volatile struct {
			uint32_t capr2_0 : 32; // 31:0
		} capr2_bi_reg0_bit;
	}; // 0x11c

	/* PRU_IEP_capr2_bi_reg1 register bit field */
	union {
		volatile uint32_t capr2_bi_reg1;

		volatile struct {
			uint32_t capr2_1 : 32; // 31:0
		} capr2_bi_reg1_bit;
	}; // 0x120

	/* PRU_IEP_capr3_bi_reg0 register bit field */
	union {
		volatile uint32_t capr3_bi_reg0;

		volatile struct {
			uint32_t capr3_0 : 32; // 31:0
		} capr3_bi_reg0_bit;
	}; // 0x124

	/* PRU_IEP_capr3_bi_reg1 register bit field */
	union {
		volatile uint32_t capr3_bi_reg1;

		volatile struct {
			uint32_t capr3_1 : 32; // 31:0
		} capr3_bi_reg1_bit;
	}; // 0x128

	/* PRU_IEP_capr4_bi_reg0 register bit field */
	union {
		volatile uint32_t capr4_bi_reg0;

		volatile struct {
			uint32_t capr4_0 : 32; // 31:0
		} capr4_bi_reg0_bit;
	}; // 0x12c

	/* PRU_IEP_capr4_bi_reg1 register bit field */
	union {
		volatile uint32_t capr4_bi_reg1;

		volatile struct {
			uint32_t capr4_1 : 32; // 31:0
		} capr4_bi_reg1_bit;
	}; // 0x130

	/* PRU_IEP_capr5_bi_reg0 register bit field */
	union {
		volatile uint32_t capr5_bi_reg0;

		volatile struct {
			uint32_t capr5_0 : 32; // 31:0
		} capr5_bi_reg0_bit;
	}; // 0x134

	/* PRU_IEP_capr5_bi_reg1 register bit field */
	union {
		volatile uint32_t capr5_bi_reg1;

		volatile struct {
			uint32_t capr5_1 : 32; // 31:0
		} capr5_bi_reg1_bit;
	}; // 0x138

	/* PRU_IEP_capr6_bi_reg0 register bit field */
	union {
		volatile uint32_t capr6_bi_reg0;

		volatile struct {
			uint32_t capr6_0 : 32; // 31:0
		} capr6_bi_reg0_bit;
	}; // 0x13c

	/* PRU_IEP_capr6_bi_reg1 register bit field */
	union {
		volatile uint32_t capr6_bi_reg1;

		volatile struct {
			uint32_t capr6_1 : 32; // 31:0
		} capr6_bi_reg1_bit;
	}; // 0x140

	/* PRU_IEP_capf6_bi_reg0 register bit field */
	union {
		volatile uint32_t capf6_bi_reg0;

		volatile struct {
			uint32_t capf6_0 : 32; // 31:0
		} capf6_bi_reg0_bit;
	}; // 0x144

	/* PRU_IEP_capf6_bi_reg1 register bit field */
	union {
		volatile uint32_t capf6_bi_reg1;

		volatile struct {
			uint32_t capf6_1 : 32; // 31:0
		} capf6_bi_reg1_bit;
	}; // 0x148

	/* PRU_IEP_capr7_bi_reg0 register bit field */
	union {
		volatile uint32_t capr7_bi_reg0;

		volatile struct {
			uint32_t capr7_0 : 32; // 31:0
		} capr7_bi_reg0_bit;
	}; // 0x14c

	/* PRU_IEP_capr7_bi_reg1 register bit field */
	union {
		volatile uint32_t capr7_bi_reg1;

		volatile struct {
			uint32_t capr7_1 : 32; // 31:0
		} capr7_bi_reg1_bit;
	}; // 0x150

	/* PRU_IEP_capf7_bi_reg0 register bit field */
	union {
		volatile uint32_t capf7_bi_reg0;

		volatile struct {
			uint32_t capf7_0 : 32; // 31:0
		} capf7_bi_reg0_bit;
	}; // 0x154

	/* PRU_IEP_capf7_bi_reg1 register bit field */
	union {
		volatile uint32_t capf7_bi_reg1;

		volatile struct {
			uint32_t capf7_1 : 32; // 31:0
		} capf7_bi_reg1_bit;
	}; // 0x158

	uint8_t rsvd15c[36]; // 0x15c - 0x17f

	/* PRU_IEP_sync_ctrl_reg register bit field */
	union {
		volatile uint32_t sync_ctrl_reg;

		volatile struct {
			uint32_t sync_en : 1; // 0
			uint32_t sync0_en : 1; // 1
			uint32_t sync1_en : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t sync0_ack_en : 1; // 4
			uint32_t sync0_cyclic_en : 1; // 5
			uint32_t sync1_ack_en : 1; // 6
			uint32_t sync1_cyclic_en : 1; // 7
			uint32_t sync1_ind_en : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} sync_ctrl_reg_bit;
	}; // 0x180

	/* PRU_IEP_sync_first_stat_reg register bit field */
	union {
		volatile uint32_t sync_first_stat_reg;

		volatile struct {
			uint32_t first_sync0 : 1; // 0
			uint32_t first_sync1 : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} sync_first_stat_reg_bit;
	}; // 0x184

	/* PRU_IEP_sync0_stat_reg register bit field */
	union {
		volatile uint32_t sync0_stat_reg;

		volatile struct {
			uint32_t sync0_pend : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} sync0_stat_reg_bit;
	}; // 0x188

	/* PRU_IEP_sync1_stat_reg register bit field */
	union {
		volatile uint32_t sync1_stat_reg;

		volatile struct {
			uint32_t sync1_pend : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} sync1_stat_reg_bit;
	}; // 0x18c

	/* PRU_IEP_sync_pwidth_reg register bit field */
	union {
		volatile uint32_t sync_pwidth_reg;

		volatile struct {
			uint32_t sync_hpw : 32; // 31:0
		} sync_pwidth_reg_bit;
	}; // 0x190

	/* PRU_IEP_sync0_period_reg register bit field */
	union {
		volatile uint32_t sync0_period_reg;

		volatile struct {
			uint32_t sync0_period : 32; // 31:0
		} sync0_period_reg_bit;
	}; // 0x194

	/* PRU_IEP_sync1_delay_reg register bit field */
	union {
		volatile uint32_t sync1_delay_reg;

		volatile struct {
			uint32_t sync1_delay : 32; // 31:0
		} sync1_delay_reg_bit;
	}; // 0x198

	/* PRU_IEP_sync_start_reg register bit field */
	union {
		volatile uint32_t sync_start_reg;

		volatile struct {
			uint32_t sync_start : 32; // 31:0
		} sync_start_reg_bit;
	}; // 0x19c

	uint8_t rsvd1a0[96]; // 0x1a0 - 0x1ff

	/* PRU_IEP_wd_prediv_reg register bit field */
	union {
		volatile uint32_t wd_prediv_reg;

		volatile struct {
			uint32_t pre_div : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} wd_prediv_reg_bit;
	}; // 0x200

	/* PRU_IEP_pdi_wd_tim_reg register bit field */
	union {
		volatile uint32_t pdi_wd_tim_reg;

		volatile struct {
			uint32_t pdi_wd_time : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} pdi_wd_tim_reg_bit;
	}; // 0x204

	/* PRU_IEP_pd_wd_tim_reg register bit field */
	union {
		volatile uint32_t pd_wd_tim_reg;

		volatile struct {
			uint32_t pd_wd_time : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} pd_wd_tim_reg_bit;
	}; // 0x208

	/* PRU_IEP_wd_status_reg register bit field */
	union {
		volatile uint32_t wd_status_reg;

		volatile struct {
			uint32_t pd_wd_stat : 1; // 0
			uint32_t rsvd1 : 15; // 15:1
			uint32_t pdi_wd_stat : 1; // 16
			uint32_t rsvd17 : 15; // 31:17
		} wd_status_reg_bit;
	}; // 0x20c

	/* PRU_IEP_wd_exp_cnt_reg register bit field */
	union {
		volatile uint32_t wd_exp_cnt_reg;

		volatile struct {
			uint32_t pdi_exp_cnt : 8; // 7:0
			uint32_t pd_exp_cnt : 8; // 15:8
			uint32_t rsvd16 : 16; // 31:16
		} wd_exp_cnt_reg_bit;
	}; // 0x210

	/* PRU_IEP_wd_ctrl_reg register bit field */
	union {
		volatile uint32_t wd_ctrl_reg;

		volatile struct {
			uint32_t pd_wd_en : 1; // 0
			uint32_t rsvd1 : 15; // 15:1
			uint32_t pdi_wd_en : 1; // 16
			uint32_t rsvd17 : 15; // 31:17
		} wd_ctrl_reg_bit;
	}; // 0x214

	uint8_t rsvd218[232]; // 0x218 - 0x2ff

	/* PRU_IEP_digio_ctrl_reg register bit field */
	union {
		volatile uint32_t digio_ctrl_reg;

		volatile struct {
			uint32_t outvalid_pol : 1; // 0
			uint32_t outvalid_mode : 1; // 1
			uint32_t bidi_mode : 1; // 2
			uint32_t wd_mode : 1; // 3
			uint32_t in_mode : 2; // 5:4
			uint32_t out_mode : 2; // 7:6
			uint32_t rsvd8 : 24; // 31:8
		} digio_ctrl_reg_bit;
	}; // 0x300

	/* PRU_IEP_digio_status_reg register bit field */
	union {
		volatile uint32_t digio_status_reg;

		volatile struct {
			uint32_t digio_stat : 32; // 31:0
		} digio_status_reg_bit;
	}; // 0x304

	/* PRU_IEP_digio_data_in_reg register bit field */
	union {
		volatile uint32_t digio_data_in_reg;

		volatile struct {
			uint32_t data_in : 32; // 31:0
		} digio_data_in_reg_bit;
	}; // 0x308

	/* PRU_IEP_digio_data_in_raw_reg register bit field */
	union {
		volatile uint32_t digio_data_in_raw_reg;

		volatile struct {
			uint32_t data_in_raw : 32; // 31:0
		} digio_data_in_raw_reg_bit;
	}; // 0x30c

	/* PRU_IEP_digio_data_out_reg register bit field */
	union {
		volatile uint32_t digio_data_out_reg;

		volatile struct {
			uint32_t data_out : 32; // 31:0
		} digio_data_out_reg_bit;
	}; // 0x310

	/* PRU_IEP_digio_data_out_en_reg register bit field */
	union {
		volatile uint32_t digio_data_out_en_reg;

		volatile struct {
			uint32_t data_out_en : 32; // 31:0
		} digio_data_out_en_reg_bit;
	}; // 0x314

	/* PRU_IEP_digio_exp_reg register bit field */
	union {
		volatile uint32_t digio_exp_reg;

		volatile struct {
			uint32_t sw_data_out_up : 1; // 0
			uint32_t outvalid_ovr_en : 1; // 1
			uint32_t sw_outvalid : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t outvalid_dly : 4; // 7:4
			uint32_t sof_dly : 4; // 11:8
			uint32_t sof_sel : 1; // 12
			uint32_t eof_sel : 1; // 13
			uint32_t rsvd14 : 18; // 31:14
		} digio_exp_reg_bit;
	}; // 0x318

} iepExt;

volatile __far iep CT_IEP0 __attribute__((cregister("PRU_IEP0", near), peripheral));
volatile __far iepExt CT_IEP0_EXT __attribute__((cregister("PRU_IEP0_EXT", far), peripheral));
volatile __far iep CT_IEP1 __attribute__((cregister("PRU_IEP1", near), peripheral));
volatile __far iepExt CT_IEP1_EXT __attribute__((cregister("PRU_IEP1_EXT", far), peripheral));

#endif /* _PRU_IEP_H_ */

