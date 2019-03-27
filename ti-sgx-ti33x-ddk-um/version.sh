#!/bin/bash -e

#http://git.ti.com/gitweb/?p=graphics/omap5-sgx-ddk-um-linux.git;a=summary

package_name="ti-sgx-ti33x-ddk-um"
debian_pkg_name="${package_name}"
package_version="1.14.3699939-git20171201.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/graphics/omap5-sgx-ddk-um-linux.git"
git_sha="bbbd5cbb55e4c54d3b02456ae553bea86fd61506"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee8"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190326"
