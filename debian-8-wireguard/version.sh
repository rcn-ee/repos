#!/bin/bash -e

#https://git.zx2c4.com/WireGuard/
#https://launchpad.net/~wireguard/+archive/ubuntu/wireguard/+packages

package_name="wireguard"
debian_pkg_name="${package_name}"
package_version="0.0.20180420+git20180423"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://git.zx2c4.com/WireGuard/"
git_sha="f182b1a2a1127599da0d61af4f7ae818455ffc42"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""
local_patch=""

jessie_version="~jessie+20180427"
stretch_version="~stretch+20180427"
buster_version="~buster+20180427"
bionic_version="~bionic+20180427"
