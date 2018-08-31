#!/bin/bash -e

mirror="http://archive.ubuntu.com/ubuntu"

package_name="wayland"
debian_pkg_name="${package_name}"
package_version="1.15.0-2"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="ubuntu"
suite="bionic"
deb_arch="armhf"
