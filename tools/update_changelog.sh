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
	if [ "x${suite}" = "xstretch" ] ; then
		backport="bpo90+"
	fi
	if [ "x${suite}" = "xtrusty" ] ; then
		backport="bpo1404+"
	fi
	if [ "x${suite}" = "xvivid" ] ; then
		backport="bpo1504+"
	fi
	if [ "x${suite}" = "xwily" ] ; then
		backport="bpo1510+"
	fi
	if [ "x${suite}" = "xxenial" ] ; then
		backport="bpo1604+"
	fi

	if [ "x${debian_version}" = "x" ] ; then
		echo "${debian_pkg_name} (${package_version}${local_patch}~${backport}${simple_date}+1) ${suite}; urgency=low" > ${wfile}
	else
		echo "${debian_pkg_name} (${debian_version}${local_patch}~${backport}${simple_date}+1) ${suite}; urgency=low" > ${wfile}
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
	echo "wheezy_version=\"~bpo70+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="jessie"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${jessie_version}"
	cat ${DIR}/version.sh | grep -v jessie_version > ${DIR}/new-version.sh
	echo "jessie_version=\"~bpo80+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="stretch"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${stretch_version}"
	cat ${DIR}/version.sh | grep -v stretch_version > ${DIR}/new-version.sh
	echo "stretch_version=\"~bpo90+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${trusty_version}"
	cat ${DIR}/version.sh | grep -v trusty_version > ${DIR}/new-version.sh
	echo "trusty_version=\"~bpo1404+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="vivid"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${vivid_version}"
	cat ${DIR}/version.sh | grep -v vivid_version > ${DIR}/new-version.sh
	echo "vivid_version=\"~bpo1504+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="wily"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${wily_version}"
	cat ${DIR}/version.sh | grep -v wily_version > ${DIR}/new-version.sh
	echo "wily_version=\"~bpo1510+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

suite="xenial"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${xenial_version}"
	cat ${DIR}/version.sh | grep -v xenial_version > ${DIR}/new-version.sh
	echo "xenial_version=\"~bpo1604+${simple_date}+1\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi
#
