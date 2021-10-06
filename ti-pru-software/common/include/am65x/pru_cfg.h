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

#ifndef _PRU_CFG_H_
#define _PRU_CFG_H_

/* PRU CFG register set */
typedef struct {

	/* PRU_CFG_pid_reg register bit field */
	union {
		volatile uint32_t pid_reg;

		volatile struct {
			uint32_t icss_idver : 32; // 31:0
		} pid_reg_bit;
	}; // 0x0

	/* PRU_CFG_hwdis_reg register bit field */
	union {
		volatile uint32_t hwdis_reg;

		volatile struct {
			uint32_t hwdis : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} hwdis_reg_bit;
	}; // 0x4

	/* PRU_CFG_gpcfg0_reg register bit field */
	union {
		volatile uint32_t gpcfg0_reg;

		volatile struct {
			uint32_t pru0_gpi_mode : 2; // 1:0
			uint32_t pru0_gpi_clk_mode : 1; // 2
			uint32_t pru0_gpi_div0 : 5; // 7:3
			uint32_t pru0_gpi_div1 : 5; // 12:8
			uint32_t pru0_gpi_sb : 1; // 13
			uint32_t pru0_gpo_mode : 1; // 14
			uint32_t pru0_gpo_div0 : 5; // 19:15
			uint32_t pru0_gpo_div1 : 5; // 24:20
			uint32_t pru0_gpo_sh1_sel : 1; // 25
			uint32_t pr1_pru0_gp_mux_sel : 4; // 29:26
			uint32_t rsvd30 : 2; // 31:30
		} gpcfg0_reg_bit;
	}; // 0x8

	/* PRU_CFG_gpcfg1_reg register bit field */
	union {
		volatile uint32_t gpcfg1_reg;

		volatile struct {
			uint32_t pru1_gpi_mode : 2; // 1:0
			uint32_t pru1_gpi_clk_mode : 1; // 2
			uint32_t pru1_gpi_div0 : 5; // 7:3
			uint32_t pru1_gpi_div1 : 5; // 12:8
			uint32_t pru1_gpi_sb : 1; // 13
			uint32_t pru1_gpo_mode : 1; // 14
			uint32_t pru1_gpo_div0 : 5; // 19:15
			uint32_t pru1_gpo_div1 : 5; // 24:20
			uint32_t pru1_gpo_sh1_sel : 1; // 25
			uint32_t pr1_pru1_gp_mux_sel : 4; // 29:26
			uint32_t rsvd30 : 2; // 31:30
		} gpcfg1_reg_bit;
	}; // 0xc

	/* PRU_CFG_cgr_reg register bit field */
	union {
		volatile uint32_t cgr_reg;

		volatile struct {
			uint32_t rsvd0 : 6; // 5:0
			uint32_t intc_clk_stop_req : 1; // 6
			uint32_t intc_clk_stop_ack : 1; // 7
			uint32_t intc_clk_en : 1; // 8
			uint32_t uart_clk_stop_req : 1; // 9
			uint32_t uart_clk_stop_ack : 1; // 10
			uint32_t uart_clk_en : 1; // 11
			uint32_t ecap_clk_stop_req : 1; // 12
			uint32_t ecap_clk_stop_ack : 1; // 13
			uint32_t ecap_clk_en : 1; // 14
			uint32_t iep_clk_stop_req : 1; // 15
			uint32_t iep_clk_stop_ack : 1; // 16
			uint32_t iep_clk_en : 1; // 17
			uint32_t rsvd18 : 11; // 28:18
			uint32_t icss_pwr_idle : 1; // 29
			uint32_t icss_stop_req : 1; // 30
			uint32_t icss_stop_ack : 1; // 31
		} cgr_reg_bit;
	}; // 0x10

	/* PRU_CFG_gpecfg0_reg register bit field */
	union {
		volatile uint32_t gpecfg0_reg;

		volatile struct {
			uint32_t pru0_gpi_sb_p : 1; // 0
			uint32_t pru0_gpi_shift_en : 1; // 1
			uint32_t rsvd2 : 2; // 3:2
			uint32_t pru0_gpo_shift_swap : 1; // 4
			uint32_t pru0_gpo_shift_clk_free : 1; // 5
			uint32_t pru0_gpo_shift_gp_en : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t pru0_gpo_shift_cnt : 8; // 15:8
			uint32_t pru0_gpo_shift_clk_high : 1; // 16
			uint32_t pru0_gpo_shift_clk_done : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} gpecfg0_reg_bit;
	}; // 0x14

	/* PRU_CFG_gpecfg1_reg register bit field */
	union {
		volatile uint32_t gpecfg1_reg;

		volatile struct {
			uint32_t pru1_gpi_sb_p : 1; // 0
			uint32_t pru1_gpi_shift_en : 1; // 1
			uint32_t rsvd2 : 2; // 3:2
			uint32_t pru1_gpo_shift_swap : 1; // 4
			uint32_t pru1_gpo_shift_clk_free : 1; // 5
			uint32_t pru1_gpo_shift_gp_en : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t pru1_gpo_shift_cnt : 8; // 15:8
			uint32_t pru1_gpo_shift_clk_high : 1; // 16
			uint32_t pru1_gpo_shift_clk_done : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} gpecfg1_reg_bit;
	}; // 0x18

	uint8_t rsvd1c[16]; // 0x1c - 0x2b

	/* PRU_CFG_mii_rt_reg register bit field */
	union {
		volatile uint32_t mii_rt_reg;

		volatile struct {
			uint32_t mii_rt_event_en : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} mii_rt_reg_bit;
	}; // 0x2c

	/* PRU_CFG_iepclk_reg register bit field */
	union {
		volatile uint32_t iepclk_reg;

		volatile struct {
			uint32_t iep_ocp_clk_en : 1; // 0
			uint32_t iep1_slv_en : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} iepclk_reg_bit;
	}; // 0x30

	/* PRU_CFG_spp_reg register bit field */
	union {
		volatile uint32_t spp_reg;

		volatile struct {
			uint32_t pru1_pad_hp_en : 1; // 0
			uint32_t xfr_shift_en : 1; // 1
			uint32_t xfr_byte_shift_en : 1; // 2
			uint32_t rtu_xfr_shift_en : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} spp_reg_bit;
	}; // 0x34

	uint8_t rsvd38[4]; // 0x38 - 0x3b

	/* PRU_CFG_core_sync_reg register bit field */
	union {
		volatile uint32_t core_sync_reg;

		volatile struct {
			uint32_t core_vbusp_sync_en : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} core_sync_reg_bit;
	}; // 0x3c

	/* PRU_CFG_sa_mx_reg register bit field */
	union {
		volatile uint32_t sa_mx_reg;

		volatile struct {
			uint32_t sa_mux_sel : 8; // 7:0
			uint32_t pwm0_remap_en : 2; // 9:8
			uint32_t pwm3_remap_en : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} sa_mx_reg_bit;
	}; // 0x40

	/* PRU_CFG_pru0_sd_clk_div_reg register bit field */
	union {
		volatile uint32_t pru0_sd_clk_div_reg;

		volatile struct {
			uint32_t pru0_sd_divfactor : 4; // 3:0
			uint32_t pru0_sd_divfactor_frac : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} pru0_sd_clk_div_reg_bit;
	}; // 0x44

	/* PRU_CFG_pru0_sd_clk_sel_reg0 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg0;

		volatile struct {
			uint32_t pru0_sd_clk_sel0 : 2; // 1:0
			uint32_t pru0_sd_clk_inv0 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel0 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_0 : 5; // 15:11
			uint32_t pru0_fd_zero_min_0 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_0 : 5; // 21:17
			uint32_t pru0_fd_zero_max_0 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg0_bit;
	}; // 0x48

	/* PRU_CFG_pru0_sd_sample_size_reg0 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg0;

		volatile struct {
			uint32_t pru0_sd_sample_size0 : 8; // 7:0
			uint32_t pru0_fd_window_size_0 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_0 : 5; // 15:11
			uint32_t pru0_fd_one_min_0 : 1; // 16
			uint32_t pru0_fd_one_max_limit_0 : 5; // 21:17
			uint32_t pru0_fd_one_max_0 : 1; // 22
			uint32_t pru0_fd_en_0 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg0_bit;
	}; // 0x4c

	/* PRU_CFG_pru0_sd_clk_sel_reg1 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg1;

		volatile struct {
			uint32_t pru0_sd_clk_sel1 : 2; // 1:0
			uint32_t pru0_sd_clk_inv1 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel1 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_1 : 5; // 15:11
			uint32_t pru0_fd_zero_min_1 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_1 : 5; // 21:17
			uint32_t pru0_fd_zero_max_1 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg1_bit;
	}; // 0x50

	/* PRU_CFG_pru0_sd_sample_size_reg1 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg1;

		volatile struct {
			uint32_t pru0_sd_sample_size1 : 8; // 7:0
			uint32_t pru0_fd_window_size_1 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_1 : 5; // 15:11
			uint32_t pru0_fd_one_min_1 : 1; // 16
			uint32_t pru0_fd_one_max_limit_1 : 5; // 21:17
			uint32_t pru0_fd_one_max_1 : 1; // 22
			uint32_t pru0_fd_en_1 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg1_bit;
	}; // 0x54

	/* PRU_CFG_pru0_sd_clk_sel_reg2 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg2;

		volatile struct {
			uint32_t pru0_sd_clk_sel2 : 2; // 1:0
			uint32_t pru0_sd_clk_inv2 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel2 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_2 : 5; // 15:11
			uint32_t pru0_fd_zero_min_2 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_2 : 5; // 21:17
			uint32_t pru0_fd_zero_max_2 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg2_bit;
	}; // 0x58

	/* PRU_CFG_pru0_sd_sample_size_reg2 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg2;

		volatile struct {
			uint32_t pru0_sd_sample_size2 : 8; // 7:0
			uint32_t pru0_fd_window_size_2 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_2 : 5; // 15:11
			uint32_t pru0_fd_one_min_2 : 1; // 16
			uint32_t pru0_fd_one_max_limit_2 : 5; // 21:17
			uint32_t pru0_fd_one_max_2 : 1; // 22
			uint32_t pru0_fd_en_2 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg2_bit;
	}; // 0x5c

	/* PRU_CFG_pru0_sd_clk_sel_reg3 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg3;

		volatile struct {
			uint32_t pru0_sd_clk_sel3 : 2; // 1:0
			uint32_t pru0_sd_clk_inv3 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel3 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_3 : 5; // 15:11
			uint32_t pru0_fd_zero_min_3 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_3 : 5; // 21:17
			uint32_t pru0_fd_zero_max_3 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg3_bit;
	}; // 0x60

	/* PRU_CFG_pru0_sd_sample_size_reg3 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg3;

		volatile struct {
			uint32_t pru0_sd_sample_size3 : 8; // 7:0
			uint32_t pru0_fd_window_size_3 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_3 : 5; // 15:11
			uint32_t pru0_fd_one_min_3 : 1; // 16
			uint32_t pru0_fd_one_max_limit_3 : 5; // 21:17
			uint32_t pru0_fd_one_max_3 : 1; // 22
			uint32_t pru0_fd_en_3 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg3_bit;
	}; // 0x64

	/* PRU_CFG_pru0_sd_clk_sel_reg4 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg4;

		volatile struct {
			uint32_t pru0_sd_clk_sel4 : 2; // 1:0
			uint32_t pru0_sd_clk_inv4 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel4 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_4 : 5; // 15:11
			uint32_t pru0_fd_zero_min_4 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_4 : 5; // 21:17
			uint32_t pru0_fd_zero_max_4 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg4_bit;
	}; // 0x68

	/* PRU_CFG_pru0_sd_sample_size_reg4 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg4;

		volatile struct {
			uint32_t pru0_sd_sample_size4 : 8; // 7:0
			uint32_t pru0_fd_window_size_4 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_4 : 5; // 15:11
			uint32_t pru0_fd_one_min_4 : 1; // 16
			uint32_t pru0_fd_one_max_limit_4 : 5; // 21:17
			uint32_t pru0_fd_one_max_4 : 1; // 22
			uint32_t pru0_fd_en_4 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg4_bit;
	}; // 0x6c

	/* PRU_CFG_pru0_sd_clk_sel_reg5 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg5;

		volatile struct {
			uint32_t pru0_sd_clk_sel5 : 2; // 1:0
			uint32_t pru0_sd_clk_inv5 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel5 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_5 : 5; // 15:11
			uint32_t pru0_fd_zero_min_5 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_5 : 5; // 21:17
			uint32_t pru0_fd_zero_max_5 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg5_bit;
	}; // 0x70

	/* PRU_CFG_pru0_sd_sample_size_reg5 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg5;

		volatile struct {
			uint32_t pru0_sd_sample_size5 : 8; // 7:0
			uint32_t pru0_fd_window_size_5 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_5 : 5; // 15:11
			uint32_t pru0_fd_one_min_5 : 1; // 16
			uint32_t pru0_fd_one_max_limit_5 : 5; // 21:17
			uint32_t pru0_fd_one_max_5 : 1; // 22
			uint32_t pru0_fd_en_5 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg5_bit;
	}; // 0x74

	/* PRU_CFG_pru0_sd_clk_sel_reg6 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg6;

		volatile struct {
			uint32_t pru0_sd_clk_sel6 : 2; // 1:0
			uint32_t pru0_sd_clk_inv6 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel6 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_6 : 5; // 15:11
			uint32_t pru0_fd_zero_min_6 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_6 : 5; // 21:17
			uint32_t pru0_fd_zero_max_6 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg6_bit;
	}; // 0x78

	/* PRU_CFG_pru0_sd_sample_size_reg6 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg6;

		volatile struct {
			uint32_t pru0_sd_sample_size6 : 8; // 7:0
			uint32_t pru0_fd_window_size_6 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_6 : 5; // 15:11
			uint32_t pru0_fd_one_min_6 : 1; // 16
			uint32_t pru0_fd_one_max_limit_6 : 5; // 21:17
			uint32_t pru0_fd_one_max_6 : 1; // 22
			uint32_t pru0_fd_en_6 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg6_bit;
	}; // 0x7c

	/* PRU_CFG_pru0_sd_clk_sel_reg7 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg7;

		volatile struct {
			uint32_t pru0_sd_clk_sel7 : 2; // 1:0
			uint32_t pru0_sd_clk_inv7 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel7 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_7 : 5; // 15:11
			uint32_t pru0_fd_zero_min_7 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_7 : 5; // 21:17
			uint32_t pru0_fd_zero_max_7 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg7_bit;
	}; // 0x80

	/* PRU_CFG_pru0_sd_sample_size_reg7 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg7;

		volatile struct {
			uint32_t pru0_sd_sample_size7 : 8; // 7:0
			uint32_t pru0_fd_window_size_7 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_7 : 5; // 15:11
			uint32_t pru0_fd_one_min_7 : 1; // 16
			uint32_t pru0_fd_one_max_limit_7 : 5; // 21:17
			uint32_t pru0_fd_one_max_7 : 1; // 22
			uint32_t pru0_fd_en_7 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg7_bit;
	}; // 0x84

	/* PRU_CFG_pru0_sd_clk_sel_reg8 register bit field */
	union {
		volatile uint32_t pru0_sd_clk_sel_reg8;

		volatile struct {
			uint32_t pru0_sd_clk_sel8 : 2; // 1:0
			uint32_t pru0_sd_clk_inv8 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru0_sd_acc_sel8 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru0_fd_zero_min_limit_8 : 5; // 15:11
			uint32_t pru0_fd_zero_min_8 : 1; // 16
			uint32_t pru0_fd_zero_max_limit_8 : 5; // 21:17
			uint32_t pru0_fd_zero_max_8 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru0_sd_clk_sel_reg8_bit;
	}; // 0x88

	/* PRU_CFG_pru0_sd_sample_size_reg8 register bit field */
	union {
		volatile uint32_t pru0_sd_sample_size_reg8;

		volatile struct {
			uint32_t pru0_sd_sample_size8 : 8; // 7:0
			uint32_t pru0_fd_window_size_8 : 3; // 10:8
			uint32_t pru0_fd_one_min_limit_8 : 5; // 15:11
			uint32_t pru0_fd_one_min_8 : 1; // 16
			uint32_t pru0_fd_one_max_limit_8 : 5; // 21:17
			uint32_t pru0_fd_one_max_8 : 1; // 22
			uint32_t pru0_fd_en_8 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru0_sd_sample_size_reg8_bit;
	}; // 0x8c

	/* PRU_CFG_pru1_sd_clk_div_reg register bit field */
	union {
		volatile uint32_t pru1_sd_clk_div_reg;

		volatile struct {
			uint32_t pru1_sd_divfactor : 4; // 3:0
			uint32_t pru1_sd_divfactor_frac : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} pru1_sd_clk_div_reg_bit;
	}; // 0x90

	/* PRU_CFG_pru1_sd_clk_sel_reg0 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg0;

		volatile struct {
			uint32_t pru1_sd_clk_sel0 : 2; // 1:0
			uint32_t pru1_sd_clk_inv0 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel0 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_0 : 5; // 15:11
			uint32_t pru1_fd_zero_min_0 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_0 : 5; // 21:17
			uint32_t pru1_fd_zero_max_0 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg0_bit;
	}; // 0x94

	/* PRU_CFG_pru1_sd_sample_size_reg0 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg0;

		volatile struct {
			uint32_t pru1_sd_sample_size0 : 8; // 7:0
			uint32_t pru1_fd_window_size_0 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_0 : 5; // 15:11
			uint32_t pru1_fd_one_min_0 : 1; // 16
			uint32_t pru1_fd_one_max_limit_0 : 5; // 21:17
			uint32_t pru1_fd_one_max_0 : 1; // 22
			uint32_t pru1_fd_en_0 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg0_bit;
	}; // 0x98

	/* PRU_CFG_pru1_sd_clk_sel_reg1 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg1;

		volatile struct {
			uint32_t pru1_sd_clk_sel1 : 2; // 1:0
			uint32_t pru1_sd_clk_inv1 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel1 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_1 : 5; // 15:11
			uint32_t pru1_fd_zero_min_1 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_1 : 5; // 21:17
			uint32_t pru1_fd_zero_max_1 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg1_bit;
	}; // 0x9c

	/* PRU_CFG_pru1_sd_sample_size_reg1 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg1;

		volatile struct {
			uint32_t pru1_sd_sample_size1 : 8; // 7:0
			uint32_t pru1_fd_window_size_1 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_1 : 5; // 15:11
			uint32_t pru1_fd_one_min_1 : 1; // 16
			uint32_t pru1_fd_one_max_limit_1 : 5; // 21:17
			uint32_t pru1_fd_one_max_1 : 1; // 22
			uint32_t pru1_fd_en_1 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg1_bit;
	}; // 0xa0

	/* PRU_CFG_pru1_sd_clk_sel_reg2 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg2;

		volatile struct {
			uint32_t pru1_sd_clk_sel2 : 2; // 1:0
			uint32_t pru1_sd_clk_inv2 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel2 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_2 : 5; // 15:11
			uint32_t pru1_fd_zero_min_2 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_2 : 5; // 21:17
			uint32_t pru1_fd_zero_max_2 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg2_bit;
	}; // 0xa4

	/* PRU_CFG_pru1_sd_sample_size_reg2 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg2;

		volatile struct {
			uint32_t pru1_sd_sample_size2 : 8; // 7:0
			uint32_t pru1_fd_window_size_2 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_2 : 5; // 15:11
			uint32_t pru1_fd_one_min_2 : 1; // 16
			uint32_t pru1_fd_one_max_limit_2 : 5; // 21:17
			uint32_t pru1_fd_one_max_2 : 1; // 22
			uint32_t pru1_fd_en_2 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg2_bit;
	}; // 0xa8

	/* PRU_CFG_pru1_sd_clk_sel_reg3 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg3;

		volatile struct {
			uint32_t pru1_sd_clk_sel3 : 2; // 1:0
			uint32_t pru1_sd_clk_inv3 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel3 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_3 : 5; // 15:11
			uint32_t pru1_fd_zero_min_3 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_3 : 5; // 21:17
			uint32_t pru1_fd_zero_max_3 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg3_bit;
	}; // 0xac

	/* PRU_CFG_pru1_sd_sample_size_reg3 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg3;

		volatile struct {
			uint32_t pru1_sd_sample_size3 : 8; // 7:0
			uint32_t pru1_fd_window_size_3 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_3 : 5; // 15:11
			uint32_t pru1_fd_one_min_3 : 1; // 16
			uint32_t pru1_fd_one_max_limit_3 : 5; // 21:17
			uint32_t pru1_fd_one_max_3 : 1; // 22
			uint32_t pru1_fd_en_3 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg3_bit;
	}; // 0xb0

	/* PRU_CFG_pru1_sd_clk_sel_reg4 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg4;

		volatile struct {
			uint32_t pru1_sd_clk_sel4 : 2; // 1:0
			uint32_t pru1_sd_clk_inv4 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel4 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_4 : 5; // 15:11
			uint32_t pru1_fd_zero_min_4 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_4 : 5; // 21:17
			uint32_t pru1_fd_zero_max_4 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg4_bit;
	}; // 0xb4

	/* PRU_CFG_pru1_sd_sample_size_reg4 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg4;

		volatile struct {
			uint32_t pru1_sd_sample_size4 : 8; // 7:0
			uint32_t pru1_fd_window_size_4 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_4 : 5; // 15:11
			uint32_t pru1_fd_one_min_4 : 1; // 16
			uint32_t pru1_fd_one_max_limit_4 : 5; // 21:17
			uint32_t pru1_fd_one_max_4 : 1; // 22
			uint32_t pru1_fd_en_4 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg4_bit;
	}; // 0xb8

	/* PRU_CFG_pru1_sd_clk_sel_reg5 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg5;

		volatile struct {
			uint32_t pru1_sd_clk_sel5 : 2; // 1:0
			uint32_t pru1_sd_clk_inv5 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel5 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_5 : 5; // 15:11
			uint32_t pru1_fd_zero_min_5 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_5 : 5; // 21:17
			uint32_t pru1_fd_zero_max_5 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg5_bit;
	}; // 0xbc

	/* PRU_CFG_pru1_sd_sample_size_reg5 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg5;

		volatile struct {
			uint32_t pru1_sd_sample_size5 : 8; // 7:0
			uint32_t pru1_fd_window_size_5 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_5 : 5; // 15:11
			uint32_t pru1_fd_one_min_5 : 1; // 16
			uint32_t pru1_fd_one_max_limit_5 : 5; // 21:17
			uint32_t pru1_fd_one_max_5 : 1; // 22
			uint32_t pru1_fd_en_5 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg5_bit;
	}; // 0xc0

	/* PRU_CFG_pru1_sd_clk_sel_reg6 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg6;

		volatile struct {
			uint32_t pru1_sd_clk_sel6 : 2; // 1:0
			uint32_t pru1_sd_clk_inv6 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel6 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_6 : 5; // 15:11
			uint32_t pru1_fd_zero_min_6 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_6 : 5; // 21:17
			uint32_t pru1_fd_zero_max_6 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg6_bit;
	}; // 0xc4

	/* PRU_CFG_pru1_sd_sample_size_reg6 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg6;

		volatile struct {
			uint32_t pru1_sd_sample_size6 : 8; // 7:0
			uint32_t pru1_fd_window_size_6 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_6 : 5; // 15:11
			uint32_t pru1_fd_one_min_6 : 1; // 16
			uint32_t pru1_fd_one_max_limit_6 : 5; // 21:17
			uint32_t pru1_fd_one_max_6 : 1; // 22
			uint32_t pru1_fd_en_6 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg6_bit;
	}; // 0xc8

	/* PRU_CFG_pru1_sd_clk_sel_reg7 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg7;

		volatile struct {
			uint32_t pru1_sd_clk_sel7 : 2; // 1:0
			uint32_t pru1_sd_clk_inv7 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel7 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_7 : 5; // 15:11
			uint32_t pru1_fd_zero_min_7 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_7 : 5; // 21:17
			uint32_t pru1_fd_zero_max_7 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg7_bit;
	}; // 0xcc

	/* PRU_CFG_pru1_sd_sample_size_reg7 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg7;

		volatile struct {
			uint32_t pru1_sd_sample_size7 : 8; // 7:0
			uint32_t pru1_fd_window_size_7 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_7 : 5; // 15:11
			uint32_t pru1_fd_one_min_7 : 1; // 16
			uint32_t pru1_fd_one_max_limit_7 : 5; // 21:17
			uint32_t pru1_fd_one_max_7 : 1; // 22
			uint32_t pru1_fd_en_7 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg7_bit;
	}; // 0xd0

	/* PRU_CFG_pru1_sd_clk_sel_reg8 register bit field */
	union {
		volatile uint32_t pru1_sd_clk_sel_reg8;

		volatile struct {
			uint32_t pru1_sd_clk_sel8 : 2; // 1:0
			uint32_t pru1_sd_clk_inv8 : 1; // 2
			uint32_t rsvd3 : 1; // 3
			uint32_t pru1_sd_acc_sel8 : 2; // 5:4
			uint32_t rsvd6 : 5; // 10:6
			uint32_t pru1_fd_zero_min_limit_8 : 5; // 15:11
			uint32_t pru1_fd_zero_min_8 : 1; // 16
			uint32_t pru1_fd_zero_max_limit_8 : 5; // 21:17
			uint32_t pru1_fd_zero_max_8 : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} pru1_sd_clk_sel_reg8_bit;
	}; // 0xd4

	/* PRU_CFG_pru1_sd_sample_size_reg8 register bit field */
	union {
		volatile uint32_t pru1_sd_sample_size_reg8;

		volatile struct {
			uint32_t pru1_sd_sample_size8 : 8; // 7:0
			uint32_t pru1_fd_window_size_8 : 3; // 10:8
			uint32_t pru1_fd_one_min_limit_8 : 5; // 15:11
			uint32_t pru1_fd_one_min_8 : 1; // 16
			uint32_t pru1_fd_one_max_limit_8 : 5; // 21:17
			uint32_t pru1_fd_one_max_8 : 1; // 22
			uint32_t pru1_fd_en_8 : 1; // 23
			uint32_t rsvd24 : 8; // 31:24
		} pru1_sd_sample_size_reg8_bit;
	}; // 0xd8

	uint8_t rsvddc[4]; // 0xdc - 0xdf

	/* PRU_CFG_pru0_ed_rx_cfg_reg register bit field */
	union {
		volatile uint32_t pru0_ed_rx_cfg_reg;

		volatile struct {
			uint32_t pru0_ed_rx_sample_size : 3; // 2:0
			uint32_t pru0_ed_rx_sb_pol : 1; // 3
			uint32_t pru0_ed_rx_clk_sel : 1; // 4
			uint32_t rsvd5 : 10; // 14:5
			uint32_t pru0_ed_rx_div_factor_frac : 1; // 15
			uint32_t pru0_ed_rx_div_factor : 16; // 31:16
		} pru0_ed_rx_cfg_reg_bit;
	}; // 0xe0

	/* PRU_CFG_pru0_ed_tx_cfg_reg register bit field */
	union {
		volatile uint32_t pru0_ed_tx_cfg_reg;

		volatile struct {
			uint32_t rsvd0 : 4; // 3:0
			uint32_t pru0_ed_tx_clk_sel : 1; // 4
			uint32_t pru0_ed_busy_0 : 1; // 5
			uint32_t pru0_ed_busy_1 : 1; // 6
			uint32_t pru0_ed_busy_2 : 1; // 7
			uint32_t pru0_endat0_clk_sync : 1; // 8
			uint32_t pru0_endat1_clk_sync : 1; // 9
			uint32_t pru0_endat2_clk_sync : 1; // 10
			uint32_t rsvd11 : 4; // 14:11
			uint32_t pru0_ed_tx_div_factor_frac : 1; // 15
			uint32_t pru0_ed_tx_div_factor : 16; // 31:16
		} pru0_ed_tx_cfg_reg_bit;
	}; // 0xe4

	/* PRU_CFG_pru0_ed_ch0_cfg0_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch0_cfg0_reg;

		volatile struct {
			uint32_t pru0_ed_tx_wdly0 : 11; // 10:0
			uint32_t pru0_ed_tx_frame_size0 : 5; // 15:11
			uint32_t pru0_ed_rx_frame_size0 : 12; // 27:16
			uint32_t pru0_ed_rx_snoop0 : 1; // 28
			uint32_t pru0_ed_clk_out_ovr_en0 : 1; // 29
			uint32_t pru0_ed_sw_clk_out0 : 1; // 30
			uint32_t pru0_ed_tx_fifo_swap_bits0 : 1; // 31
		} pru0_ed_ch0_cfg0_reg_bit;
	}; // 0xe8

	/* PRU_CFG_pru0_ed_ch0_cfg1_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch0_cfg1_reg;

		volatile struct {
			uint32_t pru0_ed_tst_delay_counter0 : 16; // 15:0
			uint32_t pru0_ed_rx_en_counter0 : 16; // 31:16
		} pru0_ed_ch0_cfg1_reg_bit;
	}; // 0xec

	/* PRU_CFG_pru0_ed_ch1_cfg0_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch1_cfg0_reg;

		volatile struct {
			uint32_t pru0_ed_tx_wdly1 : 11; // 10:0
			uint32_t pru0_ed_tx_frame_size1 : 5; // 15:11
			uint32_t pru0_ed_rx_frame_size1 : 12; // 27:16
			uint32_t pru0_ed_rx_snoop1 : 1; // 28
			uint32_t pru0_ed_clk_out_ovr_en1 : 1; // 29
			uint32_t pru0_ed_sw_clk_out1 : 1; // 30
			uint32_t pru0_ed_tx_fifo_swap_bits1 : 1; // 31
		} pru0_ed_ch1_cfg0_reg_bit;
	}; // 0xf0

	/* PRU_CFG_pru0_ed_ch1_cfg1_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch1_cfg1_reg;

		volatile struct {
			uint32_t pru0_ed_tst_delay_counter1 : 16; // 15:0
			uint32_t pru0_ed_rx_en_counter1 : 16; // 31:16
		} pru0_ed_ch1_cfg1_reg_bit;
	}; // 0xf4

	/* PRU_CFG_pru0_ed_ch2_cfg0_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch2_cfg0_reg;

		volatile struct {
			uint32_t pru0_ed_tx_wdly2 : 11; // 10:0
			uint32_t pru0_ed_tx_frame_size2 : 5; // 15:11
			uint32_t pru0_ed_rx_frame_size2 : 12; // 27:16
			uint32_t pru0_ed_rx_snoop2 : 1; // 28
			uint32_t pru0_ed_clk_out_ovr_en2 : 1; // 29
			uint32_t pru0_ed_sw_clk_out2 : 1; // 30
			uint32_t pru0_ed_tx_fifo_swap_bits2 : 1; // 31
		} pru0_ed_ch2_cfg0_reg_bit;
	}; // 0xf8

	/* PRU_CFG_pru0_ed_ch2_cfg1_reg register bit field */
	union {
		volatile uint32_t pru0_ed_ch2_cfg1_reg;

		volatile struct {
			uint32_t pru0_ed_tst_delay_counter2 : 16; // 15:0
			uint32_t pru0_ed_rx_en_counter2 : 16; // 31:16
		} pru0_ed_ch2_cfg1_reg_bit;
	}; // 0xfc
} cfg;

// start the extended structure here to match the constant registers
typedef struct {

	/* PRU_CFG_pru1_ed_rx_cfg_reg register bit field */
	union {
		volatile uint32_t pru1_ed_rx_cfg_reg;

		volatile struct {
			uint32_t pru1_ed_rx_sample_size : 3; // 2:0
			uint32_t pru1_ed_rx_sb_pol : 1; // 3
			uint32_t pru1_ed_rx_clk_sel : 1; // 4
			uint32_t rsvd5 : 10; // 14:5
			uint32_t pru1_ed_rx_div_factor_frac : 1; // 15
			uint32_t pru1_ed_rx_div_factor : 16; // 31:16
		} pru1_ed_rx_cfg_reg_bit;
	}; // 0x100

	/* PRU_CFG_pru1_ed_tx_cfg_reg register bit field */
	union {
		volatile uint32_t pru1_ed_tx_cfg_reg;

		volatile struct {
			uint32_t rsvd0 : 4; // 3:0
			uint32_t pru1_ed_tx_clk_sel : 1; // 4
			uint32_t pru1_ed_busy_0 : 1; // 5
			uint32_t pru1_ed_busy_1 : 1; // 6
			uint32_t pru1_ed_busy_2 : 1; // 7
			uint32_t pru1_endat0_clk_sync : 1; // 8
			uint32_t pru1_endat1_clk_sync : 1; // 9
			uint32_t pru1_endat2_clk_sync : 1; // 10
			uint32_t rsvd11 : 4; // 14:11
			uint32_t pru1_ed_tx_div_factor_frac : 1; // 15
			uint32_t pru1_ed_tx_div_factor : 16; // 31:16
		} pru1_ed_tx_cfg_reg_bit;
	}; // 0x104

	/* PRU_CFG_pru1_ed_ch0_cfg0_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch0_cfg0_reg;

		volatile struct {
			uint32_t pru1_ed_tx_wdly0 : 11; // 10:0
			uint32_t pru1_ed_tx_frame_size0 : 5; // 15:11
			uint32_t pru1_ed_rx_frame_size0 : 12; // 27:16
			uint32_t pru1_ed_rx_snoop0 : 1; // 28
			uint32_t pru1_ed_clk_out_ovr_en0 : 1; // 29
			uint32_t pru1_ed_sw_clk_out0 : 1; // 30
			uint32_t pru1_ed_tx_fifo_swap_bits0 : 1; // 31
		} pru1_ed_ch0_cfg0_reg_bit;
	}; // 0x108

	/* PRU_CFG_pru1_ed_ch0_cfg1_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch0_cfg1_reg;

		volatile struct {
			uint32_t pru1_ed_tst_delay_counter0 : 16; // 15:0
			uint32_t pru1_ed_rx_en_counter0 : 16; // 31:16
		} pru1_ed_ch0_cfg1_reg_bit;
	}; // 0x10c

	/* PRU_CFG_pru1_ed_ch1_cfg0_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch1_cfg0_reg;

		volatile struct {
			uint32_t pru1_ed_tx_wdly1 : 11; // 10:0
			uint32_t pru1_ed_tx_frame_size1 : 5; // 15:11
			uint32_t pru1_ed_rx_frame_size1 : 12; // 27:16
			uint32_t pru1_ed_rx_snoop1 : 1; // 28
			uint32_t pru1_ed_clk_out_ovr_en1 : 1; // 29
			uint32_t pru1_ed_sw_clk_out1 : 1; // 30
			uint32_t pru1_ed_tx_fifo_swap_bits1 : 1; // 31
		} pru1_ed_ch1_cfg0_reg_bit;
	}; // 0x110

	/* PRU_CFG_pru1_ed_ch1_cfg1_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch1_cfg1_reg;

		volatile struct {
			uint32_t pru1_ed_tst_delay_counter1 : 16; // 15:0
			uint32_t pru1_ed_rx_en_counter1 : 16; // 31:16
		} pru1_ed_ch1_cfg1_reg_bit;
	}; // 0x114

	/* PRU_CFG_pru1_ed_ch2_cfg0_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch2_cfg0_reg;

		volatile struct {
			uint32_t pru1_ed_tx_wdly2 : 11; // 10:0
			uint32_t pru1_ed_tx_frame_size2 : 5; // 15:11
			uint32_t pru1_ed_rx_frame_size2 : 12; // 27:16
			uint32_t pru1_ed_rx_snoop2 : 1; // 28
			uint32_t pru1_ed_clk_out_ovr_en2 : 1; // 29
			uint32_t pru1_ed_sw_clk_out2 : 1; // 30
			uint32_t pru1_ed_tx_fifo_swap_bits2 : 1; // 31
		} pru1_ed_ch2_cfg0_reg_bit;
	}; // 0x118

	/* PRU_CFG_pru1_ed_ch2_cfg1_reg register bit field */
	union {
		volatile uint32_t pru1_ed_ch2_cfg1_reg;

		volatile struct {
			uint32_t pru1_ed_tst_delay_counter2 : 16; // 15:0
			uint32_t pru1_ed_rx_en_counter2 : 16; // 31:16
		} pru1_ed_ch2_cfg1_reg_bit;
	}; // 0x11c

	uint8_t rsvd120[4]; // 0x120 - 0x123

	/* PRU_CFG_rtu0_poke_en0_reg register bit field */
	union {
		volatile uint32_t rtu0_poke_en0_reg;

		volatile struct {
			uint32_t rtu0_poke_r20_en : 4; // 3:0
			uint32_t rtu0_poke_r21_en : 4; // 7:4
			uint32_t rtu0_poke_r22_en : 4; // 11:8
			uint32_t rtu0_poke_r23_en : 4; // 15:12
			uint32_t rtu0_poke_r24_en : 4; // 19:16
			uint32_t rtu0_poke_r25_en : 4; // 23:20
			uint32_t rtu0_poke_r26_en : 4; // 27:24
			uint32_t rtu0_poke_r27_en : 4; // 31:28
		} rtu0_poke_en0_reg_bit;
	}; // 0x124

	uint8_t rsvd128[4]; // 0x128 - 0x12b

	/* PRU_CFG_rtu1_poke_en0_reg register bit field */
	union {
		volatile uint32_t rtu1_poke_en0_reg;

		volatile struct {
			uint32_t rtu1_poke_r20_en : 4; // 3:0
			uint32_t rtu1_poke_r21_en : 4; // 7:4
			uint32_t rtu1_poke_r22_en : 4; // 11:8
			uint32_t rtu1_poke_r23_en : 4; // 15:12
			uint32_t rtu1_poke_r24_en : 4; // 19:16
			uint32_t rtu1_poke_r25_en : 4; // 23:20
			uint32_t rtu1_poke_r26_en : 4; // 27:24
			uint32_t rtu1_poke_r27_en : 4; // 31:28
		} rtu1_poke_en0_reg_bit;
	}; // 0x12c

	/* PRU_CFG_pwm0 register bit field */
	union {
		volatile uint32_t pwm0;

		volatile struct {
			uint32_t pwm0_debounce_value : 8; // 7:0
			uint32_t pwm0_trip_mask : 9; // 16:8
			uint32_t pwm0_trip_cmp0_en : 1; // 17
			uint32_t pwm0_trip_reset : 1; // 18
			uint32_t pwm0_over_err_trip : 1; // 19
			uint32_t pwm0_pos_err_trip : 1; // 20
			uint32_t pwm0_trip_vec : 9; // 29:21
			uint32_t pwm0_trip_s : 1; // 30
			uint32_t rsvd31 : 1; // 31
		} pwm0_bit;
	}; // 0x130

	/* PRU_CFG_pwm1 register bit field */
	union {
		volatile uint32_t pwm1;

		volatile struct {
			uint32_t pwm1_debounce_value : 8; // 7:0
			uint32_t pwm1_trip_mask : 9; // 16:8
			uint32_t pwm1_trip_cmp0_en : 1; // 17
			uint32_t pwm1_trip_reset : 1; // 18
			uint32_t pwm1_over_err_trip : 1; // 19
			uint32_t pwm1_pos_err_trip : 1; // 20
			uint32_t pwm1_trip_vec : 9; // 29:21
			uint32_t pwm1_trip_s : 1; // 30
			uint32_t rsvd31 : 1; // 31
		} pwm1_bit;
	}; // 0x134

	/* PRU_CFG_pwm2 register bit field */
	union {
		volatile uint32_t pwm2;

		volatile struct {
			uint32_t pwm2_debounce_value : 8; // 7:0
			uint32_t pwm2_trip_mask : 9; // 16:8
			uint32_t pwm2_trip_cmp0_en : 1; // 17
			uint32_t pwm2_trip_reset : 1; // 18
			uint32_t pwm2_over_err_trip : 1; // 19
			uint32_t pwm2_pos_err_trip : 1; // 20
			uint32_t pwm2_trip_vec : 9; // 29:21
			uint32_t pwm2_trip_s : 1; // 30
			uint32_t rsvd31 : 1; // 31
		} pwm2_bit;
	}; // 0x138

	/* PRU_CFG_pwm3 register bit field */
	union {
		volatile uint32_t pwm3;

		volatile struct {
			uint32_t pwm3_debounce_value : 8; // 7:0
			uint32_t pwm3_trip_mask : 9; // 16:8
			uint32_t pwm3_trip_cmp0_en : 1; // 17
			uint32_t pwm3_trip_reset : 1; // 18
			uint32_t pwm3_over_err_trip : 1; // 19
			uint32_t pwm3_pos_err_trip : 1; // 20
			uint32_t pwm3_trip_vec : 9; // 29:21
			uint32_t pwm3_trip_s : 1; // 30
			uint32_t rsvd31 : 1; // 31
		} pwm3_bit;
	}; // 0x13c

	/* PRU_CFG_pwm0_0 register bit field */
	union {
		volatile uint32_t pwm0_0;

		volatile struct {
			uint32_t pwm0_0_pos_init : 2; // 1:0
			uint32_t pwm0_0_neg_init : 2; // 3:2
			uint32_t pwm0_0_pos_trip : 2; // 5:4
			uint32_t pwm0_0_neg_trip : 2; // 7:6
			uint32_t pwm0_0_pos_act : 2; // 9:8
			uint32_t pwm0_0_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm0_0_bit;
	}; // 0x140

	/* PRU_CFG_pwm0_1 register bit field */
	union {
		volatile uint32_t pwm0_1;

		volatile struct {
			uint32_t pwm0_1_pos_init : 2; // 1:0
			uint32_t pwm0_1_neg_init : 2; // 3:2
			uint32_t pwm0_1_pos_trip : 2; // 5:4
			uint32_t pwm0_1_neg_trip : 2; // 7:6
			uint32_t pwm0_1_pos_act : 2; // 9:8
			uint32_t pwm0_1_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm0_1_bit;
	}; // 0x144

	/* PRU_CFG_pwm0_2 register bit field */
	union {
		volatile uint32_t pwm0_2;

		volatile struct {
			uint32_t pwm0_2_pos_init : 2; // 1:0
			uint32_t pwm0_2_neg_init : 2; // 3:2
			uint32_t pwm0_2_pos_trip : 2; // 5:4
			uint32_t pwm0_2_neg_trip : 2; // 7:6
			uint32_t pwm0_2_pos_act : 2; // 9:8
			uint32_t pwm0_2_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm0_2_bit;
	}; // 0x148

	/* PRU_CFG_pwm1_0 register bit field */
	union {
		volatile uint32_t pwm1_0;

		volatile struct {
			uint32_t pwm1_0_pos_init : 2; // 1:0
			uint32_t pwm1_0_neg_init : 2; // 3:2
			uint32_t pwm1_0_pos_trip : 2; // 5:4
			uint32_t pwm1_0_neg_trip : 2; // 7:6
			uint32_t pwm1_0_pos_act : 2; // 9:8
			uint32_t pwm1_0_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm1_0_bit;
	}; // 0x14c

	/* PRU_CFG_pwm1_1 register bit field */
	union {
		volatile uint32_t pwm1_1;

		volatile struct {
			uint32_t pwm1_1_pos_init : 2; // 1:0
			uint32_t pwm1_1_neg_init : 2; // 3:2
			uint32_t pwm1_1_pos_trip : 2; // 5:4
			uint32_t pwm1_1_neg_trip : 2; // 7:6
			uint32_t pwm1_1_pos_act : 2; // 9:8
			uint32_t pwm1_1_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm1_1_bit;
	}; // 0x150

	/* PRU_CFG_pwm1_2 register bit field */
	union {
		volatile uint32_t pwm1_2;

		volatile struct {
			uint32_t pwm1_2_pos_init : 2; // 1:0
			uint32_t pwm1_2_neg_init : 2; // 3:2
			uint32_t pwm1_2_pos_trip : 2; // 5:4
			uint32_t pwm1_2_neg_trip : 2; // 7:6
			uint32_t pwm1_2_pos_act : 2; // 9:8
			uint32_t pwm1_2_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm1_2_bit;
	}; // 0x154

	/* PRU_CFG_pwm2_0 register bit field */
	union {
		volatile uint32_t pwm2_0;

		volatile struct {
			uint32_t pwm2_0_pos_init : 2; // 1:0
			uint32_t pwm2_0_neg_init : 2; // 3:2
			uint32_t pwm2_0_pos_trip : 2; // 5:4
			uint32_t pwm2_0_neg_trip : 2; // 7:6
			uint32_t pwm2_0_pos_act : 2; // 9:8
			uint32_t pwm2_0_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm2_0_bit;
	}; // 0x158

	/* PRU_CFG_pwm2_1 register bit field */
	union {
		volatile uint32_t pwm2_1;

		volatile struct {
			uint32_t pwm2_1_pos_init : 2; // 1:0
			uint32_t pwm2_1_neg_init : 2; // 3:2
			uint32_t pwm2_1_pos_trip : 2; // 5:4
			uint32_t pwm2_1_neg_trip : 2; // 7:6
			uint32_t pwm2_1_pos_act : 2; // 9:8
			uint32_t pwm2_1_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm2_1_bit;
	}; // 0x15c

	/* PRU_CFG_pwm2_2 register bit field */
	union {
		volatile uint32_t pwm2_2;

		volatile struct {
			uint32_t pwm2_2_pos_init : 2; // 1:0
			uint32_t pwm2_2_neg_init : 2; // 3:2
			uint32_t pwm2_2_pos_trip : 2; // 5:4
			uint32_t pwm2_2_neg_trip : 2; // 7:6
			uint32_t pwm2_2_pos_act : 2; // 9:8
			uint32_t pwm2_2_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm2_2_bit;
	}; // 0x160

	/* PRU_CFG_pwm3_0 register bit field */
	union {
		volatile uint32_t pwm3_0;

		volatile struct {
			uint32_t pwm3_0_pos_init : 2; // 1:0
			uint32_t pwm3_0_neg_init : 2; // 3:2
			uint32_t pwm3_0_pos_trip : 2; // 5:4
			uint32_t pwm3_0_neg_trip : 2; // 7:6
			uint32_t pwm3_0_pos_act : 2; // 9:8
			uint32_t pwm3_0_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm3_0_bit;
	}; // 0x164

	/* PRU_CFG_pwm3_1 register bit field */
	union {
		volatile uint32_t pwm3_1;

		volatile struct {
			uint32_t pwm3_1_pos_init : 2; // 1:0
			uint32_t pwm3_1_neg_init : 2; // 3:2
			uint32_t pwm3_1_pos_trip : 2; // 5:4
			uint32_t pwm3_1_neg_trip : 2; // 7:6
			uint32_t pwm3_1_pos_act : 2; // 9:8
			uint32_t pwm3_1_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm3_1_bit;
	}; // 0x168

	/* PRU_CFG_pwm3_2 register bit field */
	union {
		volatile uint32_t pwm3_2;

		volatile struct {
			uint32_t pwm3_2_pos_init : 2; // 1:0
			uint32_t pwm3_2_neg_init : 2; // 3:2
			uint32_t pwm3_2_pos_trip : 2; // 5:4
			uint32_t pwm3_2_neg_trip : 2; // 7:6
			uint32_t pwm3_2_pos_act : 2; // 9:8
			uint32_t pwm3_2_neg_act : 2; // 11:10
			uint32_t rsvd12 : 20; // 31:12
		} pwm3_2_bit;
	}; // 0x16c

	/* PRU_CFG_spin_lock0 register bit field */
	union {
		volatile uint32_t spin_lock0;

		volatile struct {
			uint32_t mmr_own_req_status_0 : 1; // 0
			uint32_t mmr_own_req_clr_0 : 1; // 1
			uint32_t rsvd2 : 6; // 7:2
			uint32_t mmr_own_req_vector_0 : 6; // 13:8
			uint32_t rsvd14 : 18; // 31:14
		} spin_lock0_bit;
	}; // 0x170

	/* PRU_CFG_spin_lock1 register bit field */
	union {
		volatile uint32_t spin_lock1;

		volatile struct {
			uint32_t mmr_own_req_status_1 : 1; // 0
			uint32_t mmr_own_req_clr_1 : 1; // 1
			uint32_t rsvd2 : 6; // 7:2
			uint32_t mmr_own_req_vector_1 : 6; // 13:8
			uint32_t rsvd14 : 18; // 31:14
		} spin_lock1_bit;
	}; // 0x174

	/* PRU_CFG_pa_stat_pdsp_cfg0 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_cfg0;

		volatile struct {
			uint32_t pa_pdsp0_index : 14; // 13:0
			uint32_t pa_pdsp0_inc_val : 17; // 30:14
			uint32_t pa_pdsp0_inc_type : 1; // 31
		} pa_stat_pdsp_cfg0_bit;
	}; // 0x178

	/* PRU_CFG_pa_stat_pdsp_stat0 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_stat0;

		volatile struct {
			uint32_t pa_pdsp0_ready : 1; // 0
			uint32_t pa_pdsp0_status : 3; // 3:1
			uint32_t rsvd4 : 28; // 31:4
		} pa_stat_pdsp_stat0_bit;
	}; // 0x17c

	/* PRU_CFG_pa_stat_pdsp_cfg1 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_cfg1;

		volatile struct {
			uint32_t pa_pdsp1_index : 14; // 13:0
			uint32_t pa_pdsp1_inc_val : 17; // 30:14
			uint32_t pa_pdsp1_inc_type : 1; // 31
		} pa_stat_pdsp_cfg1_bit;
	}; // 0x180

	/* PRU_CFG_pa_stat_pdsp_stat1 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_stat1;

		volatile struct {
			uint32_t pa_pdsp1_ready : 1; // 0
			uint32_t pa_pdsp1_status : 3; // 3:1
			uint32_t rsvd4 : 28; // 31:4
		} pa_stat_pdsp_stat1_bit;
	}; // 0x184

	/* PRU_CFG_pa_stat_pdsp_cfg2 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_cfg2;

		volatile struct {
			uint32_t pa_pdsp2_index : 14; // 13:0
			uint32_t pa_pdsp2_inc_val : 17; // 30:14
			uint32_t pa_pdsp2_inc_type : 1; // 31
		} pa_stat_pdsp_cfg2_bit;
	}; // 0x188

	/* PRU_CFG_pa_stat_pdsp_stat2 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_stat2;

		volatile struct {
			uint32_t pa_pdsp2_ready : 1; // 0
			uint32_t pa_pdsp2_status : 3; // 3:1
			uint32_t rsvd4 : 28; // 31:4
		} pa_stat_pdsp_stat2_bit;
	}; // 0x18c

	/* PRU_CFG_pa_stat_pdsp_cfg3 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_cfg3;

		volatile struct {
			uint32_t pa_pdsp3_index : 14; // 13:0
			uint32_t pa_pdsp3_inc_val : 17; // 30:14
			uint32_t pa_pdsp3_inc_type : 1; // 31
		} pa_stat_pdsp_cfg3_bit;
	}; // 0x190

	/* PRU_CFG_pa_stat_pdsp_stat3 register bit field */
	union {
		volatile uint32_t pa_stat_pdsp_stat3;

		volatile struct {
			uint32_t pa_pdsp3_ready : 1; // 0
			uint32_t pa_pdsp3_status : 3; // 3:1
			uint32_t rsvd4 : 28; // 31:4
		} pa_stat_pdsp_stat3_bit;
	}; // 0x194

} cfgExt;

volatile __far cfg CT_CFG __attribute__((cregister("PRU_CFG", near), peripheral));
volatile __far cfgExt CT_CFG_EXT __attribute__((cregister("PRU_CFG_EXT", near), peripheral));

#endif /* _PRU_CFG_H_ */

