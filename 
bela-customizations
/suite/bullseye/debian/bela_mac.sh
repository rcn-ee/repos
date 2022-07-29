#!/bin/sh -e
#
# Copyright (c) 2013-2017 Robert Nelson <robertcnelson@gmail.com>
# Copyright (c) 2018 Liam Donovan <liam@bela.io>
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

#cpsw_0_mac = eth0 - wlan0 (in eeprom)
#cpsw_1_mac = usb0 (BeagleBone Side) (in eeprom)
#cpsw_2_mac = usb0 (USB host, pc side) ((cpsw_0_mac + cpsw_2_mac) /2 )
#cpsw_3_mac = wl18xx (AP) (cpsw_0_mac + 3)
#cpsw_4_mac = usb1 (BeagleBone Side)
#cpsw_5_mac = usb1 (USB host, pc side)

mac_address="/proc/device-tree/ocp/ethernet@4a100000/slave@4a100200/mac-address"
if [ -f ${mac_address} ] && [ -f /usr/bin/hexdump ] ; then
	cpsw_0_mac=$(hexdump -v -e '1/1 "%02X" ":"' ${mac_address} | sed 's/.$//')
	cpsw_0_mac=$(echo $cpsw_0_mac | cut -c 5-17 | sed s/./BE:1A/1)

	#Some devices are showing a blank cpsw_0_mac [00:00:00:00:00:00], let's fix that up...
	if [ "x${cpsw_0_mac}" = "xBE:1A:00:00:00:00" ] ; then
		cpsw_0_mac="BE:1A:8C:A2:ED:68"
	fi
else
	#todo: generate random mac... (this is a development tre board in the lab...)
	cpsw_0_mac="BE:1A:8C:A2:ED:68"
fi

unset use_cached_cpsw_mac
if [ -f /etc/cpsw_0_mac ] ; then
	unset test_cpsw_0_mac
	test_cpsw_0_mac=$(cat /etc/cpsw_0_mac)
	if [ "x${cpsw_0_mac}" = "x${test_cpsw_0_mac}" ] ; then
		use_cached_cpsw_mac="true"
	else
		echo "${cpsw_0_mac}" > /etc/cpsw_0_mac || true
	fi
else
	echo "${cpsw_0_mac}" > /etc/cpsw_0_mac || true
fi

if [ "x${use_cached_cpsw_mac}" = "xtrue" ] && [ -f /etc/cpsw_1_mac ] ; then
	cpsw_1_mac=$(cat /etc/cpsw_1_mac)
else
	mac_address="/proc/device-tree/ocp/ethernet@4a100000/slave@4a100300/mac-address"
	if [ -f ${mac_address} ] && [ -f /usr/bin/hexdump ] ; then
		cpsw_1_mac=$(hexdump -v -e '1/1 "%02X" ":"' ${mac_address} | sed 's/.$//')
		cpsw_1_mac=$(echo $cpsw_1_mac | cut -c 5-17 | sed s/./BE:1A/1)

		#Some devices are showing a blank cpsw_1_mac [00:00:00:00:00:00], let's fix that up...
		if [ "x${cpsw_1_mac}" = "xBE:1A:00:00:00:00" ] ; then
			if [ -f /usr/bin/bc ] ; then
				mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-14)

				cpsw_0_6=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}')
				#bc cuts off leading zero's, we need ten/ones value
				cpsw_res=$(echo "obase=16;ibase=16;$cpsw_0_6 + 102" | bc)

				cpsw_1_mac=${mac_0_prefix}:$(echo ${cpsw_res} | cut -c 2-3)
			else
				cpsw_1_mac="BE:1A:8C:A2:ED:70"
			fi
		fi
		echo "${cpsw_1_mac}" > /etc/cpsw_1_mac || true
	else
		#todo: generate random mac...
		cpsw_1_mac="BE:1A:8C:A2:ED:70"
		echo "${cpsw_1_mac}" > /etc/cpsw_1_mac || true
	fi
fi

if [ "x${use_cached_cpsw_mac}" = "xtrue" ] && [ -f /etc/cpsw_2_mac ] ; then
	cpsw_2_mac=$(cat /etc/cpsw_2_mac)
else
	if [ -f /usr/bin/bc ] ; then
		mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-14)

		cpsw_0_6=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}')
		cpsw_1_6=$(echo ${cpsw_1_mac} | awk -F ':' '{print $6}')

		cpsw_add=$(echo "obase=16;ibase=16;$cpsw_0_6 + $cpsw_1_6" | bc)
		cpsw_div=$(echo "obase=16;ibase=16;$cpsw_add / 2" | bc)
		#bc cuts off leading zero's, we need ten/ones value
		cpsw_res=$(echo "obase=16;ibase=16;$cpsw_div + 100" | bc)

		cpsw_2_mac=${mac_0_prefix}:$(echo ${cpsw_res} | cut -c 2-3)
		echo "${log} uncached cpsw_2_mac: [${cpsw_2_mac}]"
	else
		cpsw_0_last=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}' | cut -c 2)
		cpsw_1_last=$(echo ${cpsw_1_mac} | awk -F ':' '{print $6}' | cut -c 2)
		mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-16)
		mac_1_prefix=$(echo ${cpsw_1_mac} | cut -c 1-16)
		#if cpsw_0_mac is even, add 1
		case "x${cpsw_0_last}" in
		x0)
			cpsw_2_mac="${mac_0_prefix}1"
			;;
		x2)
			cpsw_2_mac="${mac_0_prefix}3"
			;;
		x4)
			cpsw_2_mac="${mac_0_prefix}5"
			;;
		x6)
			cpsw_2_mac="${mac_0_prefix}7"
			;;
		x8)
			cpsw_2_mac="${mac_0_prefix}9"
			;;
		xA)
			cpsw_2_mac="${mac_0_prefix}B"
			;;
		xC)
			cpsw_2_mac="${mac_0_prefix}D"
			;;
		xE)
			cpsw_2_mac="${mac_0_prefix}F"
			;;
		*)
			#else, subtract 1 from cpsw_1_mac
			case "x${cpsw_1_last}" in
			xF)
				cpsw_2_mac="${mac_1_prefix}E"
				;;
			xD)
				cpsw_2_mac="${mac_1_prefix}C"
				;;
			xB)
				cpsw_2_mac="${mac_1_prefix}A"
				;;
			x9)
				cpsw_2_mac="${mac_1_prefix}8"
				;;
			x7)
				cpsw_2_mac="${mac_1_prefix}6"
				;;
			x5)
				cpsw_2_mac="${mac_1_prefix}4"
				;;
			x3)
				cpsw_2_mac="${mac_1_prefix}2"
				;;
			x1)
				cpsw_2_mac="${mac_1_prefix}0"
				;;
			*)
				#todo: generate random mac...
				cpsw_2_mac="BE:1A:8C:A2:ED:6A"
				;;
			esac
			;;
		esac
	fi
	echo "${cpsw_2_mac}" > /etc/cpsw_2_mac || true
fi

if [ "x${use_cached_cpsw_mac}" = "xtrue" ] && [ -f /etc/cpsw_3_mac ] ; then
	cpsw_3_mac=$(cat /etc/cpsw_3_mac)
else
	if [ -f /usr/bin/bc ] ; then
		mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-14)

		cpsw_0_6=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}')
		#bc cuts off leading zero's, we need ten/ones value
		cpsw_res=$(echo "obase=16;ibase=16;$cpsw_0_6 + 103" | bc)

		cpsw_3_mac=${mac_0_prefix}:$(echo ${cpsw_res} | cut -c 2-3)
	else
		cpsw_3_mac="BE:1A:8C:A2:ED:71"
	fi
	echo "${cpsw_3_mac}" > /etc/cpsw_3_mac || true
fi

if [ "x${use_cached_cpsw_mac}" = "xtrue" ] && [ -f /etc/cpsw_4_mac ] ; then
	cpsw_4_mac=$(cat /etc/cpsw_4_mac)
else
	if [ -f /usr/bin/bc ] ; then
		mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-14)

		cpsw_0_6=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}')
		#bc cuts off leading zero's, we need ten/ones value
		cpsw_res=$(echo "obase=16;ibase=16;$cpsw_0_6 + 104" | bc)

		cpsw_4_mac=${mac_0_prefix}:$(echo ${cpsw_res} | cut -c 2-3)
	else
		cpsw_4_mac="BE:1A:8C:A2:ED:72"
	fi
	echo "${cpsw_4_mac}" > /etc/cpsw_4_mac || true
fi

if [ "x${use_cached_cpsw_mac}" = "xtrue" ] && [ -f /etc/cpsw_5_mac ] ; then
	cpsw_5_mac=$(cat /etc/cpsw_5_mac)
else
	if [ -f /usr/bin/bc ] ; then
		mac_0_prefix=$(echo ${cpsw_0_mac} | cut -c 1-14)

		cpsw_0_6=$(echo ${cpsw_0_mac} | awk -F ':' '{print $6}')
		#bc cuts off leading zero's, we need ten/ones value
		cpsw_res=$(echo "obase=16;ibase=16;$cpsw_0_6 + 105" | bc)

		cpsw_5_mac=${mac_0_prefix}:$(echo ${cpsw_res} | cut -c 2-3)
	else
		cpsw_5_mac="BE:1A:8C:A2:ED:73"
	fi
	echo "${cpsw_5_mac}" > /etc/cpsw_5_mac || true
fi

echo "${log} cpsw_0_mac: [${cpsw_0_mac}]"
echo "${log} cpsw_1_mac: [${cpsw_1_mac}]"
echo "${log} cpsw_2_mac: [${cpsw_2_mac}]"
echo "${log} cpsw_3_mac: [${cpsw_3_mac}]"
echo "${log} cpsw_4_mac: [${cpsw_4_mac}]"
echo "${log} cpsw_5_mac: [${cpsw_5_mac}]"
