#!/bin/bash -e

. version.sh

build_package () {
	out_dir="/mnt/farm/outgoing/${dist}/${package}_${debian_version}"
	if [ -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		mkdir ./${dist}
		cd ./${dist}
		sbuild -d ${dist} http://httphost/farm/incoming/${dist}/${package}_${debian_version}.dsc

		if [ -f ${package}_${debian_version}_armhf.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${package}_${debian_version}_armhf.changes ${out_dir}/

			if [ -f ${package}_${version}.orig.tar.xz ] ; then
				cp -v ${package}_${version}.orig.tar.xz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}.debian.tar.gz ] ; then
				cp -v ${package}_${debian_version}.debian.tar.gz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}.debian.tar.xz ] ; then
				cp -v ${package}_${debian_version}.debian.tar.xz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}_armhf.deb ] ; then
				cp -v ${package}_${debian_version}_armhf.deb ${out_dir}/
			fi
		fi
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

