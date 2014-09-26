#!/bin/bash

. version.sh

if [ -f ${package_name}-${package_version}.tar.gz ] ; then
	mv ${package_name}-${package_version}.tar.gz ${package_source}
fi
