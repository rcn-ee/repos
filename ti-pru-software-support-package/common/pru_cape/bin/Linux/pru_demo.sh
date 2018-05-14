#!/bin/bash

led0_link="$(readlink -f ./pru_fw/PRU_LED0.out)"
led1_link="$(readlink -f ./pru_fw/PRU_LED1.out)"
switch_link="$(readlink -f ./pru_fw/PRU_Switch.out)"
audio_link="$(readlink -f ./pru_fw/PRU_Audio.out)"
uart_link="$(readlink -f ./pru_fw/PRU_Hardware_UART.out)"
temp0_link="$(readlink -f ./pru_fw/PRU_HDQ_TempSensor0.out)"
temp1_link="$(readlink -f ./pru_fw/PRU_HDQ_TempSensor1.out)"
rpmsg_led_link="$(readlink -f ./pru_fw/PRU_RPMsg_LED0.out)"
halt_link="$(readlink -f ./pru_fw/PRU_Halt.out)"

echo ""
echo "*******************************"
echo "*        PRU Cape Demo        *"
echo "*******************************"
echo ""

while true; do
	echo "Which firmware would you like to load?"
	echo ""
	echo "1. LEDs"
	echo "2. Switches"
	echo "3. Audio"
	echo "4. UART"
	echo "5. Temp sensor"
	echo "6. RPMsg Toggle LEDs"
	echo "7. Halt"
	echo ""
	read -p "selection: " test_number
	echo ""

	case "$test_number" in
	1) fw0_link=${led0_link}
	   fw1_link=${led1_link} ;;
	2) fw0_link=${switch_link}
	   fw1_link=${halt_link} ;;
	3) fw0_link=${halt_link}
	   fw1_link=${audio_link} ;;
	4) fw0_link=${uart_link}
	   fw1_link=${halt_link} ;;
	5) fw0_link=${temp0_link}
	   fw1_link=${temp1_link} ;;
	6) fw0_link=${rpmsg_led_link}
	   fw1_link=${halt_link} ;;
	7) fw0_link=${halt_link}
	   fw1_link=${halt_link} ;;
	*) echo "invalid selection"
	   echo ""
	   continue ;;
	esac

	if [ ${fw0_link} ] && [ ${fw1_link} ];
	then
		rm /lib/firmware/am335x-pru0-fw &> /dev/null
		rm /lib/firmware/am335x-pru1-fw &> /dev/null

		if [ -e /sys/bus/platform/drivers/pru-rproc/4a334000.pru0 ]; then
			echo 4a334000.pru0 > /sys/bus/platform/drivers/pru-rproc/unbind
		fi
		if [ -e /sys/bus/platform/drivers/pru-rproc/4a338000.pru1 ]; then
			echo 4a338000.pru1 > /sys/bus/platform/drivers/pru-rproc/unbind
		fi

		ln -s ${fw0_link} /lib/firmware/am335x-pru0-fw
		ln -s ${fw1_link} /lib/firmware/am335x-pru1-fw
		echo 4a334000.pru0 > /sys/bus/platform/drivers/pru-rproc/bind
		echo 4a338000.pru1 > /sys/bus/platform/drivers/pru-rproc/bind
		echo ""
		echo "Firmware " $test_number " is running"
		echo ""

		case "$test_number" in
		6) /bin/bash ./pru0_led.sh ;;
		esac

	else
		echo "At least one of the firmware .out files does not seem to exist. Did you"
		echo "build all of the firmwares in the pru_fw directory? Check the paths at"
		echo "the top of this script and make sure the files exist."
		echo ""
	fi

	loop=true
	while $loop; do
		read -p "Would you like to load a different firmware? y/n: " run_again
		echo""

		case "$run_again" in
		y) loop=false ;;
		n) exit ;;
		*) echo "invalid response"
		echo "";;
		esac
	done
done
