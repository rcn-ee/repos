#!/bin/bash -e

. version.sh

run () {
	out_dir="/mnt/farm/outgoing/${dist}/${debian_pkg_name}_${debian_version}"
	if [ -f /var/lib/sbuild/${dist}-armhf.tar.gz ] ; then
		if [ -d ./${dist} ] ; then
			rm -rf ./${dist}/
		fi

		mkdir ./${dist}
		cd ./${dist}
		sbuild -d ${dist} http://httphost/farm/incoming/${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc

		if [ -f ${debian_pkg_name}_${debian_version}${rcn_ee_version}_armhf.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${debian_pkg_name}_${debian_version}${rcn_ee_version}_armhf.changes ${out_dir}/
			cp -v *.deb ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v ${package_source} ${out_dir}/ || true
			cp -v *.tar.* ${out_dir}/ || true
			cp -v *.diff.* ${out_dir}/ || true
		fi
		cd ../
	fi
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	rcn_ee_version="${jessie_version}"
	run
fi

