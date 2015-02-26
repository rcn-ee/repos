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

		options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite}"
		sbuild ${options} ${mirror}/${dl_path}${package_name}_${debian_version}.dsc

		if [ -f *.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v *orig* ${out_dir}/ || true
			cp -v *debian* ${out_dir}/ || true
			cp -v *.changes ${out_dir}/ || true
			cp -v *.deb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
		fi

		cd ../
	fi
}

dist="debian"
suite="jessie"
backport="~bpo80"
deb_arch="armhf"
run

