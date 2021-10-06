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

#ifndef _PRU_ECAP_H_
#define _PRU_ECAP_H_

/* PRU ECAP register set */
typedef struct {

	/* PRU_ECAP_TSCNT register bit field */
	union {
		volatile uint32_t TSCNT;

		volatile struct {
			uint32_t TSCNT : 32; // 31:0
		} TSCNT_bit;
	}; // 0x0

	/* PRU_ECAP_CNTPHS register bit field */
	union {
		volatile uint32_t CNTPHS;

		volatile struct {
			uint32_t CNTPHS : 32; // 31:0
		} CNTPHS_bit;
	}; // 0x4

	/* PRU_ECAP_CAP1 register bit field */
	union {
		volatile uint32_t CAP1;

		volatile struct {
			uint32_t CAP1 : 32; // 31:0
		} CAP1_bit;
	}; // 0x8

	/* PRU_ECAP_CAP2 register bit field */
	union {
		volatile uint32_t CAP2;

		volatile struct {
			uint32_t CAP2 : 32; // 31:0
		} CAP2_bit;
	}; // 0xc

	/* PRU_ECAP_CAP3 register bit field */
	union {
		volatile uint32_t CAP3;

		volatile struct {
			uint32_t CAP3 : 32; // 31:0
		} CAP3_bit;
	}; // 0x10

	/* PRU_ECAP_CAP4 register bit field */
	union {
		volatile uint32_t CAP4;

		volatile struct {
			uint32_t CAP4 : 32; // 31:0
		} CAP4_bit;
	}; // 0x14

	uint8_t rsvd18[16]; // 0x18 - 0x27

	/* PRU_ECAP_ECCTL2_ECCTL1 register bit field */
	union {
		volatile uint32_t ECCTL2_ECCTL1;

		volatile struct {
			uint32_t CAP1POL : 1; // 0
			uint32_t CTRRST1 : 1; // 1
			uint32_t CAP2POL : 1; // 2
			uint32_t CTRRST2 : 1; // 3
			uint32_t CAP3POL : 1; // 4
			uint32_t CTRRST3 : 1; // 5
			uint32_t CAP4POL : 1; // 6
			uint32_t CTRRST4 : 1; // 7
			uint32_t CAPLDEN : 1; // 8
			uint32_t EVTFLTPS : 5; // 13:9
			uint32_t SOFT : 1; // 14
			uint32_t FREE : 1; // 15
			uint32_t CONT_ONESHT : 1; // 16
			uint32_t STOPVALUE : 2; // 18:17
			uint32_t REARM_RESET : 1; // 19
			uint32_t TSCNTSTP : 1; // 20
			uint32_t SYNCI_EN : 1; // 21
			uint32_t SYNCO_SEL : 2; // 23:22
			uint32_t SWSYNC : 1; // 24
			uint32_t CAP_APWM : 1; // 25
			uint32_t APWMPOL : 1; // 26
			uint32_t FILTER : 5; // 31:27
		} ECCTL2_ECCTL1_bit;
	}; // 0x28

	/* PRU_ECAP_ECFLG_ECEINT register bit field */
	union {
		volatile uint32_t ECFLG_ECEINT;

		volatile struct {
			uint32_t EN_RESV0 : 1; // 0
			uint32_t EN_CEVT1 : 1; // 1
			uint32_t EN_CEVT2 : 1; // 2
			uint32_t EN_CEVT3 : 1; // 3
			uint32_t EN_CEVT4 : 1; // 4
			uint32_t EN_CNTOVF : 1; // 5
			uint32_t EN_PRDEQ : 1; // 6
			uint32_t EN_CMPEQ : 1; // 7
			uint32_t EN__RESV1 : 8; // 15:8
			uint32_t FLAG_INT : 1; // 16
			uint32_t FLAG_CEVT1 : 1; // 17
			uint32_t FLAG_CEVT2 : 1; // 18
			uint32_t FLAG_CEVT3 : 1; // 19
			uint32_t FLAG_CEVT4 : 1; // 20
			uint32_t FLAG_CNTOVF : 1; // 21
			uint32_t FLAG_PRDEQ : 1; // 22
			uint32_t FLAG_CMPEQ : 1; // 23
			uint32_t FLAG_RESV0 : 8; // 31:24
		} ECFLG_ECEINT_bit;
	}; // 0x2c

	/* PRU_ECAP_ECCLR register bit field */
	union {
		volatile uint32_t ECCLR;

		volatile struct {
			uint32_t INT : 1; // 0
			uint32_t CEVT1 : 1; // 1
			uint32_t CEVT2 : 1; // 2
			uint32_t CEVT3 : 1; // 3
			uint32_t CEVT4 : 1; // 4
			uint32_t CNTOVF : 1; // 5
			uint32_t PRDEQ : 1; // 6
			uint32_t CMPEQ : 1; // 7
			uint32_t _RESV0 : 8; // 15:8
			uint32_t rsvd16 : 16; // 31:16
		} ECCLR_bit;
	}; // 0x30

	/* PRU_ECAP_ECFRC register bit field */
	union {
		volatile uint32_t ECFRC;

		volatile struct {
			uint32_t _RESV0 : 1; // 0
			uint32_t CEVT1 : 1; // 1
			uint32_t CEVT2 : 1; // 2
			uint32_t CEVT3 : 1; // 3
			uint32_t CEVT4 : 1; // 4
			uint32_t CNTOVF : 1; // 5
			uint32_t PRDEQ : 1; // 6
			uint32_t CMPEQ : 1; // 7
			uint32_t _RESV1 : 8; // 15:8
			uint32_t rsvd16 : 16; // 31:16
		} ECFRC_bit;
	}; // 0x34

	uint8_t rsvd38[36]; // 0x38 - 0x5b

	/* PRU_ECAP_PID register bit field */
	union {
		volatile uint32_t PID;

		volatile struct {
			uint32_t REVID : 32; // 31:0
		} PID_bit;
	}; // 0x5c

} ecap;

volatile __far ecap CT_ECAP __attribute__((cregister("PRU_ECAP", near), peripheral));

#endif /* _PRU_ECAP_H_ */

