#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="llvm-toolchain-3.8"
debian_pkg_name="${package_name}"
package_version="3.8.1"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-24"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
