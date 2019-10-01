#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libjpeg-turbo"
debian_pkg_name="${package_name}"
package_version="1.5.1"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libj/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

stretch_version="~stretch+20191001"
