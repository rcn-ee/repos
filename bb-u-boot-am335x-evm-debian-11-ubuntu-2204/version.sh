#!/bin/bash -e

#https://openbeagle.org/beagleboard/u-boot/-/tree/v2022.04-bbb.io-am335x-am57xx

package_name="bb-u-boot-am335x-evm"
debian_pkg_name="${package_name}"
package_version="2022.04.20240115.1"
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

focal_version="~focal+20240115"
bullseye_version="~bullseye+20250217"
bookworm_version="~bookworm+20250217"
trixie_version="~trixie+20250217"
jammy_version="~jammy+20250217"
noble_version="~noble+20250217"
