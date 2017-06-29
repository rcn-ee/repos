#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.13.00"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="c2493c7190c7e5b4135f64d2aacc2de3ff57e0bb"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-r0.0rcnee6"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170629"
stretch_version="~stretch+20170629"
xenial_version="~xenial+20170629"
