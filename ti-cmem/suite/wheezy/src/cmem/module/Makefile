ROOTDIR = ../../..

# need an absolute path for -I switch below in EXTRA_CFLAGS
ABS_ROOTDIR = $(shell cd $(ROOTDIR); pwd)

# We conditionally include $(ROOTDIR)/Rules.make because when the
# kernel make system invokes us, it won't be found... but that's okay.
-include $(ROOTDIR)/products.mak

TARGET = cmemk.ko

obj-m += cmemk.o

EXTRA_CFLAGS +=	-I$(ABS_ROOTDIR)/include

MAKE_ENV = ARCH=$(ARCH) CROSS_COMPILE=$(TOOLCHAIN_PREFIX)

ifeq ("$(CMEM_KERNEL_STUB)", "1")
EXTRA_CFLAGS += -DCMEM_KERNEL_STUB
endif

debug: EXTRA_CFLAGS += -D__DEBUG

.PHONY: clean debug release install glibc

glibc: release

docs:

release:
	@echo Making module release...
	make -C $(KERNEL_INSTALL_DIR) M=`pwd` $(MAKE_ENV) \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" modules

debug:
	@echo Making module debug...
	make -C $(KERNEL_INSTALL_DIR) M=`pwd` $(MAKE_ENV) \
		EXTRA_CFLAGS="$(EXTRA_CFLAGS)" modules

install:
	@echo Making module install...
	install -d $(EXEC_DIR)
	install $(TARGET) $(EXEC_DIR)

clean:
	-rm -rf *.o *mod* *.ko .cmem* .tmp* Module.symvers
