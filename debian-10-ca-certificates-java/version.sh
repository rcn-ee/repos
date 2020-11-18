#!/bin/bash -e

#https://packages.debian.org/source/buster/systemd

mirror="http://http.debian.net/debian"

package_name="ca-certificates-java"
debian_pkg_name="${package_name}"
package_version="20190405"
package_source="${debian_pkg_name}_${package_version}.tar.xz"
src_dir="ca-certificates-java"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

buster_version="~buster+20201118"
