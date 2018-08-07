#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.47.02.00"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="24c36385d096613af123d1e1696fb2fee652ef36"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-r0.0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180807"
buster_version="~buster+20180807"
bionic_version="~bionic+20180807"
