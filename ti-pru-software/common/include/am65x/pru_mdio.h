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

#ifndef _PRU_MDIO_H_
#define _PRU_MDIO_H_

/* PRU MDIO register set */
typedef struct {

	/* PRU_MDIO_MDIO_VERSION_REG register bit field */
	union {
		volatile uint32_t MDIO_VERSION_REG;

		volatile struct {
			uint32_t REVMINOR : 8; // 7:0
			uint32_t REVMAJ : 8; // 15:8
			uint32_t MODID : 16; // 31:16
		} MDIO_VERSION_REG_bit;
	}; // 0x0

	/* PRU_MDIO_CONTROL_REG register bit field */
	union {
		volatile uint32_t CONTROL_REG;

		volatile struct {
			uint32_t CLKDIV : 16; // 15:0
			uint32_t rsvd16 : 1; // 16
			uint32_t INT_TEST_ENABLE : 1; // 17
			uint32_t FAULT_DETECT_ENABLE : 1; // 18
			uint32_t FAULT : 1; // 19
			uint32_t PREAMBLE : 1; // 20
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HIGHEST_USER_CHANNEL : 5; // 28:24
			uint32_t rsvd29 : 1; // 29
			uint32_t ENABLE : 1; // 30
			uint32_t IDLE : 1; // 31
		} CONTROL_REG_bit;
	}; // 0x4

	/* PRU_MDIO_ALIVE_REG register bit field */
	union {
		volatile uint32_t ALIVE_REG;

		volatile struct {
			uint32_t ALIVE : 32; // 31:0
		} ALIVE_REG_bit;
	}; // 0x8

	/* PRU_MDIO_LINK_REG register bit field */
	union {
		volatile uint32_t LINK_REG;

		volatile struct {
			uint32_t LINK : 32; // 31:0
		} LINK_REG_bit;
	}; // 0xc

	/* PRU_MDIO_LINK_INT_RAW_REG register bit field */
	union {
		volatile uint32_t LINK_INT_RAW_REG;

		volatile struct {
			uint32_t LINKINTRAW : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} LINK_INT_RAW_REG_bit;
	}; // 0x10

	/* PRU_MDIO_LINK_INT_MASKED_REG register bit field */
	union {
		volatile uint32_t LINK_INT_MASKED_REG;

		volatile struct {
			uint32_t LINKINTMASKED : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} LINK_INT_MASKED_REG_bit;
	}; // 0x14

	/* PRU_MDIO_LINK_INT_MASK_SET_REG register bit field */
	union {
		volatile uint32_t LINK_INT_MASK_SET_REG;

		volatile struct {
			uint32_t LINKINTMASKSET : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} LINK_INT_MASK_SET_REG_bit;
	}; // 0x18

	/* PRU_MDIO_LINK_INT_MASK_CLEAR_REG register bit field */
	union {
		volatile uint32_t LINK_INT_MASK_CLEAR_REG;

		volatile struct {
			uint32_t LINKINTMASKCLR : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} LINK_INT_MASK_CLEAR_REG_bit;
	}; // 0x1c

	/* PRU_MDIO_USER_INT_RAW_REG register bit field */
	union {
		volatile uint32_t USER_INT_RAW_REG;

		volatile struct {
			uint32_t USERINTRAW : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} USER_INT_RAW_REG_bit;
	}; // 0x20

	/* PRU_MDIO_USER_INT_MASKED_REG register bit field */
	union {
		volatile uint32_t USER_INT_MASKED_REG;

		volatile struct {
			uint32_t USERINTMASKED : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} USER_INT_MASKED_REG_bit;
	}; // 0x24

	/* PRU_MDIO_USER_INT_MASK_SET_REG register bit field */
	union {
		volatile uint32_t USER_INT_MASK_SET_REG;

		volatile struct {
			uint32_t USERINTMASKSET : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} USER_INT_MASK_SET_REG_bit;
	}; // 0x28

	/* PRU_MDIO_USER_INT_MASK_CLEAR_REG register bit field */
	union {
		volatile uint32_t USER_INT_MASK_CLEAR_REG;

		volatile struct {
			uint32_t USERINTMASKCLR : 2; // 1:0
			uint32_t rsvd2 : 30; // 31:2
		} USER_INT_MASK_CLEAR_REG_bit;
	}; // 0x2c

	/* PRU_MDIO_MANUAL_IF_REG register bit field */
	union {
		volatile uint32_t MANUAL_IF_REG;

		volatile struct {
			uint32_t mdio_pin : 1; // 0
			uint32_t mdio_oe : 1; // 1
			uint32_t mdio_mdclk_o : 1; // 2
			uint32_t rsvd3 : 29; // 31:3
		} MANUAL_IF_REG_bit;
	}; // 0x30

	/* PRU_MDIO_POLL_REG register bit field */
	union {
		volatile uint32_t POLL_REG;

		volatile struct {
			uint32_t ipg : 8; // 7:0
			uint32_t rsvd8 : 22; // 29:8
			uint32_t statechangemode : 1; // 30
			uint32_t manualmode : 1; // 31
		} POLL_REG_bit;
	}; // 0x34

	/* PRU_MDIO_POLL_EN_REG register bit field */
	union {
		volatile uint32_t POLL_EN_REG;

		volatile struct {
			uint32_t poll_en : 32; // 31:0
		} POLL_EN_REG_bit;
	}; // 0x38

	/* PRU_MDIO_CLAUS45_REG register bit field */
	union {
		volatile uint32_t CLAUS45_REG;

		volatile struct {
			uint32_t clause45 : 32; // 31:0
		} CLAUS45_REG_bit;
	}; // 0x3c

	/* PRU_MDIO_USER_ADDR0_REG register bit field */
	union {
		volatile uint32_t USER_ADDR0_REG;

		volatile struct {
			uint32_t user_addr0 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} USER_ADDR0_REG_bit;
	}; // 0x40

	/* PRU_MDIO_USER_ADDR1_REG register bit field */
	union {
		volatile uint32_t USER_ADDR1_REG;

		volatile struct {
			uint32_t user_addr1 : 16; // 15:0
			uint32_t rsvd16 : 16; // 31:16
		} USER_ADDR1_REG_bit;
	}; // 0x44

} mdio;

volatile __far mdio CT_MDIO __attribute__((cregister("MII_MDIO", near), peripheral));

#endif /* _PRU_MDIO_H_ */

