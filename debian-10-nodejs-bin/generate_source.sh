#!/bin/bash

arch="armv7l"
#arch="x64"

. version.sh

wget -c https://nodejs.org/dist/v${package_version}/node-v${package_version}.tar.gz
wget -c https://nodejs.org/dist/v${package_version}/node-v${package_version}-linux-${arch}.tar.xz

if [ -d ./nodejs_${package_version} ] ; then
	rm -rf ./nodejs_${package_version} || true
fi

mkdir nodejs_${package_version}
mkdir nodejs_${package_version}/built/
mkdir nodejs_${package_version}/src/

tar xf node-v${package_version}-linux-${arch}.tar.xz -C ./nodejs_${package_version}/built/
mv nodejs_${package_version}/built/node-v${package_version}-linux-${arch}/* nodejs_${package_version}/built/
rm -rf nodejs_${package_version}/built/node-v${package_version}-linux-${arch}/ || true

tar xf node-v${package_version}.tar.gz -C ./nodejs_${package_version}/src/
mv nodejs_${package_version}/src/node-v${package_version}/* nodejs_${package_version}/src/
rm -rf nodejs_${package_version}/src/node-v${package_version}/ || true

cd ./nodejs_${package_version}/
tar cJf ../nodejs_${package_version}.orig.tar.xz ./*
cd ../
rm -rf ./nodejs_${package_version} || true

#wget  -c http://deb.nodesource.com/node_8.x/pool/main/n/nodejs/nodejs_8.9.1-1nodesource1_amd64.deb
