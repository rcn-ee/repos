#!/bin/bash -e

. version.sh

base="/var/www/html/repos.rcn-ee.net/"
outgoing="/var/www/html/farm/outgoing"

run () {
	changes_file=$(ls ${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/ | grep changes)

	if [ ! "x${changes_file}" = "x" ] ; then
		if [ -f ${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${changes_file} ] ; then
			wfile="${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${changes_file}"
			reprepro -b ${repo} -C main include ${suite} ${wfile}
		fi
	fi
}

dist="debian"
suite="stretch"
if [ -d suite/${suite}/ ] ; then
	repo="${base}${dist}-exp/"
	deb_arch="armhf"
	rcn_ee_version="${jessie_version}"
	run
fi
#
