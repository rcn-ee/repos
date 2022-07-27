#!/bin/bash -e

package_name="sancloud-firmware"
debian_pkg_name="${package_name}"
package_version="0.1.0.20220309.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

buster_version="~buster+20220727"
bullseye_version="~bullseye+20220727"
focal_version="~focal+20220727"
jammy_version="~jammy+20220727"
