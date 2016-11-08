/****************************************************************************/
/*  K2G_PRU.cmd																*/
/*  Copyright (c) 2016  Texas Instruments Incorporated                      */
/*                                                                          */
/*    Description: This file is a linker command file that can be used for  */
/*                 linking PRU programs built with the C compiler and       */
/*                 the resulting .out file on a k2g device.					*/
/****************************************************************************/

-cr								/* Link using C conventions */

/* Specify the System Memory Map */
MEMORY
{
      PAGE 0:
	PRU_IMEM		: org = 0x00000000 len = 0x00004000  /* 16kB PRU-ICSS Instruction RAM */

      PAGE 1:
	/* RAM */
	PRU_DMEM_0_1	: org = 0x00000000 len = 0x00002000 CREGISTER=24 /* 8kB PRU Data RAM 0_1 */
	PRU_DMEM_1_0	: org = 0x00002000 len = 0x00002000	CREGISTER=25 /* 8kB PRU Data RAM 1_0 */

	  PAGE 2:
	PRU_SHAREDMEM	: org = 0x00010000 len = 0x00010000 CREGISTER=28 /* 64kB Shared RAM */

	MSMC			: org = 0x0C000000 len = 0x00100000	CREGISTER=30
	DDR3A		    : org = 0x80000000 len = 0x00000100	CREGISTER=31

	/* Peripherals */
	PRU_INTC		: org = 0x00020000 len = 0x00001504	CREGISTER=0
	PRU_ECAP		: org = 0x00030000 len = 0x00000060	CREGISTER=3
	PRU_CFG			: org = 0x00026000 len = 0x00000044	CREGISTER=4
	PRU_UART		: org = 0x00028000 len = 0x00000038	CREGISTER=7
	PRU_MDIO		: org = 0x00032400 len = 0x00000090	CREGISTER=21
	PRU_IEP			: org = 0x0002E000 len = 0x0000031C	CREGISTER=26
	PRU_MII_RT		: org = 0x00032000 len = 0x00000070	CREGISTER=27

	TIMER_1			: org = 0x02210000 len = 0x00000048	CREGISTER=1
	I2C0			: org = 0x02530000 len = 0x0000003C	CREGISTER=2
	MMC0			: org = 0x23000000 len = 0x00000300	CREGISTER=5
	SPI0			: org = 0x21805400 len = 0x00000200	CREGISTER=6
	MCASP0_DMA		: org = 0x21804000 len = 0x00000400	CREGISTER=8
	NSSUL			: org = 0x04000000 len = 0x00040060	CREGISTER=9
	SEC_MGR			: org = 0x02500000 len = 0x00008000	CREGISTER=10
	UART_1			: org = 0x02531000 len = 0x00000038	CREGISTER=11
	UART_2			: org = 0x02531400 len = 0x00000038	CREGISTER=12
	CIC				: org = 0x02600000 len = 0x00001510	CREGISTER=13
	DCAN0_CFG		: org = 0x0260B200 len = 0x00000170	CREGISTER=14
	DCAN1_CFG		: org = 0x0260B400 len = 0x00000170	CREGISTER=15
	SPI1			: org = 0x21805800 len = 0x00000200	CREGISTER=16
	I2C_1			: org = 0x02530400 len = 0x0000003C	CREGISTER=17
	EPWM_0			: org = 0x021D0000 len = 0x00000044	CREGISTER=18
	ECAP_0			: org = 0x021D1800 len = 0x00000060	CREGISTER=19
	SEMAPHORE		: org = 0x02640000 len = 0x0000050C	CREGISTER=22
	MMQP_REG5		: org = 0x02A50000 len = 0x00002000	CREGISTER=23
	EDMA0_CC_CFG	: org = 0x02000000 len = 0x00002E98	CREGISTER=29

	RSVD20			: org = 0x000AE000 len = 0x00000001	CREGISTER=20
}

/* Specify the sections allocation into memory */
SECTIONS {
	/* Forces _c_int00 to the start of PRU IRAM. Not necessary when loading
	   an ELF file, but useful when loading a binary */
	.text:_c_int00*	>  0x0, PAGE 0

	.text		>  PRU_IMEM, PAGE 0
	.stack		>  PRU_DMEM_0_1, PAGE 1
	.bss		>  PRU_DMEM_0_1, PAGE 1
	.cio		>  PRU_DMEM_0_1, PAGE 1
	.data		>  PRU_DMEM_0_1, PAGE 1
	.switch		>  PRU_DMEM_0_1, PAGE 1
	.sysmem		>  PRU_DMEM_0_1, PAGE 1
	.cinit		>  PRU_DMEM_0_1, PAGE 1
	.rodata		>  PRU_DMEM_0_1, PAGE 1
	.rofardata	>  PRU_DMEM_0_1, PAGE 1
	.farbss		>  PRU_DMEM_0_1, PAGE 1
	.fardata	>  PRU_DMEM_0_1, PAGE 1

	.resource_table > PRU_DMEM_0_1, PAGE 1
}
