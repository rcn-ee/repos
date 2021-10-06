Programmable Real-time Unit (PRU) Software Support Package
------------------------------------------------------------
============================================================
	AM65x EXAMPLES
============================================================

DESCRIPTION

	This directory provides basic "building block" examples for the AM65x
	PRU_ICSSG cores. The concepts shown in these examples can be combined to
	create PRU_ICSSG applications.


HELP! THE ICSSG EXAMPLES ARE STRUCTURED DIFFERENTLY THAN THE ICSS EXAMPLES!

	Project naming convention:
	PRU_xxx is for PRU cores
	RTU_xxx is for RTU cores (note the different command linker file)
	TX_PRU_xxx is for Tx_PRU cores (only available on AM65x SR2.0 SoCs)

	We build firmware for multiple ICSSG instances in the Makefile
	(e.g., PRU_RPMsg_Echo_Interrupt0/Makefile builds firmware for PRU0 in
	ICSSG0, ICSSG1, and ICSSG2). You could also have a separate project for
	each PRU/RTU core in each ICSSG, but we decided that many projects in
	the PRU Software Support Package (PSSP) would get overwhelming.


WHAT EXAMPLES ARE INCLUDED?

	EXAMPLE
	---------
	PRU_Halt
	RTU_Halt
	TX_PRU_Halt
		This is the basic example. The core gets initialized, and then
		does nothing.

	PRU_MAC_Multiply_Accum
		This show the Multiplier with Accumulation (see TRM for more)

	PRU_RPMsg_Echo_Interrupt0
	PRU_RPMsg_Echo_Interrupt1
	RTU_RPMsg_Echo_Interrupt0
	RTU_RPMsg_Echo_Interrupt1
		RPMsg examples demonstrate the RemoteProc RPMsg protocl to
		communicate between the ARM and the PRU. RPMsg is not the best
		inter-processor communication method for every design, but it is
		useful for initial debugging and demonstrations.


AM65x SR1.0 vs SR2.0 USAGE

	The AM65x SoCs uses different revisions of the ICSSG IP between AM65x
	SR1.0 and SR2.0 SoCs. The revised ICSSG IP on AM65x SR2.0 SoCs have
	two additional auxiliary PRU cores called Tx_PRUs, one per slice, in
	each ICSSG instance. These new cores share the same Data RAMs present
	within the IP, but use their own dedicated Instruction RAMs to execute
	code. For further details and differences, please refer to the
	"Programmable Real-Time Unit and Industrial Communication Subsystem"
	chapters in the "AM65x/DRA80xM Processors Technical Reference Manual"
	available under the Technical Documents on the corresponding
	AM65xx part on www.ti.com.

	The linker command files in the current examples demonstrate an example
	partitioning of the Data RAMs to be used with all the PRU, RTU and
	Tx_PRU cores for SR2.0 SoCs. These examples can be run on SR1.0 SoCs as
	well, with the memory dedicated for Tx_PRUs unused. This need not be the
	case if the applications are intended only for AM65x SR1.0 SoCs.


ADDITIONAL RESOURCES

	For more information about the PRU, visit:

	PRU-ICSS Wiki            - http://processors.wiki.ti.com/index.php/PRU-ICSS
	PRU-ICSS/PRU_ICSSG docs	 - http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Foundational_Components_PRU-ICSS_PRU_ICSSG.html
	Linux SDK Support	 - http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/index.html
	PRU Training Slides      - http://www.ti.com/sitarabootcamp
	PRU Evaluation Hardware  - http://www.ti.com/tool/PRUCAPE
	AM65x TRM                - https://www.ti.com/lit/pdf/spruid7
	Support                  - http://e2e.ti.com

