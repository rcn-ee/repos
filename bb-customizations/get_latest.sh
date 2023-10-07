#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.beagleboard.org/beagleboard/usr-customizations.git ./src/
}

copy_dir () {
	cp -rv ./src${wdir}/* ./suite/focal/debian/
	cp -rv ./src${wdir}/* ./suite/buster/debian/
	cp -rv ./src${wdir}/* ./suite/bullseye/debian/
	cp -rv ./src${wdir}/* ./suite/bookworm/debian/
	cp -rv ./src${wdir}/* ./suite/jammy/debian/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/focal/debian/
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
	cp -v ./src${wdir}${wfile} ./suite/bullseye/debian/
}

copy_some () {
	cp -v ./src${wdir}${wfile} ./suite/buster/debian/
}

dl_src

wfile="zz-uenv_txt" ; wdir="/arm32/etc/kernel/postinst.d/" ; copy_all

wfile="rtl8723bu-blacklist.conf" ; wdir="/arm32/etc/modprobe.d/" ; copy_some

wfile="10-of-symlink.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_all
wfile="60-omap-tty.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="80-eeprom-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="80-gpio-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="80-i2c-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_all
wfile="81-pwm-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_all
wfile="82-gpio-config-pin.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="83-eqep-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="85-gpio-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="86-remoteproc-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="86-rpmsg-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="87-iio-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_all
wfile="88-leds-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some
wfile="89-uio-noroot.rules" ; wdir="/arm32/etc/udev/rules.d/" ; copy_some

wfile="generic-board-startup.service" ; wdir="/arm32/lib/systemd/system/" ; copy_some

wfile="ti_pru_firmware" ; wdir="/arm32/usr/share/initramfs-tools/hooks/" ; copy_all

wfile="am335x-pru0-fw.sleep" ; wdir="/pru/am33_am57/am335x/" ; copy_all
wfile="am335x-pru1-fw.sleep" ; wdir="/pru/am33_am57/am335x/" ; copy_all

wfile="am57xx-pru1_0-fw.sleep" ; wdir="/pru/am33_am57/am57xx/" ; copy_all
wfile="am57xx-pru1_1-fw.sleep" ; wdir="/pru/am33_am57/am57xx/" ; copy_all

wfile="am57xx-pru2_0-fw.sleep" ; wdir="/pru/am33_am57/am57xx/" ; copy_all
wfile="am57xx-pru2_1-fw.sleep" ; wdir="/pru/am33_am57/am57xx/" ; copy_all

wfile="beagle-version" ; wdir="/arm32/usr/sbin/" ; copy_some

wdir="/common/etc/bbb.io/" ; copy_dir
