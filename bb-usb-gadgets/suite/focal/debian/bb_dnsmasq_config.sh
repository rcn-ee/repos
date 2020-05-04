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

ap_interface="SoftAp0"

if [ -f /etc/default/bb-wl18xx ] ; then
	. /etc/default/bb-wl18xx
fi

if [ -f /etc/default/bb-boot ] ; then
	. /etc/default/bb-boot
else
	if [ -f /opt/scripts/boot/default/bb-boot ] ; then
		cp -v /opt/scripts/boot/default/bb-boot /etc/default/ || true
		. /etc/default/bb-boot
	else
		USB0_SUBNET=192.168.7
		USB0_ADDRESS=192.168.7.2
		USB0_NETMASK=255.255.255.0

		USB1_ENABLE=enable
		USB1_SUBNET=192.168.6
		USB1_ADDRESS=192.168.6.2
		USB1_NETMASK=255.255.255.0
	fi
fi

unset got_softap0
#Only create SoftAp0 if /etc/default/bb-wl18xx TETHER_ENABLED is set, we still need usb0/usb1 configured...
if [ "x${TETHER_ENABLED}" = "xyes" ] ; then
	if [ -d /sys/class/net/${ap_interface} ] ; then
		got_softapt0=enable
	fi
fi

wfile="/etc/dnsmasq.d/SoftAp0"

if [ "x${got_softapt0}" = "xenable" ] ; then
	echo "interface=${ap_interface}" > ${wfile}
	echo "interface=usb0" >> ${wfile}
else
	echo "interface=usb0" > ${wfile}
fi

if [ "x${USB1_ENABLE}" = "xenable" ] ; then
	echo "interface=usb1" >> ${wfile}
fi

echo "port=53" >> ${wfile}
echo "dhcp-authoritative" >> ${wfile}
echo "domain-needed" >> ${wfile}
echo "bogus-priv" >> ${wfile}
echo "expand-hosts" >> ${wfile}
echo "cache-size=2048" >> ${wfile}

if [ "x${got_softapt0}" = "xenable" ] ; then
	echo "dhcp-range=${ap_interface},${USE_WL18XX_IP_PREFIX}.50,${USE_WL18XX_IP_PREFIX}.150,60m" >> ${wfile}
fi

echo "dhcp-range=usb0,${USB0_SUBNET}.1,${USB0_SUBNET}.1,20m" >> ${wfile}

if [ "x${USB1_ENABLE}" = "xenable" ] ; then
	echo "dhcp-range=usb1,${USB1_SUBNET}.1,${USB1_SUBNET}.1,20m" >> ${wfile}
fi

echo "listen-address=127.0.0.1" >> ${wfile}

if [ "x${got_softapt0}" = "xenable" ] ; then
	echo "listen-address=${USE_WL18XX_IP_PREFIX}.1" >> ${wfile}
fi

echo "listen-address=${USB0_ADDRESS}" >> ${wfile}

if [ "x${USB1_ENABLE}" = "xenable" ] ; then
	echo "listen-address=${USB1_ADDRESS}" >> ${wfile}
fi

if [ "x${got_softapt0}" = "xenable" ] ; then
	echo "dhcp-option-force=interface:${ap_interface},option:dns-server,${USE_WL18XX_IP_PREFIX}.1" >> ${wfile}
	echo "dhcp-option-force=interface:${ap_interface},option:mtu,1500" >> ${wfile}
fi

echo "dhcp-option=usb0,3" >> ${wfile}
echo "dhcp-option=usb0,6" >> ${wfile}

if [ "x${USB1_ENABLE}" = "xenable" ] ; then
	echo "dhcp-option=usb1,3" >> ${wfile}
	echo "dhcp-option=usb1,6" >> ${wfile}
fi

echo "dhcp-leasefile=/var/run/dnsmasq.leases" >> ${wfile}

#
