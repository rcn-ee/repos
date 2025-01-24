#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20250124.0"
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

focal_version="~focal+20241210"
bullseye_version="~bullseye+20250124"
bookworm_version="~bookworm+20250124"
trixie_version="~trixie+20250124"
jammy_version="~jammy+20250124"
noble_version="~noble+20250124"
