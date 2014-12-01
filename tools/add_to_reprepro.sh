#!/bin/bash -e

. version.sh

base="/var/www/html/repos.rcn-ee.net/"
outgoing="/var/www/html/farm/outgoing"

run () {
	wfile="${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${suite} ${wfile}
		fi
	fi

	wfile="${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${package_name}_${package_version}${rcn_ee_version}_${deb_arch}.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${package_name}_${package_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${suite} ${wfile}
		fi
	fi

	if [ "x${archive}" = "xenable" ] ; then
		mkdir -p ${base}archive/${debian_pkg_name}/${suite}/${package_version}/
		cp -v ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.deb ${base}archive/${debian_pkg_name}/${suite}/${package_version}/
	fi
}

dist="debian"
suite="wheezy"
if [ -d ${dist}/${suite}/ ] ; then
	repo="${base}${dist}/"
	deb_arch=armhf
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="debian"
suite="jessie"
if [ -d ${dist}/${suite}/ ] ; then
	repo="${base}${dist}/"
	deb_arch=armhf
	rcn_ee_version="${jessie_version}"
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d ${dist}/${suite}/ ] ; then
	repo="${base}${dist}/"
	deb_arch=armhf
	rcn_ee_version="${trusty_version}"
	run
fi

