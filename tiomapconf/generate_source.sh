#!/bin/bash -e

. version.sh

git clone ${git_repo} ${package}
if [ -f ./${package}/.git/config ] ; then
	cd ./${package}/
	git archive --format=tar --prefix=${package}_${version}/ HEAD | gzip > ../${package}_${version}.orig.tar.gz
	cd ../
	rm -rf ./${package}/
fi
