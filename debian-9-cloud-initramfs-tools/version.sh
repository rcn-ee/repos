#!/bin/bash -e

#https://git.launchpad.net/~cloud-initramfs-tools/cloud-initramfs-tools
#https://packages.ubuntu.com/source/cosmic/cloud-initramfs-tools
#mirror="http://http.debian.net/debian"
mirror="http://archive.ubuntu.com/ubuntu"

package_name="cloud-initramfs-tools"
debian_pkg_name="${package_name}"
package_version="0.42ubuntu1"
package_source="${debian_pkg_name}_${package_version}.tar.xz"
src_dir="wtd"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180830"
