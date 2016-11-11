#!/bin/bash -e

mirror="http://ports.ubuntu.com"

package_name="dh-autoreconf"
debian_pkg_name="${package_name}"
package_version="12~ubuntu16.04.1"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

dist="ubuntu"
suite="xenial"
deb_arch="armhf"

