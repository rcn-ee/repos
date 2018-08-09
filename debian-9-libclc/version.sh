#!/bin/bash -e

#https://packages.debian.org/source/buster/libclc
mirror="http://http.debian.net/debian"

package_name="libclc"
debian_pkg_name="${package_name}"
package_version="0.2.0+git20180518"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="libc/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
local_patch="rcnee0"

stretch_version="~stretch+20180809"
