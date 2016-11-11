#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="firmware-nonfree"
debian_pkg_name="${package_name}"
package_version="20160824"

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/non-free/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
