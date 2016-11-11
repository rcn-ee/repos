#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="e2fsprogs"
debian_pkg_name="${package_name}"
package_version="1.43"

git_repo=""
git_sha=""
reprepro_dir="e/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3~bpo8+1"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
