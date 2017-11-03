#!/bin/bash -e

#https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/

package_name="libgpiod"
debian_pkg_name="${package_name}"
package_version="0.3.2-git20171031"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git"
git_sha="a029549af5d2792762286536db09b2cf564dc7a7"
reprepro_dir="libg/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee3"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20171103"
buster_version="~buster+20171103"
