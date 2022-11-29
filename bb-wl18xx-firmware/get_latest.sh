#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.beagleboard.org/beagleboard/usr-customizations.git ./src/
}

copy_all () {
	cp -v ./src/${wfile} ./suite/bionic/debian/
	cp -v ./src/${wfile} ./suite/buster/debian/
}

copy_some () {
	cp -v ./src/${wfile} ./suite/focal/debian/
	cp -v ./src/${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="arm32/usr/bin/bb-wl18xx-bluetooth" ; copy_all
wfile="arm32/lib/systemd/system/bb-wl18xx-bluetooth.service" ; copy_all
wfile="arm32/usr/bin/bb-wl18xx-tether" ; copy_all
wfile="arm32/usr/bin/bb-wl18xx-wlan0" ; copy_all
wfile="arm32/lib/systemd/system/bb-wl18xx-wlan0.service" ; copy_all

#wfile="TIInit_11.8.32.bts" ; wdir="/debian/" ; copy_all
#wfile="wl18xx.conf" ; wdir="/debian/" ; copy_all
#wfile="wl18xx-conf.bin" ; wdir="/debian/" ; copy_all
#wfile="wl18xx-fw-4.bin" ; wdir="/debian/" ; copy_all

#wfile="TIInit_11.8.32.bts" ; wdir="/debian/" ; copy_some
#wfile="wl18xx.conf" ; wdir="/debian/" ; copy_some
#wfile="wl18xx-conf.bin" ; wdir="/debian/" ; copy_some
#wfile="wl18xx-fw-4.bin" ; wdir="/debian/" ; copy_some
