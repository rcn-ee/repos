#!/bin/bash -e

. version.sh

generate_dsc () {
	if [ -d ./${dist} ] ; then
		rm -rf ./${dist}/
	fi
	mkdir ./${dist}

	cp -v ${package}_${version}.orig.tar.${orig} ./${dist}
	if [ ! "x${deb_patch}" = "x" ] ; then
		cp -v ${package}_${debian_version}.diff.gz ./${dist}
	fi

	cd ./${dist}
	tar xf ${package}_${version}.orig.tar.${orig}
	if [ ! "x${deb_patch}" = "x" ] ; then
		cd ./${package}-${version}
		zcat ../${package}_${debian_version}.diff.gz | patch -p1
	else
		cd ./${package}_${version}
	fi

	cp -rv ../../debian/${dist}/* ./
	debuild -us -uc -S

	cd ../../
}

sfile () {
	if [ -f ${package}_${version}.orig.tar.gz ] ; then
		orig="gz"
		generate_dsc
	elif [ -f ${package}_${version}.orig.tar.xz ] ; then
		orig="xz"
		generate_dsc
	fi
}

dist="wheezy"
sfile

dist="jessie"
sfile

