#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="python-evdev"
debian_pkg_name="${package_name}"
package_version="1.1.2+dfsg"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""

dist="debian"
suite="stretch"
deb_arch="armhf"
