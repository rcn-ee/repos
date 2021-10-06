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

#ifndef _PRU_TASKS_MGR_H_
#define _PRU_TASKS_MGR_H_

/* PRU TASKS MGR register set */
typedef struct {

	/* PRU_TASKS_MGR_global_cfg register bit field */
	union {
		volatile uint32_t global_cfg;

		volatile struct {
			uint32_t tasks_mgr_mode : 2; // 1:0
			uint32_t ts1_en_s0 : 1; // 2
			uint32_t ts1_en_s1 : 1; // 3
			uint32_t ts1_en_s2 : 1; // 4
			uint32_t ts1_en_s3 : 1; // 5
			uint32_t ts1_en_s4 : 1; // 6
			uint32_t ts2_en_s0 : 1; // 7
			uint32_t ts2_en_s1 : 1; // 8
			uint32_t ts2_en_s2 : 1; // 9
			uint32_t ts2_en_s3 : 1; // 10
			uint32_t ts2_en_s4 : 1; // 11
			uint32_t rsvd12 : 20; // 31:12
		} global_cfg_bit;
	}; // 0x0

	/* PRU_TASKS_MGR_global_status register bit field */
	union {
		volatile uint32_t global_status;

		volatile struct {
			uint32_t ts1_state : 4; // 3:0
			uint32_t ts2_state : 4; // 7:4
			uint32_t ts1_sub_pend_0 : 1; // 8
			uint32_t ts1_sub_pend_1 : 1; // 9
			uint32_t ts1_sub_pend_2 : 1; // 10
			uint32_t ts1_sub_pend_3 : 1; // 11
			uint32_t ts1_sub_pend_4 : 1; // 12
			uint32_t ts2_sub_pend_0 : 1; // 13
			uint32_t ts2_sub_pend_1 : 1; // 14
			uint32_t ts2_sub_pend_2 : 1; // 15
			uint32_t ts2_sub_pend_3 : 1; // 16
			uint32_t ts2_sub_pend_4 : 1; // 17
			uint32_t rsvd18 : 14; // 31:18
		} global_status_bit;
	}; // 0x4

	/* PRU_TASKS_MGR_ts1_pc_s0 register bit field */
	union {
		volatile uint32_t ts1_pc_s0;

		volatile struct {
			uint32_t ts1_pc_s0 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts1_pc_s0_bit;
	}; // 0x8

	/* PRU_TASKS_MGR_ts1_pc_s1 register bit field */
	union {
		volatile uint32_t ts1_pc_s1;

		volatile struct {
			uint32_t ts1_pc_s1 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts1_pc_s1_bit;
	}; // 0xc

	/* PRU_TASKS_MGR_ts1_pc_s2 register bit field */
	union {
		volatile uint32_t ts1_pc_s2;

		volatile struct {
			uint32_t ts1_pc_s2 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts1_pc_s2_bit;
	}; // 0x10

	/* PRU_TASKS_MGR_ts1_pc_s3 register bit field */
	union {
		volatile uint32_t ts1_pc_s3;

		volatile struct {
			uint32_t ts1_pc_s3 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts1_pc_s3_bit;
	}; // 0x14

	/* PRU_TASKS_MGR_ts1_pc_s4 register bit field */
	union {
		volatile uint32_t ts1_pc_s4;

		volatile struct {
			uint32_t ts1_pc_s4 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts1_pc_s4_bit;
	}; // 0x18

	/* PRU_TASKS_MGR_ts2_pc_s0 register bit field */
	union {
		volatile uint32_t ts2_pc_s0;

		volatile struct {
			uint32_t ts2_pc_s0 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts2_pc_s0_bit;
	}; // 0x1c

	/* PRU_TASKS_MGR_ts2_pc_s1 register bit field */
	union {
		volatile uint32_t ts2_pc_s1;

		volatile struct {
			uint32_t ts2_pc_s1 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts2_pc_s1_bit;
	}; // 0x20

	/* PRU_TASKS_MGR_ts2_pc_s2 register bit field */
	union {
		volatile uint32_t ts2_pc_s2;

		volatile struct {
			uint32_t ts2_pc_s2 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts2_pc_s2_bit;
	}; // 0x24

	/* PRU_TASKS_MGR_ts2_pc_s3 register bit field */
	union {
		volatile uint32_t ts2_pc_s3;

		volatile struct {
			uint32_t ts2_pc_s3 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts2_pc_s3_bit;
	}; // 0x28

	/* PRU_TASKS_MGR_ts2_pc_s4 register bit field */
	union {
		volatile uint32_t ts2_pc_s4;

		volatile struct {
			uint32_t ts2_pc_s4 : 14; // 13:0
			uint32_t rsvd14 : 18; // 31:14
		} ts2_pc_s4_bit;
	}; // 0x2c

	/* PRU_TASKS_MGR_rx_cfg register bit field */
	union {
		volatile uint32_t rx_cfg;

		volatile struct {
			uint32_t bk1_size : 5; // 4:0
			uint32_t bk2_size : 5; // 9:5
			uint32_t bkn_size : 5; // 14:10
			uint32_t rsvd15 : 17; // 31:15
		} rx_cfg_bit;
	}; // 0x30

	/* PRU_TASKS_MGR_tx_cfg register bit field */
	union {
		volatile uint32_t tx_cfg;

		volatile struct {
			uint32_t tx_wm : 6; // 5:0
			uint32_t rsvd6 : 26; // 31:6
		} tx_cfg_bit;
	}; // 0x34

	/* PRU_TASKS_MGR_ts1_gen_cfg1 register bit field */
	union {
		volatile uint32_t ts1_gen_cfg1;

		volatile struct {
			uint32_t ts1_gen_s0_mx : 8; // 7:0
			uint32_t ts1_gen_s1_mx : 8; // 15:8
			uint32_t ts1_gen_s2_mx : 8; // 23:16
			uint32_t ts1_gen_s3_mx : 8; // 31:24
		} ts1_gen_cfg1_bit;
	}; // 0x38

	/* PRU_TASKS_MGR_ts1_gen_cfg2 register bit field */
	union {
		volatile uint32_t ts1_gen_cfg2;

		volatile struct {
			uint32_t ts1_gen_s4_mx : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} ts1_gen_cfg2_bit;
	}; // 0x3c

	/* PRU_TASKS_MGR_ts2_gen_cfg1 register bit field */
	union {
		volatile uint32_t ts2_gen_cfg1;

		volatile struct {
			uint32_t ts2_gen_s0_mx : 8; // 7:0
			uint32_t ts2_gen_s1_mx : 8; // 15:8
			uint32_t ts2_gen_s2_mx : 8; // 23:16
			uint32_t ts2_gen_s3_mx : 8; // 31:24
		} ts2_gen_cfg1_bit;
	}; // 0x40

	/* PRU_TASKS_MGR_ts2_gen_cfg2 register bit field */
	union {
		volatile uint32_t ts2_gen_cfg2;

		volatile struct {
			uint32_t ts2_gen_s4_mx : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} ts2_gen_cfg2_bit;
	}; // 0x44

	/* PRU_TASKS_MGR_cap_en_cfg register bit field */
	union {
		volatile uint32_t cap_en_cfg;

		volatile struct {
			uint32_t new_cap_en : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} cap_en_cfg_bit;
	}; // 0x48

} tasksMgr;

volatile __far tasksMgr CT_TM_PRU0 __attribute__((cregister("TM_CFG_PRU0", near), peripheral));
volatile __far tasksMgr CT_TM_PRU1 __attribute__((cregister("TM_CFG_PRU1", near), peripheral));
volatile __far tasksMgr CT_TM_RTU0 __attribute__((cregister("TM_CFG_RTU0", near), peripheral));
volatile __far tasksMgr CT_TM_RTU1 __attribute__((cregister("TM_CFG_RTU1", near), peripheral));

#endif /* _PRU_TASKS_MGR_H_ */

