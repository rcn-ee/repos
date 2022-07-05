#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://github.com/beagleboard/customizations ./src/
	#git clone git@github.com:rcn-ee/customizations.git ./src/
	#git clone -b fix-extra-space-in-zz-uenv_txt git@github.com:rcn-ee/customizations.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/focal/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
	cp -v ./src${wdir}${wfile} ./suite/bullseye/debian/
}

copy_some () {
	cp -v ./src${wdir}${wfile} ./suite/bionic/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="zz-uenv_txt" ; wdir="/etc/kernel/postinst.d/" ; copy_all

wfile="rtl8723bu-blacklist.conf" ; wdir="/etc/modprobe.d/" ; copy_some

wfile="10-of-symlink.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="60-omap-tty.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="80-eeprom-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="80-gpio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="80-i2c-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="81-pwm-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="82-gpio-config-pin.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="83-eqep-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="85-gpio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="86-remoteproc-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="86-rpmsg-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="87-iio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_all
wfile="88-leds-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some
wfile="89-uio-noroot.rules" ; wdir="/etc/udev/rules.d/" ; copy_some

wfile="generic-board-startup.service" ; wdir="/lib/systemd/system/" ; copy_some

wfile="ti_pru_firmware" ; wdir="/usr/share/initramfs-tools/hooks/" ; copy_all

wfile="am335x-pru0-fw.sleep" ; wdir="/src/am335x/" ; copy_all
wfile="am335x-pru1-fw.sleep" ; wdir="/src/am335x/" ; copy_all

wfile="am57xx-pru1_0-fw.sleep" ; wdir="/src/am57xx/" ; copy_all
wfile="am57xx-pru1_1-fw.sleep" ; wdir="/src/am57xx/" ; copy_all

wfile="am57xx-pru2_0-fw.sleep" ; wdir="/src/am57xx/" ; copy_all
wfile="am57xx-pru2_1-fw.sleep" ; wdir="/src/am57xx/" ; copy_all

wfile="beagle-version" ; wdir="/usr/bin/" ; copy_some
