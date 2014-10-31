#!/bin/bash -e

. version.sh

run () {
	if [ ! -d /mnt/farm/incoming/${dist}/ ] ; then
		mkdir -p /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${package_source} ] ; then
		cp -v ${dist}/${package_source} /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc ] ; then
		cp -v ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${package_name}_${package_version}${rcn_ee_version}.dsc ] ; then
		cp -v ${dist}/${package_name}_${package_version}${rcn_ee_version}.dsc /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.xz ] ; then
		cp -v ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.xz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.gz ] ; then
		cp -v ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.gz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.tar.gz ] ; then
		cp -v ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.tar.gz /mnt/farm/incoming/${dist}/
	elif [ -f ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.diff.gz ] ; then
		cp -v ${dist}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.diff.gz /mnt/farm/incoming/${dist}/
	fi

	if [ -f ${dist}/${package_name}_${package_version}${rcn_ee_version}.tar.xz ] ; then
		cp -v ${dist}/${package_name}_${package_version}${rcn_ee_version}.tar.xz /mnt/farm/incoming/${dist}/
	fi
}

dist="wheezy"
if [ -d debian/${dist}/ ] ; then
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="jessie"
if [ -d debian/${dist}/ ] ; then
	rcn_ee_version="${jessie_version}"
	run
fi

