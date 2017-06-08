#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.12.00"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="8c0ec9c270cafaef0a56c376fc28c1b7714cb09c"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee3"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170608"
stretch_version="~stretch+20170608"
xenial_version="~xenial+20170608"
