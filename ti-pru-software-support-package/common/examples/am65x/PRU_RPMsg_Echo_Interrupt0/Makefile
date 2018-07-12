# PRU_CGT environment variable must point to the TI PRU code gen tools directory. E.g.:
#(Desktop Linux) export PRU_CGT=/path/to/pru/code/gen/tools/ti-cgt-pru_2.2.1
#(Windows) set PRU_CGT=C:/path/to/pru/code/gen/tools/ti-cgt-pru_2.2.1
#(ARM Linux*) export PRU_CGT=/usr/share/ti/cgt-pru
#
# *ARM Linux also needs to create a symbolic link to the /usr/bin/ directory in
# order to use the same Makefile
#(ARM Linux) ln -s /usr/bin/ /usr/share/ti/cgt-pru/bin

ifndef PRU_CGT
define ERROR_BODY

*******************************************************************************
PRU_CGT environment variable is not set. Examples given:
(Desktop Linux) export PRU_CGT=/path/to/pru/code/gen/tools/ti-cgt-pru_2.2.1
(Windows) set PRU_CGT=C:/path/to/pru/code/gen/tools/ti-cgt-pru_2.2.1
(ARM Linux*) export PRU_CGT=/usr/share/ti/cgt-pru

*ARM Linux also needs to create a symbolic link to the /usr/bin/ directory in
order to use the same Makefile
(ARM Linux) ln -s /usr/bin/ /usr/share/ti/cgt-pru/bin
*******************************************************************************

endef
$(error $(ERROR_BODY))
endif

ICSSG ?= 0
MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MKFILE_PATH))))
PROJ_NAME=$(CURRENT_DIR)
LINKER_COMMAND_FILE=./AM65x_PRU0.cmd
LIBS=--library=../../../lib/rpmsg_lib.lib
INCLUDE=--include_path=../../../include --include_path=../../../include/am65x
STACK_SIZE=0x100
HEAP_SIZE=0x100
GEN_DIR=gen/icssg$(ICSSG)
TARG_NAME=$(PROJ_NAME:0=$(ICSSG)_0)

#Common compiler and linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
CFLAGS=-v3 -O2 --display_error_number --endian=little --hardware_mac=on --obj_directory=$(GEN_DIR) --pp_directory=$(GEN_DIR) -ppd -ppa
#Linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
LFLAGS=--reread_libs --warn_sections --stack_size=$(STACK_SIZE) --heap_size=$(HEAP_SIZE)

PORT_NUM ?= 30
ifeq ($(ICSSG), 1)
	PORT_NUM = 34
else ifeq ($(ICSSG), 2)
	PORT_NUM = 38
endif

# Instance specific defines to be passed to program
DCFLAGS=-DCHAN_PORT=$(PORT_NUM)

TARGET=$(GEN_DIR)/$(TARG_NAME).out
MAP=$(GEN_DIR)/$(TARG_NAME).map
SOURCES=$(wildcard *.c)
#Using .object instead of .obj in order to not conflict with the CCS build process
OBJECTS=$(patsubst %,$(GEN_DIR)/%,$(SOURCES:.c=.object))

all: .printStart .build_all .printEnd

.build_all:
	@make --no-print-directory .build_one ICSSG=0
	@echo ''
	@make --no-print-directory .build_one ICSSG=1
	@echo ''
	@make --no-print-directory .build_one ICSSG=2
	@echo ''

.printStart:
	@echo ''
	@echo '************************************************************'
	@echo 'Building project: $(PROJ_NAME)'
	@echo ''

.printEnd:
	@echo ''
	@echo 'Finished building project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

.build_one: $(TARGET)

# Invokes the linker (-z flag) to make the .out file
$(TARGET): $(OBJECTS) $(LINKER_COMMAND_FILE)
	@echo ''
	@echo 'Building target: $@'
	@echo 'Invoking: PRU Linker'
	$(PRU_CGT)/bin/clpru $(CFLAGS) -z -i$(PRU_CGT)/lib -i$(PRU_CGT)/include $(LFLAGS) -o $(TARGET) $(OBJECTS) -m$(MAP) $(LINKER_COMMAND_FILE) --library=libc.a $(LIBS)
	@echo 'Finished building target: $@'
	@echo ''
	@echo 'Output files can be found in the "$(GEN_DIR)" directory'

# Invokes the compiler on all c files in the directory to create the object files
$(GEN_DIR)/%.object: %.c
	@mkdir -p $(GEN_DIR)
	@echo '###### Building for ICSSG$(ICSSG) ######'
	@echo 'Building file: $<'
	@echo 'Invoking: PRU Compiler'
	$(PRU_CGT)/bin/clpru --include_path=$(PRU_CGT)/include $(INCLUDE) $(CFLAGS) $(DCFLAGS) -fe $@ $<

.PHONY: all clean

# Remove the $(GEN_DIR) directory
clean:
	@echo ''
	@echo '************************************************************'
	@echo 'Cleaning project: $(PROJ_NAME)'
	@echo ''
	@make --no-print-directory .clean_one ICSSG=0
	@echo ''
	@make --no-print-directory .clean_one ICSSG=1
	@echo ''
	@make --no-print-directory .clean_one ICSSG=2
	@echo ''
	@echo 'Removing the generated "gen" directory'
	@rm -rf gen
	@echo ''
	@echo 'Finished cleaning project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

.clean_one:
	@echo 'Removing files in the "$(GEN_DIR)" directory'
	@rm -rf $(GEN_DIR)

# Includes the dependencies that the compiler creates (-ppd and -ppa flags)
-include $(OBJECTS:%.object=%.pp)
