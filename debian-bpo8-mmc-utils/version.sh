#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="mmc-utils"
debian_pkg_name="${package_name}"
package_version="0~gita3d3331"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"

