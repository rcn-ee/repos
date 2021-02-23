#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="smartmontools"
debian_pkg_name="${package_name}"
package_version="7.2"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo10+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="buster"
deb_arch="armhf"
