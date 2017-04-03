#!/bin/bash -e

. version.sh

incoming_mirror="http://incoming.debian.org/debian-buildd"

git clone ${git_repo} ignore

if [ -f ./ignore/.git/config ] ; then
	cd ./ignore/
	git checkout Copter-3.5
	git submodule update --init --recursive
	tar cvfJ ../${package_name}_${package_version}.orig.tar.xz ./*
	cd ../
	rm -rf ./ignore/
fi
