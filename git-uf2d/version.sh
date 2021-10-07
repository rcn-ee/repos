#!/bin/bash -e

#https://github.com/beagleboard/uf2-linux

package_name="uf2d"
debian_pkg_name="${package_name}"
package_version="0.1.0-git20191211.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/uf2-linux"
git_sha="3baf80349b93b1c6af265f9422aea9727d36f62a"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211007"
