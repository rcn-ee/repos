#!/bin/bash -e

#https://github.com/beagleboard/u-boot/tree/v2020.10-rc4-bbb.io-am57xx

package_name="bb-u-boot-am57xx-evm"
debian_pkg_name="${package_name}"
package_version="2021.04.20210625.3"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

stretch_version="~stretch+20220720"
buster_version="~buster+20220720"
bullseye_version="~bullseye+20220720"
bionic_version="~bionic+20220720"
focal_version="~focal+20220720"
jammy_version="~jammy+20220720"
