#!/bin/bash -e

#https://github.com/beagleboard/bb.org-overlays

package_name="bb-uboot-am335x-evm"
debian_pkg_name="${package_name}"
package_version="2020.01.20210205.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/u-boot"
git_sha="55ac96a8461d06edfa89cda37459753397de268a"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

buster_version="~buster+20210205"
