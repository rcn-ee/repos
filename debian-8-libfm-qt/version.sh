#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libfm-qt"
debian_pkg_name="${package_name}"
package_version="0.10.0+20151214"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="libf/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee2"

jessie_version="~bpo80+20160222+1"
