@******************************************************************************
@
@ startup_ARMCA8.S - Init code routine for Cortex A8 cores and Linaro baremetal
@
@******************************************************************************
@
@ Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
@  (Rafael de Souza - 2014) Added VFP and NEON initialization routines
@
@
@  Redistribution and use in source and binary forms, with or without
@  modification, are permitted provided that the following conditions
@  are met:
@
@    Redistributions of source code must retain the above copyright
@    notice, this list of conditions and the following disclaimer.
@
@    Redistributions in binary form must reproduce the above copyright
@    notice, this list of conditions and the following disclaimer in the
@    documentation and/or other materials provided with the
@    distribution.
@
@    Neither the name of Texas Instruments Incorporated nor the names of
@    its contributors may be used to endorse or promote products derived
@    from this software without specific prior written permission.
@
@  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
@  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
@  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
@  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
@  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
@  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
@  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
@  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
@  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
@  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
@  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
@
@******************************************************************************

@****************************** Global Symbols*******************************
        .global Entry
        .global __stack
        .global __bss_start__
        .global __bss_end__
        .global start_boot

@************************ Internal Definitions ******************************
@
@ to set the mode bits in CPSR for different modes
@
        .set  MODE_USR, 0x10
        .set  MODE_FIQ, 0x11
        .set  MODE_IRQ, 0x12
        .set  MODE_SVC, 0x13
        .set  MODE_ABT, 0x17
        .set  MODE_UND, 0x1B
        .set  MODE_SYS, 0x1F

        .equ  I_F_BIT, 0xC0

@**************************** Code Section ***********************************
        .text

@
@ This code is assembled for ARM instructions
@
        .code 32

@******************************************************************************
@
@******************************************************************************
@
@ The reset handler sets up the stack pointers for all the modes. The FIQ and
@ IRQ shall be disabled during this. Then clears the BSS section, enters the
@ main function.

Entry:
@
@ The stack for all the modes (Abort, FIQ, etc.) is set by
@ the runtime support library.
@

@
@ Set up the Vector Base Address Regsiter
@
		LDR   r0, = __isr_vector
		MCR   p15, 0, r0, c12, c0, 0     @ Write VBAR Register

.if __ARM_PCS_VFP == 1
@
@ Enable NEON extensions and the VFP. Must be done before entering user mode.
@
        MRC   p15, #0, r3, c1, c0, #2    @ Read CPACR
		ORR   r3, r3, #0x00F00000        @ Enable access to CP10 and CP11
		MCR   p15, #0, r3, c1, c0, #2    @ Write CPACR
		MOV   r3, #0
      	MOV   r0,#0x40000000
        FMXR  FPEXC,r0                   @ Set FPEXC bit 30 to enable VFP
		MCR   p15, #0, r3, c7, c5, #4    @ flush prefetch buffer because of FMXR above
.endif

.if USERMODE == 1
@
@ Change to user mode. It allows for a stack smaller than 64kB.
@
        MSR   cpsr_c, #MODE_USR|I_F_BIT  @ change to user mode
.endif

@
@ The BSS section is cleared by the runtime support library
@

@
@ Enter the main function.
@ The symbol _start is the entry point for the runtime support library
@

Enter_BootLoader:
         LDR   r10, = _start              @ Get the address of _start
         MOV   lr,pc                     @ Dummy return
         BX    r10                       @ Branch to main
         SUB   pc, pc, #0x08             @ looping

@
@ Set the Stack space here
@
    .section .stack
    .align 4
    .globl  __StackBase
    .globl  __StackLimit
__StackLimit:
@    .space   0x400			@ the stack size is set by the linker script
    .size  __StackLimit, . - __StackLimit
__StackBase:
    .size  __StackBase, . - __StackBase

@
@ Set the Heap space here
@
    .section .heap
    .align 4
    .globl  __HeapBase
    .globl  __HeapLimit
__HeapBase:
@    .space   0x400			@ the heap size is set by the linker script
    .size  __HeapBase, . - __HeapBase
__HeapLimit:
    .size  __HeapLimit, . - __HeapLimit

@
@ Set the Interrupt vector table here
@

    .section .isr_vector
    .align 4
    .globl  __isr_vector
__isr_vector:
        LDR   pc, [pc,#24]       @ 0x00 Reset
        LDR   pc, [pc,#-8]       @ 0x04 Undefined Instruction
        LDR   pc, [pc,#24]       @ 0x08 Supervisor Call
        LDR   pc, [pc,#-8]       @ 0x0C Prefetch Abort
        LDR   pc, [pc,#-8]       @ 0x10 Data Abort
        LDR   pc, [pc,#-8]       @ 0x14 Not used
        LDR   pc, [pc,#-8]       @ 0x18 IRQ interrupt
        LDR   pc, [pc,#-8]       @ 0x1C FIQ interrupt
        .long  Entry
        .long  0
        .long  SVC_Handler
        .long  0
        .long  0
        .long  0
        .long  0
        .long  0

    /* External interrupts */
        .long  Default_Handler

        .size  __isr_vector, . - __isr_vector

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
        .macro  def_default_handler    handler_name
        .align 1
        .thumb_func
        .type  \handler_name, %function
\handler_name :
        B    .
        .size  \handler_name, . - \handler_name
        .endm

        def_default_handler  NMI_Handler
        def_default_handler  HardFault_Handler
        def_default_handler  SVC_Handler
        def_default_handler  PendSV_Handler
        def_default_handler  SysTick_Handler
        def_default_handler  Default_Handler

       .weak  DEF_IRQHandler
       .set  DEF_IRQHandler, Default_Handler

@
@ End of the file
@
       .end

