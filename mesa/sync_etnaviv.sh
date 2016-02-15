#!/bin/bash -e

mkdir -p ./ignore/etnaviv

if [ ! -f ./ignore/etnaviv/.git/config ] ; then
	git clone https://github.com/etnaviv/mesa ./ignore/etnaviv
	cd ./ignore/etnaviv/
	git checkout origin/master -b master
	git branch -D 11.1_etnaviv
else
	cd ./ignore/etnaviv/
	git checkout master -f
	git branch -D tmp
fi

git pull
git checkout origin/11.1_etnaviv -b tmp

git diff 4b2d9f29e9b75cbbeb76ccf753a256e11f07ee1a...HEAD >  ../../suite/jessie/debian/patches/0001-etnaviv-base.diff
git diff 4b2d9f29e9b75cbbeb76ccf753a256e11f07ee1a...HEAD > ../../suite/stretch/debian/patches/0001-etnaviv-base.diff
git diff 4b2d9f29e9b75cbbeb76ccf753a256e11f07ee1a...HEAD >  ../../suite/xenial/debian/patches/0001-etnaviv-base.diff

#sed -i -e 's:opcs:etopcs:g' ./src/gallium/drivers/etnaviv/etnaviv_disasm.c

#echo "" >  ../../suite/jessie/debian/patches/0002-etnaviv-wip.diff
#echo "" > ../../suite/stretch/debian/patches/0002-etnaviv-wip.diff
#echo "" >  ../../suite/xenial/debian/patches/0002-etnaviv-wip.diff

#git diff | patch -p1 -R

cd ../../
