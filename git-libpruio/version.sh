#!/bin/bash -e

#https://github.com/DTJF/libpruio

package_name="libpruio"
debian_pkg_name="${package_name}"
package_version="0.6.6-git20211230.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/DTJF/libpruio"
git_sha="6da1b5183d548c62aa7efb3801791ca6902ee167"
reprepro_dir="libp/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""


buster_version="~buster+20220311"
bullseye_version="~bullseye+20220311"
