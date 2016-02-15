#!/bin/bash -e

. version.sh

if [ -f ./git/.git/config ] ; then
	git clone --reference ./git/ ${git_repo} ignore
else
	git clone ${git_repo} ./git/
	git clone --reference ./git/ ${git_repo} ignore
fi
if [ -f ./ignore/.git/config ] ; then
	cd ./ignore/
	./create_debian_src.sh
	cp -v ti-llvm-3.3-3.3.tar.gz ../${package_name}_${package_version}.orig.tar.xz
	#rm -rf ./ignore/
fi


