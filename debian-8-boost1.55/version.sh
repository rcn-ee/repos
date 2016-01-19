#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="boost1.55"
debian_pkg_name="${package_name}"
package_version="1.55.0+dfsg"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}.orig"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-3"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

jessie_version="~bpo80+20160119+1"
