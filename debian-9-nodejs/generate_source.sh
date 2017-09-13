#!/bin/bash

. version.sh

wget https://nodejs.org/download/release/v${package_version}/node-v${package_version}.tar.gz
mv node-v${package_version}.tar.gz nodejs_${package_version}.orig.tar.gz
