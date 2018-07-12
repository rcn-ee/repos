/****************************************************************************/
/*  AM335x.lds                                                              */
/*  Copyright (c) 2015  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the GCC compiler    */
/*                 and running the resulting .out file on an AM335x device. */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/

MEMORY
{

    SRAM :     o = 0x402F0400,  l = 0x0000FC00  /* 64kB internal SRAM */
    L3OCMC0 :  o = 0x40300000,  l = 0x00010000  /* 64kB L3 OCMC SRAM */
    M3SHUMEM : o = 0x44D00000,  l = 0x00004000  /* 16kB M3 Shared Unified Code Space */
    M3SHDMEM : o = 0x44D80000,  l = 0x00002000  /* 8kB M3 Shared Data Memory */
    DDR0 :     o = 0x80000000,  l = 0x40000000  /* 1GB external DDR Bank 0 */

}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory region DDR0.
 * It references following symbols, which must be defined in code:
 *   Entry : Entry of reset handler
 * 
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __HeapBase        - To be compatible with Linaro's semihosting support 
 *   __StackLimit
 *   __StackTop
 *   __StackBase    - To be compatible with Linaro's semihosting support 
 *   __stack
 */
ENTRY(Entry)

SECTIONS
{
    .rsthand :
    {
        . = ALIGN(0x10000);
        KEEP(*(.isr_vector))
        *startup_ARMCA8.o (.text)
    } > DDR0
    
    . = ALIGN(4);
    .text :
    {
        *(.text*)

        KEEP(*(.init))
        KEEP(*(.fini))

        /* .ctors */
        *crtbegin.o(.ctors)
        *crtbegin?.o(.ctors)
        *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
        *(SORT(.ctors.*))
        *(.ctors)

        /* .dtors */
         *crtbegin.o(.dtors)
         *crtbegin?.o(.dtors)
         *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
         *(SORT(.dtors.*))
         *(.dtors)

        *(.rodata*)

        KEEP(*(.eh_frame*))
    } > DDR0

    .ARM.extab : 
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > DDR0

    __exidx_start = .;
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > DDR0
    __exidx_end = .;

        
    .data :
    {
        . = ALIGN(4);
        __data_start__ = .;
        *(vtable)
        *(.data*)

        . = ALIGN(4);
        /* preinit data */
        PROVIDE_HIDDEN (__preinit_array_start = .);
        KEEP(*(.preinit_array))
        PROVIDE_HIDDEN (__preinit_array_end = .);

        . = ALIGN(4);
        /* init data */
        PROVIDE_HIDDEN (__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE_HIDDEN (__init_array_end = .);


        . = ALIGN(4);
        /* finit data */
        PROVIDE_HIDDEN (__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        PROVIDE_HIDDEN (__fini_array_end = .);

        . = ALIGN(4);
        /* All data end */
        __data_end__ = .;

    } > DDR0

    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    } > DDR0
    
    .heap (NOLOAD):
    {
        /* The line below can be used to FILL the memory with a known value and
         * debug any stack overruns. For this to work, the specifier (NOLOAD) above 
         * must be removed at the expense of an increase in the output binary size */
        FILL(0xDEADBEEF)
        . = ALIGN(4);
        __end__ = .;
        end = __end__;
        /* The line below created to be compatible with Linaro's semihosting support */
        __HeapBase = __end__; 
        *(.heap*)
        . = . + HEAPSIZE;
        __HeapLimit = .; 
    } > DDR0

    /* .stack section doesn't contain any symbols. It is only
     * used for linker to calculate size of stack sections, and assign
     * values to stack symbols later */
    .stack (NOLOAD):
    {
        /* The line below can be used to FILL the memory with a known value and
         * debug any stack overruns. For this to work, the specifier (NOLOAD) above 
         * must be removed at the expense of an increase in the output binary size */
        FILL(0xBAD0BAD0)
        . = ALIGN(4);
        __StackLimit = . ;
        *(.stack*)
        . = . + STACKSIZE;
        __StackTop = . ;
        /* The line below created to be compatible with Linaro's semihosting support */
        __StackBase = . ;
    } > DDR0
    PROVIDE(__stack = __StackTop);

}
/**************************************************************************/
