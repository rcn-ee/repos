#!/bin/bash -e

#https://github.com/QupZilla/qupzilla/commits/v1.8

package_name="qupzilla"
debian_pkg_name="${package_name}"
#package_version="1.8.4"
package_version="1.8.6-git20150126"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/QupZilla/qupzilla"
git_sha="a0de5dc24a15d4662d39014276fd2357223f5e87"
reprepro_dir="q/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141006+1"
jessie_version="~20150126+1"
