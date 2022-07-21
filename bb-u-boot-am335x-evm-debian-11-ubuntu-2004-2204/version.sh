#!/bin/bash -e

#https://git.beagleboard.org/beagleboard/u-boot/-/tree/v2022.04-bbb.io-am335x-am57xx

package_name="bb-u-boot-am335x-evm"
debian_pkg_name="${package_name}"
package_version="2022.04.20220602.1"
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

bullseye_version="~bullseye+20220720"
focal_version="~focal+20220720"
jammy_version="~jammy+20220720"
