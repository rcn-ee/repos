#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="btrfs-progs"
debian_pkg_name="${package_name}"
package_version="4.13.3"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo9+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
