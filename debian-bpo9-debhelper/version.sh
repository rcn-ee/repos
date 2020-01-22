#!/bin/bash -e

#https://snapshot.debian.org/archive/debian/20171125T160845Z/pool/main/d/debhelper/debhelper_10.10.9~bpo9%2B1.dsc
mirror="https://snapshot.debian.org/archive/debian/20171125T160845Z"

package_name="debhelper"
debian_pkg_name="${package_name}"
package_version="10.10.9~bpo9+1"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
#debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
