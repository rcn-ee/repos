#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="freerdp2"
debian_pkg_name="${package_name}"
package_version="2.0.0~git20161130.1.e60d0d5+dfsg1-1"

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
