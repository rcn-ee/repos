#!/bin/bash -e

#https://packages.debian.org/source/bullseye/libinih
mirror="https://deb.debian.org/debian"

package_name="libinih"
debian_pkg_name="${package_name}"
package_version="48"

git_repo=""
git_sha=""
reprepro_dir="libi/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo10+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="buster"
deb_arch="armhf"
