#!/bin/bash -e

mirror="http://ports.ubuntu.com"

#https://launchpad.net/ubuntu/+archive/primary/+files/initramfs-tools_0.103ubuntu15.tar.gz

package_name="initramfs-tools"
debian_pkg_name="${package_name}"
package_version="0.103ubuntu15"
dl_package_source="${package_name}_${package_version}.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="initramfs-tools-0.103ubuntu15"

git_repo=""
git_sha=""
reprepro_dir="i/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1rcnee1"
debian_untar=""
debian_patch=""

vivid_version="~bpo1504+20151007+1"
