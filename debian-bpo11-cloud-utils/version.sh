#!/bin/bash -e

#https://packages.debian.org/source/bookworm/cloud-utils
mirror="https://deb.debian.org/debian"

package_name="cloud-utils"
debian_pkg_name="${package_name}"
package_version="0.33"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
