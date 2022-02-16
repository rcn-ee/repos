#!/bin/bash -e

package_name="bbb.io-xfce4-desktop"
debian_pkg_name="${package_name}"
package_version="1.20220216.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

bullseye_version="~bullseye+20220216"
