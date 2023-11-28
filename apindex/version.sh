#!/bin/bash -e

package_name="apindex"
debian_pkg_name="${package_name}"
package_version="2.2-1.20230319.6"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="a/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

buster_version="~buster+20231128"
bullseye_version="~bullseye+20231128"
bookworm_version="~bookworm+20231128"
trixie_version="~trixie+20231128"
focal_version="~focal+20231128"
jammy_version="~jammy+20231128"
