#!/bin/bash -e

#https://github.com/tomba/rwmem

package_name="rwmem"
debian_pkg_name="${package_name}"
package_version="2.0-git20210806.2"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/tomba/rwmem"
git_sha="c8291705c82bb0686be9adf6a427a2b72114719a"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

buster_version="~buster+20220302"
bullseye_version="~bullseye+20220302"
