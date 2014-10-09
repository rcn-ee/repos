#!/bin/bash -e

. version.sh

if [ ! -f /usr/bin/svn ] ; then
	sudo apt-get update ; sudo apt-get install -y subversion git-svn
fi

if [ ! -d ./ignore/ ] ; then
	mkdir ./ignore/
	cd ./ignore/
	svn co http://src.chromium.org/svn/trunk/tools/depot_tools

	mkdir -p ./dart
	cd ./dart/
	svn ls https://dart.googlecode.com/svn/branches/${repo_branch}/

	mkdir ./dart-repo
	cd ./dart-repo
	../../depot_tools/gclient config https://dart.googlecode.com/svn/branches/${repo_branch}/deps/all.deps
	git svn clone -rHEAD https://dart.googlecode.com/svn/branches/${repo_branch}/dart dart
	../../depot_tools/gclient sync -n
	../../depot_tools/gclient runhooks
	cd ./dart/

	mkdir out
	./tools/create_tarball.py
	cp -v ./out/dart-*.tar.gz ../../../../
fi

