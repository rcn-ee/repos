#!/bin/bash -e

#https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/

package_name="libgpiod"
debian_pkg_name="${package_name}"
package_version="0.3.2-git20171201"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git"
git_sha="7d613094586a5a07c408e179f4fcf0243656f5bb"
reprepro_dir="libg/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20171206"
buster_version="~buster+20171206"
