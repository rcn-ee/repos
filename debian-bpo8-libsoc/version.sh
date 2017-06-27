#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libsoc"
debian_pkg_name="${package_name}"
package_version="0.8.2"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
