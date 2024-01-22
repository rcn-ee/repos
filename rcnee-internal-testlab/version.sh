#!/bin/bash -e

package_name="rcnee-internal-testlab"
debian_pkg_name="${package_name}"
package_version="1.20240122.0"
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

bullseye_version="~bullseye+20240122"
bookworm_version="~bookworm+20240122"
trixie_version="~trixie+20240122"
jammy_version="~jammy+20240122"
noble_version="~noble+20240122"
