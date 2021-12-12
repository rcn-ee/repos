#!/bin/bash -e

. version.sh

for d in suite/*
do
  OLD=`pwd`
  cd $d
  rm *.tar.bz2 || true
  # TODO - once Binutils 2.38 is released, switch back to official tarballs.
  # wget http://ftpmirror.gnu.org/binutils/binutils-${package_version}.tar.bz2
  wget http://dinux.eu/gnupru/binutils-2.37.50.g2749ac13.tar.bz2
  cd $OLD
done

