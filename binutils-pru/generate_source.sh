#!/bin/bash -e

. version.sh

for d in suite/*
do
  OLD=`pwd`
  cd $d
  if [ ! -f ${package_name}_${package_version}.tar.bz2 ] ; then
    wget https://github.com/dinuxbg/gnupru/releases/download/${gnupru_release}/${package_name}_${package_version}.tar.bz2
  fi
  cd $OLD
done

