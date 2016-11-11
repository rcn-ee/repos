#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libseccomp"
debian_pkg_name="${package_name}"
package_version="2.2.3"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3~bpo8+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
