#!/bin/bash -e

. version.sh

if [ ! "x${git_repo}" = "x" ] ; then
	git clone ${git_repo} ignore
	if [ -f ./ignore/.git/config ] ; then
		cd ./ignore/
		git archive --format=tar --prefix=${package_name}_${package_version}/ HEAD | xz > ../${package_name}_${package_version}.orig.tar.xz
		cd ../
		rm -rf ./ignore/
	fi
else
	if [ ! "x${package_source}" = "x" ] ; then
		wget -c ${dl_path}${package_source}
		if [ ! "x${debian_patch}" = "x" ] ; then
			wget -c ${dl_path}${debian_patch}
		fi
		if [ ! "x${debian_untar}" = "x" ] ; then
			wget -c ${dl_path}${debian_untar}
		fi
	fi
fi

