#!/bin/bash -e

. version.sh

incoming_mirror="http://incoming.debian.org/debian-buildd"

if [ -d ./ignore ] ; then
	rm -rf ./ignore || true
fi

mkdir -p ./ignore

git clone ${git_repo} ignore/${package_name}_${package_version}/

if [ -f ./ignore/${package_name}_${package_version}/.git/config ] ; then
	cd ./ignore/${package_name}_${package_version}/
	git checkout ${git_branch}
	git submodule update --init --recursive
	rm -rf modules/PX4NuttX/misc/buildroot/toolchain/gcc/3.3.6/900-sx12-20101109.patch || true
	cd ../
	tar cf ../${package_name}_${package_version}.orig.tar ./*
	cd ../
	if [ -f ${package_name}_${package_version}.orig.tar.xz ] ; then
		rm -rf ${package_name}_${package_version}.orig.tar.xz || true
	fi
	xz -T0 -z -v ${package_name}_${package_version}.orig.tar
	rm -rf ./ignore/
fi
