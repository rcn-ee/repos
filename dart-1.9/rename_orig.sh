#!/bin/bash

. version.sh

if [ -f ${src_dir}.tar.gz ] ; then
	mv ${src_dir}.tar.gz ${package_source}
fi
