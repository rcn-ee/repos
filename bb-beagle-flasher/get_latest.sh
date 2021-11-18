#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://github.com/rcn-ee/beagle-flasher ./src/
}

copy_all () {
	cp -v ./src/${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="beagle-flasher" ; copy_all
wfile="init-beagle-flasher" ; copy_all
wfile="templates/beaglebone-black-emmc-to-microsd" ; copy_all
wfile="templates/beaglebone-black-microsd-to-emmc" ; copy_all
