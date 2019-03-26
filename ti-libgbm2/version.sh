#!/bin/bash -e

#http://git.ti.com/gitweb/?p=glsdk/libgbm.git;a=summary

package_name="ti-libgbm2"
debian_pkg_name="${package_name}"
package_version="2.0.0-git20171206.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/glsdk/libgbm.git"
git_sha="f316cf4b98ca3f4a1ca92a48ddd8aa559894a45c"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190326"
