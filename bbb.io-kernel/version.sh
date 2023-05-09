#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20230508.0"
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

buster_version="~buster+20230508"
bullseye_version="~bullseye+20230508"
bookworm_version="~bookworm+20230508"
focal_version="~focal+20230508"
jammy_version="~jammy+20230508"
