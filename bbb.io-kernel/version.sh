#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20241112.0"
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

bullseye_version="~bullseye+20241112"
bookworm_version="~bookworm+20241112"
trixie_version="~trixie+20241112"
focal_version="~focal+20241112"
jammy_version="~jammy+20241112"
noble_version="~noble+20241112"
