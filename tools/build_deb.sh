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

		if [ -f ${localdir}/incoming/${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc ] ; then
			sbuild --arch=${deb_arch} -A -s --force-orig-source -d ${suite} http://httphost/farm/incoming/${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc
		elif [ -f ${localdir}/incoming/${suite}/${package_name}_${package_version}${rcn_ee_version}.dsc ] ; then
			sbuild --arch=${deb_arch} -A -s --force-orig-source -d ${suite} http://httphost/farm/incoming/${suite}/${package_name}_${package_version}${rcn_ee_version}.dsc
		fi

		if [ -f ${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.changes ${out_dir}/
			cp -v *.deb ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v ${package_source} ${out_dir}/ || true
			cp -v *.tar.* ${out_dir}/ || true
			cp -v *.diff.* ${out_dir}/ || true
		fi

		if [ -f ${package_name}_${package_version}${rcn_ee_version}_${deb_arch}.changes ] ; then
			mkdir -p ${out_dir}/
			cp -v ${package_name}_${package_version}${rcn_ee_version}_${deb_arch}.changes ${out_dir}/
			cp -v *.deb ${out_dir}/ || true
			cp -v *.udeb ${out_dir}/ || true
			cp -v *.dsc ${out_dir}/ || true
			cp -v ../${package_source} ${out_dir}/ || true
			cp -v ${package_source} ${out_dir}/ || true
			cp -v *.tar.* ${out_dir}/ || true
			cp -v *.diff.* ${out_dir}/ || true
		fi

		cd ../
	fi
}

dist="debian"
suite="wheezy"
if [ -d suite/${suite}/ ] ; then
	deb_arch="armhf"
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="debian"
suite="jessie"
if [ -d suite/${suite}/ ] ; then
	deb_arch="armhf"
	rcn_ee_version="${jessie_version}"
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d suite/${suite}/ ] ; then
	deb_arch="armhf"
	rcn_ee_version="${trusty_version}"
	run
fi

