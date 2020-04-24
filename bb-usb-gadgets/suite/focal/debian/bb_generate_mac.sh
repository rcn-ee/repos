#!/bin/sh -e
#
# Copyright (c) 2013-2020 Robert Nelson <robertcnelson@gmail.com>
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

#Ported from: https://github.com/RobertCNelson/boot-scripts/blob/master/boot/am335x_evm.sh

if ! id | grep -q root; then
	echo "must be run as root"
	exit
fi

log="bb_generate_mac.sh"
pre="/etc/cpsw_"

usage () {
	echo "usage: sudo $(basename $0) --mac 1C:BA:8C:A2:ED:70"
	exit 2
}

process_base () {
	mac_addr0_octet_1_5=$(echo ${mac_addr0} | cut -c 1-14)
	mac_addr0_octet_6=$(echo ${mac_addr0} | awk -F ':' '{print $6}')

	unset use_cached_mac_addr
	if [ -f ${pre}0_mac ] ; then
		unset use_cached_mac_addr
		test_mac_addr0=$(cat /etc/cpsw_0_mac)
		if [ "x${mac_addr0}" = "x${test_mac_addr0}" ] ; then
			use_cached_bb_mac="true"
		else
			echo "${mac_addr0}" > ${pre}0_mac || true
		fi
	else
		echo "${mac_addr0}" > ${pre}0_mac || true
	fi
}

generate_addr1 () {
	if [ "x${use_cached_mac_addr}" = "xtrue" ] && [ -f ${pre}1_mac ] ; then
		mac_addr1=$(cat ${pre}1_mac)
	else
		#bc cuts off leading zero's, we need ten/ones value
		new_octet_6=$(echo "obase=16;ibase=16;$mac_addr0_octet_6 + 102" | bc)

		mac_addr1=${mac_addr0_octet_1_5}:$(echo ${new_octet_6} | cut -c 2-3)
		echo "${mac_addr1}" > ${pre}1_mac || true
	fi
}

generate_addr2 () {
	if [ "x${use_cached_mac_addr}" = "xtrue" ] && [ -f ${pre}2_mac ] ; then
		mac_addr1=$(cat ${pre}2_mac)
	else
		#bc cuts off leading zero's, we need ten/ones value
		new_octet_6=$(echo "obase=16;ibase=16;$mac_addr0_octet_6 + 103" | bc)

		mac_addr2=${mac_addr0_octet_1_5}:$(echo ${new_octet_6} | cut -c 2-3)
		echo "${mac_addr2}" > ${pre}2_mac || true
	fi
}

generate_addr3 () {
	if [ "x${use_cached_mac_addr}" = "xtrue" ] && [ -f ${pre}3_mac ] ; then
		mac_addr1=$(cat ${pre}3_mac)
	else
		#bc cuts off leading zero's, we need ten/ones value
		new_octet_6=$(echo "obase=16;ibase=16;$mac_addr0_octet_6 + 104" | bc)

		mac_addr3=${mac_addr0_octet_1_5}:$(echo ${new_octet_6} | cut -c 2-3)
		echo "${mac_addr3}" > ${pre}3_mac || true
	fi
}

generate_addr4 () {
	if [ "x${use_cached_mac_addr}" = "xtrue" ] && [ -f ${pre}4_mac ] ; then
		mac_addr1=$(cat ${pre}4_mac)
	else
		#bc cuts off leading zero's, we need ten/ones value
		new_octet_6=$(echo "obase=16;ibase=16;$mac_addr0_octet_6 + 105" | bc)

		mac_addr4=${mac_addr0_octet_1_5}:$(echo ${new_octet_6} | cut -c 2-3)
		echo "${mac_addr4}" > ${pre}4_mac || true
	fi
}

generate_addr5 () {
	if [ "x${use_cached_mac_addr}" = "xtrue" ] && [ -f ${pre}5_mac ] ; then
		mac_addr5=$(cat ${pre}5_mac)
	else
		#bc cuts off leading zero's, we need ten/ones value
		new_octet_6=$(echo "obase=16;ibase=16;$mac_addr0_octet_6 + 106" | bc)

		mac_addr5=${mac_addr0_octet_1_5}:$(echo ${new_octet_6} | cut -c 2-3)
		echo "${mac_addr5}" > ${pre}5_mac || true
	fi
}

generate_all () {
	process_base
	generate_addr1
	generate_addr2
	generate_addr3
	generate_addr4
	generate_addr5
}

unset mac_addr0
unset mac_addr0_octet_1_5
unset mac_addr0_octet_6

# parse commandline options
while [ ! -z "$1" ] ; do
	case $1 in
	-h|--help)
		usage
		;;
	--mac)
		mac_addr0="$2"
		generate_all
		;;
	esac
	shift
done

if [ ! "${mac_addr0}" ] ; then
	echo "ERROR: --mac undefined"
	usage
fi

echo "${log} ${pre}0_mac: [${mac_addr0}]"
echo "${log} ${pre}1_mac: [${mac_addr1}]"
echo "${log} ${pre}2_mac: [${mac_addr2}]"
echo "${log} ${pre}3_mac: [${mac_addr3}]"
echo "${log} ${pre}4_mac: [${mac_addr4}]"
echo "${log} ${pre}5_mac: [${mac_addr5}]"

