/****************************************************************************/
/*  AM335x.cmd                                                              */
/*  Copyright (c) 2015  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an AM335x device.     */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/

#ifdef A8_CORE     /* A8 memory map */
MEMORY
{
    SRAM:     o = 0x402F0400  l = 0x0000FC00  /* 64kB internal SRAM */
    L3OCMC0:  o = 0x40300000  l = 0x00010000  /* 64kB L3 OCMC SRAM */
    M3SHUMEM: o = 0x44D00000  l = 0x00004000  /* 16kB M3 Shared Unified Code Space */
    M3SHDMEM: o = 0x44D80000  l = 0x00002000  /* 8kB M3 Shared Data Memory */
    DDR0:     o = 0x80000000  l = 0x40000000  /* 1GB external DDR Bank 0 */
}

SECTIONS
{
    .text          >  L3OCMC0
    .stack         >  L3OCMC0
    .bss           >  L3OCMC0
    .cio           >  L3OCMC0
    .const         >  L3OCMC0
    .data          >  L3OCMC0
    .switch        >  L3OCMC0
    .sysmem        >  L3OCMC0
    .far           >  L3OCMC0
    .args          >  L3OCMC0
    .ppinfo        >  L3OCMC0
    .ppdata        >  L3OCMC0

    /* TI-ABI or COFF sections */
    .pinit         >  L3OCMC0
    .cinit         >  L3OCMC0

    /* EABI sections */
    .binit         >  L3OCMC0
    .init_array    >  L3OCMC0
    .neardata      >  L3OCMC0
    .fardata       >  L3OCMC0
    .rodata        >  L3OCMC0
}
#endif             /* A8 memory map */

#ifdef M3_CORE     /* M3 memory map */
MEMORY
{
    M3UMEM:   o = 0x00000000  l = 0x00004000  /* 16kB M3 Local Unified Code Space */
    M3DMEM:   o = 0x00080000  l = 0x00002000  /* 8kB M3 Local Data Memory */
    M3SHUMEM: o = 0x20000000  l = 0x00004000  /* 16kB M3 Shared Unified Code Space */
    M3SHDMEM: o = 0x20080000  l = 0x00002000  /* 8kB M3 Shared Data Memory */
}

SECTIONS
{
    .text          >  M3UMEM
    .stack         >  M3DMEM
    .bss           >  M3DMEM
    .cio           >  M3DMEM
    .const         >  M3UMEM
    .data          >  M3DMEM
    .switch        >  M3DMEM
    .sysmem        >  M3DMEM
    .far           >  M3DMEM
    .args          >  M3DMEM
    .ppinfo        >  M3DMEM
    .ppdata        >  M3DMEM

    /* TI-ABI or COFF sections */
    .pinit         >  M3UMEM
    .cinit         >  M3UMEM

    /* EABI sections */
    .binit         >  M3UMEM
    .init_array    >  M3UMEM
    .neardata      >  M3DMEM
    .fardata       >  M3DMEM
    .rodata        >  M3UMEM
}
#endif             /* M3 memory map */

#ifdef PRU_CORE    /* PRU memory map */
MEMORY
{
    PAGE 0:
      PRUIMEM:   o = 0x00000000  l = 0x00001000  /* 8kB PRU0 Instruction RAM */
    PAGE 1:
      PRUDMEM:   o = 0x00000000  l = 0x00001000  /* 8kB PRU Data RAM 0 */
	PAGE 2:
      SHAREDMEM: o = 0x00010000  l = 0x00003000  /* 12kB Shared RAM */
}

SECTIONS
{
    .text:_c_int00 >  0x0
    .text          >  PRUIMEM, PAGE 0
    .bss           >  PRUDMEM, PAGE 1
    .data          >  PRUDMEM, PAGE 1
    .rodata        >  PRUDMEM, PAGE 1
    .farbss        >  SHAREDMEM, PAGE 2
    .fardata       >  SHAREDMEM, PAGE 2
    .rofardata     >  SHAREDMEM, PAGE 2
    .sysmem        >  PRUDMEM, PAGE 1
    .stack         >  PRUDMEM, PAGE 1
    .init_array    >  PRUDMEM, PAGE 1
	.cinit         >  PRUDMEM, PAGE 1
	.args          >  PRUDMEM, PAGE 1
}
#endif             /* PRU memory map */

