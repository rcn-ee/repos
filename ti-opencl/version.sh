#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary
#https://github.com/rcn-ee/ti-opencl/commits/v01.01.17.01-bb.org

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.17.01-git20181129.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/ti-opencl.git"
git_sha="93dfcd77bd72f1dc1daa7fe331a2134102e8cfbc"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190103"
buster_version="~buster+20190103"
bionic_version="~bionic+20190103"
