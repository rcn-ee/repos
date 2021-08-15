#!/bin/bash -e

#https://git.launchpad.net/~cloud-initramfs-tools/cloud-initramfs-tools
#https://packages.ubuntu.com/source/focal/cloud-initramfs-tools
#mirror="http://http.debian.net/debian"
mirror="http://archive.ubuntu.com/ubuntu"

package_name="cloud-initramfs-tools"
debian_pkg_name="${package_name}"
package_version="0.47ubuntu1"
package_source="${debian_pkg_name}_${package_version}.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20210815"
buster_version="~buster+20210815"
bullseye_version="~bullseye+20210815"
bionic_version="~bionic+20210815"
focal_version="~focal+20210815"
