#!/bin/bash -e

#http://git.arm.linux.org.uk/cgit/libdrm-armada.git/
#https://github.com/rcn-ee/libdrm-armada-mirror

package_name="libdrm-armada"
debian_pkg_name="${package_name}"
package_version="2.0.3-git20180720.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/libdrm-armada-mirror.git"
git_sha="607c697d7c403356601cd0d5fa6407b61a45e8ed"
reprepro_dir="libd/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

buster_version="~buster+20211229"
bullseye_version="~bullseye+20211229"
focal_version="~focal+20211229"
