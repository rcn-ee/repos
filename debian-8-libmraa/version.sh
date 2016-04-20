#!/bin/bash -e

#https://github.com/Pillar1989/mraa/tree/BBGW

package_name="libmraa"
debian_pkg_name="${package_name}"
package_version="0.9.5-git20160420"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Pillar1989/mraa"
git_sha="d860fc8d4e8a38ad8cf62345dfeb6b53fe62afdb"
reprepro_dir="libm/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160420+1"
