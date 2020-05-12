#!/bin/bash -e

mirror="https://deb.debian.org/debian"

package_name="llvm-toolchain-8"
debian_pkg_name="${package_name}"
package_version="8"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3~bpo109+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="buster"
deb_arch="armhf"
