#!/bin/bash -e

package_name="bb-u-boot-am335x-evm-rc"
debian_pkg_name="${package_name}"
package_version="2023.10.20230904.0"
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

buster_version="~buster+20230905"
bullseye_version="~bullseye+20230905"
focal_version="~focal+20230905"
jammy_version="~jammy+20230905"
