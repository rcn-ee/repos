#!/bin/bash -e

#https://packages.debian.org/source/bookworm/linuxcnc
mirror="https://deb.debian.org/debian"

package_name="linuxcnc"
debian_pkg_name="${package_name}"
package_version="2.9.0~pre0+git20221105.ffb6bda926"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1.2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
