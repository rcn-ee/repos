Programmable Real-time Unit (PRU) Software Support Package
------------------------------------------------------------
============================================================
	AM64x EXAMPLES
============================================================

DESCRIPTION

	This directory provides basic "building block" examples for the AM64x
	PRU_ICSSG cores. The concepts shown in these examples can be combined to
	create PRU_ICSSG applications.


HELP! THE ICSSG EXAMPLES ARE STRUCTURED DIFFERENTLY THAN THE ICSS EXAMPLES!

	Project naming convention:
	PRU_xxx is for PRU cores
	RTU_xxx is for RTU cores (note the different command linker file)
	TX_PRU_xxx is for Tx_PRU cores

	We build firmware for multiple ICSSG instances in the Makefile
	(e.g., PRU_RPMsg_Echo_Interrupt0/Makefile builds firmware for PRU0 in
	ICSSG0 and ICSSG1). You could also have a separate project for
	each PRU/RTU core in each ICSSG, but we decided that many projects in
	the PRU Software Support Package (PSSP) would get overwhelming.


WHAT EXAMPLES ARE INCLUDED?

	EXAMPLE
	---------
	PRU_Halt
	RTU_Halt
	TX_PRU_Halt
		Halt examples are basic empty ICSS/ICSSG projects.
		The core gets initialized, and then does nothing.

	PRU_Direct_Connect0
	PRU_Direct_Connect1
		Direct_Connect examples demonstrate how to:
		 * Pass INTC configuration to Linux RemoteProc driver
		 * Pass interrupts and data between PRU cores

	PRU_MAC_Multiply_Accum
	RTU_MAC_Multiply_Accum
		MAC_Multiply_Accum examples demonstrate how to:
		 * Adjust Data RAM size (RTU_MAC_Multiply_Accum only)
		 * Use the multiply with accumulate (MAC) module. See TRM for
		   more information.

	PRU_RPMsg_Echo_Interrupt0
	PRU_RPMsg_Echo_Interrupt1
	RTU_RPMsg_Echo_Interrupt0
	RTU_RPMsg_Echo_Interrupt1
		RPMsg examples demonstrate the RemoteProc RPMsg protocol to
		communicate between the ARM and the PRU. RPMsg is not the best
		inter-processor communication method for every design, but it is
		useful for initial debugging and demonstrations.

		NOTE! As of AM64x/AM65x TI Processor Linux SDK 8.0, Linux PRU
		RPMsg is NOT supported. The RPMsg projects have been ported to
		be compatible with Linux 5.10 RemoteProc driver in order to
		enable future PRU RPMsg development.


ADDITIONAL RESOURCES

	For more information about the PRU, visit:

	PRU-ICSS Wiki            - http://processors.wiki.ti.com/index.php/PRU-ICSS
	PRU-ICSS/PRU_ICSSG docs	 - http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Foundational_Components_PRU-ICSS_PRU_ICSSG.html
	Linux SDK Support	 - http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/index.html
	PRU Training Slides      - http://www.ti.com/sitarabootcamp
	PRU Evaluation Hardware  - http://www.ti.com/tool/PRUCAPE
	AM64x TRM                - https://www.ti.com/lit/pdf/spruim2
	Support                  - http://e2e.ti.com
