#!/bin/bash -e

. version.sh

if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
	wget https://github.com/beagleboard/bone101/archive/${package_version}.tar.gz
	mv ${package_version}.tar.gz ${package_name}_${package_version}.orig.tar.gz
fi

