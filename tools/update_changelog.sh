#!/bin/bash -e

. version.sh

DIR="$PWD"

run () {
	wfile="${DIR}/suite/${suite}/debian/new"

	if [ "x${debian_version}" = "x" ] ; then
		echo "${debian_pkg_name} (${package_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
	else
		echo "${debian_pkg_name} (${debian_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
	fi
	echo "" >> ${wfile}
	echo "  * Rebuild for repos.rcn-ee.com" >> ${wfile}
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
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="jessie"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${jessie_version}"
	cat ${DIR}/version.sh | grep -v jessie_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="stretch"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${stretch_version}"
	cat ${DIR}/version.sh | grep -v stretch_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${trusty_version}"
	cat ${DIR}/version.sh | grep -v trusty_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="xenial"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${xenial_version}"
	cat ${DIR}/version.sh | grep -v xenial_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="yakkety"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${yakkety_version}"
	cat ${DIR}/version.sh | grep -v yakkety_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="zesty"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${zesty_version}"
	cat ${DIR}/version.sh | grep -v zesty_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="artful"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${artful_version}"
	cat ${DIR}/version.sh | grep -v artful_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

#
