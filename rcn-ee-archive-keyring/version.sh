#!/bin/bash -e

package_name="rcn-ee-archive-keyring"
debian_pkg_name="${package_name}"
package_version="2017.01.24"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}"
debian_untar=""
debian_patch=""

zesty_version="~bpo1704+20170124+1"
