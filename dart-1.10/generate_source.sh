#!/bin/bash -e

. version.sh

if [ ! -f /usr/bin/svn ] ; then
	sudo apt-get update ; sudo apt-get install -y subversion git-svn
fi

if [ ! -d ./ignore/ ] ; then
	mkdir ./ignore/
	cd ./ignore/
	git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
	export PATH=$PATH:`pwd`//depot_tools

	mkdir ./dart-repo
	cd ./dart-repo
	gclient config https://github.com/dart-lang/sdk.git
	gclient sync --with_branch_heads --jobs 16

#	cd sdk
#	git checkout 1.10.1 -b tmp

#	mkdir out
#	./tools/create_tarball.py
#	cp -v ./out/dart-*.tar.gz ../../../../
fi

