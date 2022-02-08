#!/bin/bash -e

#http://deb.debian.org/debian/pool/main/libd/libdrm/libdrm_2.4.109-2.dsc
mirror="https://deb.debian.org/debian"

package_name="libdrm"
debian_pkg_name="${package_name}"
package_version="2.4.109"

git_repo=""
git_sha=""
reprepro_dir="libd/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
