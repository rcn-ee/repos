#!/bin/bash -e

#https://packages.debian.org/source/bullseye-backports/barrier
mirror="https://deb.debian.org/debian"

package_name="barrier"
debian_pkg_name="${package_name}"
package_version="2.4.0+dfsg"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2~bpo11+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
