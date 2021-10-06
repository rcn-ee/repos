#!/bin/bash

if [ -e /dev/rpmsg_pru30 ] 
then
	while true; do
		read -p "PRU0: Input an LED color to toggle ('q' to quit)[r,g,b,o]: " rgbo
		if [ $rgbo = 'q' ]; then
			exit
		fi
		echo $rgbo > /dev/rpmsg_pru30
	done
else
	echo "/dev/rpmsg_pru30 device does not exist"
fi
		
