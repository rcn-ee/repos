#!/bin/bash -e

package_name="galcore-headers"
debian_pkg_name="${package_name}"
package_version="4.6.6.1381"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee5"
debian_untar=""
debian_patch=""

clear_changelog="enable"

buster_version="~buster+20211229"
bullseye_version="~bullseye+20211229"
focal_version="~focal+20211229"
