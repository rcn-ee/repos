#!/bin/bash

dl_src () {
	if [ -d ./src/ ] ; then
		rm -rf ./src/
	fi

	git clone https://git.beagleboard.org/beagleboard/usr-customizations.git ./src/
}


copy_all () {
	cp -v ./src/${wfile} ./suite/buster/debian/
	cp -v ./src/${wfile} ./suite/focal/debian/
	cp -v ./src/${wfile} ./suite/bullseye/debian/
}

dl_src

wfile="arm32/usr/sbin/beagle-version" ; copy_all
