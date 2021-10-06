/*
 * Copyright (C) 2021 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _PRU_UART_H_
#define _PRU_UART_H_

/* PRU UART register set */
typedef struct {

	/* PRU_UART_RBR_TBR register bit field */
	union {
		volatile uint32_t RBR_TBR;

		volatile struct {
			uint32_t RBR_DATA : 8; // 7:0
			uint32_t TBR_DATA : 10; // 17:8
			uint32_t rsvd18 : 14; // 31:18
		} RBR_TBR_bit;
	}; // 0x0

	/* PRU_UART_INT_EN register bit field */
	union {
		volatile uint32_t INT_EN;

		volatile struct {
			uint32_t ERBI : 1; // 0
			uint32_t ETBEI : 1; // 1
			uint32_t ELSI : 1; // 2
			uint32_t EDSSI : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} INT_EN_bit;
	}; // 0x4

	/* PRU_UART_INT_FIFO register bit field */
	union {
		volatile uint32_t INT_FIFO;

		volatile struct {
			uint32_t IIR_IPEND : 1; // 0
			uint32_t IIR_INTID : 3; // 3:1
			uint32_t rsvd4 : 2; // 5:4
			uint32_t IIR_FIFOEN : 2; // 7:6
			uint32_t FCR_FIFOEN : 1; // 8
			uint32_t FCR_RXCLR : 1; // 9
			uint32_t FCR_TXCLR : 1; // 10
			uint32_t FCR_DMAMODE1 : 1; // 11
			uint32_t rsvd12 : 2; // 13:12
			uint32_t FCR_RXFIFTL : 2; // 15:14
			uint32_t rsvd16 : 16; // 31:16
		} INT_FIFO_bit;
	}; // 0x8

	/* PRU_UART_LCTR register bit field */
	union {
		volatile uint32_t LCTR;

		volatile struct {
			uint32_t WLS0 : 1; // 0
			uint32_t WLS1 : 1; // 1
			uint32_t STB : 1; // 2
			uint32_t PEN : 1; // 3
			uint32_t EPS : 1; // 4
			uint32_t SP : 1; // 5
			uint32_t BC : 1; // 6
			uint32_t DLAB : 1; // 7
			uint32_t rsvd8 : 24; // 31:8
		} LCTR_bit;
	}; // 0xc

	/* PRU_UART_MCTR register bit field */
	union {
		volatile uint32_t MCTR;

		volatile struct {
			uint32_t DTR : 1; // 0
			uint32_t RTS : 1; // 1
			uint32_t OUT1 : 1; // 2
			uint32_t OUT2 : 1; // 3
			uint32_t LOOP : 1; // 4
			uint32_t AFE : 1; // 5
			uint32_t rsvd6 : 26; // 31:6
		} MCTR_bit;
	}; // 0x10

	/* PRU_UART_LSR1 register bit field */
	union {
		volatile uint32_t LSR1;

		volatile struct {
			uint32_t DR : 1; // 0
			uint32_t OE : 1; // 1
			uint32_t PE : 1; // 2
			uint32_t FE : 1; // 3
			uint32_t BI : 1; // 4
			uint32_t THRE : 1; // 5
			uint32_t TEMT : 1; // 6
			uint32_t RXFIFOE : 1; // 7
			uint32_t rsvd8 : 24; // 31:8
		} LSR1_bit;
	}; // 0x14

	/* PRU_UART_MSR register bit field */
	union {
		volatile uint32_t MSR;

		volatile struct {
			uint32_t DCTS : 1; // 0
			uint32_t DDSR : 1; // 1
			uint32_t TERI : 1; // 2
			uint32_t DCD : 1; // 3
			uint32_t CTS : 1; // 4
			uint32_t DSR : 1; // 5
			uint32_t RI : 1; // 6
			uint32_t CD : 1; // 7
			uint32_t rsvd8 : 24; // 31:8
		} MSR_bit;
	}; // 0x18

	/* PRU_UART_SCRATCH register bit field */
	union {
		volatile uint32_t SCRATCH;

		volatile struct {
			uint32_t DATA : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} SCRATCH_bit;
	}; // 0x1c

	/* PRU_UART_DIVLSB register bit field */
	union {
		volatile uint32_t DIVLSB;

		volatile struct {
			uint32_t DLL : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} DIVLSB_bit;
	}; // 0x20

	/* PRU_UART_DIVMSB register bit field */
	union {
		volatile uint32_t DIVMSB;

		volatile struct {
			uint32_t DLH : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} DIVMSB_bit;
	}; // 0x24

	/* PRU_UART_PID register bit field */
	union {
		volatile uint32_t PID;

		volatile struct {
			uint32_t PID : 32; // 31:0
		} PID_bit;
	}; // 0x28

	uint8_t rsvd2c[4]; // 0x2c - 0x2f

	/* PRU_UART_PWR register bit field */
	union {
		volatile uint32_t PWR;

		volatile struct {
			uint32_t FREE : 1; // 0
			uint32_t RES : 1; // 1
			uint32_t rsvd2 : 11; // 12:2
			uint32_t URRST : 1; // 13
			uint32_t UTRST : 1; // 14
			uint32_t URST : 1; // 15
			uint32_t rsvd16 : 16; // 31:16
		} PWR_bit;
	}; // 0x30

	/* PRU_UART_MODE register bit field */
	union {
		volatile uint32_t MODE;

		volatile struct {
			uint32_t OSM_SEL : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} MODE_bit;
	}; // 0x34

} uart;

volatile __far uart CT_UART __attribute__((cregister("PRU_UART", far), peripheral));

#endif /* _PRU_UART_H_ */

