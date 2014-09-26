#!/bin/bash -e

. version.sh

DIR="$PWD"

run () {
	wfile="${DIR}/debian/${dist}/debian/new"
	backport=""
	if [ "x${dist}" = "xwheezy" ] ; then
		backport="bpo70+"
	fi

	if [ "x${debian_version}" = "x" ] ; then
		echo "${debian_pkg_name} (${package_version}~${backport}${simple_date}+1) ${dist}; urgency=low" > ${wfile}
	else
		echo "${debian_pkg_name} (${debian_version}~${backport}${simple_date}+1) ${dist}; urgency=low" > ${wfile}
	fi
	echo "" >> ${wfile}
	echo "  * Rebuild for repos.rcn-ee.net" >> ${wfile}
	echo "" >> ${wfile}
	echo " -- Robert Nelson <robertcnelson@gmail.com>  ${new_date}" >> ${wfile}
	echo "" >> ${wfile}

	cat ${DIR}/debian/${dist}/debian/changelog >> ${wfile}
	rm ${DIR}/debian/${dist}/debian/changelog
	mv ${wfile} ${DIR}/debian/${dist}/debian/changelog
}

new_date=`LANG=C date -R`
simple_date=`LANG=C date +%Y%m%d`

dist="wheezy"
if [ -d ${DIR}/debian/${dist}/ ] ; then
	rcn_ee_version="${wheezy_version}"
	cat ${DIR}/version.sh | grep -v wheezy_version > ${DIR}/new-version.sh
	echo "wheezy_version=\"~bpo70+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="jessie"
if [ -d ${DIR}/debian/${dist}/ ] ; then
	rcn_ee_version="${jessie_version}"
	cat ${DIR}/version.sh | grep -v jessie_version > ${DIR}/new-version.sh
	echo "jessie_version=\"~${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi
