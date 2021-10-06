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

#ifndef _PRU_MII_G_RT_H_
#define _PRU_MII_G_RT_H_

/* PRU MII G RT register set */
typedef struct {

	/* PRU_MII_G_RT_icss_g_cfg register bit field */
	union {
		volatile uint32_t icss_g_cfg;

		volatile struct {
			uint32_t tx_l1_en : 1; // 0
			uint32_t tx_l2_en : 1; // 1
			uint32_t rx_l2_g_en : 1; // 2
			uint32_t mii0_mode : 2; // 4:3
			uint32_t mii1_mode : 2; // 6:5
			uint32_t rsvd7 : 1; // 7
			uint32_t iep1_tx_en : 1; // 8
			uint32_t rtu_pru_psi_share_en : 1; // 9
			uint32_t rx_sfd_tx_sof_en : 1; // 10
			uint32_t rsvd11 : 5; // 15:11
			uint32_t sgmii_mode : 1; // 16
			uint32_t rsvd17 : 15; // 31:17
		} icss_g_cfg_bit;
	}; // 0x0

	/* PRU_MII_G_RT_rgmii_cfg register bit field */
	union {
		volatile uint32_t rgmii_cfg;

		volatile struct {
			uint32_t rgmii0_link : 1; // 0
			uint32_t rgmii0_speed : 2; // 2:1
			uint32_t rgmii0_fullduplex : 1; // 3
			uint32_t rgmii1_link : 1; // 4
			uint32_t rgmii1_speed : 2; // 6:5
			uint32_t rgmii1_fullduplex : 1; // 7
			uint32_t rgmii_eee_en : 1; // 8
			uint32_t rgmii_eee_phy_only : 1; // 9
			uint32_t rsvd10 : 6; // 15:10
			uint32_t rgmii0_inband : 1; // 16
			uint32_t rgmii0_gig_in : 1; // 17
			uint32_t rgmii0_fullduplex_in : 1; // 18
			uint32_t rsvd19 : 1; // 19
			uint32_t rgmii1_inband : 1; // 20
			uint32_t rgmii1_gig_in : 1; // 21
			uint32_t rgmii1_fullduplex_in : 1; // 22
			uint32_t rsvd23 : 9; // 31:23
		} rgmii_cfg_bit;
	}; // 0x4

	/* PRU_MII_G_RT_mac_pru0_0 register bit field */
	union {
		volatile uint32_t mac_pru0_0;

		volatile struct {
			uint32_t mac_pru0_0 : 32; // 31:0
		} mac_pru0_0_bit;
	}; // 0x8

	/* PRU_MII_G_RT_mac_pru0_1 register bit field */
	union {
		volatile uint32_t mac_pru0_1;

		volatile struct {
			uint32_t mac_pru0_1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} mac_pru0_1_bit;
	}; // 0xc

	/* PRU_MII_G_RT_mac_pru1_0 register bit field */
	union {
		volatile uint32_t mac_pru1_0;

		volatile struct {
			uint32_t mac_pru1_0 : 32; // 31:0
		} mac_pru1_0_bit;
	}; // 0x10

	/* PRU_MII_G_RT_mac_pru1_1 register bit field */
	union {
		volatile uint32_t mac_pru1_1;

		volatile struct {
			uint32_t mac_pru1_1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} mac_pru1_1_bit;
	}; // 0x14

	/* PRU_MII_G_RT_mac_interface_0 register bit field */
	union {
		volatile uint32_t mac_interface_0;

		volatile struct {
			uint32_t mac_inf_0 : 32; // 31:0
		} mac_interface_0_bit;
	}; // 0x18

	/* PRU_MII_G_RT_mac_interface_1 register bit field */
	union {
		volatile uint32_t mac_interface_1;

		volatile struct {
			uint32_t mac_inf_1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} mac_interface_1_bit;
	}; // 0x1c

	/* PRU_MII_G_RT_preempt_cfg register bit field */
	union {
		volatile uint32_t preempt_cfg;

		volatile struct {
			uint32_t rsvd0 : 8; // 7:0
			uint32_t exp_smd : 8; // 15:8
			uint32_t smd_v : 8; // 23:16
			uint32_t smd_r : 8; // 31:24
		} preempt_cfg_bit;
	}; // 0x20

	/* PRU_MII_G_RT_smdt1s_cfg register bit field */
	union {
		volatile uint32_t smdt1s_cfg;

		volatile struct {
			uint32_t smdt1s_0 : 8; // 7:0
			uint32_t smdt1s_1 : 8; // 15:8
			uint32_t smdt1s_2 : 8; // 23:16
			uint32_t smdt1s_3 : 8; // 31:24
		} smdt1s_cfg_bit;
	}; // 0x24

	/* PRU_MII_G_RT_smdt1c_cfg register bit field */
	union {
		volatile uint32_t smdt1c_cfg;

		volatile struct {
			uint32_t smdt1c_0 : 8; // 7:0
			uint32_t smdt1c_1 : 8; // 15:8
			uint32_t smdt1c_2 : 8; // 23:16
			uint32_t smdt1c_3 : 8; // 31:24
		} smdt1c_cfg_bit;
	}; // 0x28

	uint8_t rsvd2c[8]; // 0x2c - 0x33

	/* PRU_MII_G_RT_frag_cnt_cfg register bit field */
	union {
		volatile uint32_t frag_cnt_cfg;

		volatile struct {
			uint32_t frag_cnt_0 : 8; // 7:0
			uint32_t frag_cnt_1 : 8; // 15:8
			uint32_t frag_cnt_2 : 8; // 23:16
			uint32_t frag_cnt_3 : 8; // 31:24
		} frag_cnt_cfg_bit;
	}; // 0x34

	uint8_t rsvd38[8]; // 0x38 - 0x3f

	/* PRU_MII_G_RT_pa_stat_push0 register bit field */
	union {
		volatile uint32_t pa_stat_push0;

		volatile struct {
			uint32_t pa_stat_push0_0 : 8; // 7:0
			uint32_t pa_stat_push1_0 : 8; // 15:8
			uint32_t pa_stat_push2_0 : 8; // 23:16
			uint32_t pa_stat_push3_0 : 8; // 31:24
		} pa_stat_push0_bit;
	}; // 0x40

	/* PRU_MII_G_RT_pa_stat_push1 register bit field */
	union {
		volatile uint32_t pa_stat_push1;

		volatile struct {
			uint32_t pa_stat_push0_1 : 8; // 7:0
			uint32_t pa_stat_push1_1 : 8; // 15:8
			uint32_t pa_stat_push2_1 : 8; // 23:16
			uint32_t pa_stat_push3_1 : 8; // 31:24
		} pa_stat_push1_bit;
	}; // 0x44

	/* PRU_MII_G_RT_pa_stat_push2 register bit field */
	union {
		volatile uint32_t pa_stat_push2;

		volatile struct {
			uint32_t pa_stat_push0_2 : 8; // 7:0
			uint32_t pa_stat_push1_2 : 8; // 15:8
			uint32_t pa_stat_push2_2 : 8; // 23:16
			uint32_t pa_stat_push3_2 : 8; // 31:24
		} pa_stat_push2_bit;
	}; // 0x48

	/* PRU_MII_G_RT_pa_stat_push3 register bit field */
	union {
		volatile uint32_t pa_stat_push3;

		volatile struct {
			uint32_t pa_stat_push0_3 : 8; // 7:0
			uint32_t pa_stat_push1_3 : 8; // 15:8
			uint32_t pa_stat_push2_3 : 8; // 23:16
			uint32_t pa_stat_push3_3 : 8; // 31:24
		} pa_stat_push3_bit;
	}; // 0x4c

	uint8_t rsvd50[16]; // 0x50 - 0x5f

	/* PRU_MII_G_RT_fdb_gen_cfg1 register bit field */
	union {
		volatile uint32_t fdb_gen_cfg1;

		volatile struct {
			uint32_t fdb_bucket_size : 2; // 1:0
			uint32_t rsvd2 : 1; // 2
			uint32_t fdb_hash_size : 4; // 6:3
			uint32_t rsvd7 : 1; // 7
			uint32_t smem_vlan_offset : 18; // 25:8
			uint32_t rsvd26 : 6; // 31:26
		} fdb_gen_cfg1_bit;
	}; // 0x60

	/* PRU_MII_G_RT_fdb_gen_cfg2 register bit field */
	union {
		volatile uint32_t fdb_gen_cfg2;

		volatile struct {
			uint32_t fdb_pru0_en : 1; // 0
			uint32_t fdb_pru1_en : 1; // 1
			uint32_t fdb_host_en : 1; // 2
			uint32_t rsvd3 : 2; // 4:3
			uint32_t fdb_hsr_en : 1; // 5
			uint32_t fdb_vlan_en : 1; // 6
			uint32_t fdb_gen_mode_en_bk0 : 1; // 7
			uint32_t fdb_gen_mode_en_bk1 : 1; // 8
			uint32_t fdb_gen_mode_byte_en : 4; // 12:9
			uint32_t rsvd13 : 19; // 31:13
		} fdb_gen_cfg2_bit;
	}; // 0x64

	/* PRU_MII_G_RT_fdb_gen_status register bit field */
	union {
		volatile uint32_t fdb_gen_status;

		volatile struct {
			uint32_t rsvd0 : 32; // 31:0
		} fdb_gen_status_bit;
	}; // 0x68

	/* PRU_MII_G_RT_fdb_df_vlan register bit field */
	union {
		volatile uint32_t fdb_df_vlan;

		volatile struct {
			uint32_t fdb_pru0_df_vlan : 12; // 11:0
			uint32_t rsvd12 : 4; // 15:12
			uint32_t fdb_pru1_df_vlan : 12; // 27:16
			uint32_t rsvd28 : 4; // 31:28
		} fdb_df_vlan_bit;
	}; // 0x6c

	/* PRU_MII_G_RT_fdb_host_da0 register bit field */
	union {
		volatile uint32_t fdb_host_da0;

		volatile struct {
			uint32_t fdb_host_da0 : 32; // 31:0
		} fdb_host_da0_bit;
	}; // 0x70

	/* PRU_MII_G_RT_fdb_host_da1 register bit field */
	union {
		volatile uint32_t fdb_host_da1;

		volatile struct {
			uint32_t fdb_host_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} fdb_host_da1_bit;
	}; // 0x74

	/* PRU_MII_G_RT_fdb_host_sa0 register bit field */
	union {
		volatile uint32_t fdb_host_sa0;

		volatile struct {
			uint32_t fdb_host_sa0 : 32; // 31:0
		} fdb_host_sa0_bit;
	}; // 0x78

	/* PRU_MII_G_RT_fdb_host_vlan_sa1 register bit field */
	union {
		volatile uint32_t fdb_host_vlan_sa1;

		volatile struct {
			uint32_t fdb_host_sa1 : 16; // 15:0
			uint32_t fdb_host_vlan_hsr : 16; // 31:16
		} fdb_host_vlan_sa1_bit;
	}; // 0x7c

	/* PRU_MII_G_RT_ft1_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft1_start_len_pru0;

		volatile struct {
			uint32_t ft1_start : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft1_len : 4; // 19:16
			uint32_t rsvd20 : 12; // 31:20
		} ft1_start_len_pru0_bit;
	}; // 0x80

	/* PRU_MII_G_RT_ft1_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft1_cfg_pru0;

		volatile struct {
			uint32_t ft1_0cfg : 2; // 1:0
			uint32_t ft1_1cfg : 2; // 3:2
			uint32_t ft1_2cfg : 2; // 5:4
			uint32_t ft1_3cfg : 2; // 7:6
			uint32_t ft1_4cfg : 2; // 9:8
			uint32_t ft1_5cfg : 2; // 11:10
			uint32_t ft1_6cfg : 2; // 13:12
			uint32_t ft1_7cfg : 2; // 15:14
			uint32_t rsvd16 : 16; // 31:16
		} ft1_cfg_pru0_bit;
	}; // 0x84

	/* PRU_MII_G_RT_ft1_0_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_0_da0_pru0;

		volatile struct {
			uint32_t ft1_0_da0 : 32; // 31:0
		} ft1_0_da0_pru0_bit;
	}; // 0x88

	/* PRU_MII_G_RT_ft1_0_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_0_da1_pru0;

		volatile struct {
			uint32_t ft1_0_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_0_da1_pru0_bit;
	}; // 0x8c

	/* PRU_MII_G_RT_ft1_0_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_0_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_0_da_mask0 : 32; // 31:0
		} ft1_0_da_mask0_pru0_bit;
	}; // 0x90

	/* PRU_MII_G_RT_ft1_0_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_0_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_0_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_0_da_mask1_pru0_bit;
	}; // 0x94

	/* PRU_MII_G_RT_ft1_1_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_1_da0_pru0;

		volatile struct {
			uint32_t ft1_1_da0 : 32; // 31:0
		} ft1_1_da0_pru0_bit;
	}; // 0x98

	/* PRU_MII_G_RT_ft1_1_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_1_da1_pru0;

		volatile struct {
			uint32_t ft1_1_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_1_da1_pru0_bit;
	}; // 0x9c

	/* PRU_MII_G_RT_ft1_1_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_1_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_1_da_mask0 : 32; // 31:0
		} ft1_1_da_mask0_pru0_bit;
	}; // 0xa0

	/* PRU_MII_G_RT_ft1_1_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_1_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_1_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_1_da_mask1_pru0_bit;
	}; // 0xa4

	/* PRU_MII_G_RT_ft1_2_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_2_da0_pru0;

		volatile struct {
			uint32_t ft1_2_da0 : 32; // 31:0
		} ft1_2_da0_pru0_bit;
	}; // 0xa8

	/* PRU_MII_G_RT_ft1_2_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_2_da1_pru0;

		volatile struct {
			uint32_t ft1_2_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_2_da1_pru0_bit;
	}; // 0xac

	/* PRU_MII_G_RT_ft1_2_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_2_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_2_da_mask0 : 32; // 31:0
		} ft1_2_da_mask0_pru0_bit;
	}; // 0xb0

	/* PRU_MII_G_RT_ft1_2_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_2_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_2_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_2_da_mask1_pru0_bit;
	}; // 0xb4

	/* PRU_MII_G_RT_ft1_3_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_3_da0_pru0;

		volatile struct {
			uint32_t ft1_3_da0 : 32; // 31:0
		} ft1_3_da0_pru0_bit;
	}; // 0xb8

	/* PRU_MII_G_RT_ft1_3_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_3_da1_pru0;

		volatile struct {
			uint32_t ft1_3_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_3_da1_pru0_bit;
	}; // 0xbc

	/* PRU_MII_G_RT_ft1_3_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_3_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_3_da_mask0 : 32; // 31:0
		} ft1_3_da_mask0_pru0_bit;
	}; // 0xc0

	/* PRU_MII_G_RT_ft1_3_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_3_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_3_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_3_da_mask1_pru0_bit;
	}; // 0xc4

	/* PRU_MII_G_RT_ft1_4_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_4_da0_pru0;

		volatile struct {
			uint32_t ft1_4_da0 : 32; // 31:0
		} ft1_4_da0_pru0_bit;
	}; // 0xc8

	/* PRU_MII_G_RT_ft1_4_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_4_da1_pru0;

		volatile struct {
			uint32_t ft1_4_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_4_da1_pru0_bit;
	}; // 0xcc

	/* PRU_MII_G_RT_ft1_4_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_4_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_4_da_mask0 : 32; // 31:0
		} ft1_4_da_mask0_pru0_bit;
	}; // 0xd0

	/* PRU_MII_G_RT_ft1_4_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_4_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_4_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_4_da_mask1_pru0_bit;
	}; // 0xd4

	/* PRU_MII_G_RT_ft1_5_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_5_da0_pru0;

		volatile struct {
			uint32_t ft1_5_da0 : 32; // 31:0
		} ft1_5_da0_pru0_bit;
	}; // 0xd8

	/* PRU_MII_G_RT_ft1_5_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_5_da1_pru0;

		volatile struct {
			uint32_t ft1_5_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_5_da1_pru0_bit;
	}; // 0xdc

	/* PRU_MII_G_RT_ft1_5_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_5_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_5_da_mask0 : 32; // 31:0
		} ft1_5_da_mask0_pru0_bit;
	}; // 0xe0

	/* PRU_MII_G_RT_ft1_5_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_5_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_5_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_5_da_mask1_pru0_bit;
	}; // 0xe4

	/* PRU_MII_G_RT_ft1_6_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_6_da0_pru0;

		volatile struct {
			uint32_t ft1_6_da0 : 32; // 31:0
		} ft1_6_da0_pru0_bit;
	}; // 0xe8

	/* PRU_MII_G_RT_ft1_6_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_6_da1_pru0;

		volatile struct {
			uint32_t ft1_6_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_6_da1_pru0_bit;
	}; // 0xec

	/* PRU_MII_G_RT_ft1_6_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_6_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_6_da_mask0 : 32; // 31:0
		} ft1_6_da_mask0_pru0_bit;
	}; // 0xf0

	/* PRU_MII_G_RT_ft1_6_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_6_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_6_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_6_da_mask1_pru0_bit;
	}; // 0xf4

	/* PRU_MII_G_RT_ft1_7_da0_pru0 register bit field */
	union {
		volatile uint32_t ft1_7_da0_pru0;

		volatile struct {
			uint32_t ft1_7_da0 : 32; // 31:0
		} ft1_7_da0_pru0_bit;
	}; // 0xf8

	/* PRU_MII_G_RT_ft1_7_da1_pru0 register bit field */
	union {
		volatile uint32_t ft1_7_da1_pru0;

		volatile struct {
			uint32_t ft1_7_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_7_da1_pru0_bit;
	}; // 0xfc

	/* PRU_MII_G_RT_ft1_7_da_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft1_7_da_mask0_pru0;

		volatile struct {
			uint32_t ft1_7_da_mask0 : 32; // 31:0
		} ft1_7_da_mask0_pru0_bit;
	}; // 0x100

	/* PRU_MII_G_RT_ft1_7_da_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft1_7_da_mask1_pru0;

		volatile struct {
			uint32_t ft1_7_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_7_da_mask1_pru0_bit;
	}; // 0x104

	/* PRU_MII_G_RT_ft3_0_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_0_start_pru0_bit;
	}; // 0x108

	/* PRU_MII_G_RT_ft3_0_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_0_start_auto_pru0_bit;
	}; // 0x10c

	/* PRU_MII_G_RT_ft3_0_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_0_start_len_pru0_bit;
	}; // 0x110

	/* PRU_MII_G_RT_ft3_0_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_0_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_0_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_0_jmp_offset_pru0_bit;
	}; // 0x114

	/* PRU_MII_G_RT_ft3_0_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_len_pru0;

		volatile struct {
			uint32_t ft3_0_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_0_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_0_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_0_len_pru0_bit;
	}; // 0x118

	/* PRU_MII_G_RT_ft3_0_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_cfg_pru0;

		volatile struct {
			uint32_t ft3_0cfg : 2; // 1:0
			uint32_t ft3_0_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_0_trig_or_en : 16; // 31:16
		} ft3_0_cfg_pru0_bit;
	}; // 0x11c

	/* PRU_MII_G_RT_ft3_0_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_t_pru0;

		volatile struct {
			uint32_t ft3_0_t : 32; // 31:0
		} ft3_0_t_pru0_bit;
	}; // 0x120

	/* PRU_MII_G_RT_ft3_0_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_t_mask_pru0;

		volatile struct {
			uint32_t ft3_0_t_mask : 32; // 31:0
		} ft3_0_t_mask_pru0_bit;
	}; // 0x124

	/* PRU_MII_G_RT_ft3_1_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_1_start_pru0_bit;
	}; // 0x128

	/* PRU_MII_G_RT_ft3_1_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_1_start_auto_pru0_bit;
	}; // 0x12c

	/* PRU_MII_G_RT_ft3_1_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_1_start_len_pru0_bit;
	}; // 0x130

	/* PRU_MII_G_RT_ft3_1_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_1_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_1_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_1_jmp_offset_pru0_bit;
	}; // 0x134

	/* PRU_MII_G_RT_ft3_1_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_len_pru0;

		volatile struct {
			uint32_t ft3_1_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_1_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_1_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_1_len_pru0_bit;
	}; // 0x138

	/* PRU_MII_G_RT_ft3_1_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_cfg_pru0;

		volatile struct {
			uint32_t ft3_1cfg : 2; // 1:0
			uint32_t ft3_1_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_1_trig_or_en : 16; // 31:16
		} ft3_1_cfg_pru0_bit;
	}; // 0x13c

	/* PRU_MII_G_RT_ft3_1_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_t_pru0;

		volatile struct {
			uint32_t ft3_1_t : 32; // 31:0
		} ft3_1_t_pru0_bit;
	}; // 0x140

	/* PRU_MII_G_RT_ft3_1_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_t_mask_pru0;

		volatile struct {
			uint32_t ft3_1_t_mask : 32; // 31:0
		} ft3_1_t_mask_pru0_bit;
	}; // 0x144

	/* PRU_MII_G_RT_ft3_2_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_2_start_pru0_bit;
	}; // 0x148

	/* PRU_MII_G_RT_ft3_2_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_2_start_auto_pru0_bit;
	}; // 0x14c

	/* PRU_MII_G_RT_ft3_2_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_2_start_len_pru0_bit;
	}; // 0x150

	/* PRU_MII_G_RT_ft3_2_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_2_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_2_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_2_jmp_offset_pru0_bit;
	}; // 0x154

	/* PRU_MII_G_RT_ft3_2_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_len_pru0;

		volatile struct {
			uint32_t ft3_2_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_2_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_2_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_2_len_pru0_bit;
	}; // 0x158

	/* PRU_MII_G_RT_ft3_2_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_cfg_pru0;

		volatile struct {
			uint32_t ft3_2cfg : 2; // 1:0
			uint32_t ft3_2_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_2_trig_or_en : 16; // 31:16
		} ft3_2_cfg_pru0_bit;
	}; // 0x15c

	/* PRU_MII_G_RT_ft3_2_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_t_pru0;

		volatile struct {
			uint32_t ft3_2_t : 32; // 31:0
		} ft3_2_t_pru0_bit;
	}; // 0x160

	/* PRU_MII_G_RT_ft3_2_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_t_mask_pru0;

		volatile struct {
			uint32_t ft3_2_t_mask : 32; // 31:0
		} ft3_2_t_mask_pru0_bit;
	}; // 0x164

	/* PRU_MII_G_RT_ft3_3_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_3_start_pru0_bit;
	}; // 0x168

	/* PRU_MII_G_RT_ft3_3_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_3_start_auto_pru0_bit;
	}; // 0x16c

	/* PRU_MII_G_RT_ft3_3_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_3_start_len_pru0_bit;
	}; // 0x170

	/* PRU_MII_G_RT_ft3_3_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_3_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_3_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_3_jmp_offset_pru0_bit;
	}; // 0x174

	/* PRU_MII_G_RT_ft3_3_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_len_pru0;

		volatile struct {
			uint32_t ft3_3_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_3_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_3_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_3_len_pru0_bit;
	}; // 0x178

	/* PRU_MII_G_RT_ft3_3_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_cfg_pru0;

		volatile struct {
			uint32_t ft3_3cfg : 2; // 1:0
			uint32_t ft3_3_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_3_trig_or_en : 16; // 31:16
		} ft3_3_cfg_pru0_bit;
	}; // 0x17c

	/* PRU_MII_G_RT_ft3_3_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_t_pru0;

		volatile struct {
			uint32_t ft3_3_t : 32; // 31:0
		} ft3_3_t_pru0_bit;
	}; // 0x180

	/* PRU_MII_G_RT_ft3_3_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_t_mask_pru0;

		volatile struct {
			uint32_t ft3_3_t_mask : 32; // 31:0
		} ft3_3_t_mask_pru0_bit;
	}; // 0x184

	/* PRU_MII_G_RT_ft3_4_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_4_start_pru0_bit;
	}; // 0x188

	/* PRU_MII_G_RT_ft3_4_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_4_start_auto_pru0_bit;
	}; // 0x18c

	/* PRU_MII_G_RT_ft3_4_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_4_start_len_pru0_bit;
	}; // 0x190

	/* PRU_MII_G_RT_ft3_4_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_4_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_4_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_4_jmp_offset_pru0_bit;
	}; // 0x194

	/* PRU_MII_G_RT_ft3_4_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_len_pru0;

		volatile struct {
			uint32_t ft3_4_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_4_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_4_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_4_len_pru0_bit;
	}; // 0x198

	/* PRU_MII_G_RT_ft3_4_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_cfg_pru0;

		volatile struct {
			uint32_t ft3_4cfg : 2; // 1:0
			uint32_t ft3_4_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_4_trig_or_en : 16; // 31:16
		} ft3_4_cfg_pru0_bit;
	}; // 0x19c

	/* PRU_MII_G_RT_ft3_4_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_t_pru0;

		volatile struct {
			uint32_t ft3_4_t : 32; // 31:0
		} ft3_4_t_pru0_bit;
	}; // 0x1a0

	/* PRU_MII_G_RT_ft3_4_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_t_mask_pru0;

		volatile struct {
			uint32_t ft3_4_t_mask : 32; // 31:0
		} ft3_4_t_mask_pru0_bit;
	}; // 0x1a4

	/* PRU_MII_G_RT_ft3_5_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_5_start_pru0_bit;
	}; // 0x1a8

	/* PRU_MII_G_RT_ft3_5_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_5_start_auto_pru0_bit;
	}; // 0x1ac

	/* PRU_MII_G_RT_ft3_5_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_5_start_len_pru0_bit;
	}; // 0x1b0

	/* PRU_MII_G_RT_ft3_5_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_5_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_5_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_5_jmp_offset_pru0_bit;
	}; // 0x1b4

	/* PRU_MII_G_RT_ft3_5_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_len_pru0;

		volatile struct {
			uint32_t ft3_5_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_5_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_5_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_5_len_pru0_bit;
	}; // 0x1b8

	/* PRU_MII_G_RT_ft3_5_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_cfg_pru0;

		volatile struct {
			uint32_t ft3_5cfg : 2; // 1:0
			uint32_t ft3_5_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_5_trig_or_en : 16; // 31:16
		} ft3_5_cfg_pru0_bit;
	}; // 0x1bc

	/* PRU_MII_G_RT_ft3_5_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_t_pru0;

		volatile struct {
			uint32_t ft3_5_t : 32; // 31:0
		} ft3_5_t_pru0_bit;
	}; // 0x1c0

	/* PRU_MII_G_RT_ft3_5_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_t_mask_pru0;

		volatile struct {
			uint32_t ft3_5_t_mask : 32; // 31:0
		} ft3_5_t_mask_pru0_bit;
	}; // 0x1c4

	/* PRU_MII_G_RT_ft3_6_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_6_start_pru0_bit;
	}; // 0x1c8

	/* PRU_MII_G_RT_ft3_6_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_6_start_auto_pru0_bit;
	}; // 0x1cc

	/* PRU_MII_G_RT_ft3_6_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_6_start_len_pru0_bit;
	}; // 0x1d0

	/* PRU_MII_G_RT_ft3_6_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_6_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_6_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_6_jmp_offset_pru0_bit;
	}; // 0x1d4

	/* PRU_MII_G_RT_ft3_6_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_len_pru0;

		volatile struct {
			uint32_t ft3_6_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_6_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_6_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_6_len_pru0_bit;
	}; // 0x1d8

	/* PRU_MII_G_RT_ft3_6_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_cfg_pru0;

		volatile struct {
			uint32_t ft3_6cfg : 2; // 1:0
			uint32_t ft3_6_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_6_trig_or_en : 16; // 31:16
		} ft3_6_cfg_pru0_bit;
	}; // 0x1dc

	/* PRU_MII_G_RT_ft3_6_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_t_pru0;

		volatile struct {
			uint32_t ft3_6_t : 32; // 31:0
		} ft3_6_t_pru0_bit;
	}; // 0x1e0

	/* PRU_MII_G_RT_ft3_6_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_t_mask_pru0;

		volatile struct {
			uint32_t ft3_6_t_mask : 32; // 31:0
		} ft3_6_t_mask_pru0_bit;
	}; // 0x1e4

	/* PRU_MII_G_RT_ft3_7_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_7_start_pru0_bit;
	}; // 0x1e8

	/* PRU_MII_G_RT_ft3_7_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_7_start_auto_pru0_bit;
	}; // 0x1ec

	/* PRU_MII_G_RT_ft3_7_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_7_start_len_pru0_bit;
	}; // 0x1f0

	/* PRU_MII_G_RT_ft3_7_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_7_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_7_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_7_jmp_offset_pru0_bit;
	}; // 0x1f4

	/* PRU_MII_G_RT_ft3_7_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_len_pru0;

		volatile struct {
			uint32_t ft3_7_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_7_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_7_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_7_len_pru0_bit;
	}; // 0x1f8

	/* PRU_MII_G_RT_ft3_7_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_cfg_pru0;

		volatile struct {
			uint32_t ft3_7cfg : 2; // 1:0
			uint32_t ft3_7_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_7_trig_or_en : 16; // 31:16
		} ft3_7_cfg_pru0_bit;
	}; // 0x1fc

	/* PRU_MII_G_RT_ft3_7_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_t_pru0;

		volatile struct {
			uint32_t ft3_7_t : 32; // 31:0
		} ft3_7_t_pru0_bit;
	}; // 0x200

	/* PRU_MII_G_RT_ft3_7_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_t_mask_pru0;

		volatile struct {
			uint32_t ft3_7_t_mask : 32; // 31:0
		} ft3_7_t_mask_pru0_bit;
	}; // 0x204

	/* PRU_MII_G_RT_ft3_8_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_8_start_pru0_bit;
	}; // 0x208

	/* PRU_MII_G_RT_ft3_8_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_8_start_auto_pru0_bit;
	}; // 0x20c

	/* PRU_MII_G_RT_ft3_8_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_8_start_len_pru0_bit;
	}; // 0x210

	/* PRU_MII_G_RT_ft3_8_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_8_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_8_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_8_jmp_offset_pru0_bit;
	}; // 0x214

	/* PRU_MII_G_RT_ft3_8_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_len_pru0;

		volatile struct {
			uint32_t ft3_8_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_8_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_8_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_8_len_pru0_bit;
	}; // 0x218

	/* PRU_MII_G_RT_ft3_8_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_cfg_pru0;

		volatile struct {
			uint32_t ft3_8cfg : 2; // 1:0
			uint32_t ft3_8_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_8_trig_or_en : 16; // 31:16
		} ft3_8_cfg_pru0_bit;
	}; // 0x21c

	/* PRU_MII_G_RT_ft3_8_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_t_pru0;

		volatile struct {
			uint32_t ft3_8_t : 32; // 31:0
		} ft3_8_t_pru0_bit;
	}; // 0x220

	/* PRU_MII_G_RT_ft3_8_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_t_mask_pru0;

		volatile struct {
			uint32_t ft3_8_t_mask : 32; // 31:0
		} ft3_8_t_mask_pru0_bit;
	}; // 0x224

	/* PRU_MII_G_RT_ft3_9_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_9_start_pru0_bit;
	}; // 0x228

	/* PRU_MII_G_RT_ft3_9_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_9_start_auto_pru0_bit;
	}; // 0x22c

	/* PRU_MII_G_RT_ft3_9_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_9_start_len_pru0_bit;
	}; // 0x230

	/* PRU_MII_G_RT_ft3_9_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_9_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_9_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_9_jmp_offset_pru0_bit;
	}; // 0x234

	/* PRU_MII_G_RT_ft3_9_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_len_pru0;

		volatile struct {
			uint32_t ft3_9_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_9_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_9_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_9_len_pru0_bit;
	}; // 0x238

	/* PRU_MII_G_RT_ft3_9_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_cfg_pru0;

		volatile struct {
			uint32_t ft3_9cfg : 2; // 1:0
			uint32_t ft3_9_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_9_trig_or_en : 16; // 31:16
		} ft3_9_cfg_pru0_bit;
	}; // 0x23c

	/* PRU_MII_G_RT_ft3_9_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_t_pru0;

		volatile struct {
			uint32_t ft3_9_t : 32; // 31:0
		} ft3_9_t_pru0_bit;
	}; // 0x240

	/* PRU_MII_G_RT_ft3_9_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_t_mask_pru0;

		volatile struct {
			uint32_t ft3_9_t_mask : 32; // 31:0
		} ft3_9_t_mask_pru0_bit;
	}; // 0x244

	/* PRU_MII_G_RT_ft3_10_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_10_start_pru0_bit;
	}; // 0x248

	/* PRU_MII_G_RT_ft3_10_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_10_start_auto_pru0_bit;
	}; // 0x24c

	/* PRU_MII_G_RT_ft3_10_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_10_start_len_pru0_bit;
	}; // 0x250

	/* PRU_MII_G_RT_ft3_10_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_10_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_10_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_10_jmp_offset_pru0_bit;
	}; // 0x254

	/* PRU_MII_G_RT_ft3_10_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_len_pru0;

		volatile struct {
			uint32_t ft3_10_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_10_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_10_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_10_len_pru0_bit;
	}; // 0x258

	/* PRU_MII_G_RT_ft3_10_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_cfg_pru0;

		volatile struct {
			uint32_t ft3_10cfg : 2; // 1:0
			uint32_t ft3_10_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_10_trig_or_en : 16; // 31:16
		} ft3_10_cfg_pru0_bit;
	}; // 0x25c

	/* PRU_MII_G_RT_ft3_10_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_t_pru0;

		volatile struct {
			uint32_t ft3_10_t : 32; // 31:0
		} ft3_10_t_pru0_bit;
	}; // 0x260

	/* PRU_MII_G_RT_ft3_10_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_t_mask_pru0;

		volatile struct {
			uint32_t ft3_10_t_mask : 32; // 31:0
		} ft3_10_t_mask_pru0_bit;
	}; // 0x264

	/* PRU_MII_G_RT_ft3_11_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_11_start_pru0_bit;
	}; // 0x268

	/* PRU_MII_G_RT_ft3_11_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_11_start_auto_pru0_bit;
	}; // 0x26c

	/* PRU_MII_G_RT_ft3_11_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_11_start_len_pru0_bit;
	}; // 0x270

	/* PRU_MII_G_RT_ft3_11_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_11_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_11_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_11_jmp_offset_pru0_bit;
	}; // 0x274

	/* PRU_MII_G_RT_ft3_11_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_len_pru0;

		volatile struct {
			uint32_t ft3_11_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_11_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_11_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_11_len_pru0_bit;
	}; // 0x278

	/* PRU_MII_G_RT_ft3_11_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_cfg_pru0;

		volatile struct {
			uint32_t ft3_11cfg : 2; // 1:0
			uint32_t ft3_11_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_11_trig_or_en : 16; // 31:16
		} ft3_11_cfg_pru0_bit;
	}; // 0x27c

	/* PRU_MII_G_RT_ft3_11_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_t_pru0;

		volatile struct {
			uint32_t ft3_11_t : 32; // 31:0
		} ft3_11_t_pru0_bit;
	}; // 0x280

	/* PRU_MII_G_RT_ft3_11_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_t_mask_pru0;

		volatile struct {
			uint32_t ft3_11_t_mask : 32; // 31:0
		} ft3_11_t_mask_pru0_bit;
	}; // 0x284

	/* PRU_MII_G_RT_ft3_12_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_12_start_pru0_bit;
	}; // 0x288

	/* PRU_MII_G_RT_ft3_12_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_12_start_auto_pru0_bit;
	}; // 0x28c

	/* PRU_MII_G_RT_ft3_12_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_12_start_len_pru0_bit;
	}; // 0x290

	/* PRU_MII_G_RT_ft3_12_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_12_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_12_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_12_jmp_offset_pru0_bit;
	}; // 0x294

	/* PRU_MII_G_RT_ft3_12_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_len_pru0;

		volatile struct {
			uint32_t ft3_12_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_12_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_12_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_12_len_pru0_bit;
	}; // 0x298

	/* PRU_MII_G_RT_ft3_12_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_cfg_pru0;

		volatile struct {
			uint32_t ft3_12cfg : 2; // 1:0
			uint32_t ft3_12_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_12_trig_or_en : 16; // 31:16
		} ft3_12_cfg_pru0_bit;
	}; // 0x29c

	/* PRU_MII_G_RT_ft3_12_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_t_pru0;

		volatile struct {
			uint32_t ft3_12_t : 32; // 31:0
		} ft3_12_t_pru0_bit;
	}; // 0x2a0

	/* PRU_MII_G_RT_ft3_12_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_t_mask_pru0;

		volatile struct {
			uint32_t ft3_12_t_mask : 32; // 31:0
		} ft3_12_t_mask_pru0_bit;
	}; // 0x2a4

	/* PRU_MII_G_RT_ft3_13_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_13_start_pru0_bit;
	}; // 0x2a8

	/* PRU_MII_G_RT_ft3_13_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_13_start_auto_pru0_bit;
	}; // 0x2ac

	/* PRU_MII_G_RT_ft3_13_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_13_start_len_pru0_bit;
	}; // 0x2b0

	/* PRU_MII_G_RT_ft3_13_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_13_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_13_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_13_jmp_offset_pru0_bit;
	}; // 0x2b4

	/* PRU_MII_G_RT_ft3_13_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_len_pru0;

		volatile struct {
			uint32_t ft3_13_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_13_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_13_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_13_len_pru0_bit;
	}; // 0x2b8

	/* PRU_MII_G_RT_ft3_13_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_cfg_pru0;

		volatile struct {
			uint32_t ft3_13cfg : 2; // 1:0
			uint32_t ft3_13_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_13_trig_or_en : 16; // 31:16
		} ft3_13_cfg_pru0_bit;
	}; // 0x2bc

	/* PRU_MII_G_RT_ft3_13_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_t_pru0;

		volatile struct {
			uint32_t ft3_13_t : 32; // 31:0
		} ft3_13_t_pru0_bit;
	}; // 0x2c0

	/* PRU_MII_G_RT_ft3_13_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_t_mask_pru0;

		volatile struct {
			uint32_t ft3_13_t_mask : 32; // 31:0
		} ft3_13_t_mask_pru0_bit;
	}; // 0x2c4

	/* PRU_MII_G_RT_ft3_14_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_14_start_pru0_bit;
	}; // 0x2c8

	/* PRU_MII_G_RT_ft3_14_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_14_start_auto_pru0_bit;
	}; // 0x2cc

	/* PRU_MII_G_RT_ft3_14_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_14_start_len_pru0_bit;
	}; // 0x2d0

	/* PRU_MII_G_RT_ft3_14_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_14_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_14_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_14_jmp_offset_pru0_bit;
	}; // 0x2d4

	/* PRU_MII_G_RT_ft3_14_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_len_pru0;

		volatile struct {
			uint32_t ft3_14_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_14_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_14_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_14_len_pru0_bit;
	}; // 0x2d8

	/* PRU_MII_G_RT_ft3_14_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_cfg_pru0;

		volatile struct {
			uint32_t ft3_14cfg : 2; // 1:0
			uint32_t ft3_14_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_14_trig_or_en : 16; // 31:16
		} ft3_14_cfg_pru0_bit;
	}; // 0x2dc

	/* PRU_MII_G_RT_ft3_14_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_t_pru0;

		volatile struct {
			uint32_t ft3_14_t : 32; // 31:0
		} ft3_14_t_pru0_bit;
	}; // 0x2e0

	/* PRU_MII_G_RT_ft3_14_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_t_mask_pru0;

		volatile struct {
			uint32_t ft3_14_t_mask : 32; // 31:0
		} ft3_14_t_mask_pru0_bit;
	}; // 0x2e4

	/* PRU_MII_G_RT_ft3_15_start_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_start_pru0;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_15_start_pru0_bit;
	}; // 0x2e8

	/* PRU_MII_G_RT_ft3_15_start_auto_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_start_auto_pru0;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_15_start_auto_pru0_bit;
	}; // 0x2ec

	/* PRU_MII_G_RT_ft3_15_start_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_start_len_pru0;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_15_start_len_pru0_bit;
	}; // 0x2f0

	/* PRU_MII_G_RT_ft3_15_jmp_offset_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_jmp_offset_pru0;

		volatile struct {
			uint32_t ft3_15_ijmp_offset_pru0 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_15_njmp_offset_pru0 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_15_jmp_offset_pru0_bit;
	}; // 0x2f4

	/* PRU_MII_G_RT_ft3_15_len_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_len_pru0;

		volatile struct {
			uint32_t ft3_15_len_start_bit_pru0 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_15_len_size_bit_pru0 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_15_len_big_en_pru0 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_15_len_pru0_bit;
	}; // 0x2f8

	/* PRU_MII_G_RT_ft3_15_cfg_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_cfg_pru0;

		volatile struct {
			uint32_t ft3_15cfg : 2; // 1:0
			uint32_t ft3_15_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_15_trig_or_en : 16; // 31:16
		} ft3_15_cfg_pru0_bit;
	}; // 0x2fc

	/* PRU_MII_G_RT_ft3_15_t_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_t_pru0;

		volatile struct {
			uint32_t ft3_15_t : 32; // 31:0
		} ft3_15_t_pru0_bit;
	}; // 0x300

	/* PRU_MII_G_RT_ft3_15_t_mask_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_t_mask_pru0;

		volatile struct {
			uint32_t ft3_15_t_mask : 32; // 31:0
		} ft3_15_t_mask_pru0_bit;
	}; // 0x304

	/* PRU_MII_G_RT_ft3_0_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_p0_pru0;

		volatile struct {
			uint32_t ft3_0_p0 : 32; // 31:0
		} ft3_0_p0_pru0_bit;
	}; // 0x308

	/* PRU_MII_G_RT_ft3_0_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_p1_pru0;

		volatile struct {
			uint32_t ft3_0_p1 : 32; // 31:0
		} ft3_0_p1_pru0_bit;
	}; // 0x30c

	/* PRU_MII_G_RT_ft3_0_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_0_p_mask0 : 32; // 31:0
		} ft3_0_p_mask0_pru0_bit;
	}; // 0x310

	/* PRU_MII_G_RT_ft3_0_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_0_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_0_p_mask1 : 32; // 31:0
		} ft3_0_p_mask1_pru0_bit;
	}; // 0x314

	/* PRU_MII_G_RT_ft3_1_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_p0_pru0;

		volatile struct {
			uint32_t ft3_1_p0 : 32; // 31:0
		} ft3_1_p0_pru0_bit;
	}; // 0x318

	/* PRU_MII_G_RT_ft3_1_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_p1_pru0;

		volatile struct {
			uint32_t ft3_1_p1 : 32; // 31:0
		} ft3_1_p1_pru0_bit;
	}; // 0x31c

	/* PRU_MII_G_RT_ft3_1_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_1_p_mask0 : 32; // 31:0
		} ft3_1_p_mask0_pru0_bit;
	}; // 0x320

	/* PRU_MII_G_RT_ft3_1_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_1_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_1_p_mask1 : 32; // 31:0
		} ft3_1_p_mask1_pru0_bit;
	}; // 0x324

	/* PRU_MII_G_RT_ft3_2_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_p0_pru0;

		volatile struct {
			uint32_t ft3_2_p0 : 32; // 31:0
		} ft3_2_p0_pru0_bit;
	}; // 0x328

	/* PRU_MII_G_RT_ft3_2_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_p1_pru0;

		volatile struct {
			uint32_t ft3_2_p1 : 32; // 31:0
		} ft3_2_p1_pru0_bit;
	}; // 0x32c

	/* PRU_MII_G_RT_ft3_2_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_2_p_mask0 : 32; // 31:0
		} ft3_2_p_mask0_pru0_bit;
	}; // 0x330

	/* PRU_MII_G_RT_ft3_2_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_2_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_2_p_mask1 : 32; // 31:0
		} ft3_2_p_mask1_pru0_bit;
	}; // 0x334

	/* PRU_MII_G_RT_ft3_3_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_p0_pru0;

		volatile struct {
			uint32_t ft3_3_p0 : 32; // 31:0
		} ft3_3_p0_pru0_bit;
	}; // 0x338

	/* PRU_MII_G_RT_ft3_3_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_p1_pru0;

		volatile struct {
			uint32_t ft3_3_p1 : 32; // 31:0
		} ft3_3_p1_pru0_bit;
	}; // 0x33c

	/* PRU_MII_G_RT_ft3_3_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_3_p_mask0 : 32; // 31:0
		} ft3_3_p_mask0_pru0_bit;
	}; // 0x340

	/* PRU_MII_G_RT_ft3_3_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_3_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_3_p_mask1 : 32; // 31:0
		} ft3_3_p_mask1_pru0_bit;
	}; // 0x344

	/* PRU_MII_G_RT_ft3_4_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_p0_pru0;

		volatile struct {
			uint32_t ft3_4_p0 : 32; // 31:0
		} ft3_4_p0_pru0_bit;
	}; // 0x348

	/* PRU_MII_G_RT_ft3_4_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_p1_pru0;

		volatile struct {
			uint32_t ft3_4_p1 : 32; // 31:0
		} ft3_4_p1_pru0_bit;
	}; // 0x34c

	/* PRU_MII_G_RT_ft3_4_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_4_p_mask0 : 32; // 31:0
		} ft3_4_p_mask0_pru0_bit;
	}; // 0x350

	/* PRU_MII_G_RT_ft3_4_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_4_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_4_p_mask1 : 32; // 31:0
		} ft3_4_p_mask1_pru0_bit;
	}; // 0x354

	/* PRU_MII_G_RT_ft3_5_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_p0_pru0;

		volatile struct {
			uint32_t ft3_5_p0 : 32; // 31:0
		} ft3_5_p0_pru0_bit;
	}; // 0x358

	/* PRU_MII_G_RT_ft3_5_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_p1_pru0;

		volatile struct {
			uint32_t ft3_5_p1 : 32; // 31:0
		} ft3_5_p1_pru0_bit;
	}; // 0x35c

	/* PRU_MII_G_RT_ft3_5_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_5_p_mask0 : 32; // 31:0
		} ft3_5_p_mask0_pru0_bit;
	}; // 0x360

	/* PRU_MII_G_RT_ft3_5_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_5_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_5_p_mask1 : 32; // 31:0
		} ft3_5_p_mask1_pru0_bit;
	}; // 0x364

	/* PRU_MII_G_RT_ft3_6_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_p0_pru0;

		volatile struct {
			uint32_t ft3_6_p0 : 32; // 31:0
		} ft3_6_p0_pru0_bit;
	}; // 0x368

	/* PRU_MII_G_RT_ft3_6_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_p1_pru0;

		volatile struct {
			uint32_t ft3_6_p1 : 32; // 31:0
		} ft3_6_p1_pru0_bit;
	}; // 0x36c

	/* PRU_MII_G_RT_ft3_6_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_6_p_mask0 : 32; // 31:0
		} ft3_6_p_mask0_pru0_bit;
	}; // 0x370

	/* PRU_MII_G_RT_ft3_6_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_6_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_6_p_mask1 : 32; // 31:0
		} ft3_6_p_mask1_pru0_bit;
	}; // 0x374

	/* PRU_MII_G_RT_ft3_7_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_p0_pru0;

		volatile struct {
			uint32_t ft3_7_p0 : 32; // 31:0
		} ft3_7_p0_pru0_bit;
	}; // 0x378

	/* PRU_MII_G_RT_ft3_7_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_p1_pru0;

		volatile struct {
			uint32_t ft3_7_p1 : 32; // 31:0
		} ft3_7_p1_pru0_bit;
	}; // 0x37c

	/* PRU_MII_G_RT_ft3_7_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_7_p_mask0 : 32; // 31:0
		} ft3_7_p_mask0_pru0_bit;
	}; // 0x380

	/* PRU_MII_G_RT_ft3_7_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_7_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_7_p_mask1 : 32; // 31:0
		} ft3_7_p_mask1_pru0_bit;
	}; // 0x384

	/* PRU_MII_G_RT_ft3_8_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_p0_pru0;

		volatile struct {
			uint32_t ft3_8_p0 : 32; // 31:0
		} ft3_8_p0_pru0_bit;
	}; // 0x388

	/* PRU_MII_G_RT_ft3_8_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_p1_pru0;

		volatile struct {
			uint32_t ft3_8_p1 : 32; // 31:0
		} ft3_8_p1_pru0_bit;
	}; // 0x38c

	/* PRU_MII_G_RT_ft3_8_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_8_p_mask0 : 32; // 31:0
		} ft3_8_p_mask0_pru0_bit;
	}; // 0x390

	/* PRU_MII_G_RT_ft3_8_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_8_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_8_p_mask1 : 32; // 31:0
		} ft3_8_p_mask1_pru0_bit;
	}; // 0x394

	/* PRU_MII_G_RT_ft3_9_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_p0_pru0;

		volatile struct {
			uint32_t ft3_9_p0 : 32; // 31:0
		} ft3_9_p0_pru0_bit;
	}; // 0x398

	/* PRU_MII_G_RT_ft3_9_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_p1_pru0;

		volatile struct {
			uint32_t ft3_9_p1 : 32; // 31:0
		} ft3_9_p1_pru0_bit;
	}; // 0x39c

	/* PRU_MII_G_RT_ft3_9_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_9_p_mask0 : 32; // 31:0
		} ft3_9_p_mask0_pru0_bit;
	}; // 0x3a0

	/* PRU_MII_G_RT_ft3_9_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_9_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_9_p_mask1 : 32; // 31:0
		} ft3_9_p_mask1_pru0_bit;
	}; // 0x3a4

	/* PRU_MII_G_RT_ft3_10_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_p0_pru0;

		volatile struct {
			uint32_t ft3_10_p0 : 32; // 31:0
		} ft3_10_p0_pru0_bit;
	}; // 0x3a8

	/* PRU_MII_G_RT_ft3_10_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_p1_pru0;

		volatile struct {
			uint32_t ft3_10_p1 : 32; // 31:0
		} ft3_10_p1_pru0_bit;
	}; // 0x3ac

	/* PRU_MII_G_RT_ft3_10_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_10_p_mask0 : 32; // 31:0
		} ft3_10_p_mask0_pru0_bit;
	}; // 0x3b0

	/* PRU_MII_G_RT_ft3_10_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_10_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_10_p_mask1 : 32; // 31:0
		} ft3_10_p_mask1_pru0_bit;
	}; // 0x3b4

	/* PRU_MII_G_RT_ft3_11_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_p0_pru0;

		volatile struct {
			uint32_t ft3_11_p0 : 32; // 31:0
		} ft3_11_p0_pru0_bit;
	}; // 0x3b8

	/* PRU_MII_G_RT_ft3_11_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_p1_pru0;

		volatile struct {
			uint32_t ft3_11_p1 : 32; // 31:0
		} ft3_11_p1_pru0_bit;
	}; // 0x3bc

	/* PRU_MII_G_RT_ft3_11_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_11_p_mask0 : 32; // 31:0
		} ft3_11_p_mask0_pru0_bit;
	}; // 0x3c0

	/* PRU_MII_G_RT_ft3_11_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_11_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_11_p_mask1 : 32; // 31:0
		} ft3_11_p_mask1_pru0_bit;
	}; // 0x3c4

	/* PRU_MII_G_RT_ft3_12_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_p0_pru0;

		volatile struct {
			uint32_t ft3_12_p0 : 32; // 31:0
		} ft3_12_p0_pru0_bit;
	}; // 0x3c8

	/* PRU_MII_G_RT_ft3_12_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_p1_pru0;

		volatile struct {
			uint32_t ft3_12_p1 : 32; // 31:0
		} ft3_12_p1_pru0_bit;
	}; // 0x3cc

	/* PRU_MII_G_RT_ft3_12_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_12_p_mask0 : 32; // 31:0
		} ft3_12_p_mask0_pru0_bit;
	}; // 0x3d0

	/* PRU_MII_G_RT_ft3_12_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_12_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_12_p_mask1 : 32; // 31:0
		} ft3_12_p_mask1_pru0_bit;
	}; // 0x3d4

	/* PRU_MII_G_RT_ft3_13_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_p0_pru0;

		volatile struct {
			uint32_t ft3_13_p0 : 32; // 31:0
		} ft3_13_p0_pru0_bit;
	}; // 0x3d8

	/* PRU_MII_G_RT_ft3_13_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_p1_pru0;

		volatile struct {
			uint32_t ft3_13_p1 : 32; // 31:0
		} ft3_13_p1_pru0_bit;
	}; // 0x3dc

	/* PRU_MII_G_RT_ft3_13_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_13_p_mask0 : 32; // 31:0
		} ft3_13_p_mask0_pru0_bit;
	}; // 0x3e0

	/* PRU_MII_G_RT_ft3_13_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_13_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_13_p_mask1 : 32; // 31:0
		} ft3_13_p_mask1_pru0_bit;
	}; // 0x3e4

	/* PRU_MII_G_RT_ft3_14_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_p0_pru0;

		volatile struct {
			uint32_t ft3_14_p0 : 32; // 31:0
		} ft3_14_p0_pru0_bit;
	}; // 0x3e8

	/* PRU_MII_G_RT_ft3_14_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_p1_pru0;

		volatile struct {
			uint32_t ft3_14_p1 : 32; // 31:0
		} ft3_14_p1_pru0_bit;
	}; // 0x3ec

	/* PRU_MII_G_RT_ft3_14_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_14_p_mask0 : 32; // 31:0
		} ft3_14_p_mask0_pru0_bit;
	}; // 0x3f0

	/* PRU_MII_G_RT_ft3_14_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_14_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_14_p_mask1 : 32; // 31:0
		} ft3_14_p_mask1_pru0_bit;
	}; // 0x3f4

	/* PRU_MII_G_RT_ft3_15_p0_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_p0_pru0;

		volatile struct {
			uint32_t ft3_15_p0 : 32; // 31:0
		} ft3_15_p0_pru0_bit;
	}; // 0x3f8

	/* PRU_MII_G_RT_ft3_15_p1_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_p1_pru0;

		volatile struct {
			uint32_t ft3_15_p1 : 32; // 31:0
		} ft3_15_p1_pru0_bit;
	}; // 0x3fc

	/* PRU_MII_G_RT_ft3_15_p_mask0_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_p_mask0_pru0;

		volatile struct {
			uint32_t ft3_15_p_mask0 : 32; // 31:0
		} ft3_15_p_mask0_pru0_bit;
	}; // 0x400

	/* PRU_MII_G_RT_ft3_15_p_mask1_pru0 register bit field */
	union {
		volatile uint32_t ft3_15_p_mask1_pru0;

		volatile struct {
			uint32_t ft3_15_p_mask1 : 32; // 31:0
		} ft3_15_p_mask1_pru0_bit;
	}; // 0x404

	/* PRU_MII_G_RT_ft_rx_ptr_pru0 register bit field */
	union {
		volatile uint32_t ft_rx_ptr_pru0;

		volatile struct {
			uint32_t ft_rx_ptr_pru0 : 32; // 31:0
		} ft_rx_ptr_pru0_bit;
	}; // 0x408

	/* PRU_MII_G_RT_rx_class0_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class0_and_en_pru0;

		volatile struct {
			uint32_t rx_class0_and_en : 32; // 31:0
		} rx_class0_and_en_pru0_bit;
	}; // 0x40c

	/* PRU_MII_G_RT_rx_class0_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class0_or_en_pru0;

		volatile struct {
			uint32_t rx_class0_or_en : 32; // 31:0
		} rx_class0_or_en_pru0_bit;
	}; // 0x410

	/* PRU_MII_G_RT_rx_class1_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class1_and_en_pru0;

		volatile struct {
			uint32_t rx_class1_and_en : 32; // 31:0
		} rx_class1_and_en_pru0_bit;
	}; // 0x414

	/* PRU_MII_G_RT_rx_class1_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class1_or_en_pru0;

		volatile struct {
			uint32_t rx_class1_or_en : 32; // 31:0
		} rx_class1_or_en_pru0_bit;
	}; // 0x418

	/* PRU_MII_G_RT_rx_class2_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class2_and_en_pru0;

		volatile struct {
			uint32_t rx_class2_and_en : 32; // 31:0
		} rx_class2_and_en_pru0_bit;
	}; // 0x41c

	/* PRU_MII_G_RT_rx_class2_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class2_or_en_pru0;

		volatile struct {
			uint32_t rx_class2_or_en : 32; // 31:0
		} rx_class2_or_en_pru0_bit;
	}; // 0x420

	/* PRU_MII_G_RT_rx_class3_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class3_and_en_pru0;

		volatile struct {
			uint32_t rx_class3_and_en : 32; // 31:0
		} rx_class3_and_en_pru0_bit;
	}; // 0x424

	/* PRU_MII_G_RT_rx_class3_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class3_or_en_pru0;

		volatile struct {
			uint32_t rx_class3_or_en : 32; // 31:0
		} rx_class3_or_en_pru0_bit;
	}; // 0x428

	/* PRU_MII_G_RT_rx_class4_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class4_and_en_pru0;

		volatile struct {
			uint32_t rx_class4_and_en : 32; // 31:0
		} rx_class4_and_en_pru0_bit;
	}; // 0x42c

	/* PRU_MII_G_RT_rx_class4_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class4_or_en_pru0;

		volatile struct {
			uint32_t rx_class4_or_en : 32; // 31:0
		} rx_class4_or_en_pru0_bit;
	}; // 0x430

	/* PRU_MII_G_RT_rx_class5_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class5_and_en_pru0;

		volatile struct {
			uint32_t rx_class5_and_en : 32; // 31:0
		} rx_class5_and_en_pru0_bit;
	}; // 0x434

	/* PRU_MII_G_RT_rx_class5_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class5_or_en_pru0;

		volatile struct {
			uint32_t rx_class5_or_en : 32; // 31:0
		} rx_class5_or_en_pru0_bit;
	}; // 0x438

	/* PRU_MII_G_RT_rx_class6_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class6_and_en_pru0;

		volatile struct {
			uint32_t rx_class6_and_en : 32; // 31:0
		} rx_class6_and_en_pru0_bit;
	}; // 0x43c

	/* PRU_MII_G_RT_rx_class6_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class6_or_en_pru0;

		volatile struct {
			uint32_t rx_class6_or_en : 32; // 31:0
		} rx_class6_or_en_pru0_bit;
	}; // 0x440

	/* PRU_MII_G_RT_rx_class7_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class7_and_en_pru0;

		volatile struct {
			uint32_t rx_class7_and_en : 32; // 31:0
		} rx_class7_and_en_pru0_bit;
	}; // 0x444

	/* PRU_MII_G_RT_rx_class7_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class7_or_en_pru0;

		volatile struct {
			uint32_t rx_class7_or_en : 32; // 31:0
		} rx_class7_or_en_pru0_bit;
	}; // 0x448

	/* PRU_MII_G_RT_rx_class8_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class8_and_en_pru0;

		volatile struct {
			uint32_t rx_class8_and_en : 32; // 31:0
		} rx_class8_and_en_pru0_bit;
	}; // 0x44c

	/* PRU_MII_G_RT_rx_class8_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class8_or_en_pru0;

		volatile struct {
			uint32_t rx_class8_or_en : 32; // 31:0
		} rx_class8_or_en_pru0_bit;
	}; // 0x450

	/* PRU_MII_G_RT_rx_class9_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class9_and_en_pru0;

		volatile struct {
			uint32_t rx_class9_and_en : 32; // 31:0
		} rx_class9_and_en_pru0_bit;
	}; // 0x454

	/* PRU_MII_G_RT_rx_class9_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class9_or_en_pru0;

		volatile struct {
			uint32_t rx_class9_or_en : 32; // 31:0
		} rx_class9_or_en_pru0_bit;
	}; // 0x458

	/* PRU_MII_G_RT_rx_class10_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class10_and_en_pru0;

		volatile struct {
			uint32_t rx_class10_and_en : 32; // 31:0
		} rx_class10_and_en_pru0_bit;
	}; // 0x45c

	/* PRU_MII_G_RT_rx_class10_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class10_or_en_pru0;

		volatile struct {
			uint32_t rx_class10_or_en : 32; // 31:0
		} rx_class10_or_en_pru0_bit;
	}; // 0x460

	/* PRU_MII_G_RT_rx_class11_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class11_and_en_pru0;

		volatile struct {
			uint32_t rx_class11_and_en : 32; // 31:0
		} rx_class11_and_en_pru0_bit;
	}; // 0x464

	/* PRU_MII_G_RT_rx_class11_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class11_or_en_pru0;

		volatile struct {
			uint32_t rx_class11_or_en : 32; // 31:0
		} rx_class11_or_en_pru0_bit;
	}; // 0x468

	/* PRU_MII_G_RT_rx_class12_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class12_and_en_pru0;

		volatile struct {
			uint32_t rx_class12_and_en : 32; // 31:0
		} rx_class12_and_en_pru0_bit;
	}; // 0x46c

	/* PRU_MII_G_RT_rx_class12_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class12_or_en_pru0;

		volatile struct {
			uint32_t rx_class12_or_en : 32; // 31:0
		} rx_class12_or_en_pru0_bit;
	}; // 0x470

	/* PRU_MII_G_RT_rx_class13_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class13_and_en_pru0;

		volatile struct {
			uint32_t rx_class13_and_en : 32; // 31:0
		} rx_class13_and_en_pru0_bit;
	}; // 0x474

	/* PRU_MII_G_RT_rx_class13_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class13_or_en_pru0;

		volatile struct {
			uint32_t rx_class13_or_en : 32; // 31:0
		} rx_class13_or_en_pru0_bit;
	}; // 0x478

	/* PRU_MII_G_RT_rx_class14_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class14_and_en_pru0;

		volatile struct {
			uint32_t rx_class14_and_en : 32; // 31:0
		} rx_class14_and_en_pru0_bit;
	}; // 0x47c

	/* PRU_MII_G_RT_rx_class14_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class14_or_en_pru0;

		volatile struct {
			uint32_t rx_class14_or_en : 32; // 31:0
		} rx_class14_or_en_pru0_bit;
	}; // 0x480

	/* PRU_MII_G_RT_rx_class15_and_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class15_and_en_pru0;

		volatile struct {
			uint32_t rx_class15_and_en : 32; // 31:0
		} rx_class15_and_en_pru0_bit;
	}; // 0x484

	/* PRU_MII_G_RT_rx_class15_or_en_pru0 register bit field */
	union {
		volatile uint32_t rx_class15_or_en_pru0;

		volatile struct {
			uint32_t rx_class15_or_en : 32; // 31:0
		} rx_class15_or_en_pru0_bit;
	}; // 0x488

	/* PRU_MII_G_RT_rx_class_cfg1_pru0 register bit field */
	union {
		volatile uint32_t rx_class_cfg1_pru0;

		volatile struct {
			uint32_t rx_class0_sel : 2; // 1:0
			uint32_t rx_class1_sel : 2; // 3:2
			uint32_t rx_class2_sel : 2; // 5:4
			uint32_t rx_class3_sel : 2; // 7:6
			uint32_t rx_class4_sel : 2; // 9:8
			uint32_t rx_class5_sel : 2; // 11:10
			uint32_t rx_class6_sel : 2; // 13:12
			uint32_t rx_class7_sel : 2; // 15:14
			uint32_t rx_class8_sel : 2; // 17:16
			uint32_t rx_class9_sel : 2; // 19:18
			uint32_t rx_class10_sel : 2; // 21:20
			uint32_t rx_class11_sel : 2; // 23:22
			uint32_t rx_class12_sel : 2; // 25:24
			uint32_t rx_class13_sel : 2; // 27:26
			uint32_t rx_class14_sel : 2; // 29:28
			uint32_t rx_class15_sel : 2; // 31:30
		} rx_class_cfg1_pru0_bit;
	}; // 0x48c

	/* PRU_MII_G_RT_rx_class_cfg2_pru0 register bit field */
	union {
		volatile uint32_t rx_class_cfg2_pru0;

		volatile struct {
			uint32_t rx_class_and_nv : 16; // 15:0
			uint32_t rx_class_or_nv : 16; // 31:16
		} rx_class_cfg2_pru0_bit;
	}; // 0x490

	/* PRU_MII_G_RT_rx_class_gates0_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates0_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel0 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask0 : 1; // 4
			uint32_t rx_class_raw_mask0 : 1; // 5
			uint32_t rx_allow_mask0 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en0 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates0_pru0_bit;
	}; // 0x494

	/* PRU_MII_G_RT_rx_class_gates1_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates1_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel1 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask1 : 1; // 4
			uint32_t rx_class_raw_mask1 : 1; // 5
			uint32_t rx_allow_mask1 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en1 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates1_pru0_bit;
	}; // 0x498

	/* PRU_MII_G_RT_rx_class_gates2_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates2_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel2 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask2 : 1; // 4
			uint32_t rx_class_raw_mask2 : 1; // 5
			uint32_t rx_allow_mask2 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en2 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates2_pru0_bit;
	}; // 0x49c

	/* PRU_MII_G_RT_rx_class_gates3_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates3_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel3 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask3 : 1; // 4
			uint32_t rx_class_raw_mask3 : 1; // 5
			uint32_t rx_allow_mask3 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en3 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates3_pru0_bit;
	}; // 0x4a0

	/* PRU_MII_G_RT_rx_class_gates4_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates4_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel4 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask4 : 1; // 4
			uint32_t rx_class_raw_mask4 : 1; // 5
			uint32_t rx_allow_mask4 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en4 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates4_pru0_bit;
	}; // 0x4a4

	/* PRU_MII_G_RT_rx_class_gates5_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates5_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel5 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask5 : 1; // 4
			uint32_t rx_class_raw_mask5 : 1; // 5
			uint32_t rx_allow_mask5 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en5 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates5_pru0_bit;
	}; // 0x4a8

	/* PRU_MII_G_RT_rx_class_gates6_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates6_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel6 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask6 : 1; // 4
			uint32_t rx_class_raw_mask6 : 1; // 5
			uint32_t rx_allow_mask6 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en6 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates6_pru0_bit;
	}; // 0x4ac

	/* PRU_MII_G_RT_rx_class_gates7_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates7_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel7 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask7 : 1; // 4
			uint32_t rx_class_raw_mask7 : 1; // 5
			uint32_t rx_allow_mask7 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en7 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates7_pru0_bit;
	}; // 0x4b0

	/* PRU_MII_G_RT_rx_class_gates8_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates8_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel8 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask8 : 1; // 4
			uint32_t rx_class_raw_mask8 : 1; // 5
			uint32_t rx_allow_mask8 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en8 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates8_pru0_bit;
	}; // 0x4b4

	/* PRU_MII_G_RT_rx_class_gates9_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates9_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel9 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask9 : 1; // 4
			uint32_t rx_class_raw_mask9 : 1; // 5
			uint32_t rx_allow_mask9 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en9 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates9_pru0_bit;
	}; // 0x4b8

	/* PRU_MII_G_RT_rx_class_gates10_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates10_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel10 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask10 : 1; // 4
			uint32_t rx_class_raw_mask10 : 1; // 5
			uint32_t rx_allow_mask10 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en10 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates10_pru0_bit;
	}; // 0x4bc

	/* PRU_MII_G_RT_rx_class_gates11_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates11_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel11 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask11 : 1; // 4
			uint32_t rx_class_raw_mask11 : 1; // 5
			uint32_t rx_allow_mask11 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en11 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates11_pru0_bit;
	}; // 0x4c0

	/* PRU_MII_G_RT_rx_class_gates12_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates12_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel12 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask12 : 1; // 4
			uint32_t rx_class_raw_mask12 : 1; // 5
			uint32_t rx_allow_mask12 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en12 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates12_pru0_bit;
	}; // 0x4c4

	/* PRU_MII_G_RT_rx_class_gates13_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates13_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel13 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask13 : 1; // 4
			uint32_t rx_class_raw_mask13 : 1; // 5
			uint32_t rx_allow_mask13 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en13 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates13_pru0_bit;
	}; // 0x4c8

	/* PRU_MII_G_RT_rx_class_gates14_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates14_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel14 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask14 : 1; // 4
			uint32_t rx_class_raw_mask14 : 1; // 5
			uint32_t rx_allow_mask14 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en14 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates14_pru0_bit;
	}; // 0x4cc

	/* PRU_MII_G_RT_rx_class_gates15_pru0 register bit field */
	union {
		volatile uint32_t rx_class_gates15_pru0;

		volatile struct {
			uint32_t rx_rate_gate_sel15 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask15 : 1; // 4
			uint32_t rx_class_raw_mask15 : 1; // 5
			uint32_t rx_allow_mask15 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en15 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates15_pru0_bit;
	}; // 0x4d0

	/* PRU_MII_G_RT_rx_green_pru0 register bit field */
	union {
		volatile uint32_t rx_green_pru0;

		volatile struct {
			uint32_t rx_green_cmp_sel : 4; // 3:0
			uint32_t rx_green_val : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} rx_green_pru0_bit;
	}; // 0x4d4

	/* PRU_MII_G_RT_sa_hash_pru0 register bit field */
	union {
		volatile uint32_t sa_hash_pru0;

		volatile struct {
			uint32_t sa_hash_seed : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} sa_hash_pru0_bit;
	}; // 0x4d8

	/* PRU_MII_G_RT_conn_hash_pru0 register bit field */
	union {
		volatile uint32_t conn_hash_pru0;

		volatile struct {
			uint32_t conn_hash_seed : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} conn_hash_pru0_bit;
	}; // 0x4dc

	/* PRU_MII_G_RT_conn_hash_start_pru0 register bit field */
	union {
		volatile uint32_t conn_hash_start_pru0;

		volatile struct {
			uint32_t conn_hash_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} conn_hash_start_pru0_bit;
	}; // 0x4e0

	/* PRU_MII_G_RT_rx_rate_cfg0_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg0_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle0 : 32; // 31:0
		} rx_rate_cfg0_pru0_bit;
	}; // 0x4e4

	/* PRU_MII_G_RT_rx_rate_cfg1_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg1_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle1 : 32; // 31:0
		} rx_rate_cfg1_pru0_bit;
	}; // 0x4e8

	/* PRU_MII_G_RT_rx_rate_cfg2_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg2_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle2 : 32; // 31:0
		} rx_rate_cfg2_pru0_bit;
	}; // 0x4ec

	/* PRU_MII_G_RT_rx_rate_cfg3_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg3_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle3 : 32; // 31:0
		} rx_rate_cfg3_pru0_bit;
	}; // 0x4f0

	/* PRU_MII_G_RT_rx_rate_cfg4_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg4_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle4 : 32; // 31:0
		} rx_rate_cfg4_pru0_bit;
	}; // 0x4f4

	/* PRU_MII_G_RT_rx_rate_cfg5_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg5_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle5 : 32; // 31:0
		} rx_rate_cfg5_pru0_bit;
	}; // 0x4f8

	/* PRU_MII_G_RT_rx_rate_cfg6_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg6_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle6 : 32; // 31:0
		} rx_rate_cfg6_pru0_bit;
	}; // 0x4fc

	/* PRU_MII_G_RT_rx_rate_cfg7_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_cfg7_pru0;

		volatile struct {
			uint32_t rx_rate_cir_idle7 : 32; // 31:0
		} rx_rate_cfg7_pru0_bit;
	}; // 0x500

	/* PRU_MII_G_RT_rx_rate_src_sel0_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_src_sel0_pru0;

		volatile struct {
			uint32_t rx_rate_src_sel0 : 6; // 5:0
			uint32_t rsvd6 : 2; // 7:6
			uint32_t rx_rate_src_sel1 : 6; // 13:8
			uint32_t rsvd14 : 2; // 15:14
			uint32_t rx_rate_src_sel2 : 6; // 21:16
			uint32_t rsvd22 : 2; // 23:22
			uint32_t rx_rate_src_sel3 : 6; // 29:24
			uint32_t rsvd30 : 2; // 31:30
		} rx_rate_src_sel0_pru0_bit;
	}; // 0x504

	/* PRU_MII_G_RT_rx_rate_src_sel1_pru0 register bit field */
	union {
		volatile uint32_t rx_rate_src_sel1_pru0;

		volatile struct {
			uint32_t rx_rate_src_sel4 : 6; // 5:0
			uint32_t rsvd6 : 2; // 7:6
			uint32_t rx_rate_src_sel5 : 6; // 13:8
			uint32_t rsvd14 : 2; // 15:14
			uint32_t rx_rate_src_sel6 : 6; // 21:16
			uint32_t rsvd22 : 2; // 23:22
			uint32_t rx_rate_src_sel7 : 6; // 29:24
			uint32_t rsvd30 : 2; // 31:30
		} rx_rate_src_sel1_pru0_bit;
	}; // 0x508

	/* PRU_MII_G_RT_tx_rate_cfg1_0_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_0_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle0 : 32; // 31:0
		} tx_rate_cfg1_0_pru0_bit;
	}; // 0x50c

	/* PRU_MII_G_RT_tx_rate_cfg2_0_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_0_pru0;

		volatile struct {
			uint32_t tx_rate_len0 : 16; // 15:0
			uint32_t tx_rate_en0 : 1; // 16
			uint32_t tx_rate_allow0 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_0_pru0_bit;
	}; // 0x510

	/* PRU_MII_G_RT_tx_rate_cfg1_1_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_1_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle1 : 32; // 31:0
		} tx_rate_cfg1_1_pru0_bit;
	}; // 0x514

	/* PRU_MII_G_RT_tx_rate_cfg2_1_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_1_pru0;

		volatile struct {
			uint32_t tx_rate_len1 : 16; // 15:0
			uint32_t tx_rate_en1 : 1; // 16
			uint32_t tx_rate_allow1 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_1_pru0_bit;
	}; // 0x518

	/* PRU_MII_G_RT_tx_rate_cfg1_2_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_2_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle2 : 32; // 31:0
		} tx_rate_cfg1_2_pru0_bit;
	}; // 0x51c

	/* PRU_MII_G_RT_tx_rate_cfg2_2_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_2_pru0;

		volatile struct {
			uint32_t tx_rate_len2 : 16; // 15:0
			uint32_t tx_rate_en2 : 1; // 16
			uint32_t tx_rate_allow2 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_2_pru0_bit;
	}; // 0x520

	/* PRU_MII_G_RT_tx_rate_cfg1_3_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_3_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle3 : 32; // 31:0
		} tx_rate_cfg1_3_pru0_bit;
	}; // 0x524

	/* PRU_MII_G_RT_tx_rate_cfg2_3_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_3_pru0;

		volatile struct {
			uint32_t tx_rate_len3 : 16; // 15:0
			uint32_t tx_rate_en3 : 1; // 16
			uint32_t tx_rate_allow3 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_3_pru0_bit;
	}; // 0x528

	/* PRU_MII_G_RT_tx_rate_cfg1_4_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_4_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle4 : 32; // 31:0
		} tx_rate_cfg1_4_pru0_bit;
	}; // 0x52c

	/* PRU_MII_G_RT_tx_rate_cfg2_4_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_4_pru0;

		volatile struct {
			uint32_t tx_rate_len4 : 16; // 15:0
			uint32_t tx_rate_en4 : 1; // 16
			uint32_t tx_rate_allow4 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_4_pru0_bit;
	}; // 0x530

	/* PRU_MII_G_RT_tx_rate_cfg1_5_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_5_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle5 : 32; // 31:0
		} tx_rate_cfg1_5_pru0_bit;
	}; // 0x534

	/* PRU_MII_G_RT_tx_rate_cfg2_5_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_5_pru0;

		volatile struct {
			uint32_t tx_rate_len5 : 16; // 15:0
			uint32_t tx_rate_en5 : 1; // 16
			uint32_t tx_rate_allow5 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_5_pru0_bit;
	}; // 0x538

	/* PRU_MII_G_RT_tx_rate_cfg1_6_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_6_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle6 : 32; // 31:0
		} tx_rate_cfg1_6_pru0_bit;
	}; // 0x53c

	/* PRU_MII_G_RT_tx_rate_cfg2_6_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_6_pru0;

		volatile struct {
			uint32_t tx_rate_len6 : 16; // 15:0
			uint32_t tx_rate_en6 : 1; // 16
			uint32_t tx_rate_allow6 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_6_pru0_bit;
	}; // 0x540

	/* PRU_MII_G_RT_tx_rate_cfg1_7_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_7_pru0;

		volatile struct {
			uint32_t tx_rate_cir_idle7 : 32; // 31:0
		} tx_rate_cfg1_7_pru0_bit;
	}; // 0x544

	/* PRU_MII_G_RT_tx_rate_cfg2_7_pru0 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_7_pru0;

		volatile struct {
			uint32_t tx_rate_len7 : 16; // 15:0
			uint32_t tx_rate_en7 : 1; // 16
			uint32_t tx_rate_allow7 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_7_pru0_bit;
	}; // 0x548

	/* PRU_MII_G_RT_rx_stat_good_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_good_pru0;

		volatile struct {
			uint32_t rx_good_frm_cnt : 32; // 31:0
		} rx_stat_good_pru0_bit;
	}; // 0x54c

	/* PRU_MII_G_RT_rx_stat_bc_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bc_pru0;

		volatile struct {
			uint32_t rx_bc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bc_pru0_bit;
	}; // 0x550

	/* PRU_MII_G_RT_rx_stat_mc_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_mc_pru0;

		volatile struct {
			uint32_t rx_mc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_mc_pru0_bit;
	}; // 0x554

	/* PRU_MII_G_RT_rx_stat_crc_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_crc_err_pru0;

		volatile struct {
			uint32_t rx_crc_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_crc_err_pru0_bit;
	}; // 0x558

	/* PRU_MII_G_RT_rx_stat_mii_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_mii_err_pru0;

		volatile struct {
			uint32_t rx_mii_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_mii_err_pru0_bit;
	}; // 0x55c

	/* PRU_MII_G_RT_rx_stat_odd_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_odd_err_pru0;

		volatile struct {
			uint32_t rx_odd_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_odd_err_pru0_bit;
	}; // 0x560

	/* PRU_MII_G_RT_rx_stat_max_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_max_size_pru0;

		volatile struct {
			uint32_t rx_max_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_max_size_pru0_bit;
	}; // 0x564

	/* PRU_MII_G_RT_rx_stat_max_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_max_err_pru0;

		volatile struct {
			uint32_t rx_max_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_max_err_pru0_bit;
	}; // 0x568

	/* PRU_MII_G_RT_rx_stat_min_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_min_size_pru0;

		volatile struct {
			uint32_t rx_min_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_min_size_pru0_bit;
	}; // 0x56c

	/* PRU_MII_G_RT_rx_stat_min_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_min_err_pru0;

		volatile struct {
			uint32_t rx_min_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_min_err_pru0_bit;
	}; // 0x570

	/* PRU_MII_G_RT_rx_stat_overrun_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_overrun_err_pru0;

		volatile struct {
			uint32_t rx_overrun_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_overrun_err_pru0_bit;
	}; // 0x574

	/* PRU_MII_G_RT_rx_stat_class0_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class0_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class0_pru0 : 32; // 31:0
		} rx_stat_class0_hit_pru0_bit;
	}; // 0x578

	/* PRU_MII_G_RT_rx_stat_class1_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class1_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class1_pru0 : 32; // 31:0
		} rx_stat_class1_hit_pru0_bit;
	}; // 0x57c

	/* PRU_MII_G_RT_rx_stat_class2_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class2_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class2_pru0 : 32; // 31:0
		} rx_stat_class2_hit_pru0_bit;
	}; // 0x580

	/* PRU_MII_G_RT_rx_stat_class3_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class3_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class3_pru0 : 32; // 31:0
		} rx_stat_class3_hit_pru0_bit;
	}; // 0x584

	/* PRU_MII_G_RT_rx_stat_class4_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class4_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class4_pru0 : 32; // 31:0
		} rx_stat_class4_hit_pru0_bit;
	}; // 0x588

	/* PRU_MII_G_RT_rx_stat_class5_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class5_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class5_pru0 : 32; // 31:0
		} rx_stat_class5_hit_pru0_bit;
	}; // 0x58c

	/* PRU_MII_G_RT_rx_stat_class6_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class6_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class6_pru0 : 32; // 31:0
		} rx_stat_class6_hit_pru0_bit;
	}; // 0x590

	/* PRU_MII_G_RT_rx_stat_class7_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class7_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class7_pru0 : 32; // 31:0
		} rx_stat_class7_hit_pru0_bit;
	}; // 0x594

	/* PRU_MII_G_RT_rx_stat_class8_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class8_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class8_pru0 : 32; // 31:0
		} rx_stat_class8_hit_pru0_bit;
	}; // 0x598

	/* PRU_MII_G_RT_rx_stat_class9_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class9_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class9_pru0 : 32; // 31:0
		} rx_stat_class9_hit_pru0_bit;
	}; // 0x59c

	/* PRU_MII_G_RT_rx_stat_class10_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class10_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class10_pru0 : 32; // 31:0
		} rx_stat_class10_hit_pru0_bit;
	}; // 0x5a0

	/* PRU_MII_G_RT_rx_stat_class11_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class11_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class11_pru0 : 32; // 31:0
		} rx_stat_class11_hit_pru0_bit;
	}; // 0x5a4

	/* PRU_MII_G_RT_rx_stat_class12_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class12_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class12_pru0 : 32; // 31:0
		} rx_stat_class12_hit_pru0_bit;
	}; // 0x5a8

	/* PRU_MII_G_RT_rx_stat_class13_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class13_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class13_pru0 : 32; // 31:0
		} rx_stat_class13_hit_pru0_bit;
	}; // 0x5ac

	/* PRU_MII_G_RT_rx_stat_class14_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class14_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class14_pru0 : 32; // 31:0
		} rx_stat_class14_hit_pru0_bit;
	}; // 0x5b0

	/* PRU_MII_G_RT_rx_stat_class15_hit_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_class15_hit_pru0;

		volatile struct {
			uint32_t rx_stat_class15_pru0 : 32; // 31:0
		} rx_stat_class15_hit_pru0_bit;
	}; // 0x5b4

	/* PRU_MII_G_RT_rx_stat_smd_frag_err_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_smd_frag_err_pru0;

		volatile struct {
			uint32_t rx_stat_smds_err_pru0 : 8; // 7:0
			uint32_t rx_stat_smdc_err_pru0 : 8; // 15:8
			uint32_t rx_stat_frag_err_pru0 : 8; // 23:16
			uint32_t rx_stat_smd_err_pru0 : 8; // 31:24
		} rx_stat_smd_frag_err_pru0_bit;
	}; // 0x5b8

	/* PRU_MII_G_RT_rx_stat_bkt1_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt1_size_pru0;

		volatile struct {
			uint32_t rx_stat_bkt1_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt1_size_pru0_bit;
	}; // 0x5bc

	/* PRU_MII_G_RT_rx_stat_bkt2_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt2_size_pru0;

		volatile struct {
			uint32_t rx_stat_bkt2_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt2_size_pru0_bit;
	}; // 0x5c0

	/* PRU_MII_G_RT_rx_stat_bkt3_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt3_size_pru0;

		volatile struct {
			uint32_t rx_stat_bkt3_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt3_size_pru0_bit;
	}; // 0x5c4

	/* PRU_MII_G_RT_rx_stat_bkt4_size_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt4_size_pru0;

		volatile struct {
			uint32_t rx_stat_bkt4_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt4_size_pru0_bit;
	}; // 0x5c8

	/* PRU_MII_G_RT_rx_stat_64_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_64_pru0;

		volatile struct {
			uint32_t rx_64_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_64_pru0_bit;
	}; // 0x5cc

	/* PRU_MII_G_RT_rx_stat_bkt1_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt1_pru0;

		volatile struct {
			uint32_t rx_stat_bkt1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt1_pru0_bit;
	}; // 0x5d0

	/* PRU_MII_G_RT_rx_stat_bkt2_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt2_pru0;

		volatile struct {
			uint32_t rx_stat_bkt2 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt2_pru0_bit;
	}; // 0x5d4

	/* PRU_MII_G_RT_rx_stat_bkt3_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt3_pru0;

		volatile struct {
			uint32_t rx_stat_bkt3 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt3_pru0_bit;
	}; // 0x5d8

	/* PRU_MII_G_RT_rx_stat_bkt4_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt4_pru0;

		volatile struct {
			uint32_t rx_stat_bkt4 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt4_pru0_bit;
	}; // 0x5dc

	/* PRU_MII_G_RT_rx_stat_bkt5_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_bkt5_pru0;

		volatile struct {
			uint32_t rx_stat_bkt5 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt5_pru0_bit;
	}; // 0x5e0

	/* PRU_MII_G_RT_rx_stat_total_bytes_pru0 register bit field */
	union {
		volatile uint32_t rx_stat_total_bytes_pru0;

		volatile struct {
			uint32_t rx_stat_total_bytes_pru : 32; // 31:0
		} rx_stat_total_bytes_pru0_bit;
	}; // 0x5e4

	/* PRU_MII_G_RT_rxtx_stat_total_bytes_pru0 register bit field */
	union {
		volatile uint32_t rxtx_stat_total_bytes_pru0;

		volatile struct {
			uint32_t rxtx_stat_total_bytes_pru : 32; // 31:0
		} rxtx_stat_total_bytes_pru0_bit;
	}; // 0x5e8

	/* PRU_MII_G_RT_tx_stat_good_port0 register bit field */
	union {
		volatile uint32_t tx_stat_good_port0;

		volatile struct {
			uint32_t tx_good_frm_cnt : 32; // 31:0
		} tx_stat_good_port0_bit;
	}; // 0x5ec

	/* PRU_MII_G_RT_tx_stat_bc_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bc_port0;

		volatile struct {
			uint32_t tx_bc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bc_port0_bit;
	}; // 0x5f0

	/* PRU_MII_G_RT_tx_stat_mc_port0 register bit field */
	union {
		volatile uint32_t tx_stat_mc_port0;

		volatile struct {
			uint32_t tx_mc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_mc_port0_bit;
	}; // 0x5f4

	/* PRU_MII_G_RT_tx_stat_odd_err_port0 register bit field */
	union {
		volatile uint32_t tx_stat_odd_err_port0;

		volatile struct {
			uint32_t tx_odd_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_odd_err_port0_bit;
	}; // 0x5f8

	/* PRU_MII_G_RT_tx_stat_underflow_err_port0 register bit field */
	union {
		volatile uint32_t tx_stat_underflow_err_port0;

		volatile struct {
			uint32_t tx_underflow_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_underflow_err_port0_bit;
	}; // 0x5fc

	/* PRU_MII_G_RT_tx_stat_max_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_max_size_port0;

		volatile struct {
			uint32_t tx_max_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_max_size_port0_bit;
	}; // 0x600

	/* PRU_MII_G_RT_tx_stat_max_err_port0 register bit field */
	union {
		volatile uint32_t tx_stat_max_err_port0;

		volatile struct {
			uint32_t tx_max_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_max_err_port0_bit;
	}; // 0x604

	/* PRU_MII_G_RT_tx_stat_min_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_min_size_port0;

		volatile struct {
			uint32_t tx_min_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_min_size_port0_bit;
	}; // 0x608

	/* PRU_MII_G_RT_tx_stat_min_err_port0 register bit field */
	union {
		volatile uint32_t tx_stat_min_err_port0;

		volatile struct {
			uint32_t tx_min_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_min_err_port0_bit;
	}; // 0x60c

	/* PRU_MII_G_RT_tx_stat_bkt1_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt1_size_port0;

		volatile struct {
			uint32_t tx_stat_bkt1_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt1_size_port0_bit;
	}; // 0x610

	/* PRU_MII_G_RT_tx_stat_bkt2_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt2_size_port0;

		volatile struct {
			uint32_t tx_stat_bkt2_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt2_size_port0_bit;
	}; // 0x614

	/* PRU_MII_G_RT_tx_stat_bkt3_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt3_size_port0;

		volatile struct {
			uint32_t tx_stat_bkt3_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt3_size_port0_bit;
	}; // 0x618

	/* PRU_MII_G_RT_tx_stat_bkt4_size_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt4_size_port0;

		volatile struct {
			uint32_t tx_stat_bkt4_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt4_size_port0_bit;
	}; // 0x61c

	/* PRU_MII_G_RT_tx_stat_64_port0 register bit field */
	union {
		volatile uint32_t tx_stat_64_port0;

		volatile struct {
			uint32_t tx_64_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_64_port0_bit;
	}; // 0x620

	/* PRU_MII_G_RT_tx_stat_bkt1_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt1_port0;

		volatile struct {
			uint32_t tx_stat_bkt1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt1_port0_bit;
	}; // 0x624

	/* PRU_MII_G_RT_tx_stat_bkt2_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt2_port0;

		volatile struct {
			uint32_t tx_stat_bkt2 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt2_port0_bit;
	}; // 0x628

	/* PRU_MII_G_RT_tx_stat_bkt3_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt3_port0;

		volatile struct {
			uint32_t tx_stat_bkt3 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt3_port0_bit;
	}; // 0x62c

	/* PRU_MII_G_RT_tx_stat_bkt4_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt4_port0;

		volatile struct {
			uint32_t tx_stat_bkt4 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt4_port0_bit;
	}; // 0x630

	/* PRU_MII_G_RT_tx_stat_bkt5_port0 register bit field */
	union {
		volatile uint32_t tx_stat_bkt5_port0;

		volatile struct {
			uint32_t tx_stat_bkt5 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt5_port0_bit;
	}; // 0x634

	/* PRU_MII_G_RT_tx_stat_total_bytes_port0 register bit field */
	union {
		volatile uint32_t tx_stat_total_bytes_port0;

		volatile struct {
			uint32_t tx_total_stat_bytes_port : 32; // 31:0
		} tx_stat_total_bytes_port0_bit;
	}; // 0x638

	/* PRU_MII_G_RT_tx_hsr_tag_port0 register bit field */
	union {
		volatile uint32_t tx_hsr_tag_port0;

		volatile struct {
			uint32_t tx_hsr_tag : 32; // 31:0
		} tx_hsr_tag_port0_bit;
	}; // 0x63c

	/* PRU_MII_G_RT_tx_hsr_seq_port0 register bit field */
	union {
		volatile uint32_t tx_hsr_seq_port0;

		volatile struct {
			uint32_t tx_hsr_seq : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_hsr_seq_port0_bit;
	}; // 0x640

	/* PRU_MII_G_RT_tx_vlan_type_tag_port0 register bit field */
	union {
		volatile uint32_t tx_vlan_type_tag_port0;

		volatile struct {
			uint32_t tx_vlan_type_tag : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_vlan_type_tag_port0_bit;
	}; // 0x644

	/* PRU_MII_G_RT_tx_vlan_ins_tag_port0 register bit field */
	union {
		volatile uint32_t tx_vlan_ins_tag_port0;

		volatile struct {
			uint32_t tx_vlan_ins_tag : 32; // 31:0
		} tx_vlan_ins_tag_port0_bit;
	}; // 0x648

	/* PRU_MII_G_RT_ft1_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft1_start_len_pru1;

		volatile struct {
			uint32_t ft1_start : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft1_len : 4; // 19:16
			uint32_t rsvd20 : 12; // 31:20
		} ft1_start_len_pru1_bit;
	}; // 0x64c

	/* PRU_MII_G_RT_ft1_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft1_cfg_pru1;

		volatile struct {
			uint32_t ft1_0cfg : 2; // 1:0
			uint32_t ft1_1cfg : 2; // 3:2
			uint32_t ft1_2cfg : 2; // 5:4
			uint32_t ft1_3cfg : 2; // 7:6
			uint32_t ft1_4cfg : 2; // 9:8
			uint32_t ft1_5cfg : 2; // 11:10
			uint32_t ft1_6cfg : 2; // 13:12
			uint32_t ft1_7cfg : 2; // 15:14
			uint32_t rsvd16 : 16; // 31:16
		} ft1_cfg_pru1_bit;
	}; // 0x650

	/* PRU_MII_G_RT_ft1_0_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_0_da0_pru1;

		volatile struct {
			uint32_t ft1_0_da0 : 32; // 31:0
		} ft1_0_da0_pru1_bit;
	}; // 0x654

	/* PRU_MII_G_RT_ft1_0_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_0_da1_pru1;

		volatile struct {
			uint32_t ft1_0_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_0_da1_pru1_bit;
	}; // 0x658

	/* PRU_MII_G_RT_ft1_0_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_0_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_0_da_mask0 : 32; // 31:0
		} ft1_0_da_mask0_pru1_bit;
	}; // 0x65c

	/* PRU_MII_G_RT_ft1_0_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_0_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_0_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_0_da_mask1_pru1_bit;
	}; // 0x660

	/* PRU_MII_G_RT_ft1_1_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_1_da0_pru1;

		volatile struct {
			uint32_t ft1_1_da0 : 32; // 31:0
		} ft1_1_da0_pru1_bit;
	}; // 0x664

	/* PRU_MII_G_RT_ft1_1_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_1_da1_pru1;

		volatile struct {
			uint32_t ft1_1_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_1_da1_pru1_bit;
	}; // 0x668

	/* PRU_MII_G_RT_ft1_1_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_1_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_1_da_mask0 : 32; // 31:0
		} ft1_1_da_mask0_pru1_bit;
	}; // 0x66c

	/* PRU_MII_G_RT_ft1_1_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_1_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_1_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_1_da_mask1_pru1_bit;
	}; // 0x670

	/* PRU_MII_G_RT_ft1_2_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_2_da0_pru1;

		volatile struct {
			uint32_t ft1_2_da0 : 32; // 31:0
		} ft1_2_da0_pru1_bit;
	}; // 0x674

	/* PRU_MII_G_RT_ft1_2_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_2_da1_pru1;

		volatile struct {
			uint32_t ft1_2_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_2_da1_pru1_bit;
	}; // 0x678

	/* PRU_MII_G_RT_ft1_2_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_2_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_2_da_mask0 : 32; // 31:0
		} ft1_2_da_mask0_pru1_bit;
	}; // 0x67c

	/* PRU_MII_G_RT_ft1_2_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_2_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_2_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_2_da_mask1_pru1_bit;
	}; // 0x680

	/* PRU_MII_G_RT_ft1_3_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_3_da0_pru1;

		volatile struct {
			uint32_t ft1_3_da0 : 32; // 31:0
		} ft1_3_da0_pru1_bit;
	}; // 0x684

	/* PRU_MII_G_RT_ft1_3_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_3_da1_pru1;

		volatile struct {
			uint32_t ft1_3_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_3_da1_pru1_bit;
	}; // 0x688

	/* PRU_MII_G_RT_ft1_3_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_3_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_3_da_mask0 : 32; // 31:0
		} ft1_3_da_mask0_pru1_bit;
	}; // 0x68c

	/* PRU_MII_G_RT_ft1_3_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_3_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_3_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_3_da_mask1_pru1_bit;
	}; // 0x690

	/* PRU_MII_G_RT_ft1_4_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_4_da0_pru1;

		volatile struct {
			uint32_t ft1_4_da0 : 32; // 31:0
		} ft1_4_da0_pru1_bit;
	}; // 0x694

	/* PRU_MII_G_RT_ft1_4_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_4_da1_pru1;

		volatile struct {
			uint32_t ft1_4_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_4_da1_pru1_bit;
	}; // 0x698

	/* PRU_MII_G_RT_ft1_4_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_4_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_4_da_mask0 : 32; // 31:0
		} ft1_4_da_mask0_pru1_bit;
	}; // 0x69c

	/* PRU_MII_G_RT_ft1_4_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_4_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_4_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_4_da_mask1_pru1_bit;
	}; // 0x6a0

	/* PRU_MII_G_RT_ft1_5_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_5_da0_pru1;

		volatile struct {
			uint32_t ft1_5_da0 : 32; // 31:0
		} ft1_5_da0_pru1_bit;
	}; // 0x6a4

	/* PRU_MII_G_RT_ft1_5_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_5_da1_pru1;

		volatile struct {
			uint32_t ft1_5_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_5_da1_pru1_bit;
	}; // 0x6a8

	/* PRU_MII_G_RT_ft1_5_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_5_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_5_da_mask0 : 32; // 31:0
		} ft1_5_da_mask0_pru1_bit;
	}; // 0x6ac

	/* PRU_MII_G_RT_ft1_5_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_5_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_5_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_5_da_mask1_pru1_bit;
	}; // 0x6b0

	/* PRU_MII_G_RT_ft1_6_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_6_da0_pru1;

		volatile struct {
			uint32_t ft1_6_da0 : 32; // 31:0
		} ft1_6_da0_pru1_bit;
	}; // 0x6b4

	/* PRU_MII_G_RT_ft1_6_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_6_da1_pru1;

		volatile struct {
			uint32_t ft1_6_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_6_da1_pru1_bit;
	}; // 0x6b8

	/* PRU_MII_G_RT_ft1_6_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_6_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_6_da_mask0 : 32; // 31:0
		} ft1_6_da_mask0_pru1_bit;
	}; // 0x6bc

	/* PRU_MII_G_RT_ft1_6_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_6_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_6_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_6_da_mask1_pru1_bit;
	}; // 0x6c0

	/* PRU_MII_G_RT_ft1_7_da0_pru1 register bit field */
	union {
		volatile uint32_t ft1_7_da0_pru1;

		volatile struct {
			uint32_t ft1_7_da0 : 32; // 31:0
		} ft1_7_da0_pru1_bit;
	}; // 0x6c4

	/* PRU_MII_G_RT_ft1_7_da1_pru1 register bit field */
	union {
		volatile uint32_t ft1_7_da1_pru1;

		volatile struct {
			uint32_t ft1_7_da1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_7_da1_pru1_bit;
	}; // 0x6c8

	/* PRU_MII_G_RT_ft1_7_da_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft1_7_da_mask0_pru1;

		volatile struct {
			uint32_t ft1_7_da_mask0 : 32; // 31:0
		} ft1_7_da_mask0_pru1_bit;
	}; // 0x6cc

	/* PRU_MII_G_RT_ft1_7_da_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft1_7_da_mask1_pru1;

		volatile struct {
			uint32_t ft1_7_da_mask1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} ft1_7_da_mask1_pru1_bit;
	}; // 0x6d0

	/* PRU_MII_G_RT_ft3_0_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_0_start_pru1_bit;
	}; // 0x6d4

	/* PRU_MII_G_RT_ft3_0_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_0_start_auto_pru1_bit;
	}; // 0x6d8

	/* PRU_MII_G_RT_ft3_0_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_0_start_len_pru1_bit;
	}; // 0x6dc

	/* PRU_MII_G_RT_ft3_0_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_0_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_0_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_0_jmp_offset_pru1_bit;
	}; // 0x6e0

	/* PRU_MII_G_RT_ft3_0_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_len_pru1;

		volatile struct {
			uint32_t ft3_0_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_0_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_0_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_0_len_pru1_bit;
	}; // 0x6e4

	/* PRU_MII_G_RT_ft3_0_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_cfg_pru1;

		volatile struct {
			uint32_t ft3_0cfg : 2; // 1:0
			uint32_t ft3_0_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_0_trig_or_en : 16; // 31:16
		} ft3_0_cfg_pru1_bit;
	}; // 0x6e8

	/* PRU_MII_G_RT_ft3_0_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_t_pru1;

		volatile struct {
			uint32_t ft3_0_t : 32; // 31:0
		} ft3_0_t_pru1_bit;
	}; // 0x6ec

	/* PRU_MII_G_RT_ft3_0_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_t_mask_pru1;

		volatile struct {
			uint32_t ft3_0_t_mask : 32; // 31:0
		} ft3_0_t_mask_pru1_bit;
	}; // 0x6f0

	/* PRU_MII_G_RT_ft3_1_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_1_start_pru1_bit;
	}; // 0x6f4

	/* PRU_MII_G_RT_ft3_1_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_1_start_auto_pru1_bit;
	}; // 0x6f8

	/* PRU_MII_G_RT_ft3_1_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_1_start_len_pru1_bit;
	}; // 0x6fc

	/* PRU_MII_G_RT_ft3_1_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_1_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_1_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_1_jmp_offset_pru1_bit;
	}; // 0x700

	/* PRU_MII_G_RT_ft3_1_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_len_pru1;

		volatile struct {
			uint32_t ft3_1_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_1_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_1_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_1_len_pru1_bit;
	}; // 0x704

	/* PRU_MII_G_RT_ft3_1_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_cfg_pru1;

		volatile struct {
			uint32_t ft3_1cfg : 2; // 1:0
			uint32_t ft3_1_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_1_trig_or_en : 16; // 31:16
		} ft3_1_cfg_pru1_bit;
	}; // 0x708

	/* PRU_MII_G_RT_ft3_1_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_t_pru1;

		volatile struct {
			uint32_t ft3_1_t : 32; // 31:0
		} ft3_1_t_pru1_bit;
	}; // 0x70c

	/* PRU_MII_G_RT_ft3_1_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_t_mask_pru1;

		volatile struct {
			uint32_t ft3_1_t_mask : 32; // 31:0
		} ft3_1_t_mask_pru1_bit;
	}; // 0x710

	/* PRU_MII_G_RT_ft3_2_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_2_start_pru1_bit;
	}; // 0x714

	/* PRU_MII_G_RT_ft3_2_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_2_start_auto_pru1_bit;
	}; // 0x718

	/* PRU_MII_G_RT_ft3_2_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_2_start_len_pru1_bit;
	}; // 0x71c

	/* PRU_MII_G_RT_ft3_2_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_2_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_2_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_2_jmp_offset_pru1_bit;
	}; // 0x720

	/* PRU_MII_G_RT_ft3_2_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_len_pru1;

		volatile struct {
			uint32_t ft3_2_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_2_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_2_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_2_len_pru1_bit;
	}; // 0x724

	/* PRU_MII_G_RT_ft3_2_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_cfg_pru1;

		volatile struct {
			uint32_t ft3_2cfg : 2; // 1:0
			uint32_t ft3_2_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_2_trig_or_en : 16; // 31:16
		} ft3_2_cfg_pru1_bit;
	}; // 0x728

	/* PRU_MII_G_RT_ft3_2_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_t_pru1;

		volatile struct {
			uint32_t ft3_2_t : 32; // 31:0
		} ft3_2_t_pru1_bit;
	}; // 0x72c

	/* PRU_MII_G_RT_ft3_2_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_t_mask_pru1;

		volatile struct {
			uint32_t ft3_2_t_mask : 32; // 31:0
		} ft3_2_t_mask_pru1_bit;
	}; // 0x730

	/* PRU_MII_G_RT_ft3_3_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_3_start_pru1_bit;
	}; // 0x734

	/* PRU_MII_G_RT_ft3_3_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_3_start_auto_pru1_bit;
	}; // 0x738

	/* PRU_MII_G_RT_ft3_3_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_3_start_len_pru1_bit;
	}; // 0x73c

	/* PRU_MII_G_RT_ft3_3_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_3_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_3_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_3_jmp_offset_pru1_bit;
	}; // 0x740

	/* PRU_MII_G_RT_ft3_3_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_len_pru1;

		volatile struct {
			uint32_t ft3_3_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_3_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_3_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_3_len_pru1_bit;
	}; // 0x744

	/* PRU_MII_G_RT_ft3_3_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_cfg_pru1;

		volatile struct {
			uint32_t ft3_3cfg : 2; // 1:0
			uint32_t ft3_3_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_3_trig_or_en : 16; // 31:16
		} ft3_3_cfg_pru1_bit;
	}; // 0x748

	/* PRU_MII_G_RT_ft3_3_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_t_pru1;

		volatile struct {
			uint32_t ft3_3_t : 32; // 31:0
		} ft3_3_t_pru1_bit;
	}; // 0x74c

	/* PRU_MII_G_RT_ft3_3_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_t_mask_pru1;

		volatile struct {
			uint32_t ft3_3_t_mask : 32; // 31:0
		} ft3_3_t_mask_pru1_bit;
	}; // 0x750

	/* PRU_MII_G_RT_ft3_4_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_4_start_pru1_bit;
	}; // 0x754

	/* PRU_MII_G_RT_ft3_4_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_4_start_auto_pru1_bit;
	}; // 0x758

	/* PRU_MII_G_RT_ft3_4_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_4_start_len_pru1_bit;
	}; // 0x75c

	/* PRU_MII_G_RT_ft3_4_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_4_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_4_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_4_jmp_offset_pru1_bit;
	}; // 0x760

	/* PRU_MII_G_RT_ft3_4_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_len_pru1;

		volatile struct {
			uint32_t ft3_4_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_4_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_4_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_4_len_pru1_bit;
	}; // 0x764

	/* PRU_MII_G_RT_ft3_4_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_cfg_pru1;

		volatile struct {
			uint32_t ft3_4cfg : 2; // 1:0
			uint32_t ft3_4_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_4_trig_or_en : 16; // 31:16
		} ft3_4_cfg_pru1_bit;
	}; // 0x768

	/* PRU_MII_G_RT_ft3_4_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_t_pru1;

		volatile struct {
			uint32_t ft3_4_t : 32; // 31:0
		} ft3_4_t_pru1_bit;
	}; // 0x76c

	/* PRU_MII_G_RT_ft3_4_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_t_mask_pru1;

		volatile struct {
			uint32_t ft3_4_t_mask : 32; // 31:0
		} ft3_4_t_mask_pru1_bit;
	}; // 0x770

	/* PRU_MII_G_RT_ft3_5_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_5_start_pru1_bit;
	}; // 0x774

	/* PRU_MII_G_RT_ft3_5_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_5_start_auto_pru1_bit;
	}; // 0x778

	/* PRU_MII_G_RT_ft3_5_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_5_start_len_pru1_bit;
	}; // 0x77c

	/* PRU_MII_G_RT_ft3_5_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_5_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_5_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_5_jmp_offset_pru1_bit;
	}; // 0x780

	/* PRU_MII_G_RT_ft3_5_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_len_pru1;

		volatile struct {
			uint32_t ft3_5_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_5_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_5_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_5_len_pru1_bit;
	}; // 0x784

	/* PRU_MII_G_RT_ft3_5_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_cfg_pru1;

		volatile struct {
			uint32_t ft3_5cfg : 2; // 1:0
			uint32_t ft3_5_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_5_trig_or_en : 16; // 31:16
		} ft3_5_cfg_pru1_bit;
	}; // 0x788

	/* PRU_MII_G_RT_ft3_5_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_t_pru1;

		volatile struct {
			uint32_t ft3_5_t : 32; // 31:0
		} ft3_5_t_pru1_bit;
	}; // 0x78c

	/* PRU_MII_G_RT_ft3_5_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_t_mask_pru1;

		volatile struct {
			uint32_t ft3_5_t_mask : 32; // 31:0
		} ft3_5_t_mask_pru1_bit;
	}; // 0x790

	/* PRU_MII_G_RT_ft3_6_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_6_start_pru1_bit;
	}; // 0x794

	/* PRU_MII_G_RT_ft3_6_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_6_start_auto_pru1_bit;
	}; // 0x798

	/* PRU_MII_G_RT_ft3_6_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_6_start_len_pru1_bit;
	}; // 0x79c

	/* PRU_MII_G_RT_ft3_6_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_6_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_6_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_6_jmp_offset_pru1_bit;
	}; // 0x7a0

	/* PRU_MII_G_RT_ft3_6_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_len_pru1;

		volatile struct {
			uint32_t ft3_6_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_6_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_6_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_6_len_pru1_bit;
	}; // 0x7a4

	/* PRU_MII_G_RT_ft3_6_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_cfg_pru1;

		volatile struct {
			uint32_t ft3_6cfg : 2; // 1:0
			uint32_t ft3_6_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_6_trig_or_en : 16; // 31:16
		} ft3_6_cfg_pru1_bit;
	}; // 0x7a8

	/* PRU_MII_G_RT_ft3_6_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_t_pru1;

		volatile struct {
			uint32_t ft3_6_t : 32; // 31:0
		} ft3_6_t_pru1_bit;
	}; // 0x7ac

	/* PRU_MII_G_RT_ft3_6_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_t_mask_pru1;

		volatile struct {
			uint32_t ft3_6_t_mask : 32; // 31:0
		} ft3_6_t_mask_pru1_bit;
	}; // 0x7b0

	/* PRU_MII_G_RT_ft3_7_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_7_start_pru1_bit;
	}; // 0x7b4

	/* PRU_MII_G_RT_ft3_7_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_7_start_auto_pru1_bit;
	}; // 0x7b8

	/* PRU_MII_G_RT_ft3_7_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_7_start_len_pru1_bit;
	}; // 0x7bc

	/* PRU_MII_G_RT_ft3_7_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_7_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_7_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_7_jmp_offset_pru1_bit;
	}; // 0x7c0

	/* PRU_MII_G_RT_ft3_7_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_len_pru1;

		volatile struct {
			uint32_t ft3_7_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_7_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_7_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_7_len_pru1_bit;
	}; // 0x7c4

	/* PRU_MII_G_RT_ft3_7_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_cfg_pru1;

		volatile struct {
			uint32_t ft3_7cfg : 2; // 1:0
			uint32_t ft3_7_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_7_trig_or_en : 16; // 31:16
		} ft3_7_cfg_pru1_bit;
	}; // 0x7c8

	/* PRU_MII_G_RT_ft3_7_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_t_pru1;

		volatile struct {
			uint32_t ft3_7_t : 32; // 31:0
		} ft3_7_t_pru1_bit;
	}; // 0x7cc

	/* PRU_MII_G_RT_ft3_7_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_t_mask_pru1;

		volatile struct {
			uint32_t ft3_7_t_mask : 32; // 31:0
		} ft3_7_t_mask_pru1_bit;
	}; // 0x7d0

	/* PRU_MII_G_RT_ft3_8_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_8_start_pru1_bit;
	}; // 0x7d4

	/* PRU_MII_G_RT_ft3_8_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_8_start_auto_pru1_bit;
	}; // 0x7d8

	/* PRU_MII_G_RT_ft3_8_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_8_start_len_pru1_bit;
	}; // 0x7dc

	/* PRU_MII_G_RT_ft3_8_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_8_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_8_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_8_jmp_offset_pru1_bit;
	}; // 0x7e0

	/* PRU_MII_G_RT_ft3_8_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_len_pru1;

		volatile struct {
			uint32_t ft3_8_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_8_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_8_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_8_len_pru1_bit;
	}; // 0x7e4

	/* PRU_MII_G_RT_ft3_8_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_cfg_pru1;

		volatile struct {
			uint32_t ft3_8cfg : 2; // 1:0
			uint32_t ft3_8_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_8_trig_or_en : 16; // 31:16
		} ft3_8_cfg_pru1_bit;
	}; // 0x7e8

	/* PRU_MII_G_RT_ft3_8_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_t_pru1;

		volatile struct {
			uint32_t ft3_8_t : 32; // 31:0
		} ft3_8_t_pru1_bit;
	}; // 0x7ec

	/* PRU_MII_G_RT_ft3_8_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_t_mask_pru1;

		volatile struct {
			uint32_t ft3_8_t_mask : 32; // 31:0
		} ft3_8_t_mask_pru1_bit;
	}; // 0x7f0

	/* PRU_MII_G_RT_ft3_9_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_9_start_pru1_bit;
	}; // 0x7f4

	/* PRU_MII_G_RT_ft3_9_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_9_start_auto_pru1_bit;
	}; // 0x7f8

	/* PRU_MII_G_RT_ft3_9_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_9_start_len_pru1_bit;
	}; // 0x7fc

	/* PRU_MII_G_RT_ft3_9_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_9_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_9_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_9_jmp_offset_pru1_bit;
	}; // 0x800

	/* PRU_MII_G_RT_ft3_9_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_len_pru1;

		volatile struct {
			uint32_t ft3_9_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_9_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_9_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_9_len_pru1_bit;
	}; // 0x804

	/* PRU_MII_G_RT_ft3_9_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_cfg_pru1;

		volatile struct {
			uint32_t ft3_9cfg : 2; // 1:0
			uint32_t ft3_9_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_9_trig_or_en : 16; // 31:16
		} ft3_9_cfg_pru1_bit;
	}; // 0x808

	/* PRU_MII_G_RT_ft3_9_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_t_pru1;

		volatile struct {
			uint32_t ft3_9_t : 32; // 31:0
		} ft3_9_t_pru1_bit;
	}; // 0x80c

	/* PRU_MII_G_RT_ft3_9_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_t_mask_pru1;

		volatile struct {
			uint32_t ft3_9_t_mask : 32; // 31:0
		} ft3_9_t_mask_pru1_bit;
	}; // 0x810

	/* PRU_MII_G_RT_ft3_10_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_10_start_pru1_bit;
	}; // 0x814

	/* PRU_MII_G_RT_ft3_10_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_10_start_auto_pru1_bit;
	}; // 0x818

	/* PRU_MII_G_RT_ft3_10_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_10_start_len_pru1_bit;
	}; // 0x81c

	/* PRU_MII_G_RT_ft3_10_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_10_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_10_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_10_jmp_offset_pru1_bit;
	}; // 0x820

	/* PRU_MII_G_RT_ft3_10_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_len_pru1;

		volatile struct {
			uint32_t ft3_10_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_10_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_10_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_10_len_pru1_bit;
	}; // 0x824

	/* PRU_MII_G_RT_ft3_10_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_cfg_pru1;

		volatile struct {
			uint32_t ft3_10cfg : 2; // 1:0
			uint32_t ft3_10_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_10_trig_or_en : 16; // 31:16
		} ft3_10_cfg_pru1_bit;
	}; // 0x828

	/* PRU_MII_G_RT_ft3_10_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_t_pru1;

		volatile struct {
			uint32_t ft3_10_t : 32; // 31:0
		} ft3_10_t_pru1_bit;
	}; // 0x82c

	/* PRU_MII_G_RT_ft3_10_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_t_mask_pru1;

		volatile struct {
			uint32_t ft3_10_t_mask : 32; // 31:0
		} ft3_10_t_mask_pru1_bit;
	}; // 0x830

	/* PRU_MII_G_RT_ft3_11_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_11_start_pru1_bit;
	}; // 0x834

	/* PRU_MII_G_RT_ft3_11_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_11_start_auto_pru1_bit;
	}; // 0x838

	/* PRU_MII_G_RT_ft3_11_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_11_start_len_pru1_bit;
	}; // 0x83c

	/* PRU_MII_G_RT_ft3_11_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_11_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_11_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_11_jmp_offset_pru1_bit;
	}; // 0x840

	/* PRU_MII_G_RT_ft3_11_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_len_pru1;

		volatile struct {
			uint32_t ft3_11_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_11_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_11_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_11_len_pru1_bit;
	}; // 0x844

	/* PRU_MII_G_RT_ft3_11_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_cfg_pru1;

		volatile struct {
			uint32_t ft3_11cfg : 2; // 1:0
			uint32_t ft3_11_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_11_trig_or_en : 16; // 31:16
		} ft3_11_cfg_pru1_bit;
	}; // 0x848

	/* PRU_MII_G_RT_ft3_11_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_t_pru1;

		volatile struct {
			uint32_t ft3_11_t : 32; // 31:0
		} ft3_11_t_pru1_bit;
	}; // 0x84c

	/* PRU_MII_G_RT_ft3_11_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_t_mask_pru1;

		volatile struct {
			uint32_t ft3_11_t_mask : 32; // 31:0
		} ft3_11_t_mask_pru1_bit;
	}; // 0x850

	/* PRU_MII_G_RT_ft3_12_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_12_start_pru1_bit;
	}; // 0x854

	/* PRU_MII_G_RT_ft3_12_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_12_start_auto_pru1_bit;
	}; // 0x858

	/* PRU_MII_G_RT_ft3_12_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_12_start_len_pru1_bit;
	}; // 0x85c

	/* PRU_MII_G_RT_ft3_12_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_12_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_12_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_12_jmp_offset_pru1_bit;
	}; // 0x860

	/* PRU_MII_G_RT_ft3_12_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_len_pru1;

		volatile struct {
			uint32_t ft3_12_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_12_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_12_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_12_len_pru1_bit;
	}; // 0x864

	/* PRU_MII_G_RT_ft3_12_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_cfg_pru1;

		volatile struct {
			uint32_t ft3_12cfg : 2; // 1:0
			uint32_t ft3_12_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_12_trig_or_en : 16; // 31:16
		} ft3_12_cfg_pru1_bit;
	}; // 0x868

	/* PRU_MII_G_RT_ft3_12_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_t_pru1;

		volatile struct {
			uint32_t ft3_12_t : 32; // 31:0
		} ft3_12_t_pru1_bit;
	}; // 0x86c

	/* PRU_MII_G_RT_ft3_12_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_t_mask_pru1;

		volatile struct {
			uint32_t ft3_12_t_mask : 32; // 31:0
		} ft3_12_t_mask_pru1_bit;
	}; // 0x870

	/* PRU_MII_G_RT_ft3_13_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_13_start_pru1_bit;
	}; // 0x874

	/* PRU_MII_G_RT_ft3_13_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_13_start_auto_pru1_bit;
	}; // 0x878

	/* PRU_MII_G_RT_ft3_13_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_13_start_len_pru1_bit;
	}; // 0x87c

	/* PRU_MII_G_RT_ft3_13_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_13_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_13_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_13_jmp_offset_pru1_bit;
	}; // 0x880

	/* PRU_MII_G_RT_ft3_13_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_len_pru1;

		volatile struct {
			uint32_t ft3_13_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_13_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_13_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_13_len_pru1_bit;
	}; // 0x884

	/* PRU_MII_G_RT_ft3_13_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_cfg_pru1;

		volatile struct {
			uint32_t ft3_13cfg : 2; // 1:0
			uint32_t ft3_13_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_13_trig_or_en : 16; // 31:16
		} ft3_13_cfg_pru1_bit;
	}; // 0x888

	/* PRU_MII_G_RT_ft3_13_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_t_pru1;

		volatile struct {
			uint32_t ft3_13_t : 32; // 31:0
		} ft3_13_t_pru1_bit;
	}; // 0x88c

	/* PRU_MII_G_RT_ft3_13_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_t_mask_pru1;

		volatile struct {
			uint32_t ft3_13_t_mask : 32; // 31:0
		} ft3_13_t_mask_pru1_bit;
	}; // 0x890

	/* PRU_MII_G_RT_ft3_14_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_14_start_pru1_bit;
	}; // 0x894

	/* PRU_MII_G_RT_ft3_14_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_14_start_auto_pru1_bit;
	}; // 0x898

	/* PRU_MII_G_RT_ft3_14_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_14_start_len_pru1_bit;
	}; // 0x89c

	/* PRU_MII_G_RT_ft3_14_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_14_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_14_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_14_jmp_offset_pru1_bit;
	}; // 0x8a0

	/* PRU_MII_G_RT_ft3_14_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_len_pru1;

		volatile struct {
			uint32_t ft3_14_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_14_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_14_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_14_len_pru1_bit;
	}; // 0x8a4

	/* PRU_MII_G_RT_ft3_14_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_cfg_pru1;

		volatile struct {
			uint32_t ft3_14cfg : 2; // 1:0
			uint32_t ft3_14_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_14_trig_or_en : 16; // 31:16
		} ft3_14_cfg_pru1_bit;
	}; // 0x8a8

	/* PRU_MII_G_RT_ft3_14_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_t_pru1;

		volatile struct {
			uint32_t ft3_14_t : 32; // 31:0
		} ft3_14_t_pru1_bit;
	}; // 0x8ac

	/* PRU_MII_G_RT_ft3_14_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_t_mask_pru1;

		volatile struct {
			uint32_t ft3_14_t_mask : 32; // 31:0
		} ft3_14_t_mask_pru1_bit;
	}; // 0x8b0

	/* PRU_MII_G_RT_ft3_15_start_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_start_pru1;

		volatile struct {
			uint32_t ft3_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_15_start_pru1_bit;
	}; // 0x8b4

	/* PRU_MII_G_RT_ft3_15_start_auto_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_start_auto_pru1;

		volatile struct {
			uint32_t ft3_start_auto : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} ft3_15_start_auto_pru1_bit;
	}; // 0x8b8

	/* PRU_MII_G_RT_ft3_15_start_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_start_len_pru1;

		volatile struct {
			uint32_t ft3_offset : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_offset_start : 3; // 18:16
			uint32_t rsvd19 : 1; // 19
			uint32_t ft3_offset_end : 3; // 22:20
			uint32_t rsvd23 : 9; // 31:23
		} ft3_15_start_len_pru1_bit;
	}; // 0x8bc

	/* PRU_MII_G_RT_ft3_15_jmp_offset_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_jmp_offset_pru1;

		volatile struct {
			uint32_t ft3_15_ijmp_offset_pru1 : 15; // 14:0
			uint32_t rsvd15 : 1; // 15
			uint32_t ft3_15_njmp_offset_pru1 : 15; // 30:16
			uint32_t rsvd31 : 1; // 31
		} ft3_15_jmp_offset_pru1_bit;
	}; // 0x8c0

	/* PRU_MII_G_RT_ft3_15_len_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_len_pru1;

		volatile struct {
			uint32_t ft3_15_len_start_bit_pru1 : 9; // 8:0
			uint32_t rsvd9 : 7; // 15:9
			uint32_t ft3_15_len_size_bit_pru1 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t ft3_15_len_big_en_pru1 : 1; // 24
			uint32_t rsvd25 : 7; // 31:25
		} ft3_15_len_pru1_bit;
	}; // 0x8c4

	/* PRU_MII_G_RT_ft3_15_cfg_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_cfg_pru1;

		volatile struct {
			uint32_t ft3_15cfg : 2; // 1:0
			uint32_t ft3_15_vlan_skip_en : 1; // 2
			uint32_t rsvd3 : 13; // 15:3
			uint32_t ft3_15_trig_or_en : 16; // 31:16
		} ft3_15_cfg_pru1_bit;
	}; // 0x8c8

	/* PRU_MII_G_RT_ft3_15_t_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_t_pru1;

		volatile struct {
			uint32_t ft3_15_t : 32; // 31:0
		} ft3_15_t_pru1_bit;
	}; // 0x8cc

	/* PRU_MII_G_RT_ft3_15_t_mask_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_t_mask_pru1;

		volatile struct {
			uint32_t ft3_15_t_mask : 32; // 31:0
		} ft3_15_t_mask_pru1_bit;
	}; // 0x8d0

	/* PRU_MII_G_RT_ft3_0_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_p0_pru1;

		volatile struct {
			uint32_t ft3_0_p0 : 32; // 31:0
		} ft3_0_p0_pru1_bit;
	}; // 0x8d4

	/* PRU_MII_G_RT_ft3_0_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_p1_pru1;

		volatile struct {
			uint32_t ft3_0_p1 : 32; // 31:0
		} ft3_0_p1_pru1_bit;
	}; // 0x8d8

	/* PRU_MII_G_RT_ft3_0_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_0_p_mask0 : 32; // 31:0
		} ft3_0_p_mask0_pru1_bit;
	}; // 0x8dc

	/* PRU_MII_G_RT_ft3_0_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_0_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_0_p_mask1 : 32; // 31:0
		} ft3_0_p_mask1_pru1_bit;
	}; // 0x8e0

	/* PRU_MII_G_RT_ft3_1_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_p0_pru1;

		volatile struct {
			uint32_t ft3_1_p0 : 32; // 31:0
		} ft3_1_p0_pru1_bit;
	}; // 0x8e4

	/* PRU_MII_G_RT_ft3_1_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_p1_pru1;

		volatile struct {
			uint32_t ft3_1_p1 : 32; // 31:0
		} ft3_1_p1_pru1_bit;
	}; // 0x8e8

	/* PRU_MII_G_RT_ft3_1_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_1_p_mask0 : 32; // 31:0
		} ft3_1_p_mask0_pru1_bit;
	}; // 0x8ec

	/* PRU_MII_G_RT_ft3_1_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_1_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_1_p_mask1 : 32; // 31:0
		} ft3_1_p_mask1_pru1_bit;
	}; // 0x8f0

	/* PRU_MII_G_RT_ft3_2_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_p0_pru1;

		volatile struct {
			uint32_t ft3_2_p0 : 32; // 31:0
		} ft3_2_p0_pru1_bit;
	}; // 0x8f4

	/* PRU_MII_G_RT_ft3_2_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_p1_pru1;

		volatile struct {
			uint32_t ft3_2_p1 : 32; // 31:0
		} ft3_2_p1_pru1_bit;
	}; // 0x8f8

	/* PRU_MII_G_RT_ft3_2_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_2_p_mask0 : 32; // 31:0
		} ft3_2_p_mask0_pru1_bit;
	}; // 0x8fc

	/* PRU_MII_G_RT_ft3_2_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_2_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_2_p_mask1 : 32; // 31:0
		} ft3_2_p_mask1_pru1_bit;
	}; // 0x900

	/* PRU_MII_G_RT_ft3_3_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_p0_pru1;

		volatile struct {
			uint32_t ft3_3_p0 : 32; // 31:0
		} ft3_3_p0_pru1_bit;
	}; // 0x904

	/* PRU_MII_G_RT_ft3_3_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_p1_pru1;

		volatile struct {
			uint32_t ft3_3_p1 : 32; // 31:0
		} ft3_3_p1_pru1_bit;
	}; // 0x908

	/* PRU_MII_G_RT_ft3_3_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_3_p_mask0 : 32; // 31:0
		} ft3_3_p_mask0_pru1_bit;
	}; // 0x90c

	/* PRU_MII_G_RT_ft3_3_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_3_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_3_p_mask1 : 32; // 31:0
		} ft3_3_p_mask1_pru1_bit;
	}; // 0x910

	/* PRU_MII_G_RT_ft3_4_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_p0_pru1;

		volatile struct {
			uint32_t ft3_4_p0 : 32; // 31:0
		} ft3_4_p0_pru1_bit;
	}; // 0x914

	/* PRU_MII_G_RT_ft3_4_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_p1_pru1;

		volatile struct {
			uint32_t ft3_4_p1 : 32; // 31:0
		} ft3_4_p1_pru1_bit;
	}; // 0x918

	/* PRU_MII_G_RT_ft3_4_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_4_p_mask0 : 32; // 31:0
		} ft3_4_p_mask0_pru1_bit;
	}; // 0x91c

	/* PRU_MII_G_RT_ft3_4_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_4_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_4_p_mask1 : 32; // 31:0
		} ft3_4_p_mask1_pru1_bit;
	}; // 0x920

	/* PRU_MII_G_RT_ft3_5_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_p0_pru1;

		volatile struct {
			uint32_t ft3_5_p0 : 32; // 31:0
		} ft3_5_p0_pru1_bit;
	}; // 0x924

	/* PRU_MII_G_RT_ft3_5_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_p1_pru1;

		volatile struct {
			uint32_t ft3_5_p1 : 32; // 31:0
		} ft3_5_p1_pru1_bit;
	}; // 0x928

	/* PRU_MII_G_RT_ft3_5_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_5_p_mask0 : 32; // 31:0
		} ft3_5_p_mask0_pru1_bit;
	}; // 0x92c

	/* PRU_MII_G_RT_ft3_5_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_5_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_5_p_mask1 : 32; // 31:0
		} ft3_5_p_mask1_pru1_bit;
	}; // 0x930

	/* PRU_MII_G_RT_ft3_6_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_p0_pru1;

		volatile struct {
			uint32_t ft3_6_p0 : 32; // 31:0
		} ft3_6_p0_pru1_bit;
	}; // 0x934

	/* PRU_MII_G_RT_ft3_6_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_p1_pru1;

		volatile struct {
			uint32_t ft3_6_p1 : 32; // 31:0
		} ft3_6_p1_pru1_bit;
	}; // 0x938

	/* PRU_MII_G_RT_ft3_6_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_6_p_mask0 : 32; // 31:0
		} ft3_6_p_mask0_pru1_bit;
	}; // 0x93c

	/* PRU_MII_G_RT_ft3_6_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_6_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_6_p_mask1 : 32; // 31:0
		} ft3_6_p_mask1_pru1_bit;
	}; // 0x940

	/* PRU_MII_G_RT_ft3_7_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_p0_pru1;

		volatile struct {
			uint32_t ft3_7_p0 : 32; // 31:0
		} ft3_7_p0_pru1_bit;
	}; // 0x944

	/* PRU_MII_G_RT_ft3_7_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_p1_pru1;

		volatile struct {
			uint32_t ft3_7_p1 : 32; // 31:0
		} ft3_7_p1_pru1_bit;
	}; // 0x948

	/* PRU_MII_G_RT_ft3_7_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_7_p_mask0 : 32; // 31:0
		} ft3_7_p_mask0_pru1_bit;
	}; // 0x94c

	/* PRU_MII_G_RT_ft3_7_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_7_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_7_p_mask1 : 32; // 31:0
		} ft3_7_p_mask1_pru1_bit;
	}; // 0x950

	/* PRU_MII_G_RT_ft3_8_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_p0_pru1;

		volatile struct {
			uint32_t ft3_8_p0 : 32; // 31:0
		} ft3_8_p0_pru1_bit;
	}; // 0x954

	/* PRU_MII_G_RT_ft3_8_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_p1_pru1;

		volatile struct {
			uint32_t ft3_8_p1 : 32; // 31:0
		} ft3_8_p1_pru1_bit;
	}; // 0x958

	/* PRU_MII_G_RT_ft3_8_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_8_p_mask0 : 32; // 31:0
		} ft3_8_p_mask0_pru1_bit;
	}; // 0x95c

	/* PRU_MII_G_RT_ft3_8_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_8_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_8_p_mask1 : 32; // 31:0
		} ft3_8_p_mask1_pru1_bit;
	}; // 0x960

	/* PRU_MII_G_RT_ft3_9_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_p0_pru1;

		volatile struct {
			uint32_t ft3_9_p0 : 32; // 31:0
		} ft3_9_p0_pru1_bit;
	}; // 0x964

	/* PRU_MII_G_RT_ft3_9_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_p1_pru1;

		volatile struct {
			uint32_t ft3_9_p1 : 32; // 31:0
		} ft3_9_p1_pru1_bit;
	}; // 0x968

	/* PRU_MII_G_RT_ft3_9_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_9_p_mask0 : 32; // 31:0
		} ft3_9_p_mask0_pru1_bit;
	}; // 0x96c

	/* PRU_MII_G_RT_ft3_9_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_9_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_9_p_mask1 : 32; // 31:0
		} ft3_9_p_mask1_pru1_bit;
	}; // 0x970

	/* PRU_MII_G_RT_ft3_10_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_p0_pru1;

		volatile struct {
			uint32_t ft3_10_p0 : 32; // 31:0
		} ft3_10_p0_pru1_bit;
	}; // 0x974

	/* PRU_MII_G_RT_ft3_10_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_p1_pru1;

		volatile struct {
			uint32_t ft3_10_p1 : 32; // 31:0
		} ft3_10_p1_pru1_bit;
	}; // 0x978

	/* PRU_MII_G_RT_ft3_10_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_10_p_mask0 : 32; // 31:0
		} ft3_10_p_mask0_pru1_bit;
	}; // 0x97c

	/* PRU_MII_G_RT_ft3_10_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_10_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_10_p_mask1 : 32; // 31:0
		} ft3_10_p_mask1_pru1_bit;
	}; // 0x980

	/* PRU_MII_G_RT_ft3_11_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_p0_pru1;

		volatile struct {
			uint32_t ft3_11_p0 : 32; // 31:0
		} ft3_11_p0_pru1_bit;
	}; // 0x984

	/* PRU_MII_G_RT_ft3_11_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_p1_pru1;

		volatile struct {
			uint32_t ft3_11_p1 : 32; // 31:0
		} ft3_11_p1_pru1_bit;
	}; // 0x988

	/* PRU_MII_G_RT_ft3_11_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_11_p_mask0 : 32; // 31:0
		} ft3_11_p_mask0_pru1_bit;
	}; // 0x98c

	/* PRU_MII_G_RT_ft3_11_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_11_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_11_p_mask1 : 32; // 31:0
		} ft3_11_p_mask1_pru1_bit;
	}; // 0x990

	/* PRU_MII_G_RT_ft3_12_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_p0_pru1;

		volatile struct {
			uint32_t ft3_12_p0 : 32; // 31:0
		} ft3_12_p0_pru1_bit;
	}; // 0x994

	/* PRU_MII_G_RT_ft3_12_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_p1_pru1;

		volatile struct {
			uint32_t ft3_12_p1 : 32; // 31:0
		} ft3_12_p1_pru1_bit;
	}; // 0x998

	/* PRU_MII_G_RT_ft3_12_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_12_p_mask0 : 32; // 31:0
		} ft3_12_p_mask0_pru1_bit;
	}; // 0x99c

	/* PRU_MII_G_RT_ft3_12_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_12_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_12_p_mask1 : 32; // 31:0
		} ft3_12_p_mask1_pru1_bit;
	}; // 0x9a0

	/* PRU_MII_G_RT_ft3_13_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_p0_pru1;

		volatile struct {
			uint32_t ft3_13_p0 : 32; // 31:0
		} ft3_13_p0_pru1_bit;
	}; // 0x9a4

	/* PRU_MII_G_RT_ft3_13_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_p1_pru1;

		volatile struct {
			uint32_t ft3_13_p1 : 32; // 31:0
		} ft3_13_p1_pru1_bit;
	}; // 0x9a8

	/* PRU_MII_G_RT_ft3_13_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_13_p_mask0 : 32; // 31:0
		} ft3_13_p_mask0_pru1_bit;
	}; // 0x9ac

	/* PRU_MII_G_RT_ft3_13_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_13_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_13_p_mask1 : 32; // 31:0
		} ft3_13_p_mask1_pru1_bit;
	}; // 0x9b0

	/* PRU_MII_G_RT_ft3_14_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_p0_pru1;

		volatile struct {
			uint32_t ft3_14_p0 : 32; // 31:0
		} ft3_14_p0_pru1_bit;
	}; // 0x9b4

	/* PRU_MII_G_RT_ft3_14_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_p1_pru1;

		volatile struct {
			uint32_t ft3_14_p1 : 32; // 31:0
		} ft3_14_p1_pru1_bit;
	}; // 0x9b8

	/* PRU_MII_G_RT_ft3_14_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_14_p_mask0 : 32; // 31:0
		} ft3_14_p_mask0_pru1_bit;
	}; // 0x9bc

	/* PRU_MII_G_RT_ft3_14_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_14_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_14_p_mask1 : 32; // 31:0
		} ft3_14_p_mask1_pru1_bit;
	}; // 0x9c0

	/* PRU_MII_G_RT_ft3_15_p0_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_p0_pru1;

		volatile struct {
			uint32_t ft3_15_p0 : 32; // 31:0
		} ft3_15_p0_pru1_bit;
	}; // 0x9c4

	/* PRU_MII_G_RT_ft3_15_p1_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_p1_pru1;

		volatile struct {
			uint32_t ft3_15_p1 : 32; // 31:0
		} ft3_15_p1_pru1_bit;
	}; // 0x9c8

	/* PRU_MII_G_RT_ft3_15_p_mask0_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_p_mask0_pru1;

		volatile struct {
			uint32_t ft3_15_p_mask0 : 32; // 31:0
		} ft3_15_p_mask0_pru1_bit;
	}; // 0x9cc

	/* PRU_MII_G_RT_ft3_15_p_mask1_pru1 register bit field */
	union {
		volatile uint32_t ft3_15_p_mask1_pru1;

		volatile struct {
			uint32_t ft3_15_p_mask1 : 32; // 31:0
		} ft3_15_p_mask1_pru1_bit;
	}; // 0x9d0

	/* PRU_MII_G_RT_ft_rx_ptr_pru1 register bit field */
	union {
		volatile uint32_t ft_rx_ptr_pru1;

		volatile struct {
			uint32_t ft_rx_ptr_pru1 : 32; // 31:0
		} ft_rx_ptr_pru1_bit;
	}; // 0x9d4

	/* PRU_MII_G_RT_rx_class0_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class0_and_en_pru1;

		volatile struct {
			uint32_t rx_class0_and_en : 32; // 31:0
		} rx_class0_and_en_pru1_bit;
	}; // 0x9d8

	/* PRU_MII_G_RT_rx_class0_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class0_or_en_pru1;

		volatile struct {
			uint32_t rx_class0_or_en : 32; // 31:0
		} rx_class0_or_en_pru1_bit;
	}; // 0x9dc

	/* PRU_MII_G_RT_rx_class1_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class1_and_en_pru1;

		volatile struct {
			uint32_t rx_class1_and_en : 32; // 31:0
		} rx_class1_and_en_pru1_bit;
	}; // 0x9e0

	/* PRU_MII_G_RT_rx_class1_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class1_or_en_pru1;

		volatile struct {
			uint32_t rx_class1_or_en : 32; // 31:0
		} rx_class1_or_en_pru1_bit;
	}; // 0x9e4

	/* PRU_MII_G_RT_rx_class2_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class2_and_en_pru1;

		volatile struct {
			uint32_t rx_class2_and_en : 32; // 31:0
		} rx_class2_and_en_pru1_bit;
	}; // 0x9e8

	/* PRU_MII_G_RT_rx_class2_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class2_or_en_pru1;

		volatile struct {
			uint32_t rx_class2_or_en : 32; // 31:0
		} rx_class2_or_en_pru1_bit;
	}; // 0x9ec

	/* PRU_MII_G_RT_rx_class3_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class3_and_en_pru1;

		volatile struct {
			uint32_t rx_class3_and_en : 32; // 31:0
		} rx_class3_and_en_pru1_bit;
	}; // 0x9f0

	/* PRU_MII_G_RT_rx_class3_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class3_or_en_pru1;

		volatile struct {
			uint32_t rx_class3_or_en : 32; // 31:0
		} rx_class3_or_en_pru1_bit;
	}; // 0x9f4

	/* PRU_MII_G_RT_rx_class4_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class4_and_en_pru1;

		volatile struct {
			uint32_t rx_class4_and_en : 32; // 31:0
		} rx_class4_and_en_pru1_bit;
	}; // 0x9f8

	/* PRU_MII_G_RT_rx_class4_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class4_or_en_pru1;

		volatile struct {
			uint32_t rx_class4_or_en : 32; // 31:0
		} rx_class4_or_en_pru1_bit;
	}; // 0x9fc

	/* PRU_MII_G_RT_rx_class5_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class5_and_en_pru1;

		volatile struct {
			uint32_t rx_class5_and_en : 32; // 31:0
		} rx_class5_and_en_pru1_bit;
	}; // 0xa00

	/* PRU_MII_G_RT_rx_class5_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class5_or_en_pru1;

		volatile struct {
			uint32_t rx_class5_or_en : 32; // 31:0
		} rx_class5_or_en_pru1_bit;
	}; // 0xa04

	/* PRU_MII_G_RT_rx_class6_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class6_and_en_pru1;

		volatile struct {
			uint32_t rx_class6_and_en : 32; // 31:0
		} rx_class6_and_en_pru1_bit;
	}; // 0xa08

	/* PRU_MII_G_RT_rx_class6_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class6_or_en_pru1;

		volatile struct {
			uint32_t rx_class6_or_en : 32; // 31:0
		} rx_class6_or_en_pru1_bit;
	}; // 0xa0c

	/* PRU_MII_G_RT_rx_class7_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class7_and_en_pru1;

		volatile struct {
			uint32_t rx_class7_and_en : 32; // 31:0
		} rx_class7_and_en_pru1_bit;
	}; // 0xa10

	/* PRU_MII_G_RT_rx_class7_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class7_or_en_pru1;

		volatile struct {
			uint32_t rx_class7_or_en : 32; // 31:0
		} rx_class7_or_en_pru1_bit;
	}; // 0xa14

	/* PRU_MII_G_RT_rx_class8_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class8_and_en_pru1;

		volatile struct {
			uint32_t rx_class8_and_en : 32; // 31:0
		} rx_class8_and_en_pru1_bit;
	}; // 0xa18

	/* PRU_MII_G_RT_rx_class8_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class8_or_en_pru1;

		volatile struct {
			uint32_t rx_class8_or_en : 32; // 31:0
		} rx_class8_or_en_pru1_bit;
	}; // 0xa1c

	/* PRU_MII_G_RT_rx_class9_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class9_and_en_pru1;

		volatile struct {
			uint32_t rx_class9_and_en : 32; // 31:0
		} rx_class9_and_en_pru1_bit;
	}; // 0xa20

	/* PRU_MII_G_RT_rx_class9_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class9_or_en_pru1;

		volatile struct {
			uint32_t rx_class9_or_en : 32; // 31:0
		} rx_class9_or_en_pru1_bit;
	}; // 0xa24

	/* PRU_MII_G_RT_rx_class10_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class10_and_en_pru1;

		volatile struct {
			uint32_t rx_class10_and_en : 32; // 31:0
		} rx_class10_and_en_pru1_bit;
	}; // 0xa28

	/* PRU_MII_G_RT_rx_class10_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class10_or_en_pru1;

		volatile struct {
			uint32_t rx_class10_or_en : 32; // 31:0
		} rx_class10_or_en_pru1_bit;
	}; // 0xa2c

	/* PRU_MII_G_RT_rx_class11_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class11_and_en_pru1;

		volatile struct {
			uint32_t rx_class11_and_en : 32; // 31:0
		} rx_class11_and_en_pru1_bit;
	}; // 0xa30

	/* PRU_MII_G_RT_rx_class11_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class11_or_en_pru1;

		volatile struct {
			uint32_t rx_class11_or_en : 32; // 31:0
		} rx_class11_or_en_pru1_bit;
	}; // 0xa34

	/* PRU_MII_G_RT_rx_class12_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class12_and_en_pru1;

		volatile struct {
			uint32_t rx_class12_and_en : 32; // 31:0
		} rx_class12_and_en_pru1_bit;
	}; // 0xa38

	/* PRU_MII_G_RT_rx_class12_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class12_or_en_pru1;

		volatile struct {
			uint32_t rx_class12_or_en : 32; // 31:0
		} rx_class12_or_en_pru1_bit;
	}; // 0xa3c

	/* PRU_MII_G_RT_rx_class13_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class13_and_en_pru1;

		volatile struct {
			uint32_t rx_class13_and_en : 32; // 31:0
		} rx_class13_and_en_pru1_bit;
	}; // 0xa40

	/* PRU_MII_G_RT_rx_class13_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class13_or_en_pru1;

		volatile struct {
			uint32_t rx_class13_or_en : 32; // 31:0
		} rx_class13_or_en_pru1_bit;
	}; // 0xa44

	/* PRU_MII_G_RT_rx_class14_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class14_and_en_pru1;

		volatile struct {
			uint32_t rx_class14_and_en : 32; // 31:0
		} rx_class14_and_en_pru1_bit;
	}; // 0xa48

	/* PRU_MII_G_RT_rx_class14_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class14_or_en_pru1;

		volatile struct {
			uint32_t rx_class14_or_en : 32; // 31:0
		} rx_class14_or_en_pru1_bit;
	}; // 0xa4c

	/* PRU_MII_G_RT_rx_class15_and_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class15_and_en_pru1;

		volatile struct {
			uint32_t rx_class15_and_en : 32; // 31:0
		} rx_class15_and_en_pru1_bit;
	}; // 0xa50

	/* PRU_MII_G_RT_rx_class15_or_en_pru1 register bit field */
	union {
		volatile uint32_t rx_class15_or_en_pru1;

		volatile struct {
			uint32_t rx_class15_or_en : 32; // 31:0
		} rx_class15_or_en_pru1_bit;
	}; // 0xa54

	/* PRU_MII_G_RT_rx_class_cfg1_pru1 register bit field */
	union {
		volatile uint32_t rx_class_cfg1_pru1;

		volatile struct {
			uint32_t rx_class0_sel : 2; // 1:0
			uint32_t rx_class1_sel : 2; // 3:2
			uint32_t rx_class2_sel : 2; // 5:4
			uint32_t rx_class3_sel : 2; // 7:6
			uint32_t rx_class4_sel : 2; // 9:8
			uint32_t rx_class5_sel : 2; // 11:10
			uint32_t rx_class6_sel : 2; // 13:12
			uint32_t rx_class7_sel : 2; // 15:14
			uint32_t rx_class8_sel : 2; // 17:16
			uint32_t rx_class9_sel : 2; // 19:18
			uint32_t rx_class10_sel : 2; // 21:20
			uint32_t rx_class11_sel : 2; // 23:22
			uint32_t rx_class12_sel : 2; // 25:24
			uint32_t rx_class13_sel : 2; // 27:26
			uint32_t rx_class14_sel : 2; // 29:28
			uint32_t rx_class15_sel : 2; // 31:30
		} rx_class_cfg1_pru1_bit;
	}; // 0xa58

	/* PRU_MII_G_RT_rx_class_cfg2_pru1 register bit field */
	union {
		volatile uint32_t rx_class_cfg2_pru1;

		volatile struct {
			uint32_t rx_class_and_nv : 16; // 15:0
			uint32_t rx_class_or_nv : 16; // 31:16
		} rx_class_cfg2_pru1_bit;
	}; // 0xa5c

	/* PRU_MII_G_RT_rx_class_gates0_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates0_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel0 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask0 : 1; // 4
			uint32_t rx_class_raw_mask0 : 1; // 5
			uint32_t rx_allow_mask0 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en0 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates0_pru1_bit;
	}; // 0xa60

	/* PRU_MII_G_RT_rx_class_gates1_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates1_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel1 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask1 : 1; // 4
			uint32_t rx_class_raw_mask1 : 1; // 5
			uint32_t rx_allow_mask1 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en1 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates1_pru1_bit;
	}; // 0xa64

	/* PRU_MII_G_RT_rx_class_gates2_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates2_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel2 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask2 : 1; // 4
			uint32_t rx_class_raw_mask2 : 1; // 5
			uint32_t rx_allow_mask2 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en2 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates2_pru1_bit;
	}; // 0xa68

	/* PRU_MII_G_RT_rx_class_gates3_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates3_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel3 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask3 : 1; // 4
			uint32_t rx_class_raw_mask3 : 1; // 5
			uint32_t rx_allow_mask3 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en3 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates3_pru1_bit;
	}; // 0xa6c

	/* PRU_MII_G_RT_rx_class_gates4_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates4_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel4 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask4 : 1; // 4
			uint32_t rx_class_raw_mask4 : 1; // 5
			uint32_t rx_allow_mask4 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en4 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates4_pru1_bit;
	}; // 0xa70

	/* PRU_MII_G_RT_rx_class_gates5_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates5_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel5 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask5 : 1; // 4
			uint32_t rx_class_raw_mask5 : 1; // 5
			uint32_t rx_allow_mask5 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en5 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates5_pru1_bit;
	}; // 0xa74

	/* PRU_MII_G_RT_rx_class_gates6_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates6_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel6 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask6 : 1; // 4
			uint32_t rx_class_raw_mask6 : 1; // 5
			uint32_t rx_allow_mask6 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en6 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates6_pru1_bit;
	}; // 0xa78

	/* PRU_MII_G_RT_rx_class_gates7_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates7_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel7 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask7 : 1; // 4
			uint32_t rx_class_raw_mask7 : 1; // 5
			uint32_t rx_allow_mask7 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en7 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates7_pru1_bit;
	}; // 0xa7c

	/* PRU_MII_G_RT_rx_class_gates8_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates8_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel8 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask8 : 1; // 4
			uint32_t rx_class_raw_mask8 : 1; // 5
			uint32_t rx_allow_mask8 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en8 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates8_pru1_bit;
	}; // 0xa80

	/* PRU_MII_G_RT_rx_class_gates9_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates9_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel9 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask9 : 1; // 4
			uint32_t rx_class_raw_mask9 : 1; // 5
			uint32_t rx_allow_mask9 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en9 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates9_pru1_bit;
	}; // 0xa84

	/* PRU_MII_G_RT_rx_class_gates10_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates10_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel10 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask10 : 1; // 4
			uint32_t rx_class_raw_mask10 : 1; // 5
			uint32_t rx_allow_mask10 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en10 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates10_pru1_bit;
	}; // 0xa88

	/* PRU_MII_G_RT_rx_class_gates11_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates11_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel11 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask11 : 1; // 4
			uint32_t rx_class_raw_mask11 : 1; // 5
			uint32_t rx_allow_mask11 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en11 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates11_pru1_bit;
	}; // 0xa8c

	/* PRU_MII_G_RT_rx_class_gates12_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates12_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel12 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask12 : 1; // 4
			uint32_t rx_class_raw_mask12 : 1; // 5
			uint32_t rx_allow_mask12 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en12 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates12_pru1_bit;
	}; // 0xa90

	/* PRU_MII_G_RT_rx_class_gates13_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates13_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel13 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask13 : 1; // 4
			uint32_t rx_class_raw_mask13 : 1; // 5
			uint32_t rx_allow_mask13 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en13 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates13_pru1_bit;
	}; // 0xa94

	/* PRU_MII_G_RT_rx_class_gates14_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates14_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel14 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask14 : 1; // 4
			uint32_t rx_class_raw_mask14 : 1; // 5
			uint32_t rx_allow_mask14 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en14 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates14_pru1_bit;
	}; // 0xa98

	/* PRU_MII_G_RT_rx_class_gates15_pru1 register bit field */
	union {
		volatile uint32_t rx_class_gates15_pru1;

		volatile struct {
			uint32_t rx_rate_gate_sel15 : 3; // 2:0
			uint32_t rsvd3 : 1; // 3
			uint32_t rx_phase_mask15 : 1; // 4
			uint32_t rx_class_raw_mask15 : 1; // 5
			uint32_t rx_allow_mask15 : 1; // 6
			uint32_t rsvd7 : 1; // 7
			uint32_t rx_red_phase_en15 : 1; // 8
			uint32_t rsvd9 : 23; // 31:9
		} rx_class_gates15_pru1_bit;
	}; // 0xa9c

	/* PRU_MII_G_RT_rx_green_pru1 register bit field */
	union {
		volatile uint32_t rx_green_pru1;

		volatile struct {
			uint32_t rx_green_cmp_sel : 4; // 3:0
			uint32_t rx_green_val : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} rx_green_pru1_bit;
	}; // 0xaa0

	/* PRU_MII_G_RT_sa_hash_pru1 register bit field */
	union {
		volatile uint32_t sa_hash_pru1;

		volatile struct {
			uint32_t sa_hash_seed : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} sa_hash_pru1_bit;
	}; // 0xaa4

	/* PRU_MII_G_RT_conn_hash_pru1 register bit field */
	union {
		volatile uint32_t conn_hash_pru1;

		volatile struct {
			uint32_t conn_hash_seed : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} conn_hash_pru1_bit;
	}; // 0xaa8

	/* PRU_MII_G_RT_conn_hash_start_pru1 register bit field */
	union {
		volatile uint32_t conn_hash_start_pru1;

		volatile struct {
			uint32_t conn_hash_start : 15; // 14:0
			uint32_t rsvd15 : 17; // 31:15
		} conn_hash_start_pru1_bit;
	}; // 0xaac

	/* PRU_MII_G_RT_rx_rate_cfg0_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg0_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle0 : 32; // 31:0
		} rx_rate_cfg0_pru1_bit;
	}; // 0xab0

	/* PRU_MII_G_RT_rx_rate_cfg1_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg1_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle1 : 32; // 31:0
		} rx_rate_cfg1_pru1_bit;
	}; // 0xab4

	/* PRU_MII_G_RT_rx_rate_cfg2_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg2_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle2 : 32; // 31:0
		} rx_rate_cfg2_pru1_bit;
	}; // 0xab8

	/* PRU_MII_G_RT_rx_rate_cfg3_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg3_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle3 : 32; // 31:0
		} rx_rate_cfg3_pru1_bit;
	}; // 0xabc

	/* PRU_MII_G_RT_rx_rate_cfg4_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg4_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle4 : 32; // 31:0
		} rx_rate_cfg4_pru1_bit;
	}; // 0xac0

	/* PRU_MII_G_RT_rx_rate_cfg5_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg5_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle5 : 32; // 31:0
		} rx_rate_cfg5_pru1_bit;
	}; // 0xac4

	/* PRU_MII_G_RT_rx_rate_cfg6_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg6_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle6 : 32; // 31:0
		} rx_rate_cfg6_pru1_bit;
	}; // 0xac8

	/* PRU_MII_G_RT_rx_rate_cfg7_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_cfg7_pru1;

		volatile struct {
			uint32_t rx_rate_cir_idle7 : 32; // 31:0
		} rx_rate_cfg7_pru1_bit;
	}; // 0xacc

	/* PRU_MII_G_RT_rx_rate_src_sel0_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_src_sel0_pru1;

		volatile struct {
			uint32_t rx_rate_src_sel0 : 6; // 5:0
			uint32_t rsvd6 : 2; // 7:6
			uint32_t rx_rate_src_sel1 : 6; // 13:8
			uint32_t rsvd14 : 2; // 15:14
			uint32_t rx_rate_src_sel2 : 6; // 21:16
			uint32_t rsvd22 : 2; // 23:22
			uint32_t rx_rate_src_sel3 : 6; // 29:24
			uint32_t rsvd30 : 2; // 31:30
		} rx_rate_src_sel0_pru1_bit;
	}; // 0xad0

	/* PRU_MII_G_RT_rx_rate_src_sel1_pru1 register bit field */
	union {
		volatile uint32_t rx_rate_src_sel1_pru1;

		volatile struct {
			uint32_t rx_rate_src_sel4 : 6; // 5:0
			uint32_t rsvd6 : 2; // 7:6
			uint32_t rx_rate_src_sel5 : 6; // 13:8
			uint32_t rsvd14 : 2; // 15:14
			uint32_t rx_rate_src_sel6 : 6; // 21:16
			uint32_t rsvd22 : 2; // 23:22
			uint32_t rx_rate_src_sel7 : 6; // 29:24
			uint32_t rsvd30 : 2; // 31:30
		} rx_rate_src_sel1_pru1_bit;
	}; // 0xad4

	/* PRU_MII_G_RT_tx_rate_cfg1_0_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_0_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle0 : 32; // 31:0
		} tx_rate_cfg1_0_pru1_bit;
	}; // 0xad8

	/* PRU_MII_G_RT_tx_rate_cfg2_0_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_0_pru1;

		volatile struct {
			uint32_t tx_rate_len0 : 16; // 15:0
			uint32_t tx_rate_en0 : 1; // 16
			uint32_t tx_rate_allow0 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_0_pru1_bit;
	}; // 0xadc

	/* PRU_MII_G_RT_tx_rate_cfg1_1_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_1_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle1 : 32; // 31:0
		} tx_rate_cfg1_1_pru1_bit;
	}; // 0xae0

	/* PRU_MII_G_RT_tx_rate_cfg2_1_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_1_pru1;

		volatile struct {
			uint32_t tx_rate_len1 : 16; // 15:0
			uint32_t tx_rate_en1 : 1; // 16
			uint32_t tx_rate_allow1 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_1_pru1_bit;
	}; // 0xae4

	/* PRU_MII_G_RT_tx_rate_cfg1_2_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_2_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle2 : 32; // 31:0
		} tx_rate_cfg1_2_pru1_bit;
	}; // 0xae8

	/* PRU_MII_G_RT_tx_rate_cfg2_2_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_2_pru1;

		volatile struct {
			uint32_t tx_rate_len2 : 16; // 15:0
			uint32_t tx_rate_en2 : 1; // 16
			uint32_t tx_rate_allow2 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_2_pru1_bit;
	}; // 0xaec

	/* PRU_MII_G_RT_tx_rate_cfg1_3_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_3_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle3 : 32; // 31:0
		} tx_rate_cfg1_3_pru1_bit;
	}; // 0xaf0

	/* PRU_MII_G_RT_tx_rate_cfg2_3_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_3_pru1;

		volatile struct {
			uint32_t tx_rate_len3 : 16; // 15:0
			uint32_t tx_rate_en3 : 1; // 16
			uint32_t tx_rate_allow3 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_3_pru1_bit;
	}; // 0xaf4

	/* PRU_MII_G_RT_tx_rate_cfg1_4_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_4_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle4 : 32; // 31:0
		} tx_rate_cfg1_4_pru1_bit;
	}; // 0xaf8

	/* PRU_MII_G_RT_tx_rate_cfg2_4_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_4_pru1;

		volatile struct {
			uint32_t tx_rate_len4 : 16; // 15:0
			uint32_t tx_rate_en4 : 1; // 16
			uint32_t tx_rate_allow4 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_4_pru1_bit;
	}; // 0xafc

	/* PRU_MII_G_RT_tx_rate_cfg1_5_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_5_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle5 : 32; // 31:0
		} tx_rate_cfg1_5_pru1_bit;
	}; // 0xb00

	/* PRU_MII_G_RT_tx_rate_cfg2_5_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_5_pru1;

		volatile struct {
			uint32_t tx_rate_len5 : 16; // 15:0
			uint32_t tx_rate_en5 : 1; // 16
			uint32_t tx_rate_allow5 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_5_pru1_bit;
	}; // 0xb04

	/* PRU_MII_G_RT_tx_rate_cfg1_6_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_6_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle6 : 32; // 31:0
		} tx_rate_cfg1_6_pru1_bit;
	}; // 0xb08

	/* PRU_MII_G_RT_tx_rate_cfg2_6_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_6_pru1;

		volatile struct {
			uint32_t tx_rate_len6 : 16; // 15:0
			uint32_t tx_rate_en6 : 1; // 16
			uint32_t tx_rate_allow6 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_6_pru1_bit;
	}; // 0xb0c

	/* PRU_MII_G_RT_tx_rate_cfg1_7_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg1_7_pru1;

		volatile struct {
			uint32_t tx_rate_cir_idle7 : 32; // 31:0
		} tx_rate_cfg1_7_pru1_bit;
	}; // 0xb10

	/* PRU_MII_G_RT_tx_rate_cfg2_7_pru1 register bit field */
	union {
		volatile uint32_t tx_rate_cfg2_7_pru1;

		volatile struct {
			uint32_t tx_rate_len7 : 16; // 15:0
			uint32_t tx_rate_en7 : 1; // 16
			uint32_t tx_rate_allow7 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} tx_rate_cfg2_7_pru1_bit;
	}; // 0xb14

	/* PRU_MII_G_RT_rx_stat_good_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_good_pru1;

		volatile struct {
			uint32_t rx_good_frm_cnt : 32; // 31:0
		} rx_stat_good_pru1_bit;
	}; // 0xb18

	/* PRU_MII_G_RT_rx_stat_bc_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bc_pru1;

		volatile struct {
			uint32_t rx_bc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bc_pru1_bit;
	}; // 0xb1c

	/* PRU_MII_G_RT_rx_stat_mc_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_mc_pru1;

		volatile struct {
			uint32_t rx_mc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_mc_pru1_bit;
	}; // 0xb20

	/* PRU_MII_G_RT_rx_stat_crc_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_crc_err_pru1;

		volatile struct {
			uint32_t rx_crc_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_crc_err_pru1_bit;
	}; // 0xb24

	/* PRU_MII_G_RT_rx_stat_mii_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_mii_err_pru1;

		volatile struct {
			uint32_t rx_mii_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_mii_err_pru1_bit;
	}; // 0xb28

	/* PRU_MII_G_RT_rx_stat_odd_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_odd_err_pru1;

		volatile struct {
			uint32_t rx_odd_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_odd_err_pru1_bit;
	}; // 0xb2c

	/* PRU_MII_G_RT_rx_stat_max_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_max_size_pru1;

		volatile struct {
			uint32_t rx_max_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_max_size_pru1_bit;
	}; // 0xb30

	/* PRU_MII_G_RT_rx_stat_max_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_max_err_pru1;

		volatile struct {
			uint32_t rx_max_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_max_err_pru1_bit;
	}; // 0xb34

	/* PRU_MII_G_RT_rx_stat_min_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_min_size_pru1;

		volatile struct {
			uint32_t rx_min_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_min_size_pru1_bit;
	}; // 0xb38

	/* PRU_MII_G_RT_rx_stat_min_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_min_err_pru1;

		volatile struct {
			uint32_t rx_min_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_min_err_pru1_bit;
	}; // 0xb3c

	/* PRU_MII_G_RT_rx_stat_overrun_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_overrun_err_pru1;

		volatile struct {
			uint32_t rx_overrun_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_overrun_err_pru1_bit;
	}; // 0xb40

	/* PRU_MII_G_RT_rx_stat_class0_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class0_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class0_pru1 : 32; // 31:0
		} rx_stat_class0_hit_pru1_bit;
	}; // 0xb44

	/* PRU_MII_G_RT_rx_stat_class1_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class1_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class1_pru1 : 32; // 31:0
		} rx_stat_class1_hit_pru1_bit;
	}; // 0xb48

	/* PRU_MII_G_RT_rx_stat_class2_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class2_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class2_pru1 : 32; // 31:0
		} rx_stat_class2_hit_pru1_bit;
	}; // 0xb4c

	/* PRU_MII_G_RT_rx_stat_class3_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class3_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class3_pru1 : 32; // 31:0
		} rx_stat_class3_hit_pru1_bit;
	}; // 0xb50

	/* PRU_MII_G_RT_rx_stat_class4_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class4_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class4_pru1 : 32; // 31:0
		} rx_stat_class4_hit_pru1_bit;
	}; // 0xb54

	/* PRU_MII_G_RT_rx_stat_class5_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class5_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class5_pru1 : 32; // 31:0
		} rx_stat_class5_hit_pru1_bit;
	}; // 0xb58

	/* PRU_MII_G_RT_rx_stat_class6_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class6_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class6_pru1 : 32; // 31:0
		} rx_stat_class6_hit_pru1_bit;
	}; // 0xb5c

	/* PRU_MII_G_RT_rx_stat_class7_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class7_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class7_pru1 : 32; // 31:0
		} rx_stat_class7_hit_pru1_bit;
	}; // 0xb60

	/* PRU_MII_G_RT_rx_stat_class8_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class8_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class8_pru1 : 32; // 31:0
		} rx_stat_class8_hit_pru1_bit;
	}; // 0xb64

	/* PRU_MII_G_RT_rx_stat_class9_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class9_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class9_pru1 : 32; // 31:0
		} rx_stat_class9_hit_pru1_bit;
	}; // 0xb68

	/* PRU_MII_G_RT_rx_stat_class10_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class10_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class10_pru1 : 32; // 31:0
		} rx_stat_class10_hit_pru1_bit;
	}; // 0xb6c

	/* PRU_MII_G_RT_rx_stat_class11_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class11_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class11_pru1 : 32; // 31:0
		} rx_stat_class11_hit_pru1_bit;
	}; // 0xb70

	/* PRU_MII_G_RT_rx_stat_class12_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class12_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class12_pru1 : 32; // 31:0
		} rx_stat_class12_hit_pru1_bit;
	}; // 0xb74

	/* PRU_MII_G_RT_rx_stat_class13_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class13_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class13_pru1 : 32; // 31:0
		} rx_stat_class13_hit_pru1_bit;
	}; // 0xb78

	/* PRU_MII_G_RT_rx_stat_class14_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class14_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class14_pru1 : 32; // 31:0
		} rx_stat_class14_hit_pru1_bit;
	}; // 0xb7c

	/* PRU_MII_G_RT_rx_stat_class15_hit_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_class15_hit_pru1;

		volatile struct {
			uint32_t rx_stat_class15_pru1 : 32; // 31:0
		} rx_stat_class15_hit_pru1_bit;
	}; // 0xb80

	/* PRU_MII_G_RT_rx_stat_smd_frag_err_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_smd_frag_err_pru1;

		volatile struct {
			uint32_t rx_stat_smds_err_pru1 : 8; // 7:0
			uint32_t rx_stat_smdc_err_pru1 : 8; // 15:8
			uint32_t rx_stat_frag_err_pru1 : 8; // 23:16
			uint32_t rx_stat_smd_err_pru1 : 8; // 31:24
		} rx_stat_smd_frag_err_pru1_bit;
	}; // 0xb84

	/* PRU_MII_G_RT_rx_stat_bkt1_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt1_size_pru1;

		volatile struct {
			uint32_t rx_stat_bkt1_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt1_size_pru1_bit;
	}; // 0xb88

	/* PRU_MII_G_RT_rx_stat_bkt2_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt2_size_pru1;

		volatile struct {
			uint32_t rx_stat_bkt2_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt2_size_pru1_bit;
	}; // 0xb8c

	/* PRU_MII_G_RT_rx_stat_bkt3_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt3_size_pru1;

		volatile struct {
			uint32_t rx_stat_bkt3_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt3_size_pru1_bit;
	}; // 0xb90

	/* PRU_MII_G_RT_rx_stat_bkt4_size_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt4_size_pru1;

		volatile struct {
			uint32_t rx_stat_bkt4_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} rx_stat_bkt4_size_pru1_bit;
	}; // 0xb94

	/* PRU_MII_G_RT_rx_stat_64_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_64_pru1;

		volatile struct {
			uint32_t rx_64_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_64_pru1_bit;
	}; // 0xb98

	/* PRU_MII_G_RT_rx_stat_bkt1_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt1_pru1;

		volatile struct {
			uint32_t rx_stat_bkt1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt1_pru1_bit;
	}; // 0xb9c

	/* PRU_MII_G_RT_rx_stat_bkt2_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt2_pru1;

		volatile struct {
			uint32_t rx_stat_bkt2 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt2_pru1_bit;
	}; // 0xba0

	/* PRU_MII_G_RT_rx_stat_bkt3_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt3_pru1;

		volatile struct {
			uint32_t rx_stat_bkt3 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt3_pru1_bit;
	}; // 0xba4

	/* PRU_MII_G_RT_rx_stat_bkt4_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt4_pru1;

		volatile struct {
			uint32_t rx_stat_bkt4 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt4_pru1_bit;
	}; // 0xba8

	/* PRU_MII_G_RT_rx_stat_bkt5_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_bkt5_pru1;

		volatile struct {
			uint32_t rx_stat_bkt5 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} rx_stat_bkt5_pru1_bit;
	}; // 0xbac

	/* PRU_MII_G_RT_rx_stat_total_bytes_pru1 register bit field */
	union {
		volatile uint32_t rx_stat_total_bytes_pru1;

		volatile struct {
			uint32_t rx_stat_total_bytes_pru : 32; // 31:0
		} rx_stat_total_bytes_pru1_bit;
	}; // 0xbb0

	/* PRU_MII_G_RT_rxtx_stat_total_bytes_pru1 register bit field */
	union {
		volatile uint32_t rxtx_stat_total_bytes_pru1;

		volatile struct {
			uint32_t rxtx_stat_total_bytes_pru : 32; // 31:0
		} rxtx_stat_total_bytes_pru1_bit;
	}; // 0xbb4

	/* PRU_MII_G_RT_tx_stat_good_port1 register bit field */
	union {
		volatile uint32_t tx_stat_good_port1;

		volatile struct {
			uint32_t tx_good_frm_cnt : 32; // 31:0
		} tx_stat_good_port1_bit;
	}; // 0xbb8

	/* PRU_MII_G_RT_tx_stat_bc_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bc_port1;

		volatile struct {
			uint32_t tx_bc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bc_port1_bit;
	}; // 0xbbc

	/* PRU_MII_G_RT_tx_stat_mc_port1 register bit field */
	union {
		volatile uint32_t tx_stat_mc_port1;

		volatile struct {
			uint32_t tx_mc_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_mc_port1_bit;
	}; // 0xbc0

	/* PRU_MII_G_RT_tx_stat_odd_err_port1 register bit field */
	union {
		volatile uint32_t tx_stat_odd_err_port1;

		volatile struct {
			uint32_t tx_odd_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_odd_err_port1_bit;
	}; // 0xbc4

	/* PRU_MII_G_RT_tx_stat_underflow_err_port1 register bit field */
	union {
		volatile uint32_t tx_stat_underflow_err_port1;

		volatile struct {
			uint32_t tx_underflow_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_underflow_err_port1_bit;
	}; // 0xbc8

	/* PRU_MII_G_RT_tx_stat_max_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_max_size_port1;

		volatile struct {
			uint32_t tx_max_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_max_size_port1_bit;
	}; // 0xbcc

	/* PRU_MII_G_RT_tx_stat_max_err_port1 register bit field */
	union {
		volatile uint32_t tx_stat_max_err_port1;

		volatile struct {
			uint32_t tx_max_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_max_err_port1_bit;
	}; // 0xbd0

	/* PRU_MII_G_RT_tx_stat_min_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_min_size_port1;

		volatile struct {
			uint32_t tx_min_size_frm : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_min_size_port1_bit;
	}; // 0xbd4

	/* PRU_MII_G_RT_tx_stat_min_err_port1 register bit field */
	union {
		volatile uint32_t tx_stat_min_err_port1;

		volatile struct {
			uint32_t tx_min_err_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_min_err_port1_bit;
	}; // 0xbd8

	/* PRU_MII_G_RT_tx_stat_bkt1_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt1_size_port1;

		volatile struct {
			uint32_t tx_stat_bkt1_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt1_size_port1_bit;
	}; // 0xbdc

	/* PRU_MII_G_RT_tx_stat_bkt2_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt2_size_port1;

		volatile struct {
			uint32_t tx_stat_bkt2_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt2_size_port1_bit;
	}; // 0xbe0

	/* PRU_MII_G_RT_tx_stat_bkt3_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt3_size_port1;

		volatile struct {
			uint32_t tx_stat_bkt3_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt3_size_port1_bit;
	}; // 0xbe4

	/* PRU_MII_G_RT_tx_stat_bkt4_size_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt4_size_port1;

		volatile struct {
			uint32_t tx_stat_bkt4_size : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} tx_stat_bkt4_size_port1_bit;
	}; // 0xbe8

	/* PRU_MII_G_RT_tx_stat_64_port1 register bit field */
	union {
		volatile uint32_t tx_stat_64_port1;

		volatile struct {
			uint32_t tx_64_frm_cnt : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_64_port1_bit;
	}; // 0xbec

	/* PRU_MII_G_RT_tx_stat_bkt1_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt1_port1;

		volatile struct {
			uint32_t tx_stat_bkt1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt1_port1_bit;
	}; // 0xbf0

	/* PRU_MII_G_RT_tx_stat_bkt2_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt2_port1;

		volatile struct {
			uint32_t tx_stat_bkt2 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt2_port1_bit;
	}; // 0xbf4

	/* PRU_MII_G_RT_tx_stat_bkt3_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt3_port1;

		volatile struct {
			uint32_t tx_stat_bkt3 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt3_port1_bit;
	}; // 0xbf8

	/* PRU_MII_G_RT_tx_stat_bkt4_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt4_port1;

		volatile struct {
			uint32_t tx_stat_bkt4 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt4_port1_bit;
	}; // 0xbfc

	/* PRU_MII_G_RT_tx_stat_bkt5_port1 register bit field */
	union {
		volatile uint32_t tx_stat_bkt5_port1;

		volatile struct {
			uint32_t tx_stat_bkt5 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_stat_bkt5_port1_bit;
	}; // 0xc00

	/* PRU_MII_G_RT_tx_stat_total_bytes_port1 register bit field */
	union {
		volatile uint32_t tx_stat_total_bytes_port1;

		volatile struct {
			uint32_t tx_total_stat_bytes_port : 32; // 31:0
		} tx_stat_total_bytes_port1_bit;
	}; // 0xc04

	/* PRU_MII_G_RT_tx_hsr_tag_port1 register bit field */
	union {
		volatile uint32_t tx_hsr_tag_port1;

		volatile struct {
			uint32_t tx_hsr_tag : 32; // 31:0
		} tx_hsr_tag_port1_bit;
	}; // 0xc08

	/* PRU_MII_G_RT_tx_hsr_seq_port1 register bit field */
	union {
		volatile uint32_t tx_hsr_seq_port1;

		volatile struct {
			uint32_t tx_hsr_seq : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_hsr_seq_port1_bit;
	}; // 0xc0c

	/* PRU_MII_G_RT_tx_vlan_type_tag_port1 register bit field */
	union {
		volatile uint32_t tx_vlan_type_tag_port1;

		volatile struct {
			uint32_t tx_vlan_type_tag : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} tx_vlan_type_tag_port1_bit;
	}; // 0xc10

	/* PRU_MII_G_RT_tx_vlan_ins_tag_port1 register bit field */
	union {
		volatile uint32_t tx_vlan_ins_tag_port1;

		volatile struct {
			uint32_t tx_vlan_ins_tag : 32; // 31:0
		} tx_vlan_ins_tag_port1_bit;
	}; // 0xc14

} miiGRt;

volatile __far miiGRt CT_MII_G_RT __attribute__((cregister("MII_G_RT", far), peripheral));

#endif /* _PRU_MII_G_RT_H_ */

