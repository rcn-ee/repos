#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.14.00"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="0bd8b01ca93ad7485f3189a1b88fcb4c6dd41ced"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180808"
