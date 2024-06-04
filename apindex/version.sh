#!/bin/bash -e

package_name="apindex"
debian_pkg_name="${package_name}"
package_version="2.2-1.20231128.1"
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
bullseye_version="~bullseye+20240604"
bookworm_version="~bookworm+20240604"
trixie_version="~trixie+20240604"
focal_version="~focal+20240604"
jammy_version="~jammy+20240604"
noble_version="~noble+20240604"
