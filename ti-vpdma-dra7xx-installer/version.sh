#!/bin/bash -e

package_name="vpdma-dra7xx-installer"
debian_pkg_name="${package_name}"
package_version="03-2012"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="v/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-r1rcnee2"
debian_untar=""
debian_patch=""

debian_dl_1="https://github.com/rcn-ee/sdk-firmware/raw/master/vpdma-fw/03-2012-r1/files/vpdma-1b8.bin"

stretch_version="~stretch+20200424"
buster_version="~buster+20200424"
bionic_version="~bionic+20200424"
focal_version="~focal+20200424"
