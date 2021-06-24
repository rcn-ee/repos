#!/bin/bash -e

#https://github.com/beagleboard/u-boot/tree/v2020.10-bbb.io-am57xx

package_name="bb-u-boot-am57xx-evm"
debian_pkg_name="${package_name}"
package_version="2020.10.20201005.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20210624"
buster_version="~buster+20210624"
bullseye_version="~bullseye+20210624"
bionic_version="~bionic+20210624"
focal_version="~focal+20210624"
