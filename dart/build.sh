#!/bin/bash -e

if [ ! -d ~/bin/depot_tools/ ] ; then
	mkdir ~/bin/
	cd ~/bin/
	svn co http://src.chromium.org/svn/trunk/tools/depot_tools
fi

mkdir -p ~/dart
cd ~/dart/
svn ls https://dart.googlecode.com/svn/branches/bleeding_edge/

mkdir dart-repo
cd dart-repo
~/bin/depot_tools/gclient config https://dart.googlecode.com/svn/branches/bleeding_edge/deps/all.deps
git svn clone -rHEAD https://dart.googlecode.com/svn/branches/bleeding_edge/dart dart
~/bin/depot_tools/gclient sync -n
~/bin/depot_tools/gclient runhooks

cd ./dart/

#build
./tools/build.py -m release --arch arm runtime

#
