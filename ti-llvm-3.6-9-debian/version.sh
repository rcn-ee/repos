#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/heads/release_36_ti
#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/tags/v01.01.07.01

package_name="ti-llvm-3.6"
debian_pkg_name="${package_name}"
package_version="3.6-git20170214"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-3.6"

git_repo="git://git.ti.com/opencl/llvm.git"
git_sha="8ff2a35c586a3d3f624712e0943777613a017bc5"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-r5rcnee4"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180802"
buster_version="~buster+20180802"
bionic_version="~bionic+20180802"
