#!/bin/bash

rm ti-connectivity/wl1271-nvs.bin
cp ti-connectivity/wl127x-nvs.bin ti-connectivity/wl1271-nvs.bin

firmware="./ti-connectivity/wl1271-nvs.bin"

firmware_dump=$(hexdump -ve '1/1 "%.2x"' ${firmware} -n 12 | awk '{print toupper($0)}')
offset0=$(echo ${firmware_dump} | cut -b 23-24)
offset1=$(echo ${firmware_dump} | cut -b 21-22)
offset2=$(echo ${firmware_dump} | cut -b 13-14)
offset3=$(echo ${firmware_dump} | cut -b 11-12)
offset4=$(echo ${firmware_dump} | cut -b 9-10)
offset5=$(echo ${firmware_dump} | cut -b 7-8)
current_mac="${offset0}:${offset1}:${offset2}:${offset3}:${offset4}:${offset5}"
echo "${firmware}=[${current_mac}]"

wlan_0_mac="00:00:00:00:00:00"

offset0=$(echo ${wlan_0_mac} | cut -b 1-2)
offset1=$(echo ${wlan_0_mac} | cut -b 4-5)
offset2=$(echo ${wlan_0_mac} | cut -b 7-8)
offset3=$(echo ${wlan_0_mac} | cut -b 10-11)
offset4=$(echo ${wlan_0_mac} | cut -b 13-14)
offset5=$(echo ${wlan_0_mac} | cut -b 16-17)

printf '\x'${offset0}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x0000000b)) status=none
printf '\x'${offset1}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x0000000a)) status=none
printf '\x'${offset2}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x00000006)) status=none
printf '\x'${offset3}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x00000005)) status=none
printf '\x'${offset4}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x00000004)) status=none
printf '\x'${offset5}'' | dd conv=notrunc of=${firmware} bs=1 seek=$((0x00000003)) status=none

echo "Writing mac address: [${wlan_0_mac}] to file: ${firmware}"
