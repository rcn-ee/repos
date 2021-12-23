#!/bin/bash -e

. version.sh

# rm *.tar.xz || true
rm *.tar.bz2 || true

# TODO - once GCC 12 is released, switch back to mainline tarballs.
# wget http://ftpmirror.gnu.org/gcc/gcc-${package_version}/gcc-${package_version}.tar.xz
wget http://dinux.eu/gnupru/gcc-${package_version}.tar.gz

wget http://sourceware.org/pub/newlib/newlib-${newlib_version}.tar.gz

rm -fr gcc-pru_*
mkdir gcc-pru_${package_version}

# Combine GCC and Newlib sources into a single source tarball.
# This way we solve the multi-stage GCC build reliance on newlib.
pushd gcc-pru_${package_version}
tar --strip-components=1 -xaf ../gcc-${package_version}.tar.??
tar -xaf ../newlib-${newlib_version}.tar.gz
mv newlib-*/newlib .
mv newlib-*/libgloss .
rm -fr newlib-*
popd

tar caf gcc-pru_${package_version}.tar.bz2 gcc-pru_${package_version}
rm -fr gcc-pru_${package_version}

for d in suite/*
do
  OLD=`pwd`
  cd $d
  cp ../../gcc-pru_${package_version}.tar.bz2 .
  cd $OLD
done

