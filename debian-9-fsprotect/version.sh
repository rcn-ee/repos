#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="fsprotect"
debian_pkg_name="${package_name}"
package_version="1.0.7"
package_source="${debian_pkg_name}_${package_version}.tar.xz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="f/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180830"
