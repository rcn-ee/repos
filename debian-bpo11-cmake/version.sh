#!/bin/bash -e

#https://packages.debian.org/source/bullseye-backports/cmake
mirror="https://deb.debian.org/debian"

package_name="cmake"
debian_pkg_name="${package_name}"
package_version="3.22.1"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo11+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
