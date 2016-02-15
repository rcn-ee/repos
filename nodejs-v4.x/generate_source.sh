#!/bin/bash -e

. version.sh

server="https://nodejs.org/dist"

if [ ! -f ${package_name}_${package_version}.orig.tar.xz ] ; then
	wget -c ${server}/v${package_version}/node-v${package_version}.tar.xz || true
	cp node-v${package_version}.tar.xz ${package_name}_${package_version}.orig.tar.xz
fi

if [ -f node-v${package_version}.tar.xz ] ; then
	rm node-v${package_version}.tar.xz
fi

