#!/bin/bash -e

#https://packages.debian.org/source/trixie/tzdata

mirror="http://http.debian.net/debian"

package_name="tzdata"
debian_pkg_name="${package_name}"
package_version="2024a"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="bbbio0"

bookworm_version="~bookworm+20240707"
