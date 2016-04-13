#!/bin/bash -e

#http://git.ti.com/gitweb/?p=wilink8-wlan/hostap.git;a=summary

#R8.7_RC12
#http://git.ti.com/gitweb/?p=wilink8-wlan/hostap.git;a=commit;h=1c4cfdf9b84494a97e45a75e014918cc5ae3a5b4

package_name="wpa"
debian_pkg_name="${package_name}"
package_version="2.5-git20160407"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/wilink8-wlan/hostap.git"
git_sha="1c4cfdf9b84494a97e45a75e014918cc5ae3a5b4"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160413+1"
