#!/bin/bash -e

package_name="bb-bbai-firmware"
debian_pkg_name="${package_name}"
package_version="1.20210923.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210923"
buster_version="~buster+20210923"
bullseye_version="~bullseye+20210923"
bionic_version="~bionic+20210923"
focal_version="~focal+20210923"
