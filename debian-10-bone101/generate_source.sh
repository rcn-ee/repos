#!/bin/bash -e

. version.sh

if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
	wget -c http://repos.rcn-ee.net/debian/pool/main/b/bone101/${package_name}_${package_version}.orig.tar.gz || true
fi

if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
	wget https://github.com/jadonk/bone101/archive/${package_version}.tar.gz
	mv ${package_version}.tar.gz ${package_name}_${package_version}.orig.tar.gz
fi

git clone --bare https://github.com/beagleboard/cloud9-examples
tar cvf ./suite/buster/debian/cloud9-examples.git.tar cloud9-examples.git/
