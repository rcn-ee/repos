#!/bin/bash -e

#https://github.com/beagleboard/customizations

package_name="bb-customizations"
debian_pkg_name="${package_name}"
package_version="1.20211214.0"
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

stretch_version="~stretch+20211214"
buster_version="~buster+20211214"
bullseye_version="~bullseye+20211214"
bionic_version="~bionic+20211214"
focal_version="~focal+20211214"
