#!/bin/bash -e

#https://code.google.com/p/dart/source/list

package_name="dart-1.9"
debian_pkg_name="${package_name}"
repo_branch="1.9"
#repo_branch="bleeding_edge"
package_version="1.9.1-git20150407"
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

wheezy_version="~bpo70+20150407+1"
jessie_version="~bpo80+20150407+1"
trusty_version="~bpo1404+20150407+1"
utopic_version="~bpo1410+20150407+1"
vivid_version="~bpo1504+20150407+1"
