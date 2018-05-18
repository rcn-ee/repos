#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libuv1"
debian_pkg_name="${package_name}"
package_version="1.18.0-3~bpo9+1"

git_repo=""
git_sha=""
reprepro_dir="libu/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
