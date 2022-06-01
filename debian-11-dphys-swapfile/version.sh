#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="dphys-swapfile"
debian_pkg_name="${package_name}"
package_version="20100506"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-7"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

bullseye_version="~bullseye+20220601"
