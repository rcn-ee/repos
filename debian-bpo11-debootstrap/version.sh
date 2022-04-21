#!/bin/bash -e

mirror="https://snapshot.debian.org/archive/debian/20211102T152554Z/"

package_name="debootstrap"
debian_pkg_name="${package_name}"
package_version="1.0.125"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="buster"
deb_arch="armhf"
