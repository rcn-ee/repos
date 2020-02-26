#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone git@github.com:rcn-ee/customizations.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/xenial/debian/
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/stretch/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="zz-uenv_txt" ; wdir="/etc/kernel/postinst.d/" ; copy_all

wfile="rtl8723bu-blacklist.conf" ; wdir="/etc/modprobe.d/" ; copy_all

wfile="10-of-symlink.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="60-omap-tty.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="80-eeprom-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="80-gpio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="81-pwm-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="82-gpio-config-pin.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="83-eqep-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="85-gpio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="86-remoteproc-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="86-rpmsg-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="87-iio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all

wfile="generic-board-startup.service" ; wdir="/lib/systemd/system/" ; copy_all
