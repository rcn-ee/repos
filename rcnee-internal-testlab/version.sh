#!/bin/bash -e

package_name="rcnee-internal-testlab"
debian_pkg_name="${package_name}"
package_version="1.20230929.1"
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

bullseye_version="~bullseye+20230929"
bookworm_version="~bookworm+20230929"
trixie_version="~trixie+20230929"
jammy_version="~jammy+20230929"
