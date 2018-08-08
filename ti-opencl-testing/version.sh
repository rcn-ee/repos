#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.14.04"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="733e105ab96d0395cd8ed2f405c5e038543d33ba"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180808"
