#!/bin/bash -e

#https://github.com/u-boot/u-boot/commits/master

package_name="generic-sys-mods"
debian_pkg_name="${package_name}"
package_version="1.20220216.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

buster_version="~buster+20220216"
bullseye_version="~bullseye+20220216"
focal_version="~focal+20220216"
