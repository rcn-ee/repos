--host_image
--image
--host_image:target=ARM
--host_image:endianness=little
--host_image:hidden_symbols

ROMS {
                PAGE 0:
                .text: o = 0x0, l = 0x2000
                PAGE 1:
                .data: o = 0x0, l = 0x2000
                PAGE 2:
                .shared: o = 0x10000, l = 0x3000
}
