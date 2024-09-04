#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20240904.0"
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

bullseye_version="~bullseye+20240904"
bookworm_version="~bookworm+20240904"
trixie_version="~trixie+20240904"
focal_version="~focal+20240904"
jammy_version="~jammy+20240904"
noble_version="~noble+20240904"
