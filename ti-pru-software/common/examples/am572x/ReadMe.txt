Programmable Real-time Unit (PRU) Software Support Package
------------------------------------------------------------
============================================================
   EXAMPLES
============================================================

DESCRIPTION

	This directory provides basic "building block" examples for the PRU. Each
	example demonstrates a particular feature of the PRU. The concepts shown in
	these examples can be combined to create PRU applications. Hence, they are
	considered "building blocks."



WHAT EXAMPLES ARE INCLUDED?

	The following examples are included in this directory.

	EXAMPLE
	---------
	PRU_Halt
		Halt examples are basic empty ICSS projects.
		The core gets initialized, and then does nothing.

	PRU_Direct_Connect0
	PRU_Direct_Connect1
		Direct_Connect examples demonstrate how to:
		 * Pass INTC configuration to Linux RemoteProc driver
		 * Pass interrupts and data between PRU cores

	PRU_MAC_Multiply_Accum
		MAC_Multiply_Accum examples demonstrate how to:
		 * Use the multiply with accumulate (MAC) module. See TRM for
		   more.

	PRU_RPMsg_Echo_Interrupt1_0
	PRU_RPMsg_Echo_Interrupt1_1
	PRU_RPMsg_Echo_Interrupt2_0
	PRU_RPMsg_Echo_Interrupt2_1
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
	PRU Training Slides      - http://www.ti.com/sitarabootcamp
	PRU Evaluation Hardware  - http://www.ti.com/tool/PRUCAPE
	AM572x TRM               - https://www.ti.com/lit/pdf/spruhz6
	Support                  - http://e2e.ti.com

