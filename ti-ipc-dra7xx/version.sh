#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.46.00.02"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="997ef62671476be051cd4f9f94907e61573dffae"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-r1.0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170629"
stretch_version="~stretch+20170629"
xenial_version="~xenial+20170629"
