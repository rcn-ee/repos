#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20240322.0"
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

buster_version="~buster+20240322"
bullseye_version="~bullseye+20240322"
bookworm_version="~bookworm+20240322"
trixie_version="~trixie+20240322"
focal_version="~focal+20240322"
jammy_version="~jammy+20240322"
noble_version="~noble+20240322"
