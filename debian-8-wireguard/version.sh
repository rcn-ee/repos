#!/bin/bash -e

#https://git.zx2c4.com/WireGuard/
#https://launchpad.net/~wireguard/+archive/ubuntu/wireguard/+packages

package_name="wireguard"
debian_pkg_name="${package_name}"
package_version="0.0.20171127+git20171127"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://git.zx2c4.com/WireGuard/"
git_sha="e4b7fec69135ecc50b3a105fbf09efc9e037e113"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""
local_patch=""

jessie_version="~jessie+20171128"
stretch_version="~stretch+20171128"
buster_version="~buster+20171128"
