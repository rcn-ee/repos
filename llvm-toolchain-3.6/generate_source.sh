#!/bin/bash -e

. version.sh

wget -c ${mirror}/${dl_path}${package_name}_${package_version}.orig-clang.tar.bz2
wget -c ${mirror}/${dl_path}${package_name}_${package_version}.orig-compiler-rt.tar.bz2
wget -c ${mirror}/${dl_path}${package_name}_${package_version}.orig-lldb.tar.bz2
wget -c ${mirror}/${dl_path}${package_name}_${package_version}.orig-polly.tar.bz2
wget -c ${mirror}/${dl_path}${package_name}_${package_version}.orig.tar.bz2
wget -c ${mirror}/${dl_path}${debian_untar}
