#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-llvm-clang-3_3.git;a=summary

package_name="ti-llvm-3.3"
debian_pkg_name="${package_name}"
package_version="3.3-git20150413"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-3.3"

git_repo="git://git.ti.com/opencl/ti-llvm-clang-3_3.git"
git_sha="29629a3e70d445cfbfbb4046a56d3648ebae9544"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20150609+1"
jessie_version="~bpo80+20150609+1"
stretch_version="~bpo90+20150609+1"
