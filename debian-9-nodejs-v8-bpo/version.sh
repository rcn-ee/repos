#!/bin/bash -e

#https://nodejs.org/download/release/latest-v8.x/

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="8.11.1~dfsg"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="node-v8.11.1"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2~bpo9+1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20180518"
