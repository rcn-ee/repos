#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="log4cxx"
debian_pkg_name="${package_name}"
package_version="0.10.0"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-12"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"

