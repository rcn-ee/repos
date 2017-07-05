#!/bin/bash -e

. version.sh

server="http://sigrok.org/download/source"

if [ ! -f ${package_name}-${package_version}.tar.gz ] ; then
	wget -c ${server}/${package_name}/${package_name}-${package_version}.tar.gz
fi

if [ ! -f ${package_name}_${package_version}.orig.tar.gz ] ; then
	cp ${package_name}-${package_version}.tar.gz ${package_name}_${package_version}.orig.tar.gz
fi

