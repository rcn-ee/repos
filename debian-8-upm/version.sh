#!/bin/bash -e

#https://github.com/Pillar1989/upm/tree/BBGW

package_name="upm"
debian_pkg_name="${package_name}"
package_version="0.5.1-git20160410"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Pillar1989/upm"
git_sha="c6c0eb8907e92c805d8aee97babf8fd88ff11259"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160410+1"
