#!/bin/bash -e

package_name="rcn-ee-archive-keyring"
debian_pkg_name="${package_name}"
package_version="2014.11.20"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="${mirror}/pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20141120+3"
jessie_version="~20141120+3"
