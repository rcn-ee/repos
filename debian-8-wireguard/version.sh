#!/bin/bash -e

#https://git.zx2c4.com/WireGuard/
#https://launchpad.net/~wireguard/+archive/ubuntu/wireguard/+packages

package_name="wireguard"
debian_pkg_name="${package_name}"
package_version="0.0.20171221+git20171221"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://git.zx2c4.com/WireGuard/"
git_sha="7e945a815b896a19ecd2ff2b8937c4f90cc978d2"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""
local_patch=""

jessie_version="~jessie+20180104"
stretch_version="~stretch+20180104"
buster_version="~buster+20180104"
bionic_version="~bionic+20180104"
