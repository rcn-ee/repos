#!/bin/bash -e

#https://github.com/Pillar1989/upm/tree/BBGW

package_name="upm"
debian_pkg_name="${package_name}"
package_version="0.5.1-git20160302"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Pillar1989/upm"
git_sha="d0c9eda1cbe367feee838be523d9ec5af921a8b7"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee6"

jessie_version="~bpo80+20160302+1"
