#!/bin/bash
#
# Copyright (c) 2014-2017 Robert Nelson <robertcnelson@gmail.com>
# Modified 2017 Liam Donovan <liam@bela.io>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

DIR=/mnt/emmc
DEVICE=/dev/mmcblk1

mkdir -p $DIR
mount ${DEVICE}p1 $DIR

trap 'umount $DIR' ERR

if [ -f $DIR/SOC.sh ] ; then
	echo "found SOC.sh in $DIR"
	cat $DIR/SOC.sh
	. $DIR/SOC.sh
elif [ -f $DIR/boot/SOC.sh ] ; then
	echo "found SOC.sh in $DIR/boot"
	cat $DIR/boot/SOC.sh
	. $DIR/boot/SOC.sh
elif [ -f $DIR/boot/uboot/SOC.sh ] ; then
	echo "found SOC.sh in $DIR/boot/uboot"
	cat $DIR/boot/uboot/SOC.sh
	. $DIR/boot/uboot/SOC.sh
elif [ -f $DIR/MLO ] ; then
	echo "emmc contains Bela image"
	bootloader_location="fatfs_boot"
else
	echo "Could not find SOC.sh"
	umount $DIR
	exit 1
fi

if [ "$bootloader_location" = "fatfs_boot" ] ; then
	echo "fatfs_boot"
	mkdir -p /tmp/boot
	cp -a /mnt/emmc/* /tmp/boot/
	rm /tmp/boot/MLO
	rm /tmp/boot/u-boot.img
	rm -rf /mnt/emmc/*
	sync
	cp /mnt/boot/MLO /mnt/emmc/
	cp /mnt/boot/u-boot.img /mnt/emmc/
	cp -a /tmp/boot/* /mnt/emmc/
	umount /mnt/emmc
	exit
fi

if [ "$board" != "am335x_evm" ] ; then
	echo "bad board $board"
	umount $DIR
	exit
fi

if [ "x${dd_spl_uboot_seek}" = "x" ] ; then
	echo "dd_spl_uboot_seek not found in ${DRIVE}/SOC.sh halting"
	umount $DIR
	exit
fi

if [ "x${dd_spl_uboot_bs}" = "x" ] ; then
	echo "dd_spl_uboot_bs not found in SOC.sh halting"
	umount $DIR
	exit
fi

if [ "x${dd_uboot_seek}" = "x" ] ; then
	echo "dd_uboot_seek not found in SOC.sh halting"
	umount $DIR
	exit
fi

if [ "x${dd_uboot_bs}" = "x" ] ; then
	echo "dd_uboot_bs not found in SOC.sh halting"
	umount $DIR
	exit
fi


echo "log: dd if=/mnt/boot/MLO of=${DEVICE} seek=${dd_spl_uboot_seek} bs=${dd_spl_uboot_bs}"
dd if=/mnt/boot/MLO of=${DEVICE} seek=${dd_spl_uboot_seek} bs=${dd_spl_uboot_bs}
echo "log: dd if=/mnt/boot/u-boot.img of=${DEVICE} seek=${dd_uboot_seek} bs=${dd_uboot_bs}"
dd if=/mnt/boot/u-boot.img of=${DEVICE} seek=${dd_uboot_seek} bs=${dd_uboot_bs}
sync

umount $DIR
