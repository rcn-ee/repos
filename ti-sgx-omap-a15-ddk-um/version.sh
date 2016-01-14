#!/bin/bash -e

#http://git.ti.com/gitweb/?p=graphics/omap5-sgx-ddk-um-linux.git;a=summary

package_name="ti-sgx-omap-a15-ddk-um"
debian_pkg_name="${package_name}"
package_version="0.0.20150815"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/graphics/omap5-sgx-ddk-um-linux.git"
git_sha="d63cd6469fff610317a8e1c986f227bb3e7922f6"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20151110+1"
