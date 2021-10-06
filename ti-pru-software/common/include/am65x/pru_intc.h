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

#ifndef _PRU_INTC_H_
#define _PRU_INTC_H_

/* PRU INTC register set */
typedef struct {

	/* PRU_INTC_REVISION_REG register bit field */
	union {
		volatile uint32_t REVISION_REG;

		volatile struct {
			uint32_t REV_MINOR : 6; // 5:0
			uint32_t REV_CUSTOM : 2; // 7:6
			uint32_t REV_MAJOR : 3; // 10:8
			uint32_t REV_RTL : 5; // 15:11
			uint32_t REV_MODULE : 12; // 27:16
			uint32_t rsvd28 : 2; // 29:28
			uint32_t REV_SCHEME : 2; // 31:30
		} REVISION_REG_bit;
	}; // 0x0

	/* PRU_INTC_CONTROL_REG register bit field */
	union {
		volatile uint32_t CONTROL_REG;

		volatile struct {
			uint32_t rsvd0 : 1; // 0
			uint32_t WAKEUP_MODE : 1; // 1
			uint32_t NEST_MODE : 2; // 3:2
			uint32_t PRIORITY_HOLD_MODE : 1; // 4
			uint32_t rsvd5 : 27; // 31:5
		} CONTROL_REG_bit;
	}; // 0x4

	uint8_t rsvd8[8]; // 0x8 - 0xf

	/* PRU_INTC_GLOBAL_ENABLE_HINT_REG register bit field */
	union {
		volatile uint32_t GLOBAL_ENABLE_HINT_REG;

		volatile struct {
			uint32_t ENABLE_HINT_ANY : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} GLOBAL_ENABLE_HINT_REG_bit;
	}; // 0x10

	uint8_t rsvd14[8]; // 0x14 - 0x1b

	/* PRU_INTC_GLB_NEST_LEVEL_REG register bit field */
	union {
		volatile uint32_t GLB_NEST_LEVEL_REG;

		volatile struct {
			uint32_t GLB_NEST_LEVEL : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t GLB_NEST_AUTO_OVR : 1; // 31
		} GLB_NEST_LEVEL_REG_bit;
	}; // 0x1c

	/* PRU_INTC_STATUS_SET_INDEX_REG register bit field */
	union {
		volatile uint32_t STATUS_SET_INDEX_REG;

		volatile struct {
			uint32_t STATUS_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} STATUS_SET_INDEX_REG_bit;
	}; // 0x20

	/* PRU_INTC_STATUS_CLR_INDEX_REG register bit field */
	union {
		volatile uint32_t STATUS_CLR_INDEX_REG;

		volatile struct {
			uint32_t STATUS_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} STATUS_CLR_INDEX_REG_bit;
	}; // 0x24

	/* PRU_INTC_ENABLE_SET_INDEX_REG register bit field */
	union {
		volatile uint32_t ENABLE_SET_INDEX_REG;

		volatile struct {
			uint32_t ENABLE_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} ENABLE_SET_INDEX_REG_bit;
	}; // 0x28

	/* PRU_INTC_ENABLE_CLR_INDEX_REG register bit field */
	union {
		volatile uint32_t ENABLE_CLR_INDEX_REG;

		volatile struct {
			uint32_t ENABLE_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} ENABLE_CLR_INDEX_REG_bit;
	}; // 0x2c

	uint8_t rsvd30[4]; // 0x30 - 0x33

	/* PRU_INTC_HINT_ENABLE_SET_INDEX_REG register bit field */
	union {
		volatile uint32_t HINT_ENABLE_SET_INDEX_REG;

		volatile struct {
			uint32_t HINT_ENABLE_SET_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} HINT_ENABLE_SET_INDEX_REG_bit;
	}; // 0x34

	/* PRU_INTC_HINT_ENABLE_CLR_INDEX_REG register bit field */
	union {
		volatile uint32_t HINT_ENABLE_CLR_INDEX_REG;

		volatile struct {
			uint32_t HINT_ENABLE_CLR_INDEX : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} HINT_ENABLE_CLR_INDEX_REG_bit;
	}; // 0x38

	uint8_t rsvd3c[68]; // 0x3c - 0x7f

	/* PRU_INTC_GLB_PRI_INTR_REG register bit field */
	union {
		volatile uint32_t GLB_PRI_INTR_REG;

		volatile struct {
			uint32_t GLB_PRI_INTR : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t GLB_NONE : 1; // 31
		} GLB_PRI_INTR_REG_bit;
	}; // 0x80

	uint8_t rsvd84[380]; // 0x84 - 0x1ff

	/* PRU_INTC_RAW_STATUS_REG0 register bit field */
	union {
		volatile uint32_t RAW_STATUS_REG0;

		volatile struct {
			uint32_t RAW_STATUS_0 : 1; // 0
			uint32_t RAW_STATUS_1 : 1; // 1
			uint32_t RAW_STATUS_2 : 1; // 2
			uint32_t RAW_STATUS_3 : 1; // 3
			uint32_t RAW_STATUS_4 : 1; // 4
			uint32_t RAW_STATUS_5 : 1; // 5
			uint32_t RAW_STATUS_6 : 1; // 6
			uint32_t RAW_STATUS_7 : 1; // 7
			uint32_t RAW_STATUS_8 : 1; // 8
			uint32_t RAW_STATUS_9 : 1; // 9
			uint32_t RAW_STATUS_10 : 1; // 10
			uint32_t RAW_STATUS_11 : 1; // 11
			uint32_t RAW_STATUS_12 : 1; // 12
			uint32_t RAW_STATUS_13 : 1; // 13
			uint32_t RAW_STATUS_14 : 1; // 14
			uint32_t RAW_STATUS_15 : 1; // 15
			uint32_t RAW_STATUS_16 : 1; // 16
			uint32_t RAW_STATUS_17 : 1; // 17
			uint32_t RAW_STATUS_18 : 1; // 18
			uint32_t RAW_STATUS_19 : 1; // 19
			uint32_t RAW_STATUS_20 : 1; // 20
			uint32_t RAW_STATUS_21 : 1; // 21
			uint32_t RAW_STATUS_22 : 1; // 22
			uint32_t RAW_STATUS_23 : 1; // 23
			uint32_t RAW_STATUS_24 : 1; // 24
			uint32_t RAW_STATUS_25 : 1; // 25
			uint32_t RAW_STATUS_26 : 1; // 26
			uint32_t RAW_STATUS_27 : 1; // 27
			uint32_t RAW_STATUS_28 : 1; // 28
			uint32_t RAW_STATUS_29 : 1; // 29
			uint32_t RAW_STATUS_30 : 1; // 30
			uint32_t RAW_STATUS_31 : 1; // 31
		} RAW_STATUS_REG0_bit;
	}; // 0x200

	/* PRU_INTC_RAW_STATUS_REG1 register bit field */
	union {
		volatile uint32_t RAW_STATUS_REG1;

		volatile struct {
			uint32_t RAW_STATUS_32 : 1; // 0
			uint32_t RAW_STATUS_33 : 1; // 1
			uint32_t RAW_STATUS_34 : 1; // 2
			uint32_t RAW_STATUS_35 : 1; // 3
			uint32_t RAW_STATUS_36 : 1; // 4
			uint32_t RAW_STATUS_37 : 1; // 5
			uint32_t RAW_STATUS_38 : 1; // 6
			uint32_t RAW_STATUS_39 : 1; // 7
			uint32_t RAW_STATUS_40 : 1; // 8
			uint32_t RAW_STATUS_41 : 1; // 9
			uint32_t RAW_STATUS_42 : 1; // 10
			uint32_t RAW_STATUS_43 : 1; // 11
			uint32_t RAW_STATUS_44 : 1; // 12
			uint32_t RAW_STATUS_45 : 1; // 13
			uint32_t RAW_STATUS_46 : 1; // 14
			uint32_t RAW_STATUS_47 : 1; // 15
			uint32_t RAW_STATUS_48 : 1; // 16
			uint32_t RAW_STATUS_49 : 1; // 17
			uint32_t RAW_STATUS_50 : 1; // 18
			uint32_t RAW_STATUS_51 : 1; // 19
			uint32_t RAW_STATUS_52 : 1; // 20
			uint32_t RAW_STATUS_53 : 1; // 21
			uint32_t RAW_STATUS_54 : 1; // 22
			uint32_t RAW_STATUS_55 : 1; // 23
			uint32_t RAW_STATUS_56 : 1; // 24
			uint32_t RAW_STATUS_57 : 1; // 25
			uint32_t RAW_STATUS_58 : 1; // 26
			uint32_t RAW_STATUS_59 : 1; // 27
			uint32_t RAW_STATUS_60 : 1; // 28
			uint32_t RAW_STATUS_61 : 1; // 29
			uint32_t RAW_STATUS_62 : 1; // 30
			uint32_t RAW_STATUS_63 : 1; // 31
		} RAW_STATUS_REG1_bit;
	}; // 0x204

	/* PRU_INTC_RAW_STATUS_REG2 register bit field */
	union {
		volatile uint32_t RAW_STATUS_REG2;

		volatile struct {
			uint32_t RAW_STATUS_64 : 1; // 0
			uint32_t RAW_STATUS_65 : 1; // 1
			uint32_t RAW_STATUS_66 : 1; // 2
			uint32_t RAW_STATUS_67 : 1; // 3
			uint32_t RAW_STATUS_68 : 1; // 4
			uint32_t RAW_STATUS_69 : 1; // 5
			uint32_t RAW_STATUS_70 : 1; // 6
			uint32_t RAW_STATUS_71 : 1; // 7
			uint32_t RAW_STATUS_72 : 1; // 8
			uint32_t RAW_STATUS_73 : 1; // 9
			uint32_t RAW_STATUS_74 : 1; // 10
			uint32_t RAW_STATUS_75 : 1; // 11
			uint32_t RAW_STATUS_76 : 1; // 12
			uint32_t RAW_STATUS_77 : 1; // 13
			uint32_t RAW_STATUS_78 : 1; // 14
			uint32_t RAW_STATUS_79 : 1; // 15
			uint32_t RAW_STATUS_80 : 1; // 16
			uint32_t RAW_STATUS_81 : 1; // 17
			uint32_t RAW_STATUS_82 : 1; // 18
			uint32_t RAW_STATUS_83 : 1; // 19
			uint32_t RAW_STATUS_84 : 1; // 20
			uint32_t RAW_STATUS_85 : 1; // 21
			uint32_t RAW_STATUS_86 : 1; // 22
			uint32_t RAW_STATUS_87 : 1; // 23
			uint32_t RAW_STATUS_88 : 1; // 24
			uint32_t RAW_STATUS_89 : 1; // 25
			uint32_t RAW_STATUS_90 : 1; // 26
			uint32_t RAW_STATUS_91 : 1; // 27
			uint32_t RAW_STATUS_92 : 1; // 28
			uint32_t RAW_STATUS_93 : 1; // 29
			uint32_t RAW_STATUS_94 : 1; // 30
			uint32_t RAW_STATUS_95 : 1; // 31
		} RAW_STATUS_REG2_bit;
	}; // 0x208

	/* PRU_INTC_RAW_STATUS_REG3 register bit field */
	union {
		volatile uint32_t RAW_STATUS_REG3;

		volatile struct {
			uint32_t RAW_STATUS_96 : 1; // 0
			uint32_t RAW_STATUS_97 : 1; // 1
			uint32_t RAW_STATUS_98 : 1; // 2
			uint32_t RAW_STATUS_99 : 1; // 3
			uint32_t RAW_STATUS_100 : 1; // 4
			uint32_t RAW_STATUS_101 : 1; // 5
			uint32_t RAW_STATUS_102 : 1; // 6
			uint32_t RAW_STATUS_103 : 1; // 7
			uint32_t RAW_STATUS_104 : 1; // 8
			uint32_t RAW_STATUS_105 : 1; // 9
			uint32_t RAW_STATUS_106 : 1; // 10
			uint32_t RAW_STATUS_107 : 1; // 11
			uint32_t RAW_STATUS_108 : 1; // 12
			uint32_t RAW_STATUS_109 : 1; // 13
			uint32_t RAW_STATUS_110 : 1; // 14
			uint32_t RAW_STATUS_111 : 1; // 15
			uint32_t RAW_STATUS_112 : 1; // 16
			uint32_t RAW_STATUS_113 : 1; // 17
			uint32_t RAW_STATUS_114 : 1; // 18
			uint32_t RAW_STATUS_115 : 1; // 19
			uint32_t RAW_STATUS_116 : 1; // 20
			uint32_t RAW_STATUS_117 : 1; // 21
			uint32_t RAW_STATUS_118 : 1; // 22
			uint32_t RAW_STATUS_119 : 1; // 23
			uint32_t RAW_STATUS_120 : 1; // 24
			uint32_t RAW_STATUS_121 : 1; // 25
			uint32_t RAW_STATUS_122 : 1; // 26
			uint32_t RAW_STATUS_123 : 1; // 27
			uint32_t RAW_STATUS_124 : 1; // 28
			uint32_t RAW_STATUS_125 : 1; // 29
			uint32_t RAW_STATUS_126 : 1; // 30
			uint32_t RAW_STATUS_127 : 1; // 31
		} RAW_STATUS_REG3_bit;
	}; // 0x20c

	/* PRU_INTC_RAW_STATUS_REG4 register bit field */
	union {
		volatile uint32_t RAW_STATUS_REG4;

		volatile struct {
			uint32_t RAW_STATUS_128 : 1; // 0
			uint32_t RAW_STATUS_129 : 1; // 1
			uint32_t RAW_STATUS_130 : 1; // 2
			uint32_t RAW_STATUS_131 : 1; // 3
			uint32_t RAW_STATUS_132 : 1; // 4
			uint32_t RAW_STATUS_133 : 1; // 5
			uint32_t RAW_STATUS_134 : 1; // 6
			uint32_t RAW_STATUS_135 : 1; // 7
			uint32_t RAW_STATUS_136 : 1; // 8
			uint32_t RAW_STATUS_137 : 1; // 9
			uint32_t RAW_STATUS_138 : 1; // 10
			uint32_t RAW_STATUS_139 : 1; // 11
			uint32_t RAW_STATUS_140 : 1; // 12
			uint32_t RAW_STATUS_141 : 1; // 13
			uint32_t RAW_STATUS_142 : 1; // 14
			uint32_t RAW_STATUS_143 : 1; // 15
			uint32_t RAW_STATUS_144 : 1; // 16
			uint32_t RAW_STATUS_145 : 1; // 17
			uint32_t RAW_STATUS_146 : 1; // 18
			uint32_t RAW_STATUS_147 : 1; // 19
			uint32_t RAW_STATUS_148 : 1; // 20
			uint32_t RAW_STATUS_149 : 1; // 21
			uint32_t RAW_STATUS_150 : 1; // 22
			uint32_t RAW_STATUS_151 : 1; // 23
			uint32_t RAW_STATUS_152 : 1; // 24
			uint32_t RAW_STATUS_153 : 1; // 25
			uint32_t RAW_STATUS_154 : 1; // 26
			uint32_t RAW_STATUS_155 : 1; // 27
			uint32_t RAW_STATUS_156 : 1; // 28
			uint32_t RAW_STATUS_157 : 1; // 29
			uint32_t RAW_STATUS_158 : 1; // 30
			uint32_t RAW_STATUS_159 : 1; // 31
		} RAW_STATUS_REG4_bit;
	}; // 0x210

	uint8_t rsvd214[108]; // 0x214 - 0x27f

	/* PRU_INTC_ENA_STATUS_REG0 register bit field */
	union {
		volatile uint32_t ENA_STATUS_REG0;

		volatile struct {
			uint32_t ENA_STATUS_0 : 1; // 0
			uint32_t ENA_STATUS_1 : 1; // 1
			uint32_t ENA_STATUS_2 : 1; // 2
			uint32_t ENA_STATUS_3 : 1; // 3
			uint32_t ENA_STATUS_4 : 1; // 4
			uint32_t ENA_STATUS_5 : 1; // 5
			uint32_t ENA_STATUS_6 : 1; // 6
			uint32_t ENA_STATUS_7 : 1; // 7
			uint32_t ENA_STATUS_8 : 1; // 8
			uint32_t ENA_STATUS_9 : 1; // 9
			uint32_t ENA_STATUS_10 : 1; // 10
			uint32_t ENA_STATUS_11 : 1; // 11
			uint32_t ENA_STATUS_12 : 1; // 12
			uint32_t ENA_STATUS_13 : 1; // 13
			uint32_t ENA_STATUS_14 : 1; // 14
			uint32_t ENA_STATUS_15 : 1; // 15
			uint32_t ENA_STATUS_16 : 1; // 16
			uint32_t ENA_STATUS_17 : 1; // 17
			uint32_t ENA_STATUS_18 : 1; // 18
			uint32_t ENA_STATUS_19 : 1; // 19
			uint32_t ENA_STATUS_20 : 1; // 20
			uint32_t ENA_STATUS_21 : 1; // 21
			uint32_t ENA_STATUS_22 : 1; // 22
			uint32_t ENA_STATUS_23 : 1; // 23
			uint32_t ENA_STATUS_24 : 1; // 24
			uint32_t ENA_STATUS_25 : 1; // 25
			uint32_t ENA_STATUS_26 : 1; // 26
			uint32_t ENA_STATUS_27 : 1; // 27
			uint32_t ENA_STATUS_28 : 1; // 28
			uint32_t ENA_STATUS_29 : 1; // 29
			uint32_t ENA_STATUS_30 : 1; // 30
			uint32_t ENA_STATUS_31 : 1; // 31
		} ENA_STATUS_REG0_bit;
	}; // 0x280

	/* PRU_INTC_ENA_STATUS_REG1 register bit field */
	union {
		volatile uint32_t ENA_STATUS_REG1;

		volatile struct {
			uint32_t ENA_STATUS_32 : 1; // 0
			uint32_t ENA_STATUS_33 : 1; // 1
			uint32_t ENA_STATUS_34 : 1; // 2
			uint32_t ENA_STATUS_35 : 1; // 3
			uint32_t ENA_STATUS_36 : 1; // 4
			uint32_t ENA_STATUS_37 : 1; // 5
			uint32_t ENA_STATUS_38 : 1; // 6
			uint32_t ENA_STATUS_39 : 1; // 7
			uint32_t ENA_STATUS_40 : 1; // 8
			uint32_t ENA_STATUS_41 : 1; // 9
			uint32_t ENA_STATUS_42 : 1; // 10
			uint32_t ENA_STATUS_43 : 1; // 11
			uint32_t ENA_STATUS_44 : 1; // 12
			uint32_t ENA_STATUS_45 : 1; // 13
			uint32_t ENA_STATUS_46 : 1; // 14
			uint32_t ENA_STATUS_47 : 1; // 15
			uint32_t ENA_STATUS_48 : 1; // 16
			uint32_t ENA_STATUS_49 : 1; // 17
			uint32_t ENA_STATUS_50 : 1; // 18
			uint32_t ENA_STATUS_51 : 1; // 19
			uint32_t ENA_STATUS_52 : 1; // 20
			uint32_t ENA_STATUS_53 : 1; // 21
			uint32_t ENA_STATUS_54 : 1; // 22
			uint32_t ENA_STATUS_55 : 1; // 23
			uint32_t ENA_STATUS_56 : 1; // 24
			uint32_t ENA_STATUS_57 : 1; // 25
			uint32_t ENA_STATUS_58 : 1; // 26
			uint32_t ENA_STATUS_59 : 1; // 27
			uint32_t ENA_STATUS_60 : 1; // 28
			uint32_t ENA_STATUS_61 : 1; // 29
			uint32_t ENA_STATUS_62 : 1; // 30
			uint32_t ENA_STATUS_63 : 1; // 31
		} ENA_STATUS_REG1_bit;
	}; // 0x284

	/* PRU_INTC_ENA_STATUS_REG2 register bit field */
	union {
		volatile uint32_t ENA_STATUS_REG2;

		volatile struct {
			uint32_t ENA_STATUS_64 : 1; // 0
			uint32_t ENA_STATUS_65 : 1; // 1
			uint32_t ENA_STATUS_66 : 1; // 2
			uint32_t ENA_STATUS_67 : 1; // 3
			uint32_t ENA_STATUS_68 : 1; // 4
			uint32_t ENA_STATUS_69 : 1; // 5
			uint32_t ENA_STATUS_70 : 1; // 6
			uint32_t ENA_STATUS_71 : 1; // 7
			uint32_t ENA_STATUS_72 : 1; // 8
			uint32_t ENA_STATUS_73 : 1; // 9
			uint32_t ENA_STATUS_74 : 1; // 10
			uint32_t ENA_STATUS_75 : 1; // 11
			uint32_t ENA_STATUS_76 : 1; // 12
			uint32_t ENA_STATUS_77 : 1; // 13
			uint32_t ENA_STATUS_78 : 1; // 14
			uint32_t ENA_STATUS_79 : 1; // 15
			uint32_t ENA_STATUS_80 : 1; // 16
			uint32_t ENA_STATUS_81 : 1; // 17
			uint32_t ENA_STATUS_82 : 1; // 18
			uint32_t ENA_STATUS_83 : 1; // 19
			uint32_t ENA_STATUS_84 : 1; // 20
			uint32_t ENA_STATUS_85 : 1; // 21
			uint32_t ENA_STATUS_86 : 1; // 22
			uint32_t ENA_STATUS_87 : 1; // 23
			uint32_t ENA_STATUS_88 : 1; // 24
			uint32_t ENA_STATUS_89 : 1; // 25
			uint32_t ENA_STATUS_90 : 1; // 26
			uint32_t ENA_STATUS_91 : 1; // 27
			uint32_t ENA_STATUS_92 : 1; // 28
			uint32_t ENA_STATUS_93 : 1; // 29
			uint32_t ENA_STATUS_94 : 1; // 30
			uint32_t ENA_STATUS_95 : 1; // 31
		} ENA_STATUS_REG2_bit;
	}; // 0x288

	/* PRU_INTC_ENA_STATUS_REG3 register bit field */
	union {
		volatile uint32_t ENA_STATUS_REG3;

		volatile struct {
			uint32_t ENA_STATUS_96 : 1; // 0
			uint32_t ENA_STATUS_97 : 1; // 1
			uint32_t ENA_STATUS_98 : 1; // 2
			uint32_t ENA_STATUS_99 : 1; // 3
			uint32_t ENA_STATUS_100 : 1; // 4
			uint32_t ENA_STATUS_101 : 1; // 5
			uint32_t ENA_STATUS_102 : 1; // 6
			uint32_t ENA_STATUS_103 : 1; // 7
			uint32_t ENA_STATUS_104 : 1; // 8
			uint32_t ENA_STATUS_105 : 1; // 9
			uint32_t ENA_STATUS_106 : 1; // 10
			uint32_t ENA_STATUS_107 : 1; // 11
			uint32_t ENA_STATUS_108 : 1; // 12
			uint32_t ENA_STATUS_109 : 1; // 13
			uint32_t ENA_STATUS_110 : 1; // 14
			uint32_t ENA_STATUS_111 : 1; // 15
			uint32_t ENA_STATUS_112 : 1; // 16
			uint32_t ENA_STATUS_113 : 1; // 17
			uint32_t ENA_STATUS_114 : 1; // 18
			uint32_t ENA_STATUS_115 : 1; // 19
			uint32_t ENA_STATUS_116 : 1; // 20
			uint32_t ENA_STATUS_117 : 1; // 21
			uint32_t ENA_STATUS_118 : 1; // 22
			uint32_t ENA_STATUS_119 : 1; // 23
			uint32_t ENA_STATUS_120 : 1; // 24
			uint32_t ENA_STATUS_121 : 1; // 25
			uint32_t ENA_STATUS_122 : 1; // 26
			uint32_t ENA_STATUS_123 : 1; // 27
			uint32_t ENA_STATUS_124 : 1; // 28
			uint32_t ENA_STATUS_125 : 1; // 29
			uint32_t ENA_STATUS_126 : 1; // 30
			uint32_t ENA_STATUS_127 : 1; // 31
		} ENA_STATUS_REG3_bit;
	}; // 0x28c

	/* PRU_INTC_ENA_STATUS_REG4 register bit field */
	union {
		volatile uint32_t ENA_STATUS_REG4;

		volatile struct {
			uint32_t ENA_STATUS_128 : 1; // 0
			uint32_t ENA_STATUS_129 : 1; // 1
			uint32_t ENA_STATUS_130 : 1; // 2
			uint32_t ENA_STATUS_131 : 1; // 3
			uint32_t ENA_STATUS_132 : 1; // 4
			uint32_t ENA_STATUS_133 : 1; // 5
			uint32_t ENA_STATUS_134 : 1; // 6
			uint32_t ENA_STATUS_135 : 1; // 7
			uint32_t ENA_STATUS_136 : 1; // 8
			uint32_t ENA_STATUS_137 : 1; // 9
			uint32_t ENA_STATUS_138 : 1; // 10
			uint32_t ENA_STATUS_139 : 1; // 11
			uint32_t ENA_STATUS_140 : 1; // 12
			uint32_t ENA_STATUS_141 : 1; // 13
			uint32_t ENA_STATUS_142 : 1; // 14
			uint32_t ENA_STATUS_143 : 1; // 15
			uint32_t ENA_STATUS_144 : 1; // 16
			uint32_t ENA_STATUS_145 : 1; // 17
			uint32_t ENA_STATUS_146 : 1; // 18
			uint32_t ENA_STATUS_147 : 1; // 19
			uint32_t ENA_STATUS_148 : 1; // 20
			uint32_t ENA_STATUS_149 : 1; // 21
			uint32_t ENA_STATUS_150 : 1; // 22
			uint32_t ENA_STATUS_151 : 1; // 23
			uint32_t ENA_STATUS_152 : 1; // 24
			uint32_t ENA_STATUS_153 : 1; // 25
			uint32_t ENA_STATUS_154 : 1; // 26
			uint32_t ENA_STATUS_155 : 1; // 27
			uint32_t ENA_STATUS_156 : 1; // 28
			uint32_t ENA_STATUS_157 : 1; // 29
			uint32_t ENA_STATUS_158 : 1; // 30
			uint32_t ENA_STATUS_159 : 1; // 31
		} ENA_STATUS_REG4_bit;
	}; // 0x290

	uint8_t rsvd294[108]; // 0x294 - 0x2ff

	/* PRU_INTC_ENABLE_REG0 register bit field */
	union {
		volatile uint32_t ENABLE_REG0;

		volatile struct {
			uint32_t ENABLE_0 : 1; // 0
			uint32_t ENABLE_1 : 1; // 1
			uint32_t ENABLE_2 : 1; // 2
			uint32_t ENABLE_3 : 1; // 3
			uint32_t ENABLE_4 : 1; // 4
			uint32_t ENABLE_5 : 1; // 5
			uint32_t ENABLE_6 : 1; // 6
			uint32_t ENABLE_7 : 1; // 7
			uint32_t ENABLE_8 : 1; // 8
			uint32_t ENABLE_9 : 1; // 9
			uint32_t ENABLE_10 : 1; // 10
			uint32_t ENABLE_11 : 1; // 11
			uint32_t ENABLE_12 : 1; // 12
			uint32_t ENABLE_13 : 1; // 13
			uint32_t ENABLE_14 : 1; // 14
			uint32_t ENABLE_15 : 1; // 15
			uint32_t ENABLE_16 : 1; // 16
			uint32_t ENABLE_17 : 1; // 17
			uint32_t ENABLE_18 : 1; // 18
			uint32_t ENABLE_19 : 1; // 19
			uint32_t ENABLE_20 : 1; // 20
			uint32_t ENABLE_21 : 1; // 21
			uint32_t ENABLE_22 : 1; // 22
			uint32_t ENABLE_23 : 1; // 23
			uint32_t ENABLE_24 : 1; // 24
			uint32_t ENABLE_25 : 1; // 25
			uint32_t ENABLE_26 : 1; // 26
			uint32_t ENABLE_27 : 1; // 27
			uint32_t ENABLE_28 : 1; // 28
			uint32_t ENABLE_29 : 1; // 29
			uint32_t ENABLE_30 : 1; // 30
			uint32_t ENABLE_31 : 1; // 31
		} ENABLE_REG0_bit;
	}; // 0x300

	/* PRU_INTC_ENABLE_REG1 register bit field */
	union {
		volatile uint32_t ENABLE_REG1;

		volatile struct {
			uint32_t ENABLE_32 : 1; // 0
			uint32_t ENABLE_33 : 1; // 1
			uint32_t ENABLE_34 : 1; // 2
			uint32_t ENABLE_35 : 1; // 3
			uint32_t ENABLE_36 : 1; // 4
			uint32_t ENABLE_37 : 1; // 5
			uint32_t ENABLE_38 : 1; // 6
			uint32_t ENABLE_39 : 1; // 7
			uint32_t ENABLE_40 : 1; // 8
			uint32_t ENABLE_41 : 1; // 9
			uint32_t ENABLE_42 : 1; // 10
			uint32_t ENABLE_43 : 1; // 11
			uint32_t ENABLE_44 : 1; // 12
			uint32_t ENABLE_45 : 1; // 13
			uint32_t ENABLE_46 : 1; // 14
			uint32_t ENABLE_47 : 1; // 15
			uint32_t ENABLE_48 : 1; // 16
			uint32_t ENABLE_49 : 1; // 17
			uint32_t ENABLE_50 : 1; // 18
			uint32_t ENABLE_51 : 1; // 19
			uint32_t ENABLE_52 : 1; // 20
			uint32_t ENABLE_53 : 1; // 21
			uint32_t ENABLE_54 : 1; // 22
			uint32_t ENABLE_55 : 1; // 23
			uint32_t ENABLE_56 : 1; // 24
			uint32_t ENABLE_57 : 1; // 25
			uint32_t ENABLE_58 : 1; // 26
			uint32_t ENABLE_59 : 1; // 27
			uint32_t ENABLE_60 : 1; // 28
			uint32_t ENABLE_61 : 1; // 29
			uint32_t ENABLE_62 : 1; // 30
			uint32_t ENABLE_63 : 1; // 31
		} ENABLE_REG1_bit;
	}; // 0x304

	/* PRU_INTC_ENABLE_REG2 register bit field */
	union {
		volatile uint32_t ENABLE_REG2;

		volatile struct {
			uint32_t ENABLE_64 : 1; // 0
			uint32_t ENABLE_65 : 1; // 1
			uint32_t ENABLE_66 : 1; // 2
			uint32_t ENABLE_67 : 1; // 3
			uint32_t ENABLE_68 : 1; // 4
			uint32_t ENABLE_69 : 1; // 5
			uint32_t ENABLE_70 : 1; // 6
			uint32_t ENABLE_71 : 1; // 7
			uint32_t ENABLE_72 : 1; // 8
			uint32_t ENABLE_73 : 1; // 9
			uint32_t ENABLE_74 : 1; // 10
			uint32_t ENABLE_75 : 1; // 11
			uint32_t ENABLE_76 : 1; // 12
			uint32_t ENABLE_77 : 1; // 13
			uint32_t ENABLE_78 : 1; // 14
			uint32_t ENABLE_79 : 1; // 15
			uint32_t ENABLE_80 : 1; // 16
			uint32_t ENABLE_81 : 1; // 17
			uint32_t ENABLE_82 : 1; // 18
			uint32_t ENABLE_83 : 1; // 19
			uint32_t ENABLE_84 : 1; // 20
			uint32_t ENABLE_85 : 1; // 21
			uint32_t ENABLE_86 : 1; // 22
			uint32_t ENABLE_87 : 1; // 23
			uint32_t ENABLE_88 : 1; // 24
			uint32_t ENABLE_89 : 1; // 25
			uint32_t ENABLE_90 : 1; // 26
			uint32_t ENABLE_91 : 1; // 27
			uint32_t ENABLE_92 : 1; // 28
			uint32_t ENABLE_93 : 1; // 29
			uint32_t ENABLE_94 : 1; // 30
			uint32_t ENABLE_95 : 1; // 31
		} ENABLE_REG2_bit;
	}; // 0x308

	/* PRU_INTC_ENABLE_REG3 register bit field */
	union {
		volatile uint32_t ENABLE_REG3;

		volatile struct {
			uint32_t ENABLE_96 : 1; // 0
			uint32_t ENABLE_97 : 1; // 1
			uint32_t ENABLE_98 : 1; // 2
			uint32_t ENABLE_99 : 1; // 3
			uint32_t ENABLE_100 : 1; // 4
			uint32_t ENABLE_101 : 1; // 5
			uint32_t ENABLE_102 : 1; // 6
			uint32_t ENABLE_103 : 1; // 7
			uint32_t ENABLE_104 : 1; // 8
			uint32_t ENABLE_105 : 1; // 9
			uint32_t ENABLE_106 : 1; // 10
			uint32_t ENABLE_107 : 1; // 11
			uint32_t ENABLE_108 : 1; // 12
			uint32_t ENABLE_109 : 1; // 13
			uint32_t ENABLE_110 : 1; // 14
			uint32_t ENABLE_111 : 1; // 15
			uint32_t ENABLE_112 : 1; // 16
			uint32_t ENABLE_113 : 1; // 17
			uint32_t ENABLE_114 : 1; // 18
			uint32_t ENABLE_115 : 1; // 19
			uint32_t ENABLE_116 : 1; // 20
			uint32_t ENABLE_117 : 1; // 21
			uint32_t ENABLE_118 : 1; // 22
			uint32_t ENABLE_119 : 1; // 23
			uint32_t ENABLE_120 : 1; // 24
			uint32_t ENABLE_121 : 1; // 25
			uint32_t ENABLE_122 : 1; // 26
			uint32_t ENABLE_123 : 1; // 27
			uint32_t ENABLE_124 : 1; // 28
			uint32_t ENABLE_125 : 1; // 29
			uint32_t ENABLE_126 : 1; // 30
			uint32_t ENABLE_127 : 1; // 31
		} ENABLE_REG3_bit;
	}; // 0x30c

	/* PRU_INTC_ENABLE_REG4 register bit field */
	union {
		volatile uint32_t ENABLE_REG4;

		volatile struct {
			uint32_t ENABLE_128 : 1; // 0
			uint32_t ENABLE_129 : 1; // 1
			uint32_t ENABLE_130 : 1; // 2
			uint32_t ENABLE_131 : 1; // 3
			uint32_t ENABLE_132 : 1; // 4
			uint32_t ENABLE_133 : 1; // 5
			uint32_t ENABLE_134 : 1; // 6
			uint32_t ENABLE_135 : 1; // 7
			uint32_t ENABLE_136 : 1; // 8
			uint32_t ENABLE_137 : 1; // 9
			uint32_t ENABLE_138 : 1; // 10
			uint32_t ENABLE_139 : 1; // 11
			uint32_t ENABLE_140 : 1; // 12
			uint32_t ENABLE_141 : 1; // 13
			uint32_t ENABLE_142 : 1; // 14
			uint32_t ENABLE_143 : 1; // 15
			uint32_t ENABLE_144 : 1; // 16
			uint32_t ENABLE_145 : 1; // 17
			uint32_t ENABLE_146 : 1; // 18
			uint32_t ENABLE_147 : 1; // 19
			uint32_t ENABLE_148 : 1; // 20
			uint32_t ENABLE_149 : 1; // 21
			uint32_t ENABLE_150 : 1; // 22
			uint32_t ENABLE_151 : 1; // 23
			uint32_t ENABLE_152 : 1; // 24
			uint32_t ENABLE_153 : 1; // 25
			uint32_t ENABLE_154 : 1; // 26
			uint32_t ENABLE_155 : 1; // 27
			uint32_t ENABLE_156 : 1; // 28
			uint32_t ENABLE_157 : 1; // 29
			uint32_t ENABLE_158 : 1; // 30
			uint32_t ENABLE_159 : 1; // 31
		} ENABLE_REG4_bit;
	}; // 0x310

	uint8_t rsvd314[108]; // 0x314 - 0x37f

	/* PRU_INTC_ENABLE_CLR_REG0 register bit field */
	union {
		volatile uint32_t ENABLE_CLR_REG0;

		volatile struct {
			uint32_t ENABLE_0_CLR : 1; // 0
			uint32_t ENABLE_1_CLR : 1; // 1
			uint32_t ENABLE_2_CLR : 1; // 2
			uint32_t ENABLE_3_CLR : 1; // 3
			uint32_t ENABLE_4_CLR : 1; // 4
			uint32_t ENABLE_5_CLR : 1; // 5
			uint32_t ENABLE_6_CLR : 1; // 6
			uint32_t ENABLE_7_CLR : 1; // 7
			uint32_t ENABLE_8_CLR : 1; // 8
			uint32_t ENABLE_9_CLR : 1; // 9
			uint32_t ENABLE_10_CLR : 1; // 10
			uint32_t ENABLE_11_CLR : 1; // 11
			uint32_t ENABLE_12_CLR : 1; // 12
			uint32_t ENABLE_13_CLR : 1; // 13
			uint32_t ENABLE_14_CLR : 1; // 14
			uint32_t ENABLE_15_CLR : 1; // 15
			uint32_t ENABLE_16_CLR : 1; // 16
			uint32_t ENABLE_17_CLR : 1; // 17
			uint32_t ENABLE_18_CLR : 1; // 18
			uint32_t ENABLE_19_CLR : 1; // 19
			uint32_t ENABLE_20_CLR : 1; // 20
			uint32_t ENABLE_21_CLR : 1; // 21
			uint32_t ENABLE_22_CLR : 1; // 22
			uint32_t ENABLE_23_CLR : 1; // 23
			uint32_t ENABLE_24_CLR : 1; // 24
			uint32_t ENABLE_25_CLR : 1; // 25
			uint32_t ENABLE_26_CLR : 1; // 26
			uint32_t ENABLE_27_CLR : 1; // 27
			uint32_t ENABLE_28_CLR : 1; // 28
			uint32_t ENABLE_29_CLR : 1; // 29
			uint32_t ENABLE_30_CLR : 1; // 30
			uint32_t ENABLE_31_CLR : 1; // 31
		} ENABLE_CLR_REG0_bit;
	}; // 0x380

	/* PRU_INTC_ENABLE_CLR_REG1 register bit field */
	union {
		volatile uint32_t ENABLE_CLR_REG1;

		volatile struct {
			uint32_t ENABLE_32_CLR : 1; // 0
			uint32_t ENABLE_33_CLR : 1; // 1
			uint32_t ENABLE_34_CLR : 1; // 2
			uint32_t ENABLE_35_CLR : 1; // 3
			uint32_t ENABLE_36_CLR : 1; // 4
			uint32_t ENABLE_37_CLR : 1; // 5
			uint32_t ENABLE_38_CLR : 1; // 6
			uint32_t ENABLE_39_CLR : 1; // 7
			uint32_t ENABLE_40_CLR : 1; // 8
			uint32_t ENABLE_41_CLR : 1; // 9
			uint32_t ENABLE_42_CLR : 1; // 10
			uint32_t ENABLE_43_CLR : 1; // 11
			uint32_t ENABLE_44_CLR : 1; // 12
			uint32_t ENABLE_45_CLR : 1; // 13
			uint32_t ENABLE_46_CLR : 1; // 14
			uint32_t ENABLE_47_CLR : 1; // 15
			uint32_t ENABLE_48_CLR : 1; // 16
			uint32_t ENABLE_49_CLR : 1; // 17
			uint32_t ENABLE_50_CLR : 1; // 18
			uint32_t ENABLE_51_CLR : 1; // 19
			uint32_t ENABLE_52_CLR : 1; // 20
			uint32_t ENABLE_53_CLR : 1; // 21
			uint32_t ENABLE_54_CLR : 1; // 22
			uint32_t ENABLE_55_CLR : 1; // 23
			uint32_t ENABLE_56_CLR : 1; // 24
			uint32_t ENABLE_57_CLR : 1; // 25
			uint32_t ENABLE_58_CLR : 1; // 26
			uint32_t ENABLE_59_CLR : 1; // 27
			uint32_t ENABLE_60_CLR : 1; // 28
			uint32_t ENABLE_61_CLR : 1; // 29
			uint32_t ENABLE_62_CLR : 1; // 30
			uint32_t ENABLE_63_CLR : 1; // 31
		} ENABLE_CLR_REG1_bit;
	}; // 0x384

	/* PRU_INTC_ENABLE_CLR_REG2 register bit field */
	union {
		volatile uint32_t ENABLE_CLR_REG2;

		volatile struct {
			uint32_t ENABLE_64_CLR : 1; // 0
			uint32_t ENABLE_65_CLR : 1; // 1
			uint32_t ENABLE_66_CLR : 1; // 2
			uint32_t ENABLE_67_CLR : 1; // 3
			uint32_t ENABLE_68_CLR : 1; // 4
			uint32_t ENABLE_69_CLR : 1; // 5
			uint32_t ENABLE_70_CLR : 1; // 6
			uint32_t ENABLE_71_CLR : 1; // 7
			uint32_t ENABLE_72_CLR : 1; // 8
			uint32_t ENABLE_73_CLR : 1; // 9
			uint32_t ENABLE_74_CLR : 1; // 10
			uint32_t ENABLE_75_CLR : 1; // 11
			uint32_t ENABLE_76_CLR : 1; // 12
			uint32_t ENABLE_77_CLR : 1; // 13
			uint32_t ENABLE_78_CLR : 1; // 14
			uint32_t ENABLE_79_CLR : 1; // 15
			uint32_t ENABLE_80_CLR : 1; // 16
			uint32_t ENABLE_81_CLR : 1; // 17
			uint32_t ENABLE_82_CLR : 1; // 18
			uint32_t ENABLE_83_CLR : 1; // 19
			uint32_t ENABLE_84_CLR : 1; // 20
			uint32_t ENABLE_85_CLR : 1; // 21
			uint32_t ENABLE_86_CLR : 1; // 22
			uint32_t ENABLE_87_CLR : 1; // 23
			uint32_t ENABLE_88_CLR : 1; // 24
			uint32_t ENABLE_89_CLR : 1; // 25
			uint32_t ENABLE_90_CLR : 1; // 26
			uint32_t ENABLE_91_CLR : 1; // 27
			uint32_t ENABLE_92_CLR : 1; // 28
			uint32_t ENABLE_93_CLR : 1; // 29
			uint32_t ENABLE_94_CLR : 1; // 30
			uint32_t ENABLE_95_CLR : 1; // 31
		} ENABLE_CLR_REG2_bit;
	}; // 0x388

	/* PRU_INTC_ENABLE_CLR_REG3 register bit field */
	union {
		volatile uint32_t ENABLE_CLR_REG3;

		volatile struct {
			uint32_t ENABLE_96_CLR : 1; // 0
			uint32_t ENABLE_97_CLR : 1; // 1
			uint32_t ENABLE_98_CLR : 1; // 2
			uint32_t ENABLE_99_CLR : 1; // 3
			uint32_t ENABLE_100_CLR : 1; // 4
			uint32_t ENABLE_101_CLR : 1; // 5
			uint32_t ENABLE_102_CLR : 1; // 6
			uint32_t ENABLE_103_CLR : 1; // 7
			uint32_t ENABLE_104_CLR : 1; // 8
			uint32_t ENABLE_105_CLR : 1; // 9
			uint32_t ENABLE_106_CLR : 1; // 10
			uint32_t ENABLE_107_CLR : 1; // 11
			uint32_t ENABLE_108_CLR : 1; // 12
			uint32_t ENABLE_109_CLR : 1; // 13
			uint32_t ENABLE_110_CLR : 1; // 14
			uint32_t ENABLE_111_CLR : 1; // 15
			uint32_t ENABLE_112_CLR : 1; // 16
			uint32_t ENABLE_113_CLR : 1; // 17
			uint32_t ENABLE_114_CLR : 1; // 18
			uint32_t ENABLE_115_CLR : 1; // 19
			uint32_t ENABLE_116_CLR : 1; // 20
			uint32_t ENABLE_117_CLR : 1; // 21
			uint32_t ENABLE_118_CLR : 1; // 22
			uint32_t ENABLE_119_CLR : 1; // 23
			uint32_t ENABLE_120_CLR : 1; // 24
			uint32_t ENABLE_121_CLR : 1; // 25
			uint32_t ENABLE_122_CLR : 1; // 26
			uint32_t ENABLE_123_CLR : 1; // 27
			uint32_t ENABLE_124_CLR : 1; // 28
			uint32_t ENABLE_125_CLR : 1; // 29
			uint32_t ENABLE_126_CLR : 1; // 30
			uint32_t ENABLE_127_CLR : 1; // 31
		} ENABLE_CLR_REG3_bit;
	}; // 0x38c

	/* PRU_INTC_ENABLE_CLR_REG4 register bit field */
	union {
		volatile uint32_t ENABLE_CLR_REG4;

		volatile struct {
			uint32_t ENABLE_128_CLR : 1; // 0
			uint32_t ENABLE_129_CLR : 1; // 1
			uint32_t ENABLE_130_CLR : 1; // 2
			uint32_t ENABLE_131_CLR : 1; // 3
			uint32_t ENABLE_132_CLR : 1; // 4
			uint32_t ENABLE_133_CLR : 1; // 5
			uint32_t ENABLE_134_CLR : 1; // 6
			uint32_t ENABLE_135_CLR : 1; // 7
			uint32_t ENABLE_136_CLR : 1; // 8
			uint32_t ENABLE_137_CLR : 1; // 9
			uint32_t ENABLE_138_CLR : 1; // 10
			uint32_t ENABLE_139_CLR : 1; // 11
			uint32_t ENABLE_140_CLR : 1; // 12
			uint32_t ENABLE_141_CLR : 1; // 13
			uint32_t ENABLE_142_CLR : 1; // 14
			uint32_t ENABLE_143_CLR : 1; // 15
			uint32_t ENABLE_144_CLR : 1; // 16
			uint32_t ENABLE_145_CLR : 1; // 17
			uint32_t ENABLE_146_CLR : 1; // 18
			uint32_t ENABLE_147_CLR : 1; // 19
			uint32_t ENABLE_148_CLR : 1; // 20
			uint32_t ENABLE_149_CLR : 1; // 21
			uint32_t ENABLE_150_CLR : 1; // 22
			uint32_t ENABLE_151_CLR : 1; // 23
			uint32_t ENABLE_152_CLR : 1; // 24
			uint32_t ENABLE_153_CLR : 1; // 25
			uint32_t ENABLE_154_CLR : 1; // 26
			uint32_t ENABLE_155_CLR : 1; // 27
			uint32_t ENABLE_156_CLR : 1; // 28
			uint32_t ENABLE_157_CLR : 1; // 29
			uint32_t ENABLE_158_CLR : 1; // 30
			uint32_t ENABLE_159_CLR : 1; // 31
		} ENABLE_CLR_REG4_bit;
	}; // 0x390

	uint8_t rsvd394[108]; // 0x394 - 0x3ff

	/* PRU_INTC_CH_MAP_REG0 register bit field */
	union {
		volatile uint32_t CH_MAP_REG0;

		volatile struct {
			uint32_t CH_MAP_0 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_1 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_2 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_3 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG0_bit;
	}; // 0x400

	/* PRU_INTC_CH_MAP_REG1 register bit field */
	union {
		volatile uint32_t CH_MAP_REG1;

		volatile struct {
			uint32_t CH_MAP_4 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_5 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_6 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_7 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG1_bit;
	}; // 0x404

	/* PRU_INTC_CH_MAP_REG2 register bit field */
	union {
		volatile uint32_t CH_MAP_REG2;

		volatile struct {
			uint32_t CH_MAP_8 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_9 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_10 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_11 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG2_bit;
	}; // 0x408

	/* PRU_INTC_CH_MAP_REG3 register bit field */
	union {
		volatile uint32_t CH_MAP_REG3;

		volatile struct {
			uint32_t CH_MAP_12 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_13 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_14 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_15 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG3_bit;
	}; // 0x40c

	/* PRU_INTC_CH_MAP_REG4 register bit field */
	union {
		volatile uint32_t CH_MAP_REG4;

		volatile struct {
			uint32_t CH_MAP_16 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_17 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_18 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_19 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG4_bit;
	}; // 0x410

	/* PRU_INTC_CH_MAP_REG5 register bit field */
	union {
		volatile uint32_t CH_MAP_REG5;

		volatile struct {
			uint32_t CH_MAP_20 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_21 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_22 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_23 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG5_bit;
	}; // 0x414

	/* PRU_INTC_CH_MAP_REG6 register bit field */
	union {
		volatile uint32_t CH_MAP_REG6;

		volatile struct {
			uint32_t CH_MAP_24 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_25 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_26 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_27 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG6_bit;
	}; // 0x418

	/* PRU_INTC_CH_MAP_REG7 register bit field */
	union {
		volatile uint32_t CH_MAP_REG7;

		volatile struct {
			uint32_t CH_MAP_28 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_29 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_30 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_31 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG7_bit;
	}; // 0x41c

	/* PRU_INTC_CH_MAP_REG8 register bit field */
	union {
		volatile uint32_t CH_MAP_REG8;

		volatile struct {
			uint32_t CH_MAP_32 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_33 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_34 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_35 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG8_bit;
	}; // 0x420

	/* PRU_INTC_CH_MAP_REG9 register bit field */
	union {
		volatile uint32_t CH_MAP_REG9;

		volatile struct {
			uint32_t CH_MAP_36 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_37 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_38 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_39 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG9_bit;
	}; // 0x424

	/* PRU_INTC_CH_MAP_REG10 register bit field */
	union {
		volatile uint32_t CH_MAP_REG10;

		volatile struct {
			uint32_t CH_MAP_40 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_41 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_42 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_43 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG10_bit;
	}; // 0x428

	/* PRU_INTC_CH_MAP_REG11 register bit field */
	union {
		volatile uint32_t CH_MAP_REG11;

		volatile struct {
			uint32_t CH_MAP_44 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_45 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_46 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_47 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG11_bit;
	}; // 0x42c

	/* PRU_INTC_CH_MAP_REG12 register bit field */
	union {
		volatile uint32_t CH_MAP_REG12;

		volatile struct {
			uint32_t CH_MAP_48 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_49 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_50 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_51 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG12_bit;
	}; // 0x430

	/* PRU_INTC_CH_MAP_REG13 register bit field */
	union {
		volatile uint32_t CH_MAP_REG13;

		volatile struct {
			uint32_t CH_MAP_52 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_53 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_54 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_55 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG13_bit;
	}; // 0x434

	/* PRU_INTC_CH_MAP_REG14 register bit field */
	union {
		volatile uint32_t CH_MAP_REG14;

		volatile struct {
			uint32_t CH_MAP_56 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_57 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_58 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_59 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG14_bit;
	}; // 0x438

	/* PRU_INTC_CH_MAP_REG15 register bit field */
	union {
		volatile uint32_t CH_MAP_REG15;

		volatile struct {
			uint32_t CH_MAP_60 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_61 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_62 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_63 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG15_bit;
	}; // 0x43c

	/* PRU_INTC_CH_MAP_REG16 register bit field */
	union {
		volatile uint32_t CH_MAP_REG16;

		volatile struct {
			uint32_t CH_MAP_64 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_65 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_66 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_67 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG16_bit;
	}; // 0x440

	/* PRU_INTC_CH_MAP_REG17 register bit field */
	union {
		volatile uint32_t CH_MAP_REG17;

		volatile struct {
			uint32_t CH_MAP_68 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_69 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_70 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_71 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG17_bit;
	}; // 0x444

	/* PRU_INTC_CH_MAP_REG18 register bit field */
	union {
		volatile uint32_t CH_MAP_REG18;

		volatile struct {
			uint32_t CH_MAP_72 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_73 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_74 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_75 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG18_bit;
	}; // 0x448

	/* PRU_INTC_CH_MAP_REG19 register bit field */
	union {
		volatile uint32_t CH_MAP_REG19;

		volatile struct {
			uint32_t CH_MAP_76 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_77 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_78 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_79 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG19_bit;
	}; // 0x44c

	/* PRU_INTC_CH_MAP_REG20 register bit field */
	union {
		volatile uint32_t CH_MAP_REG20;

		volatile struct {
			uint32_t CH_MAP_80 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_81 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_82 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_83 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG20_bit;
	}; // 0x450

	/* PRU_INTC_CH_MAP_REG21 register bit field */
	union {
		volatile uint32_t CH_MAP_REG21;

		volatile struct {
			uint32_t CH_MAP_84 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_85 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_86 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_87 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG21_bit;
	}; // 0x454

	/* PRU_INTC_CH_MAP_REG22 register bit field */
	union {
		volatile uint32_t CH_MAP_REG22;

		volatile struct {
			uint32_t CH_MAP_88 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_89 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_90 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_91 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG22_bit;
	}; // 0x458

	/* PRU_INTC_CH_MAP_REG23 register bit field */
	union {
		volatile uint32_t CH_MAP_REG23;

		volatile struct {
			uint32_t CH_MAP_92 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_93 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_94 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_95 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG23_bit;
	}; // 0x45c

	/* PRU_INTC_CH_MAP_REG24 register bit field */
	union {
		volatile uint32_t CH_MAP_REG24;

		volatile struct {
			uint32_t CH_MAP_96 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_97 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_98 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_99 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG24_bit;
	}; // 0x460

	/* PRU_INTC_CH_MAP_REG25 register bit field */
	union {
		volatile uint32_t CH_MAP_REG25;

		volatile struct {
			uint32_t CH_MAP_100 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_101 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_102 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_103 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG25_bit;
	}; // 0x464

	/* PRU_INTC_CH_MAP_REG26 register bit field */
	union {
		volatile uint32_t CH_MAP_REG26;

		volatile struct {
			uint32_t CH_MAP_104 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_105 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_106 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_107 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG26_bit;
	}; // 0x468

	/* PRU_INTC_CH_MAP_REG27 register bit field */
	union {
		volatile uint32_t CH_MAP_REG27;

		volatile struct {
			uint32_t CH_MAP_108 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_109 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_110 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_111 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG27_bit;
	}; // 0x46c

	/* PRU_INTC_CH_MAP_REG28 register bit field */
	union {
		volatile uint32_t CH_MAP_REG28;

		volatile struct {
			uint32_t CH_MAP_112 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_113 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_114 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_115 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG28_bit;
	}; // 0x470

	/* PRU_INTC_CH_MAP_REG29 register bit field */
	union {
		volatile uint32_t CH_MAP_REG29;

		volatile struct {
			uint32_t CH_MAP_116 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_117 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_118 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_119 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG29_bit;
	}; // 0x474

	/* PRU_INTC_CH_MAP_REG30 register bit field */
	union {
		volatile uint32_t CH_MAP_REG30;

		volatile struct {
			uint32_t CH_MAP_120 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_121 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_122 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_123 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG30_bit;
	}; // 0x478

	/* PRU_INTC_CH_MAP_REG31 register bit field */
	union {
		volatile uint32_t CH_MAP_REG31;

		volatile struct {
			uint32_t CH_MAP_124 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_125 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_126 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_127 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG31_bit;
	}; // 0x47c

	/* PRU_INTC_CH_MAP_REG32 register bit field */
	union {
		volatile uint32_t CH_MAP_REG32;

		volatile struct {
			uint32_t CH_MAP_128 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_129 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_130 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_131 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG32_bit;
	}; // 0x480

	/* PRU_INTC_CH_MAP_REG33 register bit field */
	union {
		volatile uint32_t CH_MAP_REG33;

		volatile struct {
			uint32_t CH_MAP_132 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_133 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_134 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_135 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG33_bit;
	}; // 0x484

	/* PRU_INTC_CH_MAP_REG34 register bit field */
	union {
		volatile uint32_t CH_MAP_REG34;

		volatile struct {
			uint32_t CH_MAP_136 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_137 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_138 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_139 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG34_bit;
	}; // 0x488

	/* PRU_INTC_CH_MAP_REG35 register bit field */
	union {
		volatile uint32_t CH_MAP_REG35;

		volatile struct {
			uint32_t CH_MAP_140 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_141 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_142 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_143 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG35_bit;
	}; // 0x48c

	/* PRU_INTC_CH_MAP_REG36 register bit field */
	union {
		volatile uint32_t CH_MAP_REG36;

		volatile struct {
			uint32_t CH_MAP_144 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_145 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_146 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_147 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG36_bit;
	}; // 0x490

	/* PRU_INTC_CH_MAP_REG37 register bit field */
	union {
		volatile uint32_t CH_MAP_REG37;

		volatile struct {
			uint32_t CH_MAP_148 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_149 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_150 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_151 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG37_bit;
	}; // 0x494

	/* PRU_INTC_CH_MAP_REG38 register bit field */
	union {
		volatile uint32_t CH_MAP_REG38;

		volatile struct {
			uint32_t CH_MAP_152 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_153 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_154 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_155 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG38_bit;
	}; // 0x498

	/* PRU_INTC_CH_MAP_REG39 register bit field */
	union {
		volatile uint32_t CH_MAP_REG39;

		volatile struct {
			uint32_t CH_MAP_156 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t CH_MAP_157 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t CH_MAP_158 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t CH_MAP_159 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} CH_MAP_REG39_bit;
	}; // 0x49c

	uint8_t rsvd4a0[864]; // 0x4a0 - 0x7ff

	/* PRU_INTC_HINT_MAP_REG0 register bit field */
	union {
		volatile uint32_t HINT_MAP_REG0;

		volatile struct {
			uint32_t HINT_MAP_0 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t HINT_MAP_1 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t HINT_MAP_2 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HINT_MAP_3 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} HINT_MAP_REG0_bit;
	}; // 0x800

	/* PRU_INTC_HINT_MAP_REG1 register bit field */
	union {
		volatile uint32_t HINT_MAP_REG1;

		volatile struct {
			uint32_t HINT_MAP_4 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t HINT_MAP_5 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t HINT_MAP_6 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HINT_MAP_7 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} HINT_MAP_REG1_bit;
	}; // 0x804

	/* PRU_INTC_HINT_MAP_REG2 register bit field */
	union {
		volatile uint32_t HINT_MAP_REG2;

		volatile struct {
			uint32_t HINT_MAP_8 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t HINT_MAP_9 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t HINT_MAP_10 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HINT_MAP_11 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} HINT_MAP_REG2_bit;
	}; // 0x808

	/* PRU_INTC_HINT_MAP_REG3 register bit field */
	union {
		volatile uint32_t HINT_MAP_REG3;

		volatile struct {
			uint32_t HINT_MAP_12 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t HINT_MAP_13 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t HINT_MAP_14 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HINT_MAP_15 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} HINT_MAP_REG3_bit;
	}; // 0x80c

	/* PRU_INTC_HINT_MAP_REG4 register bit field */
	union {
		volatile uint32_t HINT_MAP_REG4;

		volatile struct {
			uint32_t HINT_MAP_16 : 5; // 4:0
			uint32_t rsvd5 : 3; // 7:5
			uint32_t HINT_MAP_17 : 5; // 12:8
			uint32_t rsvd13 : 3; // 15:13
			uint32_t HINT_MAP_18 : 5; // 20:16
			uint32_t rsvd21 : 3; // 23:21
			uint32_t HINT_MAP_19 : 5; // 28:24
			uint32_t rsvd29 : 3; // 31:29
		} HINT_MAP_REG4_bit;
	}; // 0x810

	uint8_t rsvd814[236]; // 0x814 - 0x8ff

	/* PRU_INTC_PRI_HINT_REG0 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG0;

		volatile struct {
			uint32_t PRI_HINT_0 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_0 : 1; // 31
		} PRI_HINT_REG0_bit;
	}; // 0x900

	/* PRU_INTC_PRI_HINT_REG1 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG1;

		volatile struct {
			uint32_t PRI_HINT_1 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_1 : 1; // 31
		} PRI_HINT_REG1_bit;
	}; // 0x904

	/* PRU_INTC_PRI_HINT_REG2 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG2;

		volatile struct {
			uint32_t PRI_HINT_2 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_2 : 1; // 31
		} PRI_HINT_REG2_bit;
	}; // 0x908

	/* PRU_INTC_PRI_HINT_REG3 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG3;

		volatile struct {
			uint32_t PRI_HINT_3 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_3 : 1; // 31
		} PRI_HINT_REG3_bit;
	}; // 0x90c

	/* PRU_INTC_PRI_HINT_REG4 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG4;

		volatile struct {
			uint32_t PRI_HINT_4 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_4 : 1; // 31
		} PRI_HINT_REG4_bit;
	}; // 0x910

	/* PRU_INTC_PRI_HINT_REG5 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG5;

		volatile struct {
			uint32_t PRI_HINT_5 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_5 : 1; // 31
		} PRI_HINT_REG5_bit;
	}; // 0x914

	/* PRU_INTC_PRI_HINT_REG6 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG6;

		volatile struct {
			uint32_t PRI_HINT_6 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_6 : 1; // 31
		} PRI_HINT_REG6_bit;
	}; // 0x918

	/* PRU_INTC_PRI_HINT_REG7 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG7;

		volatile struct {
			uint32_t PRI_HINT_7 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_7 : 1; // 31
		} PRI_HINT_REG7_bit;
	}; // 0x91c

	/* PRU_INTC_PRI_HINT_REG8 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG8;

		volatile struct {
			uint32_t PRI_HINT_8 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_8 : 1; // 31
		} PRI_HINT_REG8_bit;
	}; // 0x920

	/* PRU_INTC_PRI_HINT_REG9 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG9;

		volatile struct {
			uint32_t PRI_HINT_9 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_9 : 1; // 31
		} PRI_HINT_REG9_bit;
	}; // 0x924

	/* PRU_INTC_PRI_HINT_REG10 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG10;

		volatile struct {
			uint32_t PRI_HINT_10 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_10 : 1; // 31
		} PRI_HINT_REG10_bit;
	}; // 0x928

	/* PRU_INTC_PRI_HINT_REG11 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG11;

		volatile struct {
			uint32_t PRI_HINT_11 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_11 : 1; // 31
		} PRI_HINT_REG11_bit;
	}; // 0x92c

	/* PRU_INTC_PRI_HINT_REG12 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG12;

		volatile struct {
			uint32_t PRI_HINT_12 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_12 : 1; // 31
		} PRI_HINT_REG12_bit;
	}; // 0x930

	/* PRU_INTC_PRI_HINT_REG13 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG13;

		volatile struct {
			uint32_t PRI_HINT_13 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_13 : 1; // 31
		} PRI_HINT_REG13_bit;
	}; // 0x934

	/* PRU_INTC_PRI_HINT_REG14 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG14;

		volatile struct {
			uint32_t PRI_HINT_14 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_14 : 1; // 31
		} PRI_HINT_REG14_bit;
	}; // 0x938

	/* PRU_INTC_PRI_HINT_REG15 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG15;

		volatile struct {
			uint32_t PRI_HINT_15 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_15 : 1; // 31
		} PRI_HINT_REG15_bit;
	}; // 0x93c

	/* PRU_INTC_PRI_HINT_REG16 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG16;

		volatile struct {
			uint32_t PRI_HINT_16 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_16 : 1; // 31
		} PRI_HINT_REG16_bit;
	}; // 0x940

	/* PRU_INTC_PRI_HINT_REG17 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG17;

		volatile struct {
			uint32_t PRI_HINT_17 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_17 : 1; // 31
		} PRI_HINT_REG17_bit;
	}; // 0x944

	/* PRU_INTC_PRI_HINT_REG18 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG18;

		volatile struct {
			uint32_t PRI_HINT_18 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_18 : 1; // 31
		} PRI_HINT_REG18_bit;
	}; // 0x948

	/* PRU_INTC_PRI_HINT_REG19 register bit field */
	union {
		volatile uint32_t PRI_HINT_REG19;

		volatile struct {
			uint32_t PRI_HINT_19 : 10; // 9:0
			uint32_t rsvd10 : 21; // 30:10
			uint32_t NONE_HINT_19 : 1; // 31
		} PRI_HINT_REG19_bit;
	}; // 0x94c

	uint8_t rsvd950[944]; // 0x950 - 0xcff

	/* PRU_INTC_POLARITY_REG0 register bit field */
	union {
		volatile uint32_t POLARITY_REG0;

		volatile struct {
			uint32_t POLARITY_0 : 1; // 0
			uint32_t POLARITY_1 : 1; // 1
			uint32_t POLARITY_2 : 1; // 2
			uint32_t POLARITY_3 : 1; // 3
			uint32_t POLARITY_4 : 1; // 4
			uint32_t POLARITY_5 : 1; // 5
			uint32_t POLARITY_6 : 1; // 6
			uint32_t POLARITY_7 : 1; // 7
			uint32_t POLARITY_8 : 1; // 8
			uint32_t POLARITY_9 : 1; // 9
			uint32_t POLARITY_10 : 1; // 10
			uint32_t POLARITY_11 : 1; // 11
			uint32_t POLARITY_12 : 1; // 12
			uint32_t POLARITY_13 : 1; // 13
			uint32_t POLARITY_14 : 1; // 14
			uint32_t POLARITY_15 : 1; // 15
			uint32_t POLARITY_16 : 1; // 16
			uint32_t POLARITY_17 : 1; // 17
			uint32_t POLARITY_18 : 1; // 18
			uint32_t POLARITY_19 : 1; // 19
			uint32_t POLARITY_20 : 1; // 20
			uint32_t POLARITY_21 : 1; // 21
			uint32_t POLARITY_22 : 1; // 22
			uint32_t POLARITY_23 : 1; // 23
			uint32_t POLARITY_24 : 1; // 24
			uint32_t POLARITY_25 : 1; // 25
			uint32_t POLARITY_26 : 1; // 26
			uint32_t POLARITY_27 : 1; // 27
			uint32_t POLARITY_28 : 1; // 28
			uint32_t POLARITY_29 : 1; // 29
			uint32_t POLARITY_30 : 1; // 30
			uint32_t POLARITY_31 : 1; // 31
		} POLARITY_REG0_bit;
	}; // 0xd00

	/* PRU_INTC_POLARITY_REG1 register bit field */
	union {
		volatile uint32_t POLARITY_REG1;

		volatile struct {
			uint32_t POLARITY_32 : 1; // 0
			uint32_t POLARITY_33 : 1; // 1
			uint32_t POLARITY_34 : 1; // 2
			uint32_t POLARITY_35 : 1; // 3
			uint32_t POLARITY_36 : 1; // 4
			uint32_t POLARITY_37 : 1; // 5
			uint32_t POLARITY_38 : 1; // 6
			uint32_t POLARITY_39 : 1; // 7
			uint32_t POLARITY_40 : 1; // 8
			uint32_t POLARITY_41 : 1; // 9
			uint32_t POLARITY_42 : 1; // 10
			uint32_t POLARITY_43 : 1; // 11
			uint32_t POLARITY_44 : 1; // 12
			uint32_t POLARITY_45 : 1; // 13
			uint32_t POLARITY_46 : 1; // 14
			uint32_t POLARITY_47 : 1; // 15
			uint32_t POLARITY_48 : 1; // 16
			uint32_t POLARITY_49 : 1; // 17
			uint32_t POLARITY_50 : 1; // 18
			uint32_t POLARITY_51 : 1; // 19
			uint32_t POLARITY_52 : 1; // 20
			uint32_t POLARITY_53 : 1; // 21
			uint32_t POLARITY_54 : 1; // 22
			uint32_t POLARITY_55 : 1; // 23
			uint32_t POLARITY_56 : 1; // 24
			uint32_t POLARITY_57 : 1; // 25
			uint32_t POLARITY_58 : 1; // 26
			uint32_t POLARITY_59 : 1; // 27
			uint32_t POLARITY_60 : 1; // 28
			uint32_t POLARITY_61 : 1; // 29
			uint32_t POLARITY_62 : 1; // 30
			uint32_t POLARITY_63 : 1; // 31
		} POLARITY_REG1_bit;
	}; // 0xd04

	/* PRU_INTC_POLARITY_REG2 register bit field */
	union {
		volatile uint32_t POLARITY_REG2;

		volatile struct {
			uint32_t POLARITY_64 : 1; // 0
			uint32_t POLARITY_65 : 1; // 1
			uint32_t POLARITY_66 : 1; // 2
			uint32_t POLARITY_67 : 1; // 3
			uint32_t POLARITY_68 : 1; // 4
			uint32_t POLARITY_69 : 1; // 5
			uint32_t POLARITY_70 : 1; // 6
			uint32_t POLARITY_71 : 1; // 7
			uint32_t POLARITY_72 : 1; // 8
			uint32_t POLARITY_73 : 1; // 9
			uint32_t POLARITY_74 : 1; // 10
			uint32_t POLARITY_75 : 1; // 11
			uint32_t POLARITY_76 : 1; // 12
			uint32_t POLARITY_77 : 1; // 13
			uint32_t POLARITY_78 : 1; // 14
			uint32_t POLARITY_79 : 1; // 15
			uint32_t POLARITY_80 : 1; // 16
			uint32_t POLARITY_81 : 1; // 17
			uint32_t POLARITY_82 : 1; // 18
			uint32_t POLARITY_83 : 1; // 19
			uint32_t POLARITY_84 : 1; // 20
			uint32_t POLARITY_85 : 1; // 21
			uint32_t POLARITY_86 : 1; // 22
			uint32_t POLARITY_87 : 1; // 23
			uint32_t POLARITY_88 : 1; // 24
			uint32_t POLARITY_89 : 1; // 25
			uint32_t POLARITY_90 : 1; // 26
			uint32_t POLARITY_91 : 1; // 27
			uint32_t POLARITY_92 : 1; // 28
			uint32_t POLARITY_93 : 1; // 29
			uint32_t POLARITY_94 : 1; // 30
			uint32_t POLARITY_95 : 1; // 31
		} POLARITY_REG2_bit;
	}; // 0xd08

	/* PRU_INTC_POLARITY_REG3 register bit field */
	union {
		volatile uint32_t POLARITY_REG3;

		volatile struct {
			uint32_t POLARITY_96 : 1; // 0
			uint32_t POLARITY_97 : 1; // 1
			uint32_t POLARITY_98 : 1; // 2
			uint32_t POLARITY_99 : 1; // 3
			uint32_t POLARITY_100 : 1; // 4
			uint32_t POLARITY_101 : 1; // 5
			uint32_t POLARITY_102 : 1; // 6
			uint32_t POLARITY_103 : 1; // 7
			uint32_t POLARITY_104 : 1; // 8
			uint32_t POLARITY_105 : 1; // 9
			uint32_t POLARITY_106 : 1; // 10
			uint32_t POLARITY_107 : 1; // 11
			uint32_t POLARITY_108 : 1; // 12
			uint32_t POLARITY_109 : 1; // 13
			uint32_t POLARITY_110 : 1; // 14
			uint32_t POLARITY_111 : 1; // 15
			uint32_t POLARITY_112 : 1; // 16
			uint32_t POLARITY_113 : 1; // 17
			uint32_t POLARITY_114 : 1; // 18
			uint32_t POLARITY_115 : 1; // 19
			uint32_t POLARITY_116 : 1; // 20
			uint32_t POLARITY_117 : 1; // 21
			uint32_t POLARITY_118 : 1; // 22
			uint32_t POLARITY_119 : 1; // 23
			uint32_t POLARITY_120 : 1; // 24
			uint32_t POLARITY_121 : 1; // 25
			uint32_t POLARITY_122 : 1; // 26
			uint32_t POLARITY_123 : 1; // 27
			uint32_t POLARITY_124 : 1; // 28
			uint32_t POLARITY_125 : 1; // 29
			uint32_t POLARITY_126 : 1; // 30
			uint32_t POLARITY_127 : 1; // 31
		} POLARITY_REG3_bit;
	}; // 0xd0c

	/* PRU_INTC_POLARITY_REG4 register bit field */
	union {
		volatile uint32_t POLARITY_REG4;

		volatile struct {
			uint32_t POLARITY_128 : 1; // 0
			uint32_t POLARITY_129 : 1; // 1
			uint32_t POLARITY_130 : 1; // 2
			uint32_t POLARITY_131 : 1; // 3
			uint32_t POLARITY_132 : 1; // 4
			uint32_t POLARITY_133 : 1; // 5
			uint32_t POLARITY_134 : 1; // 6
			uint32_t POLARITY_135 : 1; // 7
			uint32_t POLARITY_136 : 1; // 8
			uint32_t POLARITY_137 : 1; // 9
			uint32_t POLARITY_138 : 1; // 10
			uint32_t POLARITY_139 : 1; // 11
			uint32_t POLARITY_140 : 1; // 12
			uint32_t POLARITY_141 : 1; // 13
			uint32_t POLARITY_142 : 1; // 14
			uint32_t POLARITY_143 : 1; // 15
			uint32_t POLARITY_144 : 1; // 16
			uint32_t POLARITY_145 : 1; // 17
			uint32_t POLARITY_146 : 1; // 18
			uint32_t POLARITY_147 : 1; // 19
			uint32_t POLARITY_148 : 1; // 20
			uint32_t POLARITY_149 : 1; // 21
			uint32_t POLARITY_150 : 1; // 22
			uint32_t POLARITY_151 : 1; // 23
			uint32_t POLARITY_152 : 1; // 24
			uint32_t POLARITY_153 : 1; // 25
			uint32_t POLARITY_154 : 1; // 26
			uint32_t POLARITY_155 : 1; // 27
			uint32_t POLARITY_156 : 1; // 28
			uint32_t POLARITY_157 : 1; // 29
			uint32_t POLARITY_158 : 1; // 30
			uint32_t POLARITY_159 : 1; // 31
		} POLARITY_REG4_bit;
	}; // 0xd10

	uint8_t rsvdd14[108]; // 0xd14 - 0xd7f

	/* PRU_INTC_TYPE_REG0 register bit field */
	union {
		volatile uint32_t TYPE_REG0;

		volatile struct {
			uint32_t TYPE_0 : 1; // 0
			uint32_t TYPE_1 : 1; // 1
			uint32_t TYPE_2 : 1; // 2
			uint32_t TYPE_3 : 1; // 3
			uint32_t TYPE_4 : 1; // 4
			uint32_t TYPE_5 : 1; // 5
			uint32_t TYPE_6 : 1; // 6
			uint32_t TYPE_7 : 1; // 7
			uint32_t TYPE_8 : 1; // 8
			uint32_t TYPE_9 : 1; // 9
			uint32_t TYPE_10 : 1; // 10
			uint32_t TYPE_11 : 1; // 11
			uint32_t TYPE_12 : 1; // 12
			uint32_t TYPE_13 : 1; // 13
			uint32_t TYPE_14 : 1; // 14
			uint32_t TYPE_15 : 1; // 15
			uint32_t TYPE_16 : 1; // 16
			uint32_t TYPE_17 : 1; // 17
			uint32_t TYPE_18 : 1; // 18
			uint32_t TYPE_19 : 1; // 19
			uint32_t TYPE_20 : 1; // 20
			uint32_t TYPE_21 : 1; // 21
			uint32_t TYPE_22 : 1; // 22
			uint32_t TYPE_23 : 1; // 23
			uint32_t TYPE_24 : 1; // 24
			uint32_t TYPE_25 : 1; // 25
			uint32_t TYPE_26 : 1; // 26
			uint32_t TYPE_27 : 1; // 27
			uint32_t TYPE_28 : 1; // 28
			uint32_t TYPE_29 : 1; // 29
			uint32_t TYPE_30 : 1; // 30
			uint32_t TYPE_31 : 1; // 31
		} TYPE_REG0_bit;
	}; // 0xd80

	/* PRU_INTC_TYPE_REG1 register bit field */
	union {
		volatile uint32_t TYPE_REG1;

		volatile struct {
			uint32_t TYPE_32 : 1; // 0
			uint32_t TYPE_33 : 1; // 1
			uint32_t TYPE_34 : 1; // 2
			uint32_t TYPE_35 : 1; // 3
			uint32_t TYPE_36 : 1; // 4
			uint32_t TYPE_37 : 1; // 5
			uint32_t TYPE_38 : 1; // 6
			uint32_t TYPE_39 : 1; // 7
			uint32_t TYPE_40 : 1; // 8
			uint32_t TYPE_41 : 1; // 9
			uint32_t TYPE_42 : 1; // 10
			uint32_t TYPE_43 : 1; // 11
			uint32_t TYPE_44 : 1; // 12
			uint32_t TYPE_45 : 1; // 13
			uint32_t TYPE_46 : 1; // 14
			uint32_t TYPE_47 : 1; // 15
			uint32_t TYPE_48 : 1; // 16
			uint32_t TYPE_49 : 1; // 17
			uint32_t TYPE_50 : 1; // 18
			uint32_t TYPE_51 : 1; // 19
			uint32_t TYPE_52 : 1; // 20
			uint32_t TYPE_53 : 1; // 21
			uint32_t TYPE_54 : 1; // 22
			uint32_t TYPE_55 : 1; // 23
			uint32_t TYPE_56 : 1; // 24
			uint32_t TYPE_57 : 1; // 25
			uint32_t TYPE_58 : 1; // 26
			uint32_t TYPE_59 : 1; // 27
			uint32_t TYPE_60 : 1; // 28
			uint32_t TYPE_61 : 1; // 29
			uint32_t TYPE_62 : 1; // 30
			uint32_t TYPE_63 : 1; // 31
		} TYPE_REG1_bit;
	}; // 0xd84

	/* PRU_INTC_TYPE_REG2 register bit field */
	union {
		volatile uint32_t TYPE_REG2;

		volatile struct {
			uint32_t TYPE_64 : 1; // 0
			uint32_t TYPE_65 : 1; // 1
			uint32_t TYPE_66 : 1; // 2
			uint32_t TYPE_67 : 1; // 3
			uint32_t TYPE_68 : 1; // 4
			uint32_t TYPE_69 : 1; // 5
			uint32_t TYPE_70 : 1; // 6
			uint32_t TYPE_71 : 1; // 7
			uint32_t TYPE_72 : 1; // 8
			uint32_t TYPE_73 : 1; // 9
			uint32_t TYPE_74 : 1; // 10
			uint32_t TYPE_75 : 1; // 11
			uint32_t TYPE_76 : 1; // 12
			uint32_t TYPE_77 : 1; // 13
			uint32_t TYPE_78 : 1; // 14
			uint32_t TYPE_79 : 1; // 15
			uint32_t TYPE_80 : 1; // 16
			uint32_t TYPE_81 : 1; // 17
			uint32_t TYPE_82 : 1; // 18
			uint32_t TYPE_83 : 1; // 19
			uint32_t TYPE_84 : 1; // 20
			uint32_t TYPE_85 : 1; // 21
			uint32_t TYPE_86 : 1; // 22
			uint32_t TYPE_87 : 1; // 23
			uint32_t TYPE_88 : 1; // 24
			uint32_t TYPE_89 : 1; // 25
			uint32_t TYPE_90 : 1; // 26
			uint32_t TYPE_91 : 1; // 27
			uint32_t TYPE_92 : 1; // 28
			uint32_t TYPE_93 : 1; // 29
			uint32_t TYPE_94 : 1; // 30
			uint32_t TYPE_95 : 1; // 31
		} TYPE_REG2_bit;
	}; // 0xd88

	/* PRU_INTC_TYPE_REG3 register bit field */
	union {
		volatile uint32_t TYPE_REG3;

		volatile struct {
			uint32_t TYPE_96 : 1; // 0
			uint32_t TYPE_97 : 1; // 1
			uint32_t TYPE_98 : 1; // 2
			uint32_t TYPE_99 : 1; // 3
			uint32_t TYPE_100 : 1; // 4
			uint32_t TYPE_101 : 1; // 5
			uint32_t TYPE_102 : 1; // 6
			uint32_t TYPE_103 : 1; // 7
			uint32_t TYPE_104 : 1; // 8
			uint32_t TYPE_105 : 1; // 9
			uint32_t TYPE_106 : 1; // 10
			uint32_t TYPE_107 : 1; // 11
			uint32_t TYPE_108 : 1; // 12
			uint32_t TYPE_109 : 1; // 13
			uint32_t TYPE_110 : 1; // 14
			uint32_t TYPE_111 : 1; // 15
			uint32_t TYPE_112 : 1; // 16
			uint32_t TYPE_113 : 1; // 17
			uint32_t TYPE_114 : 1; // 18
			uint32_t TYPE_115 : 1; // 19
			uint32_t TYPE_116 : 1; // 20
			uint32_t TYPE_117 : 1; // 21
			uint32_t TYPE_118 : 1; // 22
			uint32_t TYPE_119 : 1; // 23
			uint32_t TYPE_120 : 1; // 24
			uint32_t TYPE_121 : 1; // 25
			uint32_t TYPE_122 : 1; // 26
			uint32_t TYPE_123 : 1; // 27
			uint32_t TYPE_124 : 1; // 28
			uint32_t TYPE_125 : 1; // 29
			uint32_t TYPE_126 : 1; // 30
			uint32_t TYPE_127 : 1; // 31
		} TYPE_REG3_bit;
	}; // 0xd8c

	/* PRU_INTC_TYPE_REG4 register bit field */
	union {
		volatile uint32_t TYPE_REG4;

		volatile struct {
			uint32_t TYPE_128 : 1; // 0
			uint32_t TYPE_129 : 1; // 1
			uint32_t TYPE_130 : 1; // 2
			uint32_t TYPE_131 : 1; // 3
			uint32_t TYPE_132 : 1; // 4
			uint32_t TYPE_133 : 1; // 5
			uint32_t TYPE_134 : 1; // 6
			uint32_t TYPE_135 : 1; // 7
			uint32_t TYPE_136 : 1; // 8
			uint32_t TYPE_137 : 1; // 9
			uint32_t TYPE_138 : 1; // 10
			uint32_t TYPE_139 : 1; // 11
			uint32_t TYPE_140 : 1; // 12
			uint32_t TYPE_141 : 1; // 13
			uint32_t TYPE_142 : 1; // 14
			uint32_t TYPE_143 : 1; // 15
			uint32_t TYPE_144 : 1; // 16
			uint32_t TYPE_145 : 1; // 17
			uint32_t TYPE_146 : 1; // 18
			uint32_t TYPE_147 : 1; // 19
			uint32_t TYPE_148 : 1; // 20
			uint32_t TYPE_149 : 1; // 21
			uint32_t TYPE_150 : 1; // 22
			uint32_t TYPE_151 : 1; // 23
			uint32_t TYPE_152 : 1; // 24
			uint32_t TYPE_153 : 1; // 25
			uint32_t TYPE_154 : 1; // 26
			uint32_t TYPE_155 : 1; // 27
			uint32_t TYPE_156 : 1; // 28
			uint32_t TYPE_157 : 1; // 29
			uint32_t TYPE_158 : 1; // 30
			uint32_t TYPE_159 : 1; // 31
		} TYPE_REG4_bit;
	}; // 0xd90

	uint8_t rsvdd94[876]; // 0xd94 - 0x10ff

	/* PRU_INTC_NEST_LEVEL_REG0 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG0;

		volatile struct {
			uint32_t NEST_HINT_0 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG0_bit;
	}; // 0x1100

	/* PRU_INTC_NEST_LEVEL_REG1 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG1;

		volatile struct {
			uint32_t NEST_HINT_1 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG1_bit;
	}; // 0x1104

	/* PRU_INTC_NEST_LEVEL_REG2 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG2;

		volatile struct {
			uint32_t NEST_HINT_2 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG2_bit;
	}; // 0x1108

	/* PRU_INTC_NEST_LEVEL_REG3 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG3;

		volatile struct {
			uint32_t NEST_HINT_3 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG3_bit;
	}; // 0x110c

	/* PRU_INTC_NEST_LEVEL_REG4 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG4;

		volatile struct {
			uint32_t NEST_HINT_4 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG4_bit;
	}; // 0x1110

	/* PRU_INTC_NEST_LEVEL_REG5 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG5;

		volatile struct {
			uint32_t NEST_HINT_5 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG5_bit;
	}; // 0x1114

	/* PRU_INTC_NEST_LEVEL_REG6 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG6;

		volatile struct {
			uint32_t NEST_HINT_6 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG6_bit;
	}; // 0x1118

	/* PRU_INTC_NEST_LEVEL_REG7 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG7;

		volatile struct {
			uint32_t NEST_HINT_7 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG7_bit;
	}; // 0x111c

	/* PRU_INTC_NEST_LEVEL_REG8 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG8;

		volatile struct {
			uint32_t NEST_HINT_8 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG8_bit;
	}; // 0x1120

	/* PRU_INTC_NEST_LEVEL_REG9 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG9;

		volatile struct {
			uint32_t NEST_HINT_9 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG9_bit;
	}; // 0x1124

	/* PRU_INTC_NEST_LEVEL_REG10 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG10;

		volatile struct {
			uint32_t NEST_HINT_10 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG10_bit;
	}; // 0x1128

	/* PRU_INTC_NEST_LEVEL_REG11 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG11;

		volatile struct {
			uint32_t NEST_HINT_11 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG11_bit;
	}; // 0x112c

	/* PRU_INTC_NEST_LEVEL_REG12 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG12;

		volatile struct {
			uint32_t NEST_HINT_12 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG12_bit;
	}; // 0x1130

	/* PRU_INTC_NEST_LEVEL_REG13 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG13;

		volatile struct {
			uint32_t NEST_HINT_13 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG13_bit;
	}; // 0x1134

	/* PRU_INTC_NEST_LEVEL_REG14 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG14;

		volatile struct {
			uint32_t NEST_HINT_14 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG14_bit;
	}; // 0x1138

	/* PRU_INTC_NEST_LEVEL_REG15 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG15;

		volatile struct {
			uint32_t NEST_HINT_15 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG15_bit;
	}; // 0x113c

	/* PRU_INTC_NEST_LEVEL_REG16 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG16;

		volatile struct {
			uint32_t NEST_HINT_16 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG16_bit;
	}; // 0x1140

	/* PRU_INTC_NEST_LEVEL_REG17 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG17;

		volatile struct {
			uint32_t NEST_HINT_17 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG17_bit;
	}; // 0x1144

	/* PRU_INTC_NEST_LEVEL_REG18 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG18;

		volatile struct {
			uint32_t NEST_HINT_18 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG18_bit;
	}; // 0x1148

	/* PRU_INTC_NEST_LEVEL_REG19 register bit field */
	union {
		volatile uint32_t NEST_LEVEL_REG19;

		volatile struct {
			uint32_t NEST_HINT_19 : 9; // 8:0
			uint32_t rsvd9 : 22; // 30:9
			uint32_t NEST_AUTO_OVR : 1; // 31
		} NEST_LEVEL_REG19_bit;
	}; // 0x114c

	uint8_t rsvd1150[944]; // 0x1150 - 0x14ff

	/* PRU_INTC_ENABLE_HINT_REG0 register bit field */
	union {
		volatile uint32_t ENABLE_HINT_REG0;

		volatile struct {
			uint32_t ENABLE_HINT_0 : 1; // 0
			uint32_t ENABLE_HINT_1 : 1; // 1
			uint32_t ENABLE_HINT_2 : 1; // 2
			uint32_t ENABLE_HINT_3 : 1; // 3
			uint32_t ENABLE_HINT_4 : 1; // 4
			uint32_t ENABLE_HINT_5 : 1; // 5
			uint32_t ENABLE_HINT_6 : 1; // 6
			uint32_t ENABLE_HINT_7 : 1; // 7
			uint32_t ENABLE_HINT_8 : 1; // 8
			uint32_t ENABLE_HINT_9 : 1; // 9
			uint32_t ENABLE_HINT_10 : 1; // 10
			uint32_t ENABLE_HINT_11 : 1; // 11
			uint32_t ENABLE_HINT_12 : 1; // 12
			uint32_t ENABLE_HINT_13 : 1; // 13
			uint32_t ENABLE_HINT_14 : 1; // 14
			uint32_t ENABLE_HINT_15 : 1; // 15
			uint32_t ENABLE_HINT_16 : 1; // 16
			uint32_t ENABLE_HINT_17 : 1; // 17
			uint32_t ENABLE_HINT_18 : 1; // 18
			uint32_t ENABLE_HINT_19 : 1; // 19
			uint32_t rsvd20 : 12; // 31:20
		} ENABLE_HINT_REG0_bit;
	}; // 0x1500

} intc;

volatile __far intc CT_INTC __attribute__((cregister("PRU_INTC", far), peripheral));

#endif /* _PRU_INTC_H_ */

