#!/bin/bash -e

#https://git.zx2c4.com/WireGuard/
#https://launchpad.net/~wireguard/+archive/ubuntu/wireguard/+packages

package_name="wireguard"
debian_pkg_name="${package_name}"
package_version="0.0.20180531+git20180531"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://git.zx2c4.com/WireGuard/"
git_sha="efd4ef83c768f407e0cf0d17aa309c8a57b39ab0"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""
local_patch=""

jessie_version="~jessie+20180612"
stretch_version="~stretch+20180612"
buster_version="~buster+20180612"
bionic_version="~bionic+20180612"
