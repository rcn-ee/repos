#!/bin/bash -e

#https://code.google.com/p/dart/source/list

package_name="dart-1.8"
debian_pkg_name="${package_name}"
repo_branch="1.8"
#repo_branch="bleeding_edge"
package_version="1.8.1-git20141130"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}.1"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

archive="enable"

wheezy_version="~bpo70+20141130+1"
jessie_version="~20141130+1"
