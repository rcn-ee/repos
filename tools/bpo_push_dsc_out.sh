#!/bin/bash -e

. version.sh

pushout () {
	if [ ! -d /mnt/farm/incoming/${dist}/ ] ; then
		mkdir -p /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${archive}_${version}.orig.tar.xz ] ; then
		cp -v ${dist}/${archive}_${version}.orig.tar.xz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${archive}_${version}.orig.tar.bz2 ] ; then
		cp -v ${dist}/${archive}_${version}.orig.tar.bz2 /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${archive}_${version}.orig.tar.gz ] ; then
		cp -v ${dist}/${archive}_${version}.orig.tar.gz /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${archive}_${debian_version}${bpo}.dsc ] ; then
		cp -v ${dist}/${archive}_${debian_version}${bpo}.dsc /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${archive}_${debian_version}${bpo}.debian.tar.xz ] ; then
		cp -v ${dist}/${archive}_${debian_version}${bpo}.debian.tar.xz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${archive}_${debian_version}${bpo}.debian.tar.gz ] ; then
		cp -v ${dist}/${archive}_${debian_version}${bpo}.debian.tar.gz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${archive}_${debian_version}${bpo}.diff.gz ] ; then
		cp -v ${dist}/${archive}_${debian_version}${bpo}.diff.gz /mnt/farm/incoming/${dist}/
	fi
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	bpo="${wheezy_backport}"
	pushout
fi
