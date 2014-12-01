#!/bin/bash -e

. version.sh

base="/var/www/html/repos.rcn-ee.net/"
outgoing="/var/www/html/farm/outgoing"

run () {

	wfile="${outgoing}/${dist}/${deb_arch}/${debian_pkg_name}_${debian_version}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi

	wfile="${outgoing}/${dist}/${deb_arch}/${debian_pkg_name}_${debian_version}/${package_name}_${package_version}${rcn_ee_version}_${deb_arch}.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${package_name}_${package_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi

	if [ "x${archive}" = "xenable" ] ; then
		mkdir -p ${base}archive/${debian_pkg_name}/${dist}/${package_version}/
		cp -v ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_${deb_arch}.deb ${base}archive/${debian_pkg_name}/${dist}/${package_version}/
	fi

}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	repo="${base}debian/"
	deb_arch=armhf
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	repo="${base}debian/"
	deb_arch=armhf
	rcn_ee_version="${jessie_version}"
	run
fi

dist="trusty"
if [ -d ubuntu/${dist}/ ] ; then
	repo="${base}ubuntu/"
        deb_arch=armhf
        rcn_ee_version="${trusty_version}"
        run
fi

