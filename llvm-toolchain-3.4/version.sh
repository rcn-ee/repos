#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="llvm-toolchain-3.4"
debian_pkg_name="${package_name}"
package_version="3.4"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}.2-13"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

wheezy_version="~bpo70+20141218+2"
