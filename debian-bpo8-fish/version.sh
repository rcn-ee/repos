#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="fish"
debian_pkg_name="${package_name}"
package_version="2.2.0"

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3~bpo8+1"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"

