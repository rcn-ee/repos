#!/bin/bash -e

. version.sh

pushout () {
	if [ ! -d /mnt/farm/incoming/${dist}/ ] ; then
		mkdir -p /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${package}_${version}.orig.tar.xz ] ; then
		cp -v ${package}_${version}.orig.tar.xz /mnt/farm/incoming/${dist}/
	else
		../tools/generate_source.sh
		if [ -f ${package}_${version}.orig.tar.xz ] ; then
			cp -v ${package}_${version}.orig.tar.xz /mnt/farm/incoming/${dist}/
		else
			exit 1
		fi
	fi

	if [ -f ${package}_${debian_version}.dsc ] ; then
		cp -v ${package}_${debian_version}.debian.tar.xz /mnt/farm/incoming/${dist}/
		cp -v ${package}_${debian_version}.dsc /mnt/farm/incoming/${dist}/
	else
		../tools/generate_dsc.sh
		if [ -f ${package}_${debian_version}.dsc ] ; then
			cp -v ${package}_${debian_version}.debian.tar.xz /mnt/farm/incoming/${dist}/
			cp -v ${package}_${debian_version}.dsc /mnt/farm/incoming/${dist}/
		else
			exit 1
		fi
	fi
}

dist="wheezy"
pushout

dist="jessie"
pushout

dist="sid"
pushout

dist="trusty"
pushout

dist="utopic"
pushout
