#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.41.00.02"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="b34c8ada4ed243cd52e504bf2c6fb3451dc730f8"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151112+1"
jessie_version="~bpo80+20151112+1"
stretch_version="~bpo90+20151112+1"
xenial_version="~bpo1604+20151112+1"
