#!/bin/bash -e

#https://packages.debian.org/source/sid/llvm-toolchain-14
mirror="https://deb.debian.org/debian"

package_name="llvm-toolchain-14"
debian_pkg_name="${package_name}"
package_version="14.0.3"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
