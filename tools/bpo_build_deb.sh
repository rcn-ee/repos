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

		if [ -f ${package}_${debian_version}${bpo}_armhf.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${package}_${debian_version}${bpo}_armhf.changes ${out_dir}/
			cp -v *.deb ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v *.tar.gz ${out_dir}/ || true
			cp -v *.tar.xz ${out_dir}/ || true
			cp -v *.diff.gz ${out_dir}/ || true
		fi
		cd ../
	fi
}

dist="wheezy"
bpo="${wheezy_backport}"
build_package

