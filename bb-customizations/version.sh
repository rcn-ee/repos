#!/bin/bash -e

#https://github.com/beagleboard/customizations

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20230714.0"
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

bionic_version="~bionic+20230530"
buster_version="~buster+20230714"
bullseye_version="~bullseye+20230714"
bookworm_version="~bookworm+20230714"
focal_version="~focal+20230714"
jammy_version="~jammy+20230714"
