#!/bin/bash -e

DIR=$PWD

. version.sh

mkdir -p ${DIR}/ignore

if [ -f ${DIR}/ignore/llvm/.git/config ] ; then
	cd ${DIR}/ignore/llvm/
	git pull
	cd ${DIR}
else
	git clone https://github.com/rcn-ee/llvm ${DIR}/ignore/llvm
fi

if [ -f ${DIR}/ignore/clang/.git/config ] ; then
	cd ${DIR}/ignore/clang/
	git pull
	cd ${DIR}
else
	git clone https://github.com/rcn-ee/clang ${DIR}/ignore/clang
fi

if [ -d ${DIR}/ti-llvm-3.6-3.6/ ] ; then
	rm -rf ${DIR}/ti-llvm-3.6-3.6 || true
fi
mkdir -p ${DIR}/ti-llvm-3.6-3.6
git clone --reference ${DIR}/ignore/llvm/ https://github.com/rcn-ee/llvm ${DIR}/ti-llvm-3.6-3.6
cd ${DIR}/ti-llvm-3.6-3.6/
git checkout c7f6029e454b70dffa3d04d500966a6ecf24a1fe -b tmp
cd ${DIR}/ti-llvm-3.6-3.6/tools
git clone --reference ${DIR}/ignore/clang/ https://github.com/rcn-ee/clang
cd ${DIR}/ti-llvm-3.6-3.6/tools/clang
git checkout 588b1961bfa2c1722db13fd4b68a2477d1cf0e5d -b tmp
cd ${DIR}/ti-llvm-3.6-3.6/
find . | grep .git | xargs rm -rf
cd ${DIR}

tar -cJf ${package_name}_${package_version}.orig.tar.xz ./ti-llvm-3.6-3.6
