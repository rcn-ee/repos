#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libclc"
debian_pkg_name="${package_name}"
package_version="0.2.0+git20171106"

git_repo=""
git_sha=""
reprepro_dir="libc/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
