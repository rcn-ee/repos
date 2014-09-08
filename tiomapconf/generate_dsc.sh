#!/bin/bash -e

. version.sh

if [ -f ${package}_${version}.orig.tar.gz ] ; then
	tar xf ${package}_${version}.orig.tar.gz
	cd ./${package}_${version}
	cp -rv ../debian/ ./
	debuild -us -uc -S
fi

