#!/bin/bash -e

. version.sh

generate_dsc () {
	if [ -f ${package}_${version}.orig.tar.xz ] ; then
		if [ -d ./${dist} ] ; then
			rm -rf ./${dist}/
		fi
		mkdir ./${dist}

		cp -v ${package}_${version}.orig.tar.xz ./${dist}

		cd ./${dist}
		tar xf ${package}_${version}.orig.tar.xz

		cd ./${package}_${version}
		cp -rv ../../debian/${dist}/* ./
		debuild -us -uc -S

		cd ../../
	fi
}

dist="wheezy"
generate_dsc

dist="jessie"
generate_dsc

