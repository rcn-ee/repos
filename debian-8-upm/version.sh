#!/bin/bash -e

#https://github.com/Pillar1989/upm/tree/BBGW

package_name="upm"
debian_pkg_name="${package_name}"
package_version="0.7.0-git20160609"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

#git_repo="https://github.com/Pillar1989/upm"
git_repo="https://github.com/rcn-ee/upm"
git_sha="c5f2b60f253b2828ffd8d7421fd34a71ec171e2a"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee3"
sbuild_chroot="nodejs-v0.12.x"

jessie_version="~bpo80+20160609+1"
