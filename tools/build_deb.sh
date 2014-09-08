#!/bin/bash -e

. version.sh

build_package () {
	if [ -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		mkdir ./${dist}
		cd ./${dist}
		sbuild -d ${dist} http://httphost/farm/incoming/${dist}/${package}_${debian_version}.dsc
		cd ../
	fi
}

dist="wheezy"
build_package

dist="jessie"
build_package

dist="sid"
build_package

dist="trusty"
build_package

dist="utopic"
build_package

