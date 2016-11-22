#!/bin/bash -e

#https://github.com/etnaviv/libetnaviv

package_name="libetnaviv"
debian_pkg_name="${package_name}"
package_version="0.0.0-git20141102"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/etnaviv/libetnaviv"
git_sha="60105d1b0755e48b37d779d8a2b9c4b458b5a2fd"
reprepro_dir="libe/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee3"

jessie_version="~bpo80+20161122+1"
stretch_version="~bpo90+20161122+1"
xenial_version="~bpo1604+20161122+1"
