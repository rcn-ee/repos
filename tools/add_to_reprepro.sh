#!/bin/bash -e

. version.sh

repo="/var/www/html/repos.rcn-ee.net/debian/"
outgoing="/var/www/html/farm/outgoing"

run () {

	if [ ! -f ${repo}pool/main/${reprepro_dir}/${package_source} ] ; then
		mkdir -p ${repo}pool/main/${reprepro_dir}/
		cp -v ${outgoing}/${dist}/${debian_pkg_name}_${debian_version}/${package_source} ${repo}pool/main/${reprepro_dir}/
	fi

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

