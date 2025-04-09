#!/bin/bash -e

. version.sh

base="/var/www/html/repos/"
outgoing="/var/www/html/farm/outgoing"

run () {
	changes_file=$(ls ${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/ | grep changes | grep -v source)

	if [ ! "x${changes_file}" = "x" ] ; then
		if [ -f ${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${changes_file} ] ; then
			wfile="${outgoing}/${suite}/${deb_arch}/${debian_pkg_name}_${debian_version}/${changes_file}"
			reprepro -b ${repo} -C main include ${suite} ${wfile}
		fi
	fi
}

runner () {
	repo="${base}${dist}/"
	if [ -d ./suite/${suite}/ ] ; then
		echo ${suite}
		run
	fi
}

start_run () {
	dist="debian"
	deb_arch="armhf"
	suite="bullseye" ; runner
	suite="bookworm" ; runner
	suite="trixie" ; runner
	suite="noble" ; runner

	dist="ubuntu"
	suite="noble" ; runner
}

if [ ! -f /tmp/cron.lock ] ; then
	start_run
else
	echo "reprepro running"
fi
#
