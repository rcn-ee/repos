#!/bin/bash -e

. version.sh

pushout () {
	if [ ! -d /mnt/farm/incoming/${dist}/ ] ; then
		mkdir -p /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${package}_${version}.orig.tar.xz ] ; then
		cp -v ${dist}/${package}_${version}.orig.tar.xz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${package}_${version}.orig.tar.gz ] ; then
		cp -v ${dist}/${package}_${version}.orig.tar.gz /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${package}_${debian_version}${bpo}.dsc ] ; then
		cp -v ${dist}/${package}_${debian_version}${bpo}.dsc /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${package}_${debian_version}${bpo}.debian.tar.xz ] ; then
		cp -v ${dist}/${package}_${debian_version}${bpo}.debian.tar.xz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${package}_${debian_version}${bpo}.debian.tar.gz ] ; then
		cp -v ${dist}/${package}_${debian_version}${bpo}.debian.tar.gz /mnt/farm/incoming/${dist}/
	fi
}

dist="wheezy"
bpo="~bpo70+1"
pushout

