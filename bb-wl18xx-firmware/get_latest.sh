#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone git@github.com:RobertCNelson/bb-wl18xx-firmware.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/focal/debian/
	cp -v ./src${wdir}${wfile} ./suite/stretch/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="bb-wl18xx-bluetooth" ; wdir="/debian/" ; copy_all
wfile="bb-wl18xx-bluetooth.service" ; wdir="/debian/" ; copy_all
wfile="bb_wl18xx_bts_firmware" ; wdir="/debian/" ; copy_all
wfile="bb-wl18xx-tether" ; wdir="/debian/" ; copy_all
wfile="bb-wl18xx-wlan0" ; wdir="/debian/" ; copy_all
wfile="bb-wl18xx-wlan0.service" ; wdir="/debian/" ; copy_all
wfile="btwilink-blacklist.conf" ; wdir="/debian/" ; copy_all
wfile="compat" ; wdir="/debian/" ; copy_all
wfile="install" ; wdir="/debian/" ; copy_all
wfile="postinst" ; wdir="/debian/" ; copy_all
wfile="postrm" ; wdir="/debian/" ; copy_all
wfile="prerm" ; wdir="/debian/" ; copy_all
wfile="rules" ; wdir="/debian/" ; copy_all
wfile="TIInit_11.8.32.bts" ; wdir="/debian/" ; copy_all
wfile="wl18xx.conf" ; wdir="/debian/" ; copy_all
wfile="wl18xx-conf.bin" ; wdir="/debian/" ; copy_all

