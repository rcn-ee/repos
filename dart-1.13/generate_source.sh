#!/bin/bash -e

. version.sh

#server="https://storage.googleapis.com/dart-archive/channels/stable/release"
server="https://gsdview.appspot.com/dart-archive/channels/dev/release"
#1.13.0-dev.7.9/linux_packages/debian_wheezy/dart_1.13.0-dev.7.9.orig.tar.gz

wget -c ${server}/${package_version}/linux_packages/debian_wheezy/dart_${package_version}.orig.tar.gz
cp dart_${package_version}.orig.tar.gz ${package_name}_${package_version}.orig.tar.gz
wget -c ${server}/${package_version}/linux_packages/debian_wheezy/dart_${debian_version}.debian.tar.gz

