#!/bin/bash -e

#https://github.com/QupZilla/qupzilla/commits/v1.8

package_name="qupzilla"
debian_pkg_name="${package_name}"
#package_version="1.8.4"
package_version="1.8.4-git20141122"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="1b81a137cede0d2a182df2691a8a594ad2f98ddb"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141126+1"
