#!/bin/bash -e

. version.sh

wget -c ${dl_path}/${package_name}-${package_version}.tar.xz

if [ ! -f ${debian_pkg_name}_${package_version}.orig.tar.xz ] ; then
	if [ -f ${package_name}-${package_version}.tar.xz ] ; then
		cp -v ${package_name}-${package_version}.tar.xz ${debian_pkg_name}_${package_version}.orig.tar.xz
	fi
fi
