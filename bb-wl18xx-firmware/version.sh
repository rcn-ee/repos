#!/bin/bash -e

package_name="bb-wl18xx-firmware"
debian_pkg_name="${package_name}"
package_version="1.20210922.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210922"
buster_version="~buster+20210922"
bullseye_version="~bullseye+20210922"
bionic_version="~bionic+20210922"
focal_version="~focal+20210922"
