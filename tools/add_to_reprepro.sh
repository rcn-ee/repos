#!/bin/bash -e

. version.sh

base="/var/www/html/repos.rcn-ee.net/"
repo="${base}debian/"
outgoing="/var/www/html/farm/outgoing"

run () {

	wfile="${outgoing}/${dist}/${debian_pkg_name}_${debian_version}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_armhf.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi

	wfile="${outgoing}/${dist}/${debian_pkg_name}_${debian_version}/${package_name}_${package_version}${rcn_ee_version}_armhf.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${package_name}_${package_version}${rcn_ee_version}*.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi

	if [ "x${archive}" = "xenable" ] ; then
		mkdir -p ${base}archive/${debian_pkg_name}/${dist}/${package_version}/
		cp -v ${repo}pool/main/${reprepro_dir}/${debian_pkg_name}_${debian_version}${rcn_ee_version}_armhf.deb ${base}archive/${debian_pkg_name}/${dist}/${package_version}/
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

