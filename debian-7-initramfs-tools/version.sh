#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="initramfs-tools"
debian_pkg_name="${package_name}"
package_version="0.109.1"
dl_package_source="${package_name}_${package_version}.tar.gz"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="i/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1rcnee2"
debian_untar=""
debian_patch=""

wheezy_version="~bpo70+20151007+1"
