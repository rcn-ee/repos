#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.14.07"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="2be51882b5c1f0f8a97fddcc7e8db2b09db41dfe"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180808"
