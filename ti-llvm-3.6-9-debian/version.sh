#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/heads/release_36_ti
#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/tags/v01.01.07.01
#http://arago-project.org/git/?p=meta-arago.git;a=blob;f=meta-arago-extras/recipes-core/llvm/ti-llvm3.6_3.6.bb;hb=HEAD

package_name="ti-llvm-3.6"
debian_pkg_name="${package_name}"
package_version="3.6-git20190111.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-3.6"

git_repo="git://git.ti.com/opencl/llvm.git"
git_sha="09780c6750b30da81e4a0a805aedf1699fbc37c7"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190924"
