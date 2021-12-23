#!/bin/bash -e

package_name="gcc-pru"
debian_pkg_name="${package_name}"
package_version="12.0.RC.gaeedb00a1a"
package_source=""
src_dir=""

newlib_version="4.1.0"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

bullseye_version="~bullseye+20211223"
focal_version="~focal+20211223"
