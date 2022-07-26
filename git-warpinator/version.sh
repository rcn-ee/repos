#!/bin/bash -e

#https://github.com/linuxmint/warpinator

package_name="warpinator"
debian_pkg_name="${package_name}"
package_version="1.2.13"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/linuxmint/warpinator"
git_sha="7a9dfae90dd57bd6c9c77fee490851641274223b"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="bbbio1"

bullseye_version="~bullseye+20220726"
