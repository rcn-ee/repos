#!/bin/bash -e

. version.sh

sudo apt-get update ; sudo apt-get install -y subversion git-svn

if [ ! -d ./ignore/ ] ; then
	mkdir ./ignore/
	cd ./ignore/
	svn co http://src.chromium.org/svn/trunk/tools/depot_tools

	mkdir -p ./dart
	cd ./dart/
	svn ls https://dart.googlecode.com/svn/branches/bleeding_edge/

	mkdir ./dart-repo
	cd ./dart-repo
	../../depot_tools/gclient config https://dart.googlecode.com/svn/branches/bleeding_edge/deps/all.deps
	git svn clone -rHEAD https://dart.googlecode.com/svn/branches/bleeding_edge/dart dart
	../../depot_tools/gclient sync -n
	../../depot_tools/gclient runhooks
	cd ./dart/

	mkdir out
	./tools/create_tarball.py
	cp -v ./out/dart-*.tar.gz ../../../../
fi

