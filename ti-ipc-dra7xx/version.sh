#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.44.01.01"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="cff640a4c7e083f78116266ef681cec49d9b584b"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-r0.0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170608"
stretch_version="~stretch+20170608"
xenial_version="~xenial+20170608"
