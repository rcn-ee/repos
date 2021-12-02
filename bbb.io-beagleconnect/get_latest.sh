#!/bin/bash

version="beta0.0.10"

dl_src () {
	if [ -d ./build/ ] ; then
		rm -rf ./build/
	fi

	wget -c https://github.com/jadonk/beagleconnect/releases/download/bcf-${version}/bcf-bcf-${version}.zip
	unzip bcf-bcf-${version}.zip
}

copy_all () {
	cp -v ./${wfile} ./suite/buster/debian/
	cp -v ./${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="build/cc1352/greybus_mikrobus_beagleconnect.config" ; copy_all
wfile="build/cc1352/wpanusb_beagleconnect.config" ; copy_all
wfile="build/cc1352/sensortest_beagleconnect.bin" ; copy_all
wfile="build/cc1352/wpanusb_beagleconnect.dts" ; copy_all
wfile="build/cc1352/sensortest_beagleconnect.dts" ; copy_all
wfile="build/cc1352/greybus_mikrobus_beagleconnect.dts" ; copy_all
wfile="build/cc1352/sensortest_beagleconnect.config" ; copy_all
wfile="build/cc1352/greybus_mikrobus_beagleconnect.bin" ; copy_all
wfile="build/cc1352/wpanusb_beagleconnect.bin" ; copy_all

wfile="build/msp430/usb_uart_bridge_lp.hex" ; copy_all
wfile="build/msp430/usb_uart_bridge.hex" ; copy_all
