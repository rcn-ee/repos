#!/bin/bash -e

#https://github.com/beagleboard/u-boot/commits/v2021.01-bb.org-am335x-am57xx

package_name="bb-u-boot-am335x-evm-blank"
debian_pkg_name="${package_name}"
package_version="2019.04.20210601.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210602"
buster_version="~buster+20210602"
bullseye_version="~bullseye+20210602"
bionic_version="~bionic+20210602"
focal_version="~focal+20210602"
