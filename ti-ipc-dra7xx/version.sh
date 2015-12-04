#!/bin/bash -e

#http://git.ti.com/gitweb/?p=ipc/ipcdev.git;a=summary

package_name="ti-ipc-dra7xx"
debian_pkg_name="${package_name}"
package_version="3.41.00.06"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/ipc/ipcdev.git"
git_sha="795af8b9cec28bd6cdd1f00df1b9084b2a285cce"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

wheezy_version="~bpo70+20151204+1"
jessie_version="~bpo80+20151204+1"
stretch_version="~bpo90+20151204+1"
xenial_version="~bpo1604+20151204+1"
