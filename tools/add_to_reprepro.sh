#!/bin/bash -ex

. version.sh

repo="/var/www/html/repos.rcn-ee.net/debian/"
outgoing="/var/www/html/farm/outgoing"

add_to_reprepro () {
	wfile="${outgoing}/${dist}/${package}_${debian_version}/${package}_${debian_version}${bpo}_armhf.changes"
	if [ ! -f ${repo}pool/main/${reprepro_dir}/${package}_${debian_version}${bpo}_armhf.deb ] ; then
		if [ -f ${wfile} ] ; then
			reprepro -b ${repo} -C main include ${dist} ${wfile}
		fi
	fi
}

dist="wheezy"
bpo="${wheezy_backport}"
add_to_reprepro

dist="jessie"
bpo=""
add_to_reprepro
