#!/bin/bash -e

. version.sh

incoming_mirror="http://incoming.debian.org/debian-buildd/"

if [ ! "x${git_repo}" = "x" ] ; then
	if [ -f ./git/.git/config ] ; then
		git clone --reference ./git/ ${git_repo} ignore
	else
		git clone ${git_repo} ignore
	fi
	if [ -f ./ignore/.git/config ] ; then
		cd ./ignore/
		git archive --format=tar --prefix=${package_name}_${package_version}/ ${git_sha} | xz > ../${package_name}_${package_version}.orig.tar.xz
		cd ../
		rm -rf ./ignore/
	fi
else
	if [ ! "x${package_source}" = "x" ] ; then
		wget -c ${mirror}/${dl_path}${package_source}
		if [ ! "x${debian_patch}" = "x" ] ; then
			wget -c ${mirror}/${dl_path}${debian_patch} || true
		fi
		if [ ! "x${debian_patch}" = "x" ] ; then
			wget -c ${incoming_mirror}/${dl_path}${debian_patch}
		fi

		if [ ! "x${debian_untar}" = "x" ] ; then
			wget -c  ${mirror}/${dl_path}${debian_untar} || true
		fi
		if [ ! "x${debian_untar}" = "x" ] ; then
			wget -c ${incoming_mirror}/${dl_path}${debian_untar}
		fi
	fi
fi

