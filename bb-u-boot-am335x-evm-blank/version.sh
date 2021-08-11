#!/bin/bash -e

#https://github.com/beagleboard/u-boot/tree/v2019.04-bbb.io-am335x

package_name="bb-u-boot-am335x-evm-blank"
debian_pkg_name="${package_name}"
package_version="2019.04.20210804.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210811"
buster_version="~buster+20210811"
bullseye_version="~bullseye+20210811"
bionic_version="~bionic+20210811"
focal_version="~focal+20210811"
