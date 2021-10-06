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

#ifndef _PRU_MII_RT_H_
#define _PRU_MII_RT_H_

/* PRU MII RT register set */
typedef struct {

	/* PRU_MII_RT_rxcfg0 register bit field */
	union {
		volatile uint32_t rxcfg0;

		volatile struct {
			uint32_t rx_enable0 : 1; // 0
			uint32_t rx_data_rdy_mode_dis0 : 1; // 1
			uint32_t rx_cut_preamble0 : 1; // 2
			uint32_t rx_mux_sel0 : 1; // 3
			uint32_t rx_l2_en0 : 1; // 4
			uint32_t rx_byte_swap0 : 1; // 5
			uint32_t rx_auto_fwd_pre0 : 1; // 6
			uint32_t rx_sfd_raw0 : 1; // 7
			uint32_t rx_err_raw0 : 1; // 8
			uint32_t rx_eof_sclr_dis0 : 1; // 9
			uint32_t rsvd10 : 22; // 31:10
		} rxcfg0_bit;
	}; // 0x0

	/* PRU_MII_RT_rxcfg1 register bit field */
	union {
		volatile uint32_t rxcfg1;

		volatile struct {
			uint32_t rx_enable1 : 1; // 0
			uint32_t rx_data_rdy_mode_dis1 : 1; // 1
			uint32_t rx_cut_preamble1 : 1; // 2
			uint32_t rx_mux_sel1 : 1; // 3
			uint32_t rx_l2_en1 : 1; // 4
			uint32_t rx_byte_swap1 : 1; // 5
			uint32_t rx_auto_fwd_pre1 : 1; // 6
			uint32_t rx_sfd_raw1 : 1; // 7
			uint32_t rx_err_raw1 : 1; // 8
			uint32_t rx_eof_sclr_dis1 : 1; // 9
			uint32_t rsvd10 : 22; // 31:10
		} rxcfg1_bit;
	}; // 0x4

	uint8_t rsvd8[8]; // 0x8 - 0xf

	/* PRU_MII_RT_txcfg0 register bit field */
	union {
		volatile uint32_t txcfg0;

		volatile struct {
			uint32_t tx_enable0 : 1; // 0
			uint32_t tx_auto_preamble0 : 1; // 1
			uint32_t tx_en_mode0 : 1; // 2
			uint32_t tx_byte_swap0 : 1; // 3
			uint32_t rsvd4 : 4; // 7:4
			uint32_t tx_mux_sel0 : 1; // 8
			uint32_t pre_tx_auto_sequence0 : 1; // 9
			uint32_t pre_tx_auto_esc_err0 : 1; // 10
			uint32_t tx_32_mode_en0 : 1; // 11
			uint32_t rsvd12 : 4; // 15:12
			uint32_t tx_start_delay0 : 10; // 25:16
			uint32_t rsvd26 : 2; // 27:26
			uint32_t tx_clk_delay0 : 3; // 30:28
			uint32_t rsvd31 : 1; // 31
		} txcfg0_bit;
	}; // 0x10

	/* PRU_MII_RT_txcfg1 register bit field */
	union {
		volatile uint32_t txcfg1;

		volatile struct {
			uint32_t tx_enable1 : 1; // 0
			uint32_t tx_auto_preamble1 : 1; // 1
			uint32_t tx_en_mode1 : 1; // 2
			uint32_t tx_byte_swap1 : 1; // 3
			uint32_t rsvd4 : 4; // 7:4
			uint32_t tx_mux_sel1 : 1; // 8
			uint32_t pre_tx_auto_sequence1 : 1; // 9
			uint32_t pre_tx_auto_esc_err1 : 1; // 10
			uint32_t tx_32_mode_en1 : 1; // 11
			uint32_t rsvd12 : 4; // 15:12
			uint32_t tx_start_delay1 : 10; // 25:16
			uint32_t rsvd26 : 2; // 27:26
			uint32_t tx_clk_delay1 : 3; // 30:28
			uint32_t rsvd31 : 1; // 31
		} txcfg1_bit;
	}; // 0x14

	uint8_t rsvd18[8]; // 0x18 - 0x1f

	/* PRU_MII_RT_tx_crc0 register bit field */
	union {
		volatile uint32_t tx_crc0;

		volatile struct {
			uint32_t tx_crc0 : 32; // 31:0
		} tx_crc0_bit;
	}; // 0x20

	/* PRU_MII_RT_tx_crc1 register bit field */
	union {
		volatile uint32_t tx_crc1;

		volatile struct {
			uint32_t tx_crc1 : 32; // 31:0
		} tx_crc1_bit;
	}; // 0x24

	uint8_t rsvd28[8]; // 0x28 - 0x2f

	/* PRU_MII_RT_tx_ipg0 register bit field */
	union {
		volatile uint32_t tx_ipg0;

		volatile struct {
			uint32_t tx_ipg0 : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} tx_ipg0_bit;
	}; // 0x30

	/* PRU_MII_RT_tx_ipg1 register bit field */
	union {
		volatile uint32_t tx_ipg1;

		volatile struct {
			uint32_t tx_ipg1 : 10; // 9:0
			uint32_t rsvd10 : 22; // 31:10
		} tx_ipg1_bit;
	}; // 0x34

	/* PRU_MII_RT_prs0 register bit field */
	union {
		volatile uint32_t prs0;

		volatile struct {
			uint32_t sync_mii0_col : 1; // 0
			uint32_t sync_mii0_crs : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} prs0_bit;
	}; // 0x38

	/* PRU_MII_RT_prs1 register bit field */
	union {
		volatile uint32_t prs1;

		volatile struct {
			uint32_t sync_mii1_col : 1; // 0
			uint32_t sync_mii1_crs : 1; // 1
			uint32_t rsvd2 : 30; // 31:2
		} prs1_bit;
	}; // 0x3c

	/* PRU_MII_RT_rx_frms0 register bit field */
	union {
		volatile uint32_t rx_frms0;

		volatile struct {
			uint32_t rx_min_frm0 : 16; // 15:0
			uint32_t rx_max_frm0 : 16; // 31:16
		} rx_frms0_bit;
	}; // 0x40

	/* PRU_MII_RT_rx_frms1 register bit field */
	union {
		volatile uint32_t rx_frms1;

		volatile struct {
			uint32_t rx_min_frm1 : 16; // 15:0
			uint32_t rx_max_frm1 : 16; // 31:16
		} rx_frms1_bit;
	}; // 0x44

	/* PRU_MII_RT_rx_pcnt0 register bit field */
	union {
		volatile uint32_t rx_pcnt0;

		volatile struct {
			uint32_t rx_min_pcnt0 : 4; // 3:0
			uint32_t rx_max_pcnt0 : 5; // 8:4
			uint32_t rsvd9 : 23; // 31:9
		} rx_pcnt0_bit;
	}; // 0x48

	/* PRU_MII_RT_rx_pcnt1 register bit field */
	union {
		volatile uint32_t rx_pcnt1;

		volatile struct {
			uint32_t rx_min_pcnt1 : 4; // 3:0
			uint32_t rx_max_pcnt1 : 5; // 8:4
			uint32_t rsvd9 : 23; // 31:9
		} rx_pcnt1_bit;
	}; // 0x4c

	/* PRU_MII_RT_rx_err0 register bit field */
	union {
		volatile uint32_t rx_err0;

		volatile struct {
			uint32_t rx_min_pcnt_err0 : 1; // 0
			uint32_t rx_max_pcnt_err0 : 1; // 1
			uint32_t rx_min_frm_err0 : 1; // 2
			uint32_t rx_max_frm_err0 : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} rx_err0_bit;
	}; // 0x50

	/* PRU_MII_RT_rx_err1 register bit field */
	union {
		volatile uint32_t rx_err1;

		volatile struct {
			uint32_t rx_min_pcnt_err1 : 1; // 0
			uint32_t rx_max_pcnt_err1 : 1; // 1
			uint32_t rx_min_frm_err1 : 1; // 2
			uint32_t rx_max_frm_err1 : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} rx_err1_bit;
	}; // 0x54

	uint8_t rsvd58[8]; // 0x58 - 0x5f

	/* PRU_MII_RT_rx_fifo_level0 register bit field */
	union {
		volatile uint32_t rx_fifo_level0;

		volatile struct {
			uint32_t rx_fifo_level0 : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} rx_fifo_level0_bit;
	}; // 0x60

	/* PRU_MII_RT_rx_fifo_level1 register bit field */
	union {
		volatile uint32_t rx_fifo_level1;

		volatile struct {
			uint32_t rx_fifo_level1 : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} rx_fifo_level1_bit;
	}; // 0x64

	/* PRU_MII_RT_tx_fifo_level0 register bit field */
	union {
		volatile uint32_t tx_fifo_level0;

		volatile struct {
			uint32_t tx_fifo_level0 : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} tx_fifo_level0_bit;
	}; // 0x68

	/* PRU_MII_RT_tx_fifo_level1 register bit field */
	union {
		volatile uint32_t tx_fifo_level1;

		volatile struct {
			uint32_t tx_fifo_level1 : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} tx_fifo_level1_bit;
	}; // 0x6c

} miiRt;

volatile __far miiRt CT_MII_RT __attribute__((cregister("MII_RT_CFG", far), peripheral));

#endif /* _PRU_MII_RT_H_ */

