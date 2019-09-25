#!/bin/bash -e

. version.sh

localdir="/mnt/farm"
builder=`cat /etc/hostname`

build () {
	if [ -f ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file} ] ; then
		if [ -f *.changes ] ; then
			sudo chown -R 1000:1000 ./*
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
			touch ./PKG_BUILT
		fi
	fi
}

run () {
	touch /tmp/sbuild-BUILDING.lock
	out_dir="${localdir}/outgoing/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/"
	if [ -f /var/lib/sbuild/${suite}-${deb_arch}.tar.gz ] ; then

		cd ./${suite}

		dsc_file=$(ls ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/ | grep dsc)

		if [ ! "x${dsc_file}" = "x" ] ; then
			build
		fi

		cd ../
	fi
	rm -f /tmp/sbuild-BUILDING.lock || true
}

runner () {
	if [ -d ./suite/${suite}/ ] ; then
		run
	fi
}

start_run () {
	deb_arch="armhf"
	suite="stretch" ; runner
	suite="buster" ; runner
	suite="bullseye" ; runner

	suite="xenial" ; runner
	suite="bionic" ; runner
}

start_run
#
