#!/bin/bash -e

#https://github.com/mattgodbolt/seasocks

package_name="seasocks"
debian_pkg_name="${package_name}"
package_version="1.4.4-git20220530.8"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/mattgodbolt/seasocks"
git_sha="4f4e64d0974775633504503a55e2d6b435539b39"
reprepro_dir="s/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

bullseye_version="~bullseye+20220720"
