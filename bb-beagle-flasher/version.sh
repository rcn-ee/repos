#!/bin/bash -e

package_name="bb-beagle-flasher"
debian_pkg_name="${package_name}"
package_version="1.20220202.3"
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

buster_version="~buster+20220301"
bullseye_version="~bullseye+20220301"
focal_version="~focal+20220301"
