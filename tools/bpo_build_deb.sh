#!/bin/bash -e

. version.sh

build_package () {
	out_dir="/mnt/farm/outgoing/${dist}/${archive}_${debian_version}"
	if [ -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		if [ -d ./${dist} ] ; then
			rm -rf ./${dist}/
		fi

		mkdir ./${dist}
		cd ./${dist}
		sbuild -d ${dist} http://httphost/farm/incoming/${dist}/${archive}_${debian_version}${bpo}.dsc

		if [ -f ${archive}_${debian_version}${bpo}_armhf.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${archive}_${debian_version}${bpo}_armhf.changes ${out_dir}/
			cp -v *.deb ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v ${deb_source} ${out_dir}/ || true
			cp -v *.tar.* ${out_dir}/ || true
			cp -v *.diff.* ${out_dir}/ || true
		fi
		cd ../
	fi
}

dist="wheezy"
bpo="${wheezy_backport}"
build_package

