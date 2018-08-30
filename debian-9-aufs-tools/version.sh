#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="aufs-tools"
debian_pkg_name="${package_name}"
epoch="1"
package_version="4.9+20170918"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="a/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180830"
