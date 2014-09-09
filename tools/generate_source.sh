#!/bin/bash -e

. version.sh

if [ ! "x${git_repo}" = "x" ] ; then
	git clone ${git_repo} ${package}
	if [ -f ./${package}/.git/config ] ; then
		cd ./${package}/
		git archive --format=tar --prefix=${package}_${version}/ HEAD | xz > ../${package}_${version}.orig.tar.xz
		cd ../
		rm -rf ./${package}/
	fi
fi

if [ ! "x${deb_source}" = "x" ] ; then
	wget -c ${deb_source}
	if [ ! "x${deb_patch}" = "x" ] ; then
		wget -c ${deb_patch}
	fi
fi
