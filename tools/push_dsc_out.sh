#!/bin/bash -e

. version.sh

run () {
	if [ ! -d /mnt/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/ ] ; then
		mkdir -p /mnt/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/
	fi

	cp -v ${suite}/*.dsc /mnt/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/
	cp -v ${suite}/*.gz /mnt/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/
}

dist="debian"
suite="wheezy"
if [ -d suite/${suite}/ ] ; then
	run
fi

suite="jessie"
if [ -d suite/${suite}/ ] ; then
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d suite/${suite}/ ] ; then
	run
fi

suite="utopic"
if [ -d suite/${suite}/ ] ; then
	run
fi

suite="vivid"
if [ -d suite/${suite}/ ] ; then
	run
fi

