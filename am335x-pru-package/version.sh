#!/bin/bash -e

package_name="am335x-pru-package"
debian_pkg_name="${package_name}"
package_version="0.20141125"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/am335x_pru_package"
git_sha="2c5b1849df51c3f0e0d79eb7bf16fa371bdc899c"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-1"
debian_patch=""
debian_diff=""

wheezy_version="~bpo70+20141125+1"
jessie_version="~20141125+1"
