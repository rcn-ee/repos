#!/bin/bash -e

. version.sh

run () {
	if [ ! -d /mnt/farm/incoming/${suite}/ ] ; then
		mkdir -p /mnt/farm/incoming/${suite}/
	fi

	if [ -f ${suite}/${package_source} ] ; then
		cp -v ${suite}/${package_source} /mnt/farm/incoming/${suite}/
	fi

	if [ -f ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc ] ; then
		cp -v ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.dsc /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${package_name}_${package_version}${rcn_ee_version}.dsc ] ; then
		cp -v ${suite}/${package_name}_${package_version}${rcn_ee_version}.dsc /mnt/farm/incoming/${suite}/
	fi

	if [ -f ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.xz ] ; then
		cp -v ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.xz /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.gz ] ; then
		cp -v ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.debian.tar.gz /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.tar.gz ] ; then
		cp -v ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.tar.gz /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.diff.gz ] ; then
		cp -v ${suite}/${debian_pkg_name}_${debian_version}${rcn_ee_version}.diff.gz /mnt/farm/incoming/${suite}/
	fi

	if [ -f ${suite}/${package_name}_${package_version}${rcn_ee_version}.tar.xz ] ; then
		cp -v ${suite}/${package_name}_${package_version}${rcn_ee_version}.tar.xz /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${package_name}_${package_version}${rcn_ee_version}.tar.bz2 ] ; then
		cp -v ${suite}/${package_name}_${package_version}${rcn_ee_version}.tar.bz2 /mnt/farm/incoming/${suite}/
	elif [ -f ${suite}/${package_name}_${package_version}${rcn_ee_version}.diff.gz ] ; then
		cp -v ${suite}/${package_name}_${package_version}${rcn_ee_version}.diff.gz /mnt/farm/incoming/${suite}/
	fi
}

dist="debian"
suite="wheezy"
if [ -d suite/${suite}/ ] ; then
	rcn_ee_version="${wheezy_version}"
	run
fi

dist="debian"
suite="jessie"
if [ -d suite/${suite}/ ] ; then
	rcn_ee_version="${jessie_version}"
	run
fi

dist="ubuntu"
suite="trusty"
if [ -d suite/${suite}/ ] ; then
	rcn_ee_version="${trusty_version}"
	run
fi

