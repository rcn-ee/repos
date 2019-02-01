#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="smartmontools"
debian_pkg_name="${package_name}"
package_version="6.6"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20190201"
