#!/bin/bash -e

mkdir -p ./ignore/etnaviv

if [ ! -f ./ignore/etnaviv/.git/config ] ; then
	git clone -b libdrm_etnaviv_v2 https://github.com/austriancoder/libdrm ./ignore/etnaviv
fi

cd ./ignore/etnaviv/
git pull

git diff b214b05ccd433c484a6a65e491a1a51b19e4811d...HEAD > ../../0001-etnaviv-base.diff

cd ../../
