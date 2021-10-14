#!/bin/bash -e

#https://github.com/rcn-ee/bbb.io-kernel
#https://github.com/rcn-ee/bbb.io-kernel/commits/master

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="20211014.5"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/bbb.io-kernel"
git_sha="135c2f046744e6aad3048a37552bb28ba60701f6"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211014"
