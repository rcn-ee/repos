#!/bin/bash -e

. version.sh

generate_dsc () {
	if [ -d ./${dist} ] ; then
		rm -rf ./${dist}/
	fi
	mkdir -p ./${dist}/${package}_${version}

	cp -v ${archive}_${version}.orig.tar.* ./${dist}
	if [ ! "x${deb_patch}" = "x" ] ; then
		cp -v ${deb_patch} ./${dist}
	fi

	cd ./${dist}
	tar xfv ${archive}_${version}.orig.tar.* -C ./${package}_${version}
	if [ ! "x${deb_patch}" = "x" ] ; then
		if [ -d ./${package}_${version} ] ; then
			cd ./${package}_${version}
		fi
		zcat ../${deb_patch} | patch -p1
	else
		if [ -d ./${package}_${version} ] ; then
			cd ./${package}_${version}
		fi
	fi

	if [ ! -d ./debian ] ; then
		mkdir ./debian
	fi

	if [ -d ../../debian/${dist}/ ] ; then
		cp -rv ../../debian/${dist}/* ./
	fi

	debuild -us -uc -S

	cd ../../
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	generate_dsc
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	generate_dsc
fi

