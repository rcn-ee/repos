#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.40.01.08"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="239354b731b77e30a70230ebb54a31a83fc8b12f"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151019+1"
jessie_version="~bpo80+20151019+1"
stretch_version="~bpo90+20151019+1"
vivid_version="~bpo1504+20151019+1"
wily_version="~bpo1510+20151019+1"
