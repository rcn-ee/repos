#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="can-utils"
debian_pkg_name="${package_name}"
package_version="0.0+git20161220"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"

