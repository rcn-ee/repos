#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="npm"
debian_pkg_name="${package_name}"
package_version="5.8.0+ds6"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-5.8.0"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20191028"
