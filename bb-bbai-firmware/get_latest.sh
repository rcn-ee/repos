#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone git@github.com:RobertCNelson/bb-bbai-firmware.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/stretch/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="bb-bbai-tether" ; wdir="/debian/" ; copy_all
wfile="bb-bbai-tether.service" ; wdir="/debian/" ; copy_all
wfile="brcmfmac43455-sdio.beagleboard.org,am5729-beagleboneai.txt" ; wdir="/debian/" ; copy_all
wfile="brcmfmac43455-sdio.clm_blob" ; wdir="/debian/" ; copy_all
wfile="compat" ; wdir="/debian/" ; copy_all
#wfile="control" ; wdir="/debian/" ; copy_all
wfile="fw_bcm43455c0_ag.bin" ; wdir="/debian/" ; copy_all
wfile="install" ; wdir="/debian/" ; copy_all
wfile="postinst" ; wdir="/debian/" ; copy_all
wfile="postrm" ; wdir="/debian/" ; copy_all
wfile="prerm" ; wdir="/debian/" ; copy_all
wfile="rules" ; wdir="/debian/" ; copy_all

