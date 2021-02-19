#!/bin/bash -e

#https://github.com/beagleboard/u-boot/commits/v2021.01-bb.org-am335x-am57xx

package_name="bb-u-boot-am57xx-evm"
debian_pkg_name="${package_name}"
package_version="2020.10.20210218.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210219"
buster_version="~buster+20210219"
bullseye_version="~bullseye+20210219"
bionic_version="~bionic+20210219"
focal_version="~focal+20210219"
