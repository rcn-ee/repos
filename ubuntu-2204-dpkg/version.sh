#!/bin/bash -e

#https://packages.ubuntu.com/source/jammy/dpkg
mirror="http://ports.ubuntu.com"

package_name="dpkg"
debian_pkg_name="${package_name}"
package_version="1.21.1ubuntu2.2"
package_source="${debian_pkg_name}_${package_version}.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version=""
debian_untar=""
debian_patch=""
local_patch="rcnee1"

jammy_version="~jammy+20230701"
