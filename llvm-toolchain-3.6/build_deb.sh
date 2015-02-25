#!/bin/bash -e

. version.sh

localdir="/mnt/farm"

run () {
	out_dir="${localdir}/outgoing/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}"
	if [ -f /var/lib/sbuild/${suite}-${deb_arch}.tar.gz ] ; then
		if [ -d ./${suite} ] ; then
			rm -rf ./${suite}/
		fi

		mkdir ./${suite}
		cd ./${suite}
			sbuild --arch=${deb_arch} -A -s --force-orig-source -d ${suite} ${mirror}/${dl_path}${package_name}-${debian_version}.dsc

		cd ../
	fi
}

dist="debian"
suite="jessie"
deb_arch="armhf"
run

