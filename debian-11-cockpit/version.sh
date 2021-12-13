#!/bin/bash -e

#https://tracker.debian.org/pkg/cockpit
#https://packages.debian.org/source/stable/cockpit

mirror="http://http.debian.net/debian"

package_name="cockpit"
debian_pkg_name="${package_name}"
package_version="259"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

bullseye_version="~bullseye+20211213"
