#!/bin/bash -e

#https://github.com/Pillar1989/mraa/tree/BBGW

package_name="libmraa"
debian_pkg_name="${package_name}"
package_version="1.0.0-git20160609"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Pillar1989/mraa"
git_sha="14c19e9155ca6a3117de35002c33f6a4a2a8431a"
reprepro_dir="libm/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"
sbuild_chroot="nodejs-v0.12.x"

jessie_version="~bpo80+20160609+1"
