#!/bin/bash -e

. version.sh

for d in suite/*
do
  OLD=`pwd`
  cd $d
  rm *.tar.bz2 || true
  wget https://github.com/dinuxbg/gnupru/releases/download/${gnupru_release}/${package_name}_${package_version}.tar.bz2
  cd $OLD
done

