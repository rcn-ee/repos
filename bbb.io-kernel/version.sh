#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20231221.1"
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

buster_version="~buster+20231221"
bullseye_version="~bullseye+20231221"
bookworm_version="~bookworm+20231221"
trixie_version="~trixie+20231221"
focal_version="~focal+20231221"
jammy_version="~jammy+20231221"
noble_version="~noble+20231221"
