#!/bin/bash -e

#https://snapshot.debian.org/package/quilt/
mirror="http://http.debian.net/debian"

package_name="quilt"
debian_pkg_name="${package_name}"
package_version="0.63"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="q/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-8"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
local_patch="rcnee0"

stretch_version="~stretch+20190321"
