#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.15.03"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="84da661abc3f9398bca9497aa13ec42604f7efd8"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0.0rcnee5"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180809"
buster_version="~buster+20180809"
bionic_version="~bionic+20180809"
