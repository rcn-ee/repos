# ARM_CCT environment variable must point to the ARM Cross-Compile Toolchain directory. E.g.:
#(Linux) export ARM_CCT=${HOME}/ti-processor-sdk-linux-am335x-evm-02.00.00.00/linux-devkit/sysroots/x86_64-arago-linux/usr/bin
ifndef ARM_CCT
define ERROR_BODY

************************************************************
ARM_CCT cross-compiler toolchain environment variable is not set.
Example given:
(Linux) export ARM_CCT=${HOME}/ti-processor-sdk-linux-am335x-evm-02.00.00.00/linux-devkit/sysroots/x86_64-arago-linux/usr/bin
************************************************************

endef
$(error $(ERROR_BODY))
endif

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MKFILE_PATH))))
PROJ_NAME=$(CURRENT_DIR)
LIBS=-lm -lpng
GEN_DIR=gen
SOURCES=pru_adc_userspace.c

all: printStart $(GEN_DIR)/$(PROJ_NAME) printEnd

printStart:
	@echo ''
	@echo '************************************************************'
	@echo 'Building project: $(PROJ_NAME)'

printEnd:
	@echo ''
	@echo 'Finished building project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

# Invokes the compiler on all c files in the directory
$(GEN_DIR)/$(PROJ_NAME): $(SOURCES)
	@mkdir -p $(GEN_DIR)
	@echo ''
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	$(ARM_CCT)/arm-linux-gnueabihf-gcc -o $(GEN_DIR)/$(PROJ_NAME) $< $(LIBS)
	@echo 'Finished building target: $@'
	@echo ''
	@echo 'Output files can be found in the "$(GEN_DIR)" directory'

.PHONY: all clean

# Remove the $(GEN_DIR) directory
clean:
	@echo ''
	@echo '************************************************************'
	@echo 'Cleaning project: $(PROJ_NAME)'
	@echo ''
	@echo 'Removing files in the "$(GEN_DIR)" directory'
	@rm -rf $(GEN_DIR)
	@echo ''
	@echo 'Finished cleaning project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

