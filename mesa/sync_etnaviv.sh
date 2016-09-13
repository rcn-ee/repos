#!/bin/bash -e

mkdir -p ./ignore/etnaviv

if [ ! -f ./ignore/etnaviv/.git/config ] ; then
	git clone https://github.com/etnaviv/mesa ./ignore/etnaviv
	cd ./ignore/etnaviv/
	git checkout origin/master -b master
	git branch -D 12.0_etnaviv
else
	cd ./ignore/etnaviv/
	git checkout master -f
	git branch -D tmp
fi

git pull
git checkout origin/12.0_etnaviv -b tmp

git diff 7d41c8aa25ce5f695233de18c0586b630cbfdc74...HEAD >  ../../suite/jessie/debian/patches/0001-etnaviv-base.diff
git diff 7d41c8aa25ce5f695233de18c0586b630cbfdc74...HEAD > ../../suite/stretch/debian/patches/0001-etnaviv-base.diff
git diff 7d41c8aa25ce5f695233de18c0586b630cbfdc74...HEAD >  ../../suite/xenial/debian/patches/0001-etnaviv-base.diff

#sed -i -e 's:opcs:etopcs:g' ./src/gallium/drivers/etnaviv/etnaviv_disasm.c

#echo "" >  ../../suite/jessie/debian/patches/0002-etnaviv-wip.diff
#echo "" > ../../suite/stretch/debian/patches/0002-etnaviv-wip.diff
#echo "" >  ../../suite/xenial/debian/patches/0002-etnaviv-wip.diff

#git diff | patch -p1 -R

cd ../../
