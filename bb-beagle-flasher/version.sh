#!/bin/bash -e

package_name="bb-beagle-flasher"
debian_pkg_name="${package_name}"
package_version="1.20231006.0"
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

buster_version="~buster+20231006"
bullseye_version="~bullseye+20231006"
bookworm_version="~bookworm+20231006"
focal_version="~focal+20231006"
jammy_version="~jammy+20231006"
