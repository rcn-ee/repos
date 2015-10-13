#!/bin/bash -e

. version.sh

server="https://storage.googleapis.com/dart-archive/channels/stable/release"

wget -c ${server}/${package_version}/linux_packages/debian_wheezy/dart_${package_version}.orig.tar.gz
wget -c ${server}/${package_version}/linux_packages/debian_wheezy/dart_${debian_version}.debian.tar.gz

