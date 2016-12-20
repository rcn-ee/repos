#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="ros-ros-comm-msgs"
debian_pkg_name="${package_name}"
package_version="1.11.2"

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-5"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"

