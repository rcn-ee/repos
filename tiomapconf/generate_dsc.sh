#!/bin/bash -e

. version.sh

if [ -f ${package}_${version}.orig.tar.gz ] ; then
	tar xf ${package}_${version}.orig.tar.gz
	cd ./${package}_${version}
	mkdir debian
	cp -rv ../debian/ ./debian
	debuild -us -uc -S
fi

