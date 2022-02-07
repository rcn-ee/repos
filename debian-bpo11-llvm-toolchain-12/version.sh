#!/bin/bash -e

#http://deb.debian.org/debian/pool/main/l/llvm-toolchain-12/llvm-toolchain-12_12.0.1-19.dsc
mirror="https://deb.debian.org/debian"

package_name="llvm-toolchain-12"
debian_pkg_name="${package_name}"
package_version="12.0.1"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-19"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
