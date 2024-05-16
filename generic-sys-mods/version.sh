#!/bin/bash -e

package_name="generic-sys-mods"
debian_pkg_name="${package_name}"
package_version="1.20240516.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

bullseye_version="~bullseye+20240516"
bookworm_version="~bookworm+20240516"
trixie_version="~trixie+20240516"
focal_version="~focal+20240516"
jammy_version="~jammy+20240516"
noble_version="~noble+20240516"
