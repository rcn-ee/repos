#!/bin/bash -e

. version.sh

repo="/var/www/html/repos.rcn-ee.net/debian/"
outgoing="/var/www/html/farm/outgoing"

add_to_reprepro () {
	if [ -f ${outgoing}/${dist}/${package}_${debian_version}_armhf.changes ] ; then
		reprepro -b ${repo} -C main include ${dist} ${outgoing}/${dist}/${package}_${debian_version}_armhf.changes
	fi
}

dist="jessie"
