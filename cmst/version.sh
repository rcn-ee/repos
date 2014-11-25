#!/bin/bash -e

#https://github.com/andrew-bibb/cmst

package_name="cmst"
debian_pkg_name="${package_name}"
package_version="2014.11.24-git20141124"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/andrew-bibb/cmst.git"
git_sha="a1aa91b4beba530db8ff4614d203a7d64e2bed24"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141125+1"
