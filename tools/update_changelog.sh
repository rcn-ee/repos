#!/bin/bash -e

. version.sh

DIR="$PWD"

run () {
	wfile="${DIR}/suite/${suite}/debian/new"
	backport=""
	if [ "x${suite}" = "xwheezy" ] ; then
		backport="bpo70+"
	fi
	if [ "x${suite}" = "xjessie" ] ; then
		backport="bpo80+"
	fi

	if [ "x${debian_version}" = "x" ] ; then
		echo "${debian_pkg_name} (${package_version}~${backport}${simple_date}+1) ${suite}; urgency=low" > ${wfile}
	else
		echo "${debian_pkg_name} (${debian_version}~${backport}${simple_date}+1) ${suite}; urgency=low" > ${wfile}
	fi
	echo "" >> ${wfile}
	echo "  * Rebuild for repos.rcn-ee.net" >> ${wfile}
	echo "" >> ${wfile}
	echo " -- Robert Nelson <robertcnelson@gmail.com>  ${new_date}" >> ${wfile}
	echo "" >> ${wfile}

	cat ${DIR}/suite/${suite}/debian/changelog >> ${wfile}
	rm ${DIR}/suite/${suite}/debian/changelog
	mv ${wfile} ${DIR}/suite/${suite}/debian/changelog
}

new_date=`LANG=C date -R`
simple_date=`LANG=C date +%Y%m%d`

dist="debian"
suite="wheezy"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${wheezy_version}"
	cat ${DIR}/version.sh | grep -v wheezy_version > ${DIR}/new-version.sh
	echo "wheezy_version=\"~bpo70+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="debian"
suite="jessie"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${jessie_version}"
	cat ${DIR}/version.sh | grep -v jessie_version > ${DIR}/new-version.sh
	echo "jessie_version=\"~bpo80+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${trusty_version}"
	cat ${DIR}/version.sh | grep -v trusty_version > ${DIR}/new-version.sh
	echo "trusty_version=\"~${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi
