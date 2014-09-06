#!/bin/bash -e

mkdir ~/bin/
cd ~/bin/
svn co http://src.chromium.org/svn/trunk/tools/depot_tools

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

#patch:
sed -i -e 's:create_sdk:runtime:g' ./tools/linux_dist_support/debian/rules
sed -i -e 's:_TYPE)/dart-sdk:_TYPE)/dart:g' ./tools/linux_dist_support/debian/rules
sed -i -e 's:mv debian:#mv debian:g' ./tools/linux_dist_support/debian/rules

#build deb:
mkdir out
./tools/create_tarball.py
./tools/create_debian_packages.py --arch armhf

#
