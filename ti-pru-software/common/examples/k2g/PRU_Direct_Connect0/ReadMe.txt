======================================
FAQ for the PRU_Direct_Connect example
======================================

1) How do I load this example from CCS instead of from a Linux core?
----------------------------------------------------------------------------
This example demonstrates how to use the Linux RemoteProc driver to initialize
the PRU INTC based on the INTC map file. CCS does not read the INTC map file
when it loads the PRU cores. If you use CCS to load the PRU_Direct_Connect
examples without any modifications, the example will not work because the PRU
interrupts will not be mapped. That means you must add code to configure the
INTC directly from your firmware.

See labs/Hands_on_Labs/lab_4/solution/button_led_0/button_led_0.c, function
configIntc() for an example of configuring the INTC from the PRU on AM335x.
Note that different PRU processors will have slightly different INTC register
names. Reference the processor's Technical Reference Manual (TRM) > PRU chapter
> INTC section > "Basic Programming Model" subsection for more details. INTC
header file with register definitions is at include/<processor>/pru_intc.h.


2) I loaded the program from Linux. How do I tell if the program worked?
------------------------------------------------------------------------------
The PRU_Direct_Connect example takes a structure of data in PRU0's data memory
(DMEM), and uses the scratchpad registers to pass that data to PRU1's DMEM. So
in order to verify that the example worked, we need to check PRU1's DMEM before
and after the example runs.

Let's take AM64x as an example.
The PRU compiler treats dmemBuf as uninitialized near data, so it goes in the
.bss section of memory. Let's check the linker command file for
PRU_Direct_Connect0 and PRU_Direct_Connect1:

PRU_Direct_Connect0:
        .text           >  PRU_IMEM, PAGE 0
        .stack          >  PRU0_DMEM_0, PAGE 1
        .bss            >  PRU0_DMEM_0, PAGE 1

PRU_Direct_Connect1:
        .text           >  PRU_IMEM, PAGE 0
        .stack          >  PRU1_DMEM_1, PAGE 1
        .bss            >  PRU1_DMEM_1, PAGE 1

So the PRU0 .bss code is stored in PRU0_DMEM_0, and the PRU1 code is stored in
PRU1_DMEM_1. Both of those locations are reachable by Constant Table entry
24 for each core. TRM table "PRU0/1 Constant Table" confirms that entry 24
points to the local Data RAM.

TRM section "PRU_ICSSG Global Memory Map" tells us that for AM64x, DRAM0 (i.e.,
PRU0_DMEM_0) is at offset 0x0000_0000, and DRAM1 (i.e., PRU1_DMEM_1) is at
offset 0x0000_2000h.

So where is .bss in the DRAM? Our linker command file places it right behind
.stack. Open the Makefile and search for "STACK_SIZE" - it is 0x100. So .bss
should start at DRAM offset 0x100.

Let's double check in the generated .map file at
gen/icssg0/PRU_Direct_Connect0_0.map:

MEMORY CONFIGURATION
         name            origin    length      used     unused   attr    fill
----------------------  --------  ---------  --------  --------  ----  --------
...
PAGE 1:
  PRU0_DMEM_0           00000000   00001000  00000118  00000ee8  RWIX
..
SECTION ALLOCATION MAP
 output                                  attributes/
section   page    origin      length       input sections
--------  ----  ----------  ----------   ----------------
...
.stack     1    00000000    00000100     UNINITIALIZED
                  00000000    00000004     rtspruv3_le.lib : boot.c.obj (.stack)
                  00000004    000000fc     --HOLE--

.bss       1    00000100    00000018     UNINITIALIZED
                  00000100    00000018     (.common:dmemBuf)

The memory map looks exactly like we expect. 0x118 bytes are "used" in
DMEM0: 0x100 for the stack, and 0x18 for dmemBuf inside section .bss.

Let's say we load the program into ICSSG0. Then PRU_Direct_Connect0 will store
dmemBuf into ICSSG0, DRAM0 starting at 0x03000_0100. PRU_Direct_Connect1 will
store dmemBuf into ICSSG0, DRAM1 starting at 0x03000_2100.

So we can verify that the example is working like this:
// search for which remoteprocX core is ICSSG0, PRU0 & PRU1
# grep -Isr pru /sys/kernel/debug/remoteproc/
// on this particular boot, I saw
/sys/kernel/debug/remoteproc/remoteproc7/name:30038000.pru
/sys/kernel/debug/remoteproc/remoteproc4/name:30034000.pru
# echo 'PRU_Direct_Connect0_0.out' > /sys/class/remoteproc/remoteproc4/firmware
# echo 'PRU_Direct_Connect0_1.out' > /sys/class/remoteproc/remoteproc7/firmware
// check initial DMEM values
# devmem2 0x30000100
Read at address  0x30000100: 0x00000000
# devmem2 0x30002100
Read at address  0x30002100: 0x00000000
// load PRU0 firmware
# echo 'start' > /sys/class/remoteproc/remoteproc4/state
# devmem2 0x30000100
Read at address  0x30000100: 0xABABABAB
# devmem2 0x30002100
Read at address  0x30002100: 0x00000000
// load PRU1 firmware
# echo 'start' > /sys/class/remoteproc/remoteproc7/state
# devmem2 0x30002100
Read at address  0x30002100: 0xABABABAB
