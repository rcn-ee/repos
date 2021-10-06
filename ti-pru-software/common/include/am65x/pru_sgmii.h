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

#ifndef _PRU_SGMII_H_
#define _PRU_SGMII_H_

/* PRU SGMII register set */
typedef struct {

	/* PRU_SGMII_SGMII_IDVER_REG register bit field */
	union {
		volatile uint32_t SGMII_IDVER_REG;

		volatile struct {
			uint32_t MINOR_VER : 8; // 7:0
			uint32_t MAJOR_VER : 3; // 10:8
			uint32_t RTL_VER : 5; // 15:11
			uint32_t TX_IDENT : 16; // 31:16
		} SGMII_IDVER_REG_bit;
	}; // 0x0

	/* PRU_SGMII_SOFT_RESET_REG register bit field */
	union {
		volatile uint32_t SOFT_RESET_REG;

		volatile struct {
			uint32_t SOFT_RESET : 1; // 0
			uint32_t RT_SOFT_RESET : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} SOFT_RESET_REG_bit;
	}; // 0x4

	uint8_t rsvd8[8]; // 0x8 - 0xf

	/* PRU_SGMII_CONTROL_REG register bit field */
	union {
		volatile uint32_t CONTROL_REG;

		volatile struct {
			uint32_t MR_AN_ENABLE : 1; // 0
			uint32_t MR_AN_RESTART : 1; // 1
			uint32_t FAST_LINK_TIMER : 1; // 2
			uint32_t MR_NP_LOADED : 1; // 3
			uint32_t LOOPBACK : 1; // 4
			uint32_t MASTER : 1; // 5
			uint32_t TEST_PATTERN_EN : 1; // 6
			uint32_t rsvd7 : 25; // 31:7
		} CONTROL_REG_bit;
	}; // 0x10

	/* PRU_SGMII_STATUS_REG register bit field */
	union {
		volatile uint32_t STATUS_REG;

		volatile struct {
			uint32_t LINK : 1; // 0
			uint32_t AN_ERROR : 1; // 1
			uint32_t MR_AN_COMPLETE : 1; // 2
			uint32_t MR_PAGE_RX : 1; // 3
			uint32_t LOCK : 1; // 4
			uint32_t FIB_SIG_DETECT : 1; // 5
			uint32_t rsvd6 : 26; // 31:6
		} STATUS_REG_bit;
	}; // 0x14

	/* PRU_SGMII_MR_ADV_ABILITY_REG register bit field */
	union {
		volatile uint32_t MR_ADV_ABILITY_REG;

		volatile struct {
			uint32_t MR_ADV_ABILITY : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} MR_ADV_ABILITY_REG_bit;
	}; // 0x18

	/* PRU_SGMII_MR_NP_TX_REG register bit field */
	union {
		volatile uint32_t MR_NP_TX_REG;

		volatile struct {
			uint32_t MR_NP_TX : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} MR_NP_TX_REG_bit;
	}; // 0x1c

	/* PRU_SGMII_MR_LP_ADV_ABILITY_REG register bit field */
	union {
		volatile uint32_t MR_LP_ADV_ABILITY_REG;

		volatile struct {
			uint32_t MR_LP_ADV_ABILITY : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} MR_LP_ADV_ABILITY_REG_bit;
	}; // 0x20

	/* PRU_SGMII_MR_LP_NP_RX_REG register bit field */
	union {
		volatile uint32_t MR_LP_NP_RX_REG;

		volatile struct {
			uint32_t MR_LP_NP_RX : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} MR_LP_NP_RX_REG_bit;
	}; // 0x24

	uint8_t rsvd28[8]; // 0x28 - 0x2f

	/* PRU_SGMII_TX_CFG_REG register bit field */
	union {
		volatile uint32_t TX_CFG_REG;

		volatile struct {
			uint32_t TX_CFG : 32; // 31:0
		} TX_CFG_REG_bit;
	}; // 0x30

	/* PRU_SGMII_RX_CFG_REG register bit field */
	union {
		volatile uint32_t RX_CFG_REG;

		volatile struct {
			uint32_t RX_CFG : 32; // 31:0
		} RX_CFG_REG_bit;
	}; // 0x34

	/* PRU_SGMII_AUX_CFG_REG register bit field */
	union {
		volatile uint32_t AUX_CFG_REG;

		volatile struct {
			uint32_t AUX_CFG : 32; // 31:0
		} AUX_CFG_REG_bit;
	}; // 0x38

	uint8_t rsvd3c[4]; // 0x3c - 0x3f

	/* PRU_SGMII_DIAG_CLEAR_REG register bit field */
	union {
		volatile uint32_t DIAG_CLEAR_REG;

		volatile struct {
			uint32_t DIAG_CLEAR : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} DIAG_CLEAR_REG_bit;
	}; // 0x40

	/* PRU_SGMII_DIAG_CONTROL_REG register bit field */
	union {
		volatile uint32_t DIAG_CONTROL_REG;

		volatile struct {
			uint32_t DIAG_EDGE_SEL : 2; // 1:0
			uint32_t rsvd2 : 2; // 3:2
			uint32_t DIAG_SM_SEL : 3; // 6:4
			uint32_t rsvd7 : 25; // 31:7
		} DIAG_CONTROL_REG_bit;
	}; // 0x44

	/* PRU_SGMII_DIAG_STATUS_REG register bit field */
	union {
		volatile uint32_t DIAG_STATUS_REG;

		volatile struct {
			uint32_t DIAG_STATUS : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} DIAG_STATUS_REG_bit;
	}; // 0x48

} sgmii;

// note that SGMII is only available on PRU-ICSSG2
#define PRU_SGMII0 (*((volatile sgmii*)0x32100))
#define PRU_SGMII1 (*((volatile sgmii*)0x32200))

#endif /* _PRU_SGMII_H_ */

