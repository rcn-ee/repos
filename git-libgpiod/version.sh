#!/bin/bash -e

#https://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git/
#https://packages.debian.org/source/sid/libgpiod

#mirror="http://http.debian.net/debian"

package_name="libgpiod"
debian_pkg_name="${package_name}"
package_version="1.1.0-git20180607.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/libs/libgpiod/libgpiod.git"
git_sha="041e675b57d4d386e44bdcf4fbbc062a42ee301f"
reprepro_dir="libg/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180712"
bionic_version="~bionic+20180712"
buster_version="~buster+20180712"
