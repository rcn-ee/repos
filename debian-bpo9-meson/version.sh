#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="meson"
debian_pkg_name="${package_name}"
package_version="0.42.1"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo9+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
