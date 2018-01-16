#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="mame"
debian_pkg_name="${package_name}"
package_version="0.154"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/non-free/${reprepro_dir}/"

debian_version="${package_version}-3.1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

jessie_version="~jessie+20180105"
