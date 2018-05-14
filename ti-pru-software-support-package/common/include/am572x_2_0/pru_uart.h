/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

	/* PRU_UART_RBR_THR_REGISTERS register bit field */
	union {
		volatile uint32_t RBR_THR_REGISTERS;

		volatile struct {
			uint32_t DATA : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} RBR_THR_REGISTERS_bit;
	}; // 0x0

	/* PRU_UART_INTERRUPT_ENABLE_REGISTER register bit field */
	union {
		volatile uint32_t INTERRUPT_ENABLE_REGISTER;

		volatile struct {
			uint32_t ERBI : 1; // 0
			uint32_t ETBEI : 1; // 1
			uint32_t ELSI : 1; // 2
			uint32_t EDSSI : 1; // 3
			uint32_t rsvd4 : 28; // 31:4
		} INTERRUPT_ENABLE_REGISTER_bit;
	}; // 0x4

	/* PRU_UART_INTERRUPT_IDENTIFICATION_REGISTER_FIFO_CONTROL_REGISTER register bit field */
	union {
		volatile uint32_t INTERRUPT_IDENTIFICATION_REGISTER_FIFO_CONTROL_REGISTER;

		volatile struct {
			uint32_t IPEND_FIFOEN : 1; // 0
			uint32_t INTID : 3; // 3:1
			uint32_t rsvd4 : 2; // 5:4
			uint32_t FIFOEN_RXFIFTL : 2; // 7:6
			uint32_t rsvd8 : 24; // 31:8
		} INTERRUPT_IDENTIFICATION_REGISTER_FIFO_CONTROL_REGISTER_bit;
	}; // 0x8

	/* PRU_UART_LINE_CONTROL_REGISTER register bit field */
	union {
		volatile uint32_t LINE_CONTROL_REGISTER;

		volatile struct {
			uint32_t WLS : 2; // 1:0
			uint32_t STB : 1; // 2
			uint32_t PEN : 1; // 3
			uint32_t EPS : 1; // 4
			uint32_t SP : 1; // 5
			uint32_t BC : 1; // 6
			uint32_t DLAB : 1; // 7
			uint32_t rsvd8 : 24; // 31:8
		} LINE_CONTROL_REGISTER_bit;
	}; // 0xc

	/* PRU_UART_MODEM_CONTROL_REGISTER register bit field */
	union {
		volatile uint32_t MODEM_CONTROL_REGISTER;

		volatile struct {
			uint32_t rsvd0 : 1; // 0
			uint32_t RTS : 1; // 1
			uint32_t OUT1 : 1; // 2
			uint32_t OUT2 : 1; // 3
			uint32_t LOOP : 1; // 4
			uint32_t AFE : 1; // 5
			uint32_t rsvd6 : 26; // 31:6
		} MODEM_CONTROL_REGISTER_bit;
	}; // 0x10

	/* PRU_UART_LINE_STATUS_REGISTER register bit field */
	union {
		volatile uint32_t LINE_STATUS_REGISTER;

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
		} LINE_STATUS_REGISTER_bit;
	}; // 0x14

	/* PRU_UART_MODEM_STATUS_REGISTER register bit field */
	union {
		volatile uint32_t MODEM_STATUS_REGISTER;

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
		} MODEM_STATUS_REGISTER_bit;
	}; // 0x18

	/* PRU_UART_SCRATCH_REGISTER register bit field */
	union {
		volatile uint32_t SCRATCH_REGISTER;

		volatile struct {
			uint32_t SCR : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} SCRATCH_REGISTER_bit;
	}; // 0x1c

	/* PRU_UART_DIVISOR_REGISTER_LSB_ register bit field */
	union {
		volatile uint32_t DIVISOR_REGISTER_LSB_;

		volatile struct {
			uint32_t DLL : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} DIVISOR_REGISTER_LSB__bit;
	}; // 0x20

	/* PRU_UART_DIVISOR_REGISTER_MSB_ register bit field */
	union {
		volatile uint32_t DIVISOR_REGISTER_MSB_;

		volatile struct {
			uint32_t DLH : 8; // 7:0
			uint32_t rsvd8 : 24; // 31:8
		} DIVISOR_REGISTER_MSB__bit;
	}; // 0x24

	/* PRU_UART_PERIPHERAL_ID_REGISTER register bit field */
	union {
		volatile uint32_t PERIPHERAL_ID_REGISTER;

		volatile struct {
			uint32_t PID : 32; // 31:0
		} PERIPHERAL_ID_REGISTER_bit;
	}; // 0x28

	uint8_t rsvd2c[4]; // 0x2c - 0x2f

	/* PRU_UART_POWERMANAGEMENT_AND_EMULATION_REGISTER register bit field */
	union {
		volatile uint32_t POWERMANAGEMENT_AND_EMULATION_REGISTER;

		volatile struct {
			uint32_t FREE : 1; // 0
			uint32_t rsvd1 : 12; // 12:1
			uint32_t URRST : 1; // 13
			uint32_t UTRST : 1; // 14
			uint32_t rsvd15 : 17; // 31:15
		} POWERMANAGEMENT_AND_EMULATION_REGISTER_bit;
	}; // 0x30

	/* PRU_UART_MODE_DEFINITION_REGISTER register bit field */
	union {
		volatile uint32_t MODE_DEFINITION_REGISTER;

		volatile struct {
			uint32_t OSM_SEL : 1; // 0
			uint32_t rsvd1 : 31; // 31:1
		} MODE_DEFINITION_REGISTER_bit;
	}; // 0x34

} pruUart;

volatile __far pruUart CT_UART __attribute__((cregister("PRU_UART", near), peripheral));

#endif /* _PRU_UART_H_ */

