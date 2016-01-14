#!/bin/bash -e

mirror="http://ports.ubuntu.com"

#https://launchpad.net/ubuntu/+archive/primary/+files/initramfs-tools_0.103ubuntu4.2.tar.xz

package_name="initramfs-tools"
debian_pkg_name="${package_name}"
package_version="0.103ubuntu4.2"
dl_package_source="${package_name}_${package_version}.tar.xz"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="initramfs-tools-0.103ubuntu4.1"

git_repo=""
git_sha=""
reprepro_dir="i/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1rcnee1"
debian_untar=""
debian_patch=""

trusty_version="~bpo1404+20151007+1"
