#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libusbgx"
debian_pkg_name="${package_name}"
package_version="0.2.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_name}-v${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libu/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
old_debian_version="0.2.0-git20210811.5-3"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="bbbio1"

bullseye_version="~bullseye+20240118"
bookworm_version="~bookworm+20240118"
jammy_version="~jammy+20240118"
