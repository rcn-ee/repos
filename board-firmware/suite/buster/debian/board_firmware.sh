#!/bin/sh -e
# Copy board firmware into the initramfs
 
if [ "$1" = "prereqs" ]; then exit 0; fi
 
. /usr/share/initramfs-tools/hook-functions
 
if [ -d /lib/firmware/ ] ; then
	board=$(cat /proc/device-tree/model | sed "s/ /_/g" | tr -d '\000')
	case "${board}" in
	NVIDIA_Tegra124_Jetson_TK1)
		if [ -f /lib/firmware/nvidia/tegra124/xusb.bin ] ; then
			mkdir -p $DESTDIR/lib/firmware/nvidia/tegra124/
			cp -a /lib/firmware/nvidia/tegra124/xusb.bin $DESTDIR/lib/firmware/nvidia/tegra124/xusb.bin
		fi
		;;
	esac
fi
