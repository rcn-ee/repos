#!/bin/bash -e

#https://github.com/mvduin/omap5-cpu-pm

package_name="omap5-cpu-pm"
debian_pkg_name="${package_name}"
package_version="0.0-git20220902.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/mvduin/omap5-cpu-pm"
git_sha="073e5ddcc1ca112c2a315825c19720b7e92f34ad"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

buster_version="~buster+20220302"
bullseye_version="~bullseye+20220902"
