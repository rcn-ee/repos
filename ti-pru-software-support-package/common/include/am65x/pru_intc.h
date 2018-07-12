/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _PRU_INTC_H_
#define _PRU_INTC_H_

/* PRU INTC register set */
typedef struct {

	/* PRU_INTC_REVID register bit field */
	union {
		volatile uint32_t REVID;

		volatile struct {
			uint32_t REVISION : 32; // 31:0
		} REVID_bit;
	}; // 0x0

	/* PRU_INTC_CR register bit field */
	union {
		volatile uint32_t CR;

		volatile struct {
			uint32_t rsvd0 : 1; // 0
			uint32_t WAKEUP_MODE : 1; // 1
			uint32_t NEST_MODE : 2; // 3:2
			uint32_t PRIORITY_HOLD_MODE : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} CR_bit;
	}; // 0x4

	uint8_t rsvd8[8]; // 0x8 - 0xf

	/* PRU_INTC_GER register bit field */
	union {
		volatile uint32_t GER;

		volatile struct {
			uint32_t ENABLE_HINT_ANY : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} GER_bit;
	}; // 0x10

	uint8_t rsvd14[8]; // 0x14 - 0x1b

	/* PRU_INTC_GNLR register bit field */
	union {
		volatile uint32_t GNLR;

		volatile struct {
			uint32_t GLB_NEST_LEVEL : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t AUTO_OVERRIDE : 1; // 31
		} GNLR_bit;
	}; // 0x1c

	/* PRU_INTC_SISR register bit field */
	union {
		volatile uint32_t SISR;

		volatile struct {
			uint32_t STATUS_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} SISR_bit;
	}; // 0x20

	/* PRU_INTC_SICR register bit field */
	union {
		volatile uint32_t SICR;

		volatile struct {
			uint32_t STATUS_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} SICR_bit;
	}; // 0x24

	/* PRU_INTC_EISR register bit field */
	union {
		volatile uint32_t EISR;

		volatile struct {
			uint32_t ENABLE_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} EISR_bit;
	}; // 0x28

	/* PRU_INTC_EICR register bit field */
	union {
		volatile uint32_t EICR;

		volatile struct {
			uint32_t ENABLE_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} EICR_bit;
	}; // 0x2c

	uint8_t rsvd30[4]; // 0x30 - 0x33

	/* PRU_INTC_HIEISR register bit field */
	union {
		volatile uint32_t HIEISR;

		volatile struct {
			uint32_t HINT_ENABLE_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} HIEISR_bit;
	}; // 0x34

	/* PRU_INTC_HIDISR register bit field */
	union {
		volatile uint32_t HIDISR;

		volatile struct {
			uint32_t HINT_ENABLE_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} HIDISR_bit;
	}; // 0x38

	uint8_t rsvd3c[68]; // 0x3c - 0x7f

	/* PRU_INTC_GPIR register bit field */
	union {
		volatile uint32_t GPIR;

		volatile struct {
			uint32_t GLB_PRI_INTR : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t GLB_NONE : 1; // 31
		} GPIR_bit;
	}; // 0x80

	uint8_t rsvd84[380]; // 0x84 - 0x1ff

	/* PRU_INTC_SRSR0 register bit field */
	union {
		volatile uint32_t SRSR0;

		volatile struct {
			uint32_t RAW_STATUS_31_0 : 32; // 31:0
		} SRSR0_bit;
	}; // 0x200

	/* PRU_INTC_SRSR1 register bit field */
	union {
		volatile uint32_t SRSR1;

		volatile struct {
			uint32_t RAW_STATUS_63_32 : 32; // 31:0
		} SRSR1_bit;
	}; // 0x204

	/* PRU_INTC_SRSR2 register bit field */
	union {
		volatile uint32_t SRSR2;

		volatile struct {
			uint32_t RAW_STATUS_95_64 : 32; // 31:0
		} SRSR2_bit;
	}; // 0x208

	/* PRU_INTC_SRSR3 register bit field */
	union {
		volatile uint32_t SRSR3;

		volatile struct {
			uint32_t RAW_STATUS_127_96 : 32; // 31:0
		} SRSR3_bit;
	}; // 0x20C

	/* PRU_INTC_SRSR4 register bit field */
	union {
		volatile uint32_t SRSR4;

		volatile struct {
			uint32_t RAW_STATUS_159_128 : 32; // 31:0
		} SRSR4_bit;
	}; // 0x210

	uint8_t rsvd214[108]; // 0x214 - 0x27f

	/* PRU_INTC_SECR0 register bit field */
	union {
		volatile uint32_t SECR0;

		volatile struct {
			uint32_t ENA_STATUS_31_0 : 32; // 31:0
		} SECR0_bit;
	}; // 0x280

	/* PRU_INTC_SECR1 register bit field */
	union {
		volatile uint32_t SECR1;

		volatile struct {
			uint32_t ENA_STATUS_63_32 : 32; // 31:0
		} SECR1_bit;
	}; // 0x284

	/* PRU_INTC_SECR2 register bit field */
	union {
		volatile uint32_t SECR2;

		volatile struct {
			uint32_t ENA_STATUS_95_64 : 32; // 31:0
		} SECR2_bit;
	}; // 0x288

	/* PRU_INTC_SECR3 register bit field */
	union {
		volatile uint32_t SECR3;

		volatile struct {
			uint32_t ENA_STATUS_127_96 : 32; // 31:0
		} SECR3_bit;
	}; // 0x28C

	/* PRU_INTC_SECR4 register bit field */
	union {
		volatile uint32_t SECR4;

		volatile struct {
			uint32_t ENA_STATUS_159_128 : 32; // 31:0
		} SECR4_bit;
	}; // 0x290

	uint8_t rsvd294[108]; // 0x294 - 0x2ff

	/* PRU_INTC_ESR0 register bit field */
	union {
		volatile uint32_t ESR0;

		volatile struct {
			uint32_t ENABLE_SET_31_0 : 32; // 31:0
		} ESR0_bit;
	}; // 0x300

	/* PRU_INTC_ERS1 register bit field */
	union {
		volatile uint32_t ERS1;

		volatile struct {
			uint32_t ENABLE_SET_63_32 : 32; // 31:0
		} ERS1_bit;
	}; // 0x304

	/* PRU_INTC_ERS2 register bit field */
	union {
		volatile uint32_t ERS2;

		volatile struct {
			uint32_t ENABLE_SET_95_64 : 32; // 31:0
		} ERS2_bit;
	}; // 0x308

	/* PRU_INTC_ERS3 register bit field */
	union {
		volatile uint32_t ERS3;

		volatile struct {
			uint32_t ENABLE_SET_127_96 : 32; // 31:0
		} ERS3_bit;
	}; // 0x30C

	/* PRU_INTC_ERS5 register bit field */
	union {
		volatile uint32_t ERS4;

		volatile struct {
			uint32_t ENABLE_SET_159_128 : 32; // 31:0
		} ERS4_bit;
	}; // 0x310

	uint8_t rsvd314[108]; // 0x314 - 0x37f

	/* PRU_INTC_ECR0 register bit field */
	union {
		volatile uint32_t ECR0;

		volatile struct {
			uint32_t ENABLE_CLR_31_0 : 32; // 31:0
		} ECR0_bit;
	}; // 0x380

	/* PRU_INTC_ECR1 register bit field */
	union {
		volatile uint32_t ECR1;

		volatile struct {
			uint32_t ENABLE_CLR_63_32 : 32; // 31:0
		} ECR1_bit;
	}; // 0x384

	/* PRU_INTC_ECR2 register bit field */
	union {
		volatile uint32_t ECR2;

		volatile struct {
			uint32_t ENABLE_CLR_95_65 : 32; // 31:0
		} ECR2_bit;
	}; // 0x388

	/* PRU_INTC_ECR3 register bit field */
	union {
		volatile uint32_t ECR3;

		volatile struct {
			uint32_t ENABLE_CLR_127_96 : 32; // 31:0
		} ECR3_bit;
	}; // 0x38C

	/* PRU_INTC_ECR4 register bit field */
	union {
		volatile uint32_t ECR4;

		volatile struct {
			uint32_t ENABLE_CLR_159_128 : 32; // 31:0
		} ECR4_bit;
	}; // 0x390

	uint8_t rsvd394[108]; // 0x394 - 0x3ff

	/* PRU_INTC_CMR0 register bit field */
	union {
		volatile uint32_t CMR0;

		volatile struct {
			uint32_t CH_MAP_0 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_1 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_2 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_3 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR0_bit;
	};	// 0x400

	/* PRU_INTC_CMR1 register bit field */
	union {
		volatile uint32_t CMR1;

		volatile struct {
			uint32_t CH_MAP_4 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_5 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_6 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_7 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR1_bit;
	};	// 0x404

	/* PRU_INTC_CMR2 register bit field */
	union {
		volatile uint32_t CMR2;

		volatile struct {
			uint32_t CH_MAP_8 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_9 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_10 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_11 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR2_bit;
	};	// 0x408

	/* PRU_INTC_CMR3 register bit field */
	union {
		volatile uint32_t CMR3;

		volatile struct {
			uint32_t CH_MAP_12 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_13 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_14 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_15 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR3_bit;
	};	// 0x40C

	/* PRU_INTC_CMR4 register bit field */
	union {
		volatile uint32_t CMR4;

		volatile struct {
			uint32_t CH_MAP_16 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_17 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_18 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_19 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR4_bit;
	};	// 0x410

	/* PRU_INTC_CMR5 register bit field */
	union {
		volatile uint32_t CMR5;

		volatile struct {
			uint32_t CH_MAP_20 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_21 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_22 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_23 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR5_bit;
	};	// 0x414

	/* PRU_INTC_CMR6 register bit field */
	union {
		volatile uint32_t CMR6;

		volatile struct {
			uint32_t CH_MAP_24 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_25 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_26 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_27 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR6_bit;
	};	// 0x418

	/* PRU_INTC_CMR7 register bit field */
	union {
		volatile uint32_t CMR7;

		volatile struct {
			uint32_t CH_MAP_28 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_29 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_30 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_31 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR7_bit;
	};	// 0x41C

	/* PRU_INTC_CMR8 register bit field */
	union {
		volatile uint32_t CMR8;

		volatile struct {
			uint32_t CH_MAP_32 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_33 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_34 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_35 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR8_bit;
	};	// 0x420

	/* PRU_INTC_CMR9 register bit field */
	union {
		volatile uint32_t CMR9;

		volatile struct {
			uint32_t CH_MAP_36 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_37 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_38 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_39 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR9_bit;
	};	// 0x424

	/* PRU_INTC_CMR10 register bit field */
	union {
		volatile uint32_t CMR10;

		volatile struct {
			uint32_t CH_MAP_40 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_41 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_42 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_43 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR10_bit;
	};	// 0x428

	/* PRU_INTC_CMR11 register bit field */
	union {
		volatile uint32_t CMR11;

		volatile struct {
			uint32_t CH_MAP_44 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_45 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_46 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_47 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR11_bit;
	};	// 0x42C

	/* PRU_INTC_CMR12 register bit field */
	union {
		volatile uint32_t CMR12;

		volatile struct {
			uint32_t CH_MAP_48 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_49 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_50 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_51 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR12_bit;
	};	// 0x430

	/* PRU_INTC_CMR13 register bit field */
	union {
		volatile uint32_t CMR13;

		volatile struct {
			uint32_t CH_MAP_52 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_53 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_54 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_55 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR13_bit;
	};	// 0x434

	/* PRU_INTC_CMR14 register bit field */
	union {
		volatile uint32_t CMR14;

		volatile struct {
			uint32_t CH_MAP_56 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_57 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_58 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_59 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR14_bit;
	};	// 0x438

	/* PRU_INTC_CMR15 register bit field */
	union {
		volatile uint32_t CMR15;

		volatile struct {
			uint32_t CH_MAP_60 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_61 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_62 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_63 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR15_bit;
	};	// 0x43C

	/* PRU_INTC_CMR16 register bit field */
	union {
		volatile uint32_t CMR16;

		volatile struct {
			uint32_t CH_MAP_64 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_65 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_66 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_67 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR16_bit;
	};	// 0x440

	/* PRU_INTC_CMR17 register bit field */
	union {
		volatile uint32_t CMR17;

		volatile struct {
			uint32_t CH_MAP_68 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_69 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_70 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_71 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR17_bit;
	};	// 0x444

	/* PRU_INTC_CMR18 register bit field */
	union {
		volatile uint32_t CMR18;

		volatile struct {
			uint32_t CH_MAP_72 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_73 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_74 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_75 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR18_bit;
	};	// 0x448

	/* PRU_INTC_CMR19 register bit field */
	union {
		volatile uint32_t CMR19;

		volatile struct {
			uint32_t CH_MAP_76 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_77 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_78 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_79 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR19_bit;
	};	// 0x44C

	/* PRU_INTC_CMR20 register bit field */
	union {
		volatile uint32_t CMR20;

		volatile struct {
			uint32_t CH_MAP_80 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_81 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_82 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_83 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR20_bit;
	};	// 0x450

	/* PRU_INTC_CMR21 register bit field */
	union {
		volatile uint32_t CMR21;

		volatile struct {
			uint32_t CH_MAP_84 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_85 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_86 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_87 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR21_bit;
	};	// 0x454

	/* PRU_INTC_CMR22 register bit field */
	union {
		volatile uint32_t CMR22;

		volatile struct {
			uint32_t CH_MAP_88 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_89 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_90 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_91 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR22_bit;
	};	// 0x458

	/* PRU_INTC_CMR23 register bit field */
	union {
		volatile uint32_t CMR23;

		volatile struct {
			uint32_t CH_MAP_92 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_93 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_94 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_95 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR23_bit;
	};	// 0x45C

	/* PRU_INTC_CMR24 register bit field */
	union {
		volatile uint32_t CMR24;

		volatile struct {
			uint32_t CH_MAP_96 : 4;		// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_97 : 4;		// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_98 : 4;		// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_99 : 4;		// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR24_bit;
	};	// 0x460

	/* PRU_INTC_CMR25 register bit field */
	union {
		volatile uint32_t CMR25;

		volatile struct {
			uint32_t CH_MAP_100 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_101 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_102 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_103 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR25_bit;
	};	// 0x464

	/* PRU_INTC_CMR26 register bit field */
	union {
		volatile uint32_t CMR26;

		volatile struct {
			uint32_t CH_MAP_104 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_105 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_106 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_107 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR26_bit;
	};	// 0x468

	/* PRU_INTC_CMR27 register bit field */
	union {
		volatile uint32_t CMR27;

		volatile struct {
			uint32_t CH_MAP_108 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_109 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_110 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_111 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR27_bit;
	};	// 0x46C

	/* PRU_INTC_CMR28 register bit field */
	union {
		volatile uint32_t CMR28;

		volatile struct {
			uint32_t CH_MAP_112 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_113 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_114 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_115 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR28_bit;
	};	// 0x470

	/* PRU_INTC_CMR29 register bit field */
	union {
		volatile uint32_t CMR29;

		volatile struct {
			uint32_t CH_MAP_116 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_117 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_118 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_119 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR29_bit;
	};	// 0x474

	/* PRU_INTC_CMR30 register bit field */
	union {
		volatile uint32_t CMR30;

		volatile struct {
			uint32_t CH_MAP_120 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_121 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_122 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_123 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR30_bit;
	};	// 0x478

	/* PRU_INTC_CMR31 register bit field */
	union {
		volatile uint32_t CMR31;

		volatile struct {
			uint32_t CH_MAP_124 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_125 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_126 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_127 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR31_bit;
	};	// 0x47C

	/* PRU_INTC_CMR32 register bit field */
	union {
		volatile uint32_t CMR32;

		volatile struct {
			uint32_t CH_MAP_128 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_129 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_130 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_131 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR32_bit;
	};	// 0x480

	/* PRU_INTC_CMR33 register bit field */
	union {
		volatile uint32_t CMR33;

		volatile struct {
			uint32_t CH_MAP_132 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_133 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_134 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_135 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR33_bit;
	};	// 0x484

	/* PRU_INTC_CMR34 register bit field */
	union {
		volatile uint32_t CMR34;

		volatile struct {
			uint32_t CH_MAP_136 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_137 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_138 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_139 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR34_bit;
	};	// 0x488

	/* PRU_INTC_CMR35 register bit field */
	union {
		volatile uint32_t CMR35;

		volatile struct {
			uint32_t CH_MAP_140 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_141 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_142 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_143 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR35_bit;
	};	// 0x48C

	/* PRU_INTC_CMR36 register bit field */
	union {
		volatile uint32_t CMR36;

		volatile struct {
			uint32_t CH_MAP_144 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_145 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_146 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_147 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR36_bit;
	};	// 0x490

	/* PRU_INTC_CMR37 register bit field */
	union {
		volatile uint32_t CMR37;

		volatile struct {
			uint32_t CH_MAP_148 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_149 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_150 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_151 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR37_bit;
	};	// 0x494

	/* PRU_INTC_CMR38 register bit field */
	union {
		volatile uint32_t CMR38;

		volatile struct {
			uint32_t CH_MAP_152 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_153 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_154 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_155 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR38_bit;
	};	// 0x498

	/* PRU_INTC_CMR39 register bit field */
	union {
		volatile uint32_t CMR39;

		volatile struct {
			uint32_t CH_MAP_156 : 4;	// 3:0
			uint32_t rsvd4 : 4;		// 7:4
			uint32_t CH_MAP_157 : 4;	// 11:8
			uint32_t rsvd12 : 4;		// 15:12
			uint32_t CH_MAP_158 : 4;	// 19:16
			uint32_t rsvd20 : 4;		// 23:20
			uint32_t CH_MAP_159 : 4;	// 27:24
			uint32_t rsvd28 : 4;		// 31:28
		} CMR39_bit;
	};	// 0x49C

	uint8_t rsvd4a0[864]; // 0x4A0 - 0x7ff

	/* PRU_INTC_HMR0 register bit field */
	union {
		volatile uint32_t HMR0;

		volatile struct {
			uint32_t HINT_MAP_0 : 4; // 3:0
			uint32_t rsvd4 : 4; // 7:4
			uint32_t HINT_MAP_1 : 4; // 11:8
			uint32_t rsvd12 : 4; // 15:12
			uint32_t HINT_MAP_2 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t HINT_MAP_3 : 4; // 27:24
			uint32_t rsvd28 : 4; // 31:28
		} HMR0_bit;
	}; // 0x800

	/* PRU_INTC_HMR1 register bit field */
	union {
		volatile uint32_t HMR1;

		volatile struct {
			uint32_t HINT_MAP_4 : 4; // 3:0
			uint32_t rsvd4 : 4; // 7:4
			uint32_t HINT_MAP_5 : 4; // 11:8
			uint32_t rsvd12 : 4; // 15:12
			uint32_t HINT_MAP_6 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t HINT_MAP_7 : 4; // 27:24
			uint32_t rsvd28 : 4; // 31:28
		} HMR1_bit;
	}; // 0x804

	/* PRU_INTC_HMR2 register bit field */
	union {
		volatile uint32_t HMR2;

		volatile struct {
			uint32_t HINT_MAP_8 : 4; // 3:0
			uint32_t rsvd4 : 4; // 7:4
			uint32_t HINT_MAP_9 : 4; // 11:8
			uint32_t rsvd12 : 4; // 15:12
			uint32_t HINT_MAP_10 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t HINT_MAP_11 : 4; // 27:24
			uint32_t rsvd28 : 4; // 31:28
		} HMR2_bit;
	}; // 0x808

	/* PRU_INTC_HMR3 register bit field */
	union {
		volatile uint32_t HMR3;

		volatile struct {
			uint32_t HINT_MAP_12 : 4; // 3:0
			uint32_t rsvd4 : 4; // 7:4
			uint32_t HINT_MAP_13 : 4; // 11:8
			uint32_t rsvd12 : 4; // 15:12
			uint32_t HINT_MAP_14 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t HINT_MAP_15 : 4; // 27:24
			uint32_t rsvd28 : 4; // 31:28
		} HMR3_bit;
	}; // 0x80C

	/* PRU_INTC_HMR4 register bit field */
	union {
		volatile uint32_t HMR4;

		volatile struct {
			uint32_t HINT_MAP_16 : 4; // 3:0
			uint32_t rsvd4 : 4; // 7:4
			uint32_t HINT_MAP_17 : 4; // 11:8
			uint32_t rsvd12 : 4; // 15:12
			uint32_t HINT_MAP_18 : 4; // 19:16
			uint32_t rsvd20 : 4; // 23:20
			uint32_t HINT_MAP_19 : 4; // 27:24
			uint32_t rsvd28 : 4; // 31:28
		} HMR34bit;
	}; // 0x810

	uint8_t rsvd814[236]; // 0x814 - 0x8ff

	/* PRU_INTC_HIPIR0 register bit field */
	union {
		volatile uint32_t HIPIR0;

		volatile struct {
			uint32_t PRI_HINT_0 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_0 : 1;	// 31
		} HIPIR0_bit;
	};	// 0x900


	/* PRU_INTC_HIPIR1 register bit field */
	union {
		volatile uint32_t HIPIR1;

		volatile struct {
			uint32_t PRI_HINT_1 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_1 : 1;	// 31
		} HIPIR1_bit;
	};	// 0x904


	/* PRU_INTC_HIPIR2 register bit field */
	union {
		volatile uint32_t HIPIR2;

		volatile struct {
			uint32_t PRI_HINT_2 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_2 : 1;	// 31
		} HIPIR2_bit;
	};	// 0x908


	/* PRU_INTC_HIPIR3 register bit field */
	union {
		volatile uint32_t HIPIR3;

		volatile struct {
			uint32_t PRI_HINT_3 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_3 : 1;	// 31
		} HIPIR3_bit;
	};	// 0x90C


	/* PRU_INTC_HIPIR4 register bit field */
	union {
		volatile uint32_t HIPIR4;

		volatile struct {
			uint32_t PRI_HINT_4 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_4 : 1;	// 31
		} HIPIR4_bit;
	};	// 0x910


	/* PRU_INTC_HIPIR5 register bit field */
	union {
		volatile uint32_t HIPIR5;

		volatile struct {
			uint32_t PRI_HINT_5 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_5 : 1;	// 31
		} HIPIR5_bit;
	};	// 0x914


	/* PRU_INTC_HIPIR6 register bit field */
	union {
		volatile uint32_t HIPIR6;

		volatile struct {
			uint32_t PRI_HINT_6 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_6 : 1;	// 31
		} HIPIR6_bit;
	};	// 0x918


	/* PRU_INTC_HIPIR7 register bit field */
	union {
		volatile uint32_t HIPIR7;

		volatile struct {
			uint32_t PRI_HINT_7 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_7 : 1;	// 31
		} HIPIR7_bit;
	};	// 0x91C


	/* PRU_INTC_HIPIR8 register bit field */
	union {
		volatile uint32_t HIPIR8;

		volatile struct {
			uint32_t PRI_HINT_8 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_8 : 1;	// 31
		} HIPIR8_bit;
	};	// 0x920


	/* PRU_INTC_HIPIR9 register bit field */
	union {
		volatile uint32_t HIPIR9;

		volatile struct {
			uint32_t PRI_HINT_9 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_9 : 1;	// 31
		} HIPIR9_bit;
	};	// 0x924

	/* PRU_INTC_HIPIR10 register bit field */
	union {
		volatile uint32_t HIPIR10;

		volatile struct {
			uint32_t PRI_HINT_10 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_10 : 1;	// 31
		} HIPIR10_bit;
	};	// 0x928


	/* PRU_INTC_HIPIR11 register bit field */
	union {
		volatile uint32_t HIPIR11;

		volatile struct {
			uint32_t PRI_HINT_11 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_11 : 1;	// 31
		} HIPIR11_bit;
	};	// 0x92C


	/* PRU_INTC_HIPIR12 register bit field */
	union {
		volatile uint32_t HIPIR12;

		volatile struct {
			uint32_t PRI_HINT_12 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_12 : 1;	// 31
		} HIPIR12_bit;
	};	// 0x930


	/* PRU_INTC_HIPIR13 register bit field */
	union {
		volatile uint32_t HIPIR13;

		volatile struct {
			uint32_t PRI_HINT_13 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_13 : 1;	// 31
		} HIPIR13_bit;
	};	// 0x934


	/* PRU_INTC_HIPIR14 register bit field */
	union {
		volatile uint32_t HIPIR14;

		volatile struct {
			uint32_t PRI_HINT_14 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_14 : 1;	// 31
		} HIPIR14_bit;
	};	// 0x938


	/* PRU_INTC_HIPIR15 register bit field */
	union {
		volatile uint32_t HIPIR15;

		volatile struct {
			uint32_t PRI_HINT_15 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_15 : 1;	// 31
		} HIPIR15_bit;
	};	// 0x93C


	/* PRU_INTC_HIPIR16 register bit field */
	union {
		volatile uint32_t HIPIR16;

		volatile struct {
			uint32_t PRI_HINT_16 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_16 : 1;	// 31
		} HIPIR16_bit;
	};	// 0x940


	/* PRU_INTC_HIPIR17 register bit field */
	union {
		volatile uint32_t HIPIR17;

		volatile struct {
			uint32_t PRI_HINT_17 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_17 : 1;	// 31
		} HIPIR17_bit;
	};	// 0x944


	/* PRU_INTC_HIPIR18 register bit field */
	union {
		volatile uint32_t HIPIR18;

		volatile struct {
			uint32_t PRI_HINT_18 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_18 : 1;	// 31
		} HIPIR18_bit;
	};	// 0x948

	/* PRU_INTC_HIPIR19 register bit field */
	union {
		volatile uint32_t HIPIR19;

		volatile struct {
			uint32_t PRI_HINT_19 : 10;	// 9:0
			uint32_t rsvd10 : 21;		// 30:10
			uint32_t NONE_HINT_19 : 1;	// 31
		} HIPIR19_bit;
	};	// 0x94C

	uint8_t rsvd950[944]; // 0x950 - 0xcff

	/* PRU_INTC_SIPR0 register bit field */
	union {
		volatile uint32_t SIPR0;

		volatile struct {
			uint32_t POLARITY_31_0 : 32; // 31:0
		} SIPR0_bit;
	}; // 0xd00

	/* PRU_INTC_SIPR1 register bit field */
	union {
		volatile uint32_t SIPR1;

		volatile struct {
			uint32_t POLARITY_63_32 : 32; // 31:0
		} SIPR1_bit;
	}; // 0xd04

	/* PRU_INTC_SIPR2 register bit field */
	union {
		volatile uint32_t SIPR2;

		volatile struct {
			uint32_t POLARITY_95_64 : 32; // 31:0
		} SIPR2_bit;
	}; // 0xd08

	/* PRU_INTC_SIPR3 register bit field */
	union {
		volatile uint32_t SIPR3;

		volatile struct {
			uint32_t POLARITY_127_96 : 32; // 31:0
		} SIPR3_bit;
	}; // 0xd0C

	/* PRU_INTC_SIPR4 register bit field */
	union {
		volatile uint32_t SIPR4;

		volatile struct {
			uint32_t POLARITY_159_128 : 32; // 31:0
		} SIPR4_bit;
	}; // 0xd10

	uint8_t rsvdd14[108]; // 0xd14 - 0xd7f

	/* PRU_INTC_SITR0 register bit field */
	union {
		volatile uint32_t SITR0;

		volatile struct {
			uint32_t TYPE_31_0 : 32; // 31:0
		} SITR0_bit;
	}; // 0xd80

	/* PRU_INTC_SITR1 register bit field */
	union {
		volatile uint32_t SITR1;

		volatile struct {
			uint32_t TYPE_63_32 : 32; // 31:0
		} SITR1_bit;
	}; // 0xd84

	/* PRU_INTC_SITR2 register bit field */
	union {
		volatile uint32_t SITR2;

		volatile struct {
			uint32_t TYPE_95_64 : 32; // 31:0
		} SITR2_bit;
	}; // 0xd88

	/* PRU_INTC_SITR3 register bit field */
	union {
		volatile uint32_t SITR3;

		volatile struct {
			uint32_t TYPE_127_96 : 32; // 31:0
		} SITR3_bit;
	}; // 0xd8C

	/* PRU_INTC_SITR4 register bit field */
	union {
		volatile uint32_t SITR4;

		volatile struct {
			uint32_t TYPE_159_128 : 32; // 31:0
		} SITR4_bit;
	}; // 0xd90

	uint8_t rsvdd94[876]; // 0xd94 - 0x10ff

	/* PRU_INTC_HINLR0 register bit field */
	union {
		volatile uint32_t HINLR0;

		volatile struct {
			uint32_t NEST_HINT_0 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR0_bit;
	};	// 0x1100


	/* PRU_INTC_HINLR1 register bit field */
	union {
		volatile uint32_t HINLR1;

		volatile struct {
			uint32_t NEST_HINT_1 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR1_bit;
	};	// 0x1104


	/* PRU_INTC_HINLR2 register bit field */
	union {
		volatile uint32_t HINLR2;

		volatile struct {
			uint32_t NEST_HINT_2 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR2_bit;
	};	// 0x1108


	/* PRU_INTC_HINLR3 register bit field */
	union {
		volatile uint32_t HINLR3;

		volatile struct {
			uint32_t NEST_HINT_3 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR3_bit;
	};	// 0x110C


	/* PRU_INTC_HINLR4 register bit field */
	union {
		volatile uint32_t HINLR4;

		volatile struct {
			uint32_t NEST_HINT_4 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR4_bit;
	};	// 0x1110


	/* PRU_INTC_HINLR5 register bit field */
	union {
		volatile uint32_t HINLR5;

		volatile struct {
			uint32_t NEST_HINT_5 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR5_bit;
	};	// 0x1114


	/* PRU_INTC_HINLR6 register bit field */
	union {
		volatile uint32_t HINLR6;

		volatile struct {
			uint32_t NEST_HINT_6 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR6_bit;
	};	// 0x1118


	/* PRU_INTC_HINLR7 register bit field */
	union {
		volatile uint32_t HINLR7;

		volatile struct {
			uint32_t NEST_HINT_7 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR7_bit;
	};	// 0x111C


	/* PRU_INTC_HINLR8 register bit field */
	union {
		volatile uint32_t HINLR8;

		volatile struct {
			uint32_t NEST_HINT_8 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR8_bit;
	};	// 0x1120


	/* PRU_INTC_HINLR9 register bit field */
	union {
		volatile uint32_t HINLR9;

		volatile struct {
			uint32_t NEST_HINT_9 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR9_bit;
	};	// 0x1124

	/* PRU_INTC_HINLR10 register bit field */
	union {
		volatile uint32_t HINLR10;

		volatile struct {
			uint32_t NEST_HINT_10 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR10_bit;
	};	// 0x1128


	/* PRU_INTC_HINLR11 register bit field */
	union {
		volatile uint32_t HINLR11;

		volatile struct {
			uint32_t NEST_HINT_11 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR11_bit;
	};	// 0x112C


	/* PRU_INTC_HINLR12 register bit field */
	union {
		volatile uint32_t HINLR12;

		volatile struct {
			uint32_t NEST_HINT_12 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR12_bit;
	};	// 0x1130


	/* PRU_INTC_HINLR13 register bit field */
	union {
		volatile uint32_t HINLR13;

		volatile struct {
			uint32_t NEST_HINT_13 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR13_bit;
	};	// 0x1134


	/* PRU_INTC_HINLR14 register bit field */
	union {
		volatile uint32_t HINLR14;

		volatile struct {
			uint32_t NEST_HINT_14 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR14_bit;
	};	// 0x1138


	/* PRU_INTC_HINLR15 register bit field */
	union {
		volatile uint32_t HINLR15;

		volatile struct {
			uint32_t NEST_HINT_15 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR15_bit;
	};	// 0x113C


	/* PRU_INTC_HINLR16 register bit field */
	union {
		volatile uint32_t HINLR16;

		volatile struct {
			uint32_t NEST_HINT_16 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR16_bit;
	};	// 0x1140


	/* PRU_INTC_HINLR17 register bit field */
	union {
		volatile uint32_t HINLR17;

		volatile struct {
			uint32_t NEST_HINT_17 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR17_bit;
	};	// 0x1144


	/* PRU_INTC_HINLR18 register bit field */
	union {
		volatile uint32_t HINLR18;

		volatile struct {
			uint32_t NEST_HINT_18 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR18_bit;
	};	// 0x1148

	/* PRU_INTC_HINLR19 register bit field */
	union {
		volatile uint32_t HINLR19;

		volatile struct {
			uint32_t NEST_HINT_19 : 9;	// 8:0
			uint32_t rsvd9 : 22;		// 30:9
			uint32_t AUTO_OVERRIDE : 1;	// 31
		} HINLR19_bit;
	};	// 0x114C

	uint8_t rsvd1150[944]; // 0x1150 - 0x14ff

	/* PRU_INTC_HIER register bit field */
	union {
		volatile uint32_t HIER;

		volatile struct {
			uint32_t ENABLE_HINT : 20; // 19:0
			uint32_t rsvd20 : 12; // 31:20
		} HIER_bit;
	}; // 0x1500

} pruIntc;

volatile __far pruIntc CT_INTC __attribute__((cregister("PRU_INTC", far), peripheral));

#endif /* _PRU_INTC_H_ */
