#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-llvm-clang-3_3.git;a=summary

package_name="ti-llvm-3.6"
debian_pkg_name="${package_name}"
package_version="3.6-git20151112"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-3.6"

git_repo="git://git.ti.com/opencl/llvm.git"
git_sha="c7f6029e454b70dffa3d04d500966a6ecf24a1fe"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

wheezy_version="~bpo70+20151223+1"
jessie_version="~bpo80+20151223+1"
stretch_version="~bpo90+20151223+1"
trusty_version="~bpo1404+20151223+1"
vivid_version="~bpo1504+20151223+1"
wily_version="~bpo1510+20151223+1"
xenial_version="~bpo1604+20151223+1"
