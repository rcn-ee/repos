#!/bin/bash -e

. version.sh

sudo mount -a

localdir="/mnt/farm"
builder=`cat /etc/hostname`

build () {
	if [ "x${sbuild_chroot}" = "x" ] ; then
		options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite} --no-run-lintian"
	else
		options="--arch=${deb_arch} -A -s --force-orig-source --dist=${suite} --chroot=${suite}-${deb_arch}-${sbuild_chroot}-sbuild --no-run-lintian"
	fi

	echo "-----------------"
	echo "sbuild ${options} ${mirror}/${dl_path}${package_name}_${debian_version}.dsc"
	echo "-----------------"
	sudo sbuild ${options} ${mirror}/${dl_path}${package_name}_${debian_version}.dsc

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
	fi
}

cleanup_suite () {
	if [ -d ./${suite} ] ; then
		sudo rm -rf ./${suite}/
	fi
}

run () {
	touch /tmp/sbuild-BUILDING.lock
	out_dir="${localdir}/outgoing/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}"
	if [ -f /var/lib/sbuild/${suite}-${deb_arch}.tar.gz ] ; then

		cleanup_suite

		mkdir ./${suite}
		cd ./${suite}

		build

		cd ../
	fi
	rm -f /tmp/sbuild-BUILDING.lock || true
}

if [ ! "x${dist}" = "x" ] ; then
	if [ ! "x${suite}" = "x" ] ; then
		if [ ! "x${deb_arch}" = "x" ] ; then
			run
		else
			echo "no deb_arch"
			exit 2
		fi
	else
		echo "no suite"
		exit 2
	fi
else
	echo "no dist"
	exit 2
fi

