#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://github.com/beagleboard/customizations.git ./src/
	#git clone git@github.com:rcn-ee/customizations.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/focal/debian/
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/stretch/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="autoconfigure_usb0.sh" ; wdir="/usr/bin/" ; copy_all
wfile="autoconfigure_usb1.sh" ; wdir="/usr/bin/" ; copy_all
wfile="bb_dnsmasq_config.sh"  ; wdir="/usr/bin/" ; copy_all
wfile="bb_generate_mac.sh"    ; wdir="/usr/bin/" ; copy_all
