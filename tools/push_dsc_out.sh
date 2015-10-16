#!/bin/bash -e

. version.sh

sudo mount -a

run () {
	wdir="/mnt/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/"
	if [ ! -d ${wdir} ] ; then
		mkdir -p ${wdir}
	fi

	cp -v ${suite}/*.dsc ${wdir} || true
	cp -v ${suite}/*.gz ${wdir} || true
	cp -v ${suite}/*.bz2 ${wdir} || true
	cp -v ${suite}/*.xz ${wdir} || true
	echo "*******************************"
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

suite="stretch"
if [ -d suite/${suite}/ ] ; then
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d suite/${suite}/ ] ; then
	run
fi

suite="vivid"
if [ -d suite/${suite}/ ] ; then
	run
fi

suite="wily"
if [ -d suite/${suite}/ ] ; then
	run
fi
