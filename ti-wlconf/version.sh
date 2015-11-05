#!/bin/bash -e

#http://git.ti.com/gitweb/?p=wilink8-wlan/18xx-ti-utils.git;a=summary

package_name="ti-wlconf"
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

wheezy_version="~bpo70+20151105+1"
jessie_version="~bpo80+20151105+1"
stretch_version="~bpo90+20151105+1"
trusty_version="~bpo1404+20151105+1"
vivid_version="~bpo1504+20151105+1"
wily_version="~bpo1510+20151105+1"
xenial_version="~bpo1604+20151105+1"
