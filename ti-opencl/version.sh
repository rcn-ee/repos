#!/bin/bash -e

#http://git.ti.com/gitweb/?p=opencl/ti-opencl.git;a=summary

package_name="ti-opencl"
debian_pkg_name="${package_name}"
package_version="01.01.10.03"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/opencl/ti-opencl.git"
git_sha="108ff29cd27e9af39c1f0b4945cb5dd1be7fed41"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee6"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20161027+1"
stretch_version="~bpo90+20161027+1"
xenial_version="~bpo1604+20161027+1"
