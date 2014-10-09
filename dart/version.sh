#!/bin/bash -e

#https://code.google.com/p/dart/source/list

package_name="dart"
debian_pkg_name="${package_name}"
#repo_branch="1.7"
repo_branch="bleeding_edge"
package_version="1.7.0-edge.41032"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

archive="enable"

wheezy_version="~bpo70+20141009+1"
jessie_version="~20141009+1"
