#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/heads/release_36_ti
#http://git.ti.com/gitweb/?p=opencl/llvm.git;a=shortlog;h=refs/tags/v01.01.07.01

package_name="ti-llvm-3.6"
debian_pkg_name="${package_name}"
package_version="3.6-git20160808"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-3.6"

git_repo="git://git.ti.com/opencl/llvm.git"
git_sha="798386e2513c812ab4b01df5b57c88b225e756bb"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20160829+1"
stretch_version="~bpo90+20160829+1"
xenial_version="~bpo1604+20160829+1"
