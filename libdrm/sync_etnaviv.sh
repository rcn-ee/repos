#!/bin/bash -e

mkdir -p ./ignore/etnaviv

if [ ! -f ./ignore/etnaviv/.git/config ] ; then
	git clone https://github.com/austriancoder/libdrm ./ignore/etnaviv
fi

cd ./ignore/etnaviv/
git pull

git diff c3496167637e35cf8a52d5e7e53a412e79d80db0...HEAD > ../../0001-etnaviv-base.diff

cd ../../
