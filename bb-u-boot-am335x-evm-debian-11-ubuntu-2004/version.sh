#!/bin/bash -e

#https://github.com/beagleboard/u-boot/commits/v2021.10-bbb.io-am335x

package_name="bb-u-boot-am335x-evm"
debian_pkg_name="${package_name}"
package_version="2021.10.20211217.0"
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

bullseye_version="~bullseye+20211217"
focal_version="~focal+20211217"
