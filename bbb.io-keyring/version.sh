#!/bin/bash -e

package_name="bbb.io-keyring"
debian_pkg_name="${package_name}"
package_version="1.20231206.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

clear_changelog="enable"

bionic_version="~bionic+20230414"
buster_version="~buster+20231206"
bullseye_version="~bullseye+20231206"
bookworm_version="~bookworm+20231206"
trixie_version="~trixie+20231206"
focal_version="~focal+20231206"
jammy_version="~jammy+20231206"
noble_version="~noble+20231206"
