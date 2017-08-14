#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libglvnd"
debian_pkg_name="${package_name}"
package_version="0.2.999+git20170802"

git_repo=""
git_sha=""
reprepro_dir="libc/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
