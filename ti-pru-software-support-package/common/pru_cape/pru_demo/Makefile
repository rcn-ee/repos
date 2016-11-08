# ARM_CGT environment variable must point to the TI ARM compiler directory. E.g.:
#(Linux) export ARM_CGT=/home/jason/ti/ccs_v6_1_0/ccsv6/tools/compiler/ti-cgt-arm_5.2.2
#(Windows) set ARM_CGT=C:/TI/ccs_v6_0_1/ccsv6/tools/compiler/ti-cgt-arm_5.2.4
ifndef ARM_CGT
define ERROR_BODY

************************************************************
ARM_CGT environment variable is not set. Examples given:
(Linux) export ARM_CGT=/home/jason/ti/ccs_v6_1_0/ccsv6/tools/compiler/ti-cgt-arm_5.2.2
(Windows) set ARM_CGT=C:/TI/ccs_v6_0_1/ccsv6/tools/compiler/ti-cgt-arm_5.2.4
************************************************************

endef
$(error $(ERROR_BODY))
endif

# SW_DIR environment variable must point to the TI Starterware directory. E.g.:
#(Linux) export SW_DIR=/home/jason/AM335X_StarterWare_02_00_01_01
#(Windows) set SW_DIR=C:/TI/AM335X_StarterWare_02_00_01_01
ifndef SW_DIR
define ERROR_BODY

************************************************************
SW_DIR environment variable is not set. Examples given:
(Linux) export SW_DIR=/home/jason/AM335X_StarterWare_02_00_01_01
(Windows) set SW_DIR=C:/TI/AM335X_StarterWare_02_00_01_01
************************************************************

endef
$(error $(ERROR_BODY))
endif

# PRU_CGT environment variable must point to the TI PRU compiler directory. E.g.:
#(Linux) export PRU_CGT=/home/jason/ti/ccs_v6_1_0/ccsv6/tools/compiler/ti-cgt-pru_2.1.0
#(Windows) set PRU_CGT=C:/TI/ccs_v6_0_1/ccsv6/tools/compiler/ti-cgt-pru_2.1.0
ifndef PRU_CGT
define ERROR_BODY

************************************************************
PRU_CGT environment variable is not set. Examples given:
(Linux) export PRU_CGT=/home/jason/ti/ccs_v6_1_0/ccsv6/tools/compiler/ti-cgt-pru_2.1.0
(Windows) set PRU_CGT=C:/TI/ccs_v6_0_1/ccsv6/tools/compiler/ti-cgt-pru_2.1.0
************************************************************

endef
$(error $(ERROR_BODY))
endif

SW_CGT_DIR=$(SW_DIR)/binary/armv7a/cgt_ccs

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MKFILE_PATH))))
PROJ_NAME=$(CURRENT_DIR)

INCLUDE=--include_path=$(ARM_CGT)/include \
--include_path=$(SW_DIR)/include/armv7a/am335x \
--include_path=$(SW_DIR)/include/armv7a \
--include_path=$(SW_DIR)/include/hw \
--include_path=$(SW_DIR)/include

SEARCH_PATH=--search_path=$(ARM_CGT)/lib \
--search_path=$(ARM_CGT)/include \
--search_path=$(SW_CGT_DIR)/am335x/drivers/Release/ \
--search_path=$(SW_CGT_DIR)/utils/Release/ \
--search_path=$(SW_CGT_DIR)/am335x/beaglebone/platform/Release/ \
--search_path=$(SW_CGT_DIR)/am335x/system_config/Release \

HEX_FILES=../pru_fw/PRU_Audio/gen/PRU_Audio_image.object \
../pru_fw/PRU_HDQ_TempSensor0/gen/PRU_HDQ_TempSensor0_image.object \
../pru_fw/PRU_HDQ_TempSensor1/gen/PRU_HDQ_TempSensor1_image.object \
../pru_fw/PRU_Hardware_UART/gen/PRU_Hardware_UART_image.object \
../pru_fw/PRU_LED0/gen/PRU_LED0_image.object \
../pru_fw/PRU_LED1/gen/PRU_LED1_image.object \
../pru_fw/PRU_Switch/gen/PRU_Switch_image.object

LINKER_COMMAND_FILE=./pru_cape_demo_make.cmd

LIBS=-l"drivers.lib" -l"system.lib" -l"utils.lib" -l"platform.lib" -l"rtsv7A8_A_le_eabi.lib"


STACK_SIZE=0x1000
HEAP_SIZE=0x2000
GEN_DIR=gen

#Common compiler and linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
CFLAGS=-mv7A8 --code_state=32 --float_support=vfplib --abi=eabi -me -O2 --define=am3359 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --pp_directory=$(GEN_DIR) -ppd

#Linker flags (Defined in 'PRU Optimizing C/C++ Compiler User's Guide)
LFLAGS=--reread_libs --define=A8_CORE=1 --warn_sections --display_error_number --diag_wrap=off --rom_model \
--stack_size=$(STACK_SIZE) --heap_size=$(HEAP_SIZE)

#Using .object instead of .obj in order to not conflict with the CCS build process
TARGET=$(GEN_DIR)/$(PROJ_NAME).out
MAP=$(GEN_DIR)/$(PROJ_NAME).map
SOURCES=$(wildcard *.c)
#Using .object instead of .obj in order to not conflict with the CCS build process
OBJECTS=$(patsubst %,$(GEN_DIR)/%,$(SOURCES:.c=.object))

all: firmwares printStart $(TARGET) printEnd

printStart:
	@echo ''
	@echo '************************************************************'
	@echo 'Building project: $(PROJ_NAME)'

printEnd:
	@echo ''
	@echo 'Finished building project: $(PROJ_NAME)'
	@echo '************************************************************'
	@echo ''

# Invokes the linker (-z flag) to make the .out file
$(TARGET): $(OBJECTS) $(LINKER_COMMAND_FILE)
	@echo ''
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	$(ARM_CGT)/bin/armcl $(CFLAGS) -z -m$(MAP) $(SEARCH_PATH) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(HEX_FILES) $(LINKER_COMMAND_FILE) $(LIBS)
	@echo 'Finished building target: $@'

# Invokes the compiler on all c files in the directory to create the object files
$(GEN_DIR)/%.object: %.c
	@mkdir -p $(GEN_DIR)
	@echo ''
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	$(ARM_CGT)/bin/armcl $(CFLAGS) $(INCLUDE) -fe $@ $<

firmwares:
	@echo ''
	@echo '************************************************************'
	@echo 'Building firmwares'
	@echo ''
	@$(MAKE) -C ../pru_fw/
	@echo ''
	@echo 'Finished building firmwares'
	@echo '************************************************************'
	@echo ''


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

# Includes the dependencies that the compiler creates (-ppd and -ppa flags)
-include $(OBJECTS:%.object=%.pp)

