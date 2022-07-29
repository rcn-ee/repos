#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.beagleboard.org/krvprashanth/bela-customizations.git ./src/
	#git clone git@git.beagleboard.org:krvprashanth/bela-customizations.git ./src/
}

copy_all () {
	cp -v ./src${wdir}${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="isc-dhcp-server" ; wdir="/etc/default/" ; copy_all
wfile="dhcpd.conf" ; wdir="/etc/dhcp/" ; copy_all
wfile="modules.conf" ; wdir="/etc/modules-load.d/" ; copy_all
wfile="interfaces" ; wdir="/etc/network/" ; copy_all
wfile="sshd_config" ; wdir="/etc/ssh/" ; copy_all
wfile="bela" ; wdir="/etc/sudoers.d/" ; copy_all
wfile="wpa_supplicant.conf" ; wdir="/etc/wpa_supplicant/" ; copy_all
wfile="fstab" ; wdir="/etc/" ; copy_all
wfile="hosts" ; wdir="/etc/" ; copy_all
wfile="motd" ; wdir="/etc/" ; copy_all
wfile="securetty" ; wdir="/etc/" ; copy_all

wfile="bela_button.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="bela_flash_emmc.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="bela_gadget.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="bela_ide.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="bela_shutdown.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="bela_startup.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="dhclient_shutdown.service" ; wdir="/lib/systemd/system/" ; copy_all
wfile="ssh_shutdown.service" ; wdir="/lib/systemd/system/" ; copy_all

wfile="bela_bootloader.sh" ; wdir="/opt/Bela/" ; copy_all
wfile="bela_button_hold.sh" ; wdir="/opt/Bela/" ; copy_all
wfile="bela_flash_emmc.sh" ; wdir="/opt/Bela/" ; copy_all
wfile="bela_gadget.sh" ; wdir="/opt/Bela/" ; copy_all
wfile="bela_mac.sh" ; wdir="/opt/Bela/" ; copy_all
wfile="bela_startup.sh" ; wdir="/opt/Bela/" ; copy_all

