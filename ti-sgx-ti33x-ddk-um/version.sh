#!/bin/bash -e

#http://git.ti.com/gitweb/?p=graphics/omap5-sgx-ddk-um-linux.git;a=summary

package_name="ti-sgx-ti33x-ddk-um"
debian_pkg_name="${package_name}"
package_version="0.0.20151104"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/graphics/omap5-sgx-ddk-um-linux.git"
git_sha="b535b96043ae2206e0c3d24b66599ca0fbe706d3"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""


jessie_version="~bpo80+20151110+1"
