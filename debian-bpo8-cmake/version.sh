#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="cmake"
debian_pkg_name="${package_name}"
package_version="3.5.2"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
