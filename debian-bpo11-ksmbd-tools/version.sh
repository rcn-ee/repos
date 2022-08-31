#!/bin/bash -e

#https://packages.debian.org/bullseye-backports/ksmbd-tools
mirror="https://deb.debian.org/debian"

package_name="ksmbd-tools"
debian_pkg_name="${package_name}"
package_version="3.4.5"

git_repo=""
git_sha=""
reprepro_dir="k/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo11+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="bullseye"
deb_arch="armhf"
