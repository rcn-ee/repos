#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="systemd"
debian_pkg_name="${package_name}"
package_version="44"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-11+deb7u4"
debian_untar="${package_name}_${debian_version}.debian.tar.gz"
debian_patch=""
local_patch="rcnee1"

wheezy_version="~bpo70+20151009+1"
