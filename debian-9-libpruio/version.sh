#!/bin/bash -e

#https://github.com/DTJF/libpruio/commits/master

package_name="libpruio"
debian_pkg_name="${package_name}"
package_version="0.6.2a-git20180920.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/DTJF/libpruio"
git_sha="48b055a0d392993c5f921ae6d330d00be708d21a"
git_branch="master"
reprepro_dir="libp/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180921"
