#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.14.06"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="03e89944c6dc4ab508698610baef623231de436d"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180808"
