#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.06.00"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="992dfba8783af895f6d4e4877ad7c0466d085bf0"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20151020+1"
jessie_version="~bpo80+20151020+1"
stretch_version="~bpo90+20151020+1"
