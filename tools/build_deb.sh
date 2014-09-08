#!/bin/bash -e

. version.sh

build_package () {
	out_dir="/mnt/farm/outgoing/${dist}/${package}_${debian_version}"
	if [ -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		if [ -d ./${dist} ] ; then
			rm -rf ./${dist}/
		fi

		mkdir ./${dist}
		cd ./${dist}
		sbuild -d ${dist} http://httphost/farm/incoming/${dist}/${package}_${debian_version}${bpo}.dsc

		if [ -f ${package}_${debian_version}_armhf.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${package}_${debian_version}_armhf.changes ${out_dir}/

			if [ -f ${package}_${version}.orig.tar.xz ] ; then
				cp -v ${package}_${version}.orig.tar.xz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}${bpo}.dsc ] ; then
				cp -v ${package}_${debian_version}${bpo}.dsc ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}${bpo}.debian.tar.gz ] ; then
				cp -v ${package}_${debian_version}${bpo}.debian.tar.gz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}${bpo}.debian.tar.xz ] ; then
				cp -v ${package}_${debian_version}${bpo}.debian.tar.xz ${out_dir}/
			fi

			if [ -f ${package}_${debian_version}_armhf.deb ] ; then
				cp -v ${package}_${debian_version}_armhf.deb ${out_dir}/
			fi
		fi
		cd ../
	fi
}

dist="wheezy"
bpo="~bpo70+1"
build_package

#dist="jessie"
#bpo=""
#build_package

