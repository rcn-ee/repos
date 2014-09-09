#!/bin/bash -e

. version.sh

generate_dsc () {
	if [ -d ./${dist} ] ; then
		rm -rf ./${dist}/
	fi
	mkdir ./${dist}

	cp -v ${archive}_${version}.orig.tar.${orig} ./${dist}
	if [ ! "x${deb_patch}" = "x" ] ; then
		cp -v ${deb_patch} ./${dist}
	fi

	cd ./${dist}
	tar xf ${archive}_${version}.orig.tar.${orig}
	if [ ! "x${deb_patch}" = "x" ] ; then
		if [ -d ./${package}-${version} ] ; then
			cd ./${package}-${version}
		fi
		if [ -d ./${package}_${version} ] ; then
			cd ./${package}_${version}
		fi
		zcat ../${deb_patch} | patch -p1
	else
		if [ -d ./${package}-${version} ] ; then
			cd ./${package}-${version}
		fi
		if [ -d ./${package}_${version} ] ; then
			cd ./${package}_${version}
		fi
	fi

	if [ -d ../../debian/${dist}/ ] ; then
		cp -rv ../../debian/${dist}/* ./
	fi

	debuild -us -uc -S

	cd ../../
}

sfile () {
	if [ -f ${archive}_${version}.orig.tar.gz ] ; then
		orig="gz"
		generate_dsc
	elif [ -f ${archive}_${version}.orig.tar.xz ] ; then
		orig="xz"
		generate_dsc
	fi
}

dist="wheezy"
sfile

dist="jessie"
sfile

