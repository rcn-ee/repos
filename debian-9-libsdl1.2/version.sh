#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libsdl1.2"
debian_pkg_name="${package_name}"
package_version="1.2.15+dfsg1"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="SDL-1.2.15/"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180116"
