PRU_ADC
-------

OVERVIEW
This is a reference project for using the PRU-ICSS to control an ADC peripheral
on the AM335x. The intent of this project is to provide a template for
controlling an on-chip peripheral using the PRU. It also demonstrates an
application of RPMsg for ARM-PRU communication.

In this example, the user passes the number of the ADC channel they want to read
to pru_adc_userspace. pru_adc_userspace passes the ADC channel number to PRU0
(running pru_adc_firmware.c) through RPMsg. pru_adc_firmware.c initializes the
ADC. Every time PRU0 receives a channel number from pru_adc_userspace, it
measures the voltage at that ADC channel. PRU0 then returns the raw value of the
voltage back to userspace through RPMsg. pru_adc_userspace converts the raw
voltage to a human-readable value and prints the voltage to the terminal.

HARDWARE
BeagleBone Black
This project was developed and tested on a BeagleBone Black. It might need
modifications before it will work on a different board or processor.

SOFTWARE
Linux
This project assumes users have downloaded Linux Processor SDK and are familiar
with booting Linux on a BeagleBone Black. Refer to the Processor SDK Linux
Software Developer's Guide at software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Overview.html
if you are unfamiliar with those steps.

DeviceTree
In general, it is suggested that the ADC is disabled in the device tree so
that Linux does not try to access it while the PRU is controlling it. That means
tscadc{
	status = "disabled";
}
in am33xx.dtsi
should not be overridden in am335x-boneblack.dts or any of the files that
am335x-boneblack.dts includes.

FILE STRUCTURE
PRU_ADC
  |
  |--pru_adc_firmware.c firmware loaded into PRU0
  |
  |--pru_adc_userspace
       |--pru_adc_userspace.c userspace code that interacts with PRU0

BUILD FIRMWARE & USERSPACE CODE
$ cd <PATH_TO_PRU_SW_SUPPORT_PACKAGE>/examples/am335x/PRU_ADC/
$ make clean
$ make
$ cd pru_adc_userspace/
$ make clean
$ make

LOAD FIRMWARE & USERSPACE CODE ONTO BOARD
PRU firmware and ARM userspace code are generated in the gen/ folders of
PRU_ADC/ and PRU_ADC/pru_adc_userspace/ respectively.

Load the PRU firmware PRU_ADC.out onto the BeagleBone Black at
/lib/firmware/

Load the ARM userspace code pru_adc_userspace onto the BeagleBone Black at
/home/root/

SETUP HARDWARE
1) Connect voltages to measure to the inputs for ADC channels 5, 6, 7. On the
BeagleBone Black those are pins AIN4, AIN5, and AIN6 respectively. Note that the
voltages may not exceed 1.8V. The BeagleBone Black board provides VDD_ADC and
GNDA_ADC which may be used as 1.8V and ground for the test voltages.

2) Establish a serial connection to the beaglebone black.

RUN EXAMPLE
1) Boot the board.

2) From the command line, type
# ./pru_adc_userspace -c ADC_CHANNEL
where CHANNEL should be 5, 6, or 7.

3) The ADC voltage measurement at that pin will print to the command line.
