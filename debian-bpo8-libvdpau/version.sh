#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libvdpau"
debian_pkg_name="${package_name}"
package_version="1.1.1-6"

git_repo=""
git_sha=""
reprepro_dir="libv/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
