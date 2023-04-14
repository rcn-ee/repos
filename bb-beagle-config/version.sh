#!/bin/bash -e

#https://github.com/SAtacker/bb-config

package_name="bb-beagle-config"
debian_pkg_name="${package_name}"
package_version="0.1.0.20220611.1"
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

buster_version="~buster+20230414"
bullseye_version="~bullseye+20230414"
bookworm_version="~bookworm+20230414"
focal_version="~focal+20230414"
jammy_version="~jammy+20230414"
