#!/bin/bash -e

. version.sh

localdir="/mnt/farm"
builder=`cat /etc/hostname`

build () {
	if [ -f ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file} ] ; then
		echo "-----------------"
		echo "sbuild ${options} http://httphost/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file}"
		echo "-----------------"
		sudo sbuild ${options} http://httphost/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}/${dsc_file}

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

cleanup_suite () {
	if [ -d ./${suite} ] ; then
		sudo rm -rf ./${suite}/
	fi
}

run () {
	touch /tmp/sbuild-BUILDING.lock
	out_dir="${localdir}/outgoing/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/"
	if [ -f /var/lib/sbuild/${suite}-${deb_arch}.tar.gz ] ; then

		if [ ! -f ./${suite}/PKG_BUILT ] ; then
			cleanup_suite

			mkdir ./${suite}
			cd ./${suite}

			dsc_file=$(ls ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}/ | grep dsc)
			if [ "x${sbuild_chroot}" = "x" ] ; then
				options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite}"
			else
				options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite} --chroot=${suite}-${deb_arch}-${sbuild_chroot}-sbuild"
			fi

			if [ ! "x${dsc_file}" = "x" ] ; then
				build
			fi

			cd ../
		fi
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
	suite="jessie" ; runner
	suite="stretch" ; runner
	suite="buster" ; runner
	suite="xenial" ; runner
	suite="artful" ; runner
	suite="bionic" ; runner
}

cleanup () {
	suite="jessie" ; cleanup_suite
	suite="stretch" ; cleanup_suite
	suite="buster" ; cleanup_suite
	suite="xenial" ; cleanup_suite
	suite="artful" ; cleanup_suite
	suite="bionic" ; cleanup_suite
}

start_run
cleanup
#
