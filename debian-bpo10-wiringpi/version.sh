#!/bin/bash -e

mirror="http://archive.ubuntu.com/ubuntu"

package_name="wiringpi"
debian_pkg_name="${package_name}"
package_version="2.50"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="buster"
deb_arch="armhf"
