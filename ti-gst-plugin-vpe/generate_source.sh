#!/bin/bash -e

. version.sh

mkdir -p ./${package_name}_${package_version}

cd ./${package_name}_${package_version}
git clone ${git_repo} .
git checkout ${git_sha}
git clone git://anongit.freedesktop.org/gstreamer/common
cd ..
tar -cJf ${package_name}_${package_version}.orig.tar.xz ./${package_name}_${package_version}

