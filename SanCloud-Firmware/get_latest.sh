#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://github.com/SanCloudLtd/firmware ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="bdwlan30.bin" ; wdir="/qca6174a/" ; copy_all
wfile="otp30.bin" ; wdir="/qca6174a/" ; copy_all
wfile="qwlan30.bin" ; wdir="/qca6174a/" ; copy_all
wfile="utf30.bin" ; wdir="/qca6174a/" ; copy_all
wfile="qcom_cfg.ini" ; wdir="/qca6174a/wlan/" ; copy_all
