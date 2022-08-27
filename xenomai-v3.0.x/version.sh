#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="xenomai-v3.0"
debian_pkg_name="${package_name}"
package_version="3.0.13-git20220802.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://source.denx.de/Xenomai/xenomai.git"
git_sha="18b35f837ea7db421a132d0bfd9067ad9f9441d7"
reprepro_dir="x/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

bullseye_version="~bullseye+20220827"
