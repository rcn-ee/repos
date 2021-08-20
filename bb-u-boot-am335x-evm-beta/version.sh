#!/bin/bash -e

#https://github.com/beagleboard/u-boot/tree/v2020.04-bbb.io-am335x

package_name="bb-u-boot-am335x-evm-beta"
debian_pkg_name="${package_name}"
package_version="2020.04.20210819.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

buster_version="~buster+20210819"
bullseye_version="~bullseye+20210819"
