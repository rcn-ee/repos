#!/bin/bash -e

#https://git.beagleboard.org/beagleboard/u-boot/-/tree/v2022.04-bbb.io-am335x-am57xx

package_name="bb-u-boot-am57xx-evm"
debian_pkg_name="${package_name}"
package_version="2022.04.20220823.1"
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

buster_version="~buster+20230804"
bullseye_version="~bullseye+20230804"
bookworm_version="~bookworm+20230804"
focal_version="~focal+20230804"
jammy_version="~jammy+20230804"
