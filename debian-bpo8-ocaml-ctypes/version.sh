#!/bin/bash -e

mirror="http://snapshot.debian.org/archive/debian/20151204T154948Z"

package_name="ocaml-ctypes"
debian_pkg_name="${package_name}"
package_version="0.4.1"

git_repo=""
git_sha=""
reprepro_dir="o/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
