#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="usb-modeswitch"
debian_pkg_name="${package_name}"
package_version="2.4.0+repack0"

git_repo=""
git_sha=""
reprepro_dir="u/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~bpo8+1"
debian_untar=""
debian_patch=""

dist="debian"
suite="jessie"
deb_arch="armhf"
