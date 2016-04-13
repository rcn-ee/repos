#!/bin/bash -e

#http://git.ti.com/gitweb/?p=wilink8-wlan/hostap.git;a=summary

#http://arago-project.org/git/?p=meta-arago.git;a=blob;f=meta-arago-extras/recipes-connectivity/hostap/hostap-daemon-wl18xx.bb;hb=HEAD

#R8.7_RC12
#http://git.ti.com/gitweb/?p=wilink8-wlan/hostap.git;a=commit;h=f80fe345acf103ba6882ac8396f19584ac184904

package_name="wpa"
debian_pkg_name="${package_name}"
package_version="2.4-git20150624"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/wilink8-wlan/hostap.git"
git_sha="f80fe345acf103ba6882ac8396f19584ac184904"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160413+1"
