#!/bin/bash -e

. version.sh

for d in suite/*
do
  OLD=`pwd`
  cd $d
  rm *.tar.bz2 || true
  wget http://ftpmirror.gnu.org/binutils/binutils-${package_version}.tar.bz2
  cd $OLD
done

