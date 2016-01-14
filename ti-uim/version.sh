#!/bin/bash -e

#http://git.ti.com/gitweb/?p=wilink8-wlan/18xx-ti-utils.git;a=summary

package_name="ti-uim"
debian_pkg_name="${package_name}"
package_version="8.6-git20151101"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/wilink8-wlan/18xx-ti-utils.git"
git_sha="d39cb9d35247ad6c06542fbac1d40a7c5bcb9856"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-1.1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20151105+1"
