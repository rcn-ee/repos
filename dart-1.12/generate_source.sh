#!/bin/bash -e

. version.sh

server="https://gsdview.appspot.com/dart-archive/channels/stable/release"

wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}.orig.tar.gz || true
if [ -f dart_${real_package_version}.orig.tar.gz ] ; then
	cp dart_${real_package_version}.orig.tar.gz ${package_name}_${package_version}.orig.tar.gz
	wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}-1.debian.tar.gz
else
	server="https://gsdview.appspot.com/dart-archive/channels/dev/release"
	wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}.orig.tar.gz
	if [ -f dart_${real_package_version}.orig.tar.gz ] ; then
		cp dart_${real_package_version}.orig.tar.gz ${package_name}_${package_version}.orig.tar.gz
		wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}-1.debian.tar.gz
		if [ -f dart_${real_package_version}-1.debian.tar.gz ] ; then
			cp dart_${real_package_version}-1.debian.tar.gz dart_${package_version}-1.debian.tar.gz
		fi
	fi
fi

