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
	git checkout Copter-3.5
	git submodule update --init --recursive
	cd ../
	tar cfJ ../${package_name}_${package_version}.orig.tar.xz ./*
	cd ../
	rm -rf ./ignore/
fi
