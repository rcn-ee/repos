#!/bin/bash -e

. version.sh

DIR="$PWD"

run () {
	wfile="${DIR}/suite/${suite}/debian/new"

	if [ ! "x${old_debian_version}" = "x" ] ; then
		if [ "x${epoch}" = "x" ] ; then
			echo "${debian_pkg_name} (${old_debian_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
		else
			echo "${debian_pkg_name} (${epoch}:${old_debian_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
		fi
	else
		if [ "x${debian_version}" = "x" ] ; then
			if [ "x${epoch}" = "x" ] ; then
				echo "${debian_pkg_name} (${package_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
			else
				echo "${debian_pkg_name} (${epoch}:${package_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
			fi
		else
			if [ "x${epoch}" = "x" ] ; then
				echo "${debian_pkg_name} (${debian_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
			else
				echo "${debian_pkg_name} (${epoch}:${debian_version}${local_patch}~${suite}+${simple_date}) ${suite}; urgency=low" > ${wfile}
			fi
		fi
	fi
	echo "" >> ${wfile}
	if [  -f ${DIR}/readme.log ] ; then
		cat ${DIR}/readme.log >> ${wfile}
	elif  [  -f ${DIR}/suite/${suite}/readme.log ] ; then
		cat ${DIR}/suite/${suite}/readme.log >> ${wfile}
	else
		echo "  * Rebuild ${debian_pkg_name}_${debian_version} for repos.rcn-ee.com" >> ${wfile}
	fi
	echo "" >> ${wfile}
	echo " -- Robert Nelson <robertcnelson@gmail.com>  ${new_date}" >> ${wfile}
	echo "" >> ${wfile}

	if [ "x${clear_changelog}" = "x" ] ; then
		cat ${DIR}/suite/${suite}/debian/changelog >> ${wfile}
	fi
	rm ${DIR}/suite/${suite}/debian/changelog
	mv ${wfile} ${DIR}/suite/${suite}/debian/changelog
}

new_date=`LANG=C date -R`
simple_date=`LANG=C date +%Y%m%d`

dist="debian"
suite="buster"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${buster_version}"
	cat ${DIR}/version.sh | grep -v buster_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="debian"
suite="bullseye"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${bullseye_version}"
	cat ${DIR}/version.sh | grep -v bullseye_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="debian"
suite="bookworm"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${bookworm_version}"
	cat ${DIR}/version.sh | grep -v bookworm_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="debian"
suite="trixie"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${trixie_version}"
	cat ${DIR}/version.sh | grep -v trixie_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="focal"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${focal_version}"
	cat ${DIR}/version.sh | grep -v focal_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="jammy"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${jammy_version}"
	cat ${DIR}/version.sh | grep -v jammy_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

dist="ubuntu"
suite="noble"
if [ -d ${DIR}/suite/${suite}/ ] ; then
	rcn_ee_version="${jammy_version}"
	cat ${DIR}/version.sh | grep -v noble_version > ${DIR}/new-version.sh
	echo "${suite}_version=\"~${suite}+${simple_date}\"" >> ${DIR}/new-version.sh
	mv ${DIR}/new-version.sh ${DIR}/version.sh
	run
fi

#
