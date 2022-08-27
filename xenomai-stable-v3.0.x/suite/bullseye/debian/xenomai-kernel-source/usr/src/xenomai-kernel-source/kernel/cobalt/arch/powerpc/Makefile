
obj-$(CONFIG_XENOMAI) += xenomai.o

xenomai-y := machine.o mayday.o thread.o

xenomai-$(CONFIG_XENO_ARCH_FPU) += fpu.o

ccflags-y := -Iarch/powerpc/xenomai/include -Iinclude/xenomai
