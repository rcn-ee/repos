#!/bin/bash -e

. version.sh

run () {
	if [ ! -d /mnt/farm/incoming/${suite}/ ] ; then
		mkdir -p /mnt/farm/incoming/${suite}/
	fi

	cp -v ${suite}/*.dsc /mnt/farm/incoming/${suite}/
	cp -v ${suite}/*.gz /mnt/farm/incoming/${suite}/
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

