#!/bin/bash -e

. version.sh

localdir="/mnt/farm"

run () {
	touch /tmp/sbuild-BUILDING.lock
	out_dir="${localdir}/outgoing/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/"
	if [ -f /var/lib/sbuild/${suite}-${deb_arch}.tar.gz ] ; then
		if [ -d ./${suite} ] ; then
			rm -rf ./${suite}/
		fi

		mkdir ./${suite}
		cd ./${suite}

		dsc_file=$(ls ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/ | grep dsc)
		options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite}"

		if [ ! "x${dsc_file}" = "x" ] ; then
			if [ -f ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file} ] ; then
				sbuild ${options} http://httphost/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file}

				if [ -f *.changes ] ; then
					if [ -d ${out_dir} ] ; then
						rm -rf ${out_dir}
					fi
					mkdir -p ${out_dir}
					cp -v *orig* ${out_dir} || true
					cp -v *debian* ${out_dir} || true
					cp -v *tar* ${out_dir} || true
					cp -v *.changes ${out_dir} || true
					cp -v *.deb ${out_dir} || true
					cp -v *.dsc ${out_dir} || true
					cp -v *.udeb ${out_dir} || true
					cp -v *.diff.gz ${out_dir} || true
					cp -v *.buildinfo ${out_dir} || true
					cp -v *${deb_arch}.build ${out_dir} || true
				fi
			fi
		fi

		cd ../
	fi
	rm -f /tmp/sbuild-BUILDING.lock || true
}

dist="debian"
suite="stretch"
if [ -d suite/${suite}/ ] ; then
	deb_arch="armhf"
	run
fi
#
