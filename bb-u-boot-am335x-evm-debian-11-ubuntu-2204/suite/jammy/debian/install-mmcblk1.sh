#!/bin/bash

if ! id | grep -q root; then
	echo "must be run as root"
	exit 1
fi

wdir="/opt/u-boot/bb-u-boot-am335x-evm"

if [ -b /dev/mmcblk1 ] ; then
	echo "dd if=${wdir}/MLO of=/dev/mmcblk1 count=2 seek=1 bs=128k"
	dd if=${wdir}/MLO of=/dev/mmcblk1 count=2 seek=1 bs=128k
	echo "dd if=${wdir}/u-boot-dtb.img of=/dev/mmcblk1 count=4 seek=1 bs=384k"
	dd if=${wdir}/u-boot-dtb.img of=/dev/mmcblk1 count=4 seek=1 bs=384k
fi
