#!/bin/bash
set -ex
[ -z "$FLASH_DESTINATION" ] && FLASH_DESTINATION=emmc

if [ "$FLASH_DESTINATION" == emmc ]; then
	DEVICE=/dev/mmcblk1
	MMCID=1
	THIS_DEVICE=/dev/mmcblk0
elif [ "$FLASH_DESTINATION" == sd ]; then
	DEVICE=/dev/mmcblk0
	MMCID=0
	THIS_DEVICE=/dev/mmcblk1
else
	echo "Invalid \$FLASH_DESTINATION: '$FLASH_DESTINATION' should be either 'emmc' or 'sd'" >& 2
	exit 1
fi
MNT_BOOT=`mktemp -d /tmp/${FLASH_DESTINATION}_boot.XXXXXX`
MNT_ROOT=`mktemp -d /tmp/${FLASH_DESTINATION}_root.XXXXXX`
MNT_THIS_BOOT=`mktemp -d /tmp/boot.XXXXX`

USR1=/sys/class/leds/beaglebone\:green\:usr1/trigger
USR2=/sys/class/leds/beaglebone\:green\:usr2/trigger
USR3=/sys/class/leds/beaglebone\:green\:usr3/trigger
SUCCESS=0
cleanup() {
	for a in $MNT_BOOT $MNT_ROOT $MNT_THIS_BOOT; do
		umount $a && rm -rf $a || true
	done
}

final_check()
{
	if [ $SUCCESS -eq 0 ]
	then
		cleanup
		set +x
		echo "An error occurred while flashing the $FLASH_DESTINATION" >& 2
		while sleep 0.5
		do
			echo "default-on" > $USR1
			echo "default-on" > $USR2
			echo "default-on" > $USR3
			sleep 0.5
			echo "none" > $USR1
			echo "none" > $USR2
			echo "none" > $USR3
		done
	else
		echo Flashing was successful
	fi
}
trap final_check EXIT

# Stop the Bela program if currently running. Makes for a faster copy.
make --no-print-directory -C /root/Bela stop || true

echo "default-on" > $USR1
echo "default-on" > $USR2
echo "default-on" > $USR3

# test if we are trying to flash the device whose partition is currently mounted on /
mount | grep "${DEVICE}p2" | grep -q "on / " && {
	echo "You are trying to flash $DEVICE ($FLASH_DESTINATION) but you have actually just
	booted from it. Specify a different FLASH_DESTINATION ('sd' or 'emmc'),
	whichever you have NOT booted from" >& 2
	exit 1;
}

# just in case anything from the destination is mounted, unmount it
umount -A ${DEVICE}p1 || true
umount -A ${DEVICE}p2 || true
mount | grep  "${DEVICE}" && {
	echo "One or more filesystems on ${DEVICE} are busy and could not be
		unmounted" >& 2
	exit 1;
}

echo "
label: dos
label-id: 0x68a0906e
device: ${DEVICE}
unit: sectors

${DEVICE}p1 : start=        2048, size=      137953, type=c, bootable
${DEVICE}p2 : start=      141312,                    type=83
" | sfdisk $DEVICE

mkfs.vfat ${DEVICE}p1
mkfs.ext4 -F ${DEVICE}p2

dosfslabel ${DEVICE}p1 BELABOOT
e2label ${DEVICE}p2 BELAROOTFS

mount ${DEVICE}p1 $MNT_BOOT
mount ${DEVICE}p2 $MNT_ROOT

echo "copying files, this may take a few minutes..."

mount ${THIS_DEVICE}p1 $MNT_THIS_BOOT
cp $MNT_THIS_BOOT/MLO $MNT_BOOT
sync
cp $MNT_THIS_BOOT/u-boot.img $MNT_BOOT
sync
rsync -r --exclude=$MNT_THIS_BOOT/MLO,$MNT_THIS_BOOT/u-boot.img,$MNT_THIS_BOOT/'FSCK*REC' $MNT_THIS_BOOT/* $MNT_BOOT
cat $MNT_THIS_BOOT/uEnv.txt | sed "s/^\(\s*mmcid=\).*/\1$MMCID/" > $MNT_BOOT/uEnv.txt
umount $MNT_THIS_BOOT
rm -rf $MNT_THIS_BOOT
cp -a /bin/ /boot/ /dev/ /etc/ /home/ /lib/ /opt/ /root/ /sbin/ /srv/ /usr/ /var/ $MNT_ROOT
mkdir -p $MNT_ROOT/media $MNT_ROOT/mnt $MNT_ROOT/proc $MNT_ROOT/run/ $MNT_ROOT/sys $MNT_ROOT/tmp
cat /etc/fstab  | sed "s:/dev/mmcblk1:/dev/mmcblkX:g" | sed "s:/dev/mmcblk0:/dev/mmcblk1:" | sed "s:/dev/mmcblkX:/dev/mmcblk0:" > $MNT_ROOT/etc/fstab
rm -rf $MNT_ROOT/etc/systemd/system/default.target.wants/bela_flash_emmc.service
rm -rf $MNT_ROOT/etc/cpsw* # reset mac address
sync

echo "Done!"

echo "mmc0" > $USR1
echo "none" > $USR2
echo "mmc1" > $USR3
SUCCESS=1
cleanup
