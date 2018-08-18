#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary
#https://github.com/rcn-ee/ti-opencl/commits/v01.01.15.03-bb.org

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.15.03-git20180817.2"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/ti-opencl.git"
git_sha="b0bf34ced52717e9fe17534236aee28bb64fbfc4"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee4"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180817"
buster_version="~buster+20180817"
bionic_version="~bionic+20180817"
