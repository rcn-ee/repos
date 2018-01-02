#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="linux"
debian_pkg_name="${package_name}"
package_version="4.9.65-3+deb9u1~bpo8+1"

git_repo=""
git_sha=""
reprepro_dir="l/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
