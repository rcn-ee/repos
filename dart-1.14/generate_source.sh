#!/bin/bash -e

. version.sh

server="https://gsdview.appspot.com/dart-archive/channels/stable/release"
if [ ! -f dart_${real_package_version}.orig.tar.gz ] ; then
	wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}.orig.tar.gz || true
fi

if [ ! -f dart_${real_package_version}.orig.tar.gz ] ; then
	server="https://gsdview.appspot.com/dart-archive/channels/dev/release"
	wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}.orig.tar.gz || true
fi

if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
	cp -v dart_${real_package_version}.orig.tar.gz ${package_name}_${package_version}.orig.tar.gz
fi

if [ ! -f dart_${real_package_version}-1.debian.tar.gz ] ; then
	wget -c ${server}/${real_package_version}/linux_packages/debian_wheezy/dart_${real_package_version}-1.debian.tar.gz
fi

if [ ! -f dart_${package_version}-1.debian.tar.gz ] ; then
	cp -v dart_${real_package_version}-1.debian.tar.gz dart_${package_version}-1.debian.tar.gz
fi

if [ ! -f ${package_name}_${package_version}-1.debian.tar.gz ] ; then
	cp -v dart_${real_package_version}-1.debian.tar.gz ${package_name}_${package_version}-1.debian.tar.gz
fi

if [ -d ./test ] ; then
	rm -rf ./test || true
fi

mkdir ./test
tar xf ${package_name}_${package_version}-1.debian.tar.gz -C ./test

