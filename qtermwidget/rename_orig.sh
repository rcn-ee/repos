#!/bin/bash

. version.sh

if [ -f ${dl_package_source} ] ; then
	mv ${dl_package_source} ${package_source}
fi
