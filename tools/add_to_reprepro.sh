#!/bin/bash -ex

. version.sh

repo="/var/www/html/repos.rcn-ee.net/debian/"
outgoing="/var/www/html/farm/outgoing"

add_to_reprepro () {
	wfile="${outgoing}/${dist}/${archive}_${debian_version}/${archive}_${debian_version}${bpo}_armhf.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${archive}_${debian_version}${bpo}_armhf.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	bpo="${wheezy_version}"
	add_to_reprepro
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	bpo="${jessie_version}"
	add_to_reprepro
fi

