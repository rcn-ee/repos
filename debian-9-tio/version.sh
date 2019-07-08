#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="tio"
debian_pkg_name="${package_name}"
package_version="1.26"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="t/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

jessie_version="~jessie+20171108"
stretch_version="~stretch+20171108"
