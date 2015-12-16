#!/bin/bash -e

. version.sh

if [ -d ./${package_name}_${package_version} ] ; then
	rm -rf ./${package_name}_${package_version} || true
fi

mkdir -p ./${package_name}_${package_version}

cd ./${package_name}_${package_version}
git clone ${git_repo} .
git checkout ${git_sha}
./autogen.sh
cd ..
tar -cJf ${package_name}_${package_version}.orig.tar.xz ./${package_name}_${package_version}

