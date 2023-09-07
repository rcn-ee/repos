#!/bin/bash -e

package_name="rcnee-internal-testlab"
debian_pkg_name="${package_name}"
package_version="1.20230906.4"
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

buster_version="~buster+20230906"
bullseye_version="~bullseye+20230906"
bookworm_version="~bookworm+20230906"
trixie_version="~trixie+20230906"
jammy_version="~jammy+20230906"
