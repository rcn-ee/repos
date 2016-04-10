#!/bin/bash -e

#https://github.com/Pillar1989/mraa/tree/BBGW

package_name="libmraa"
debian_pkg_name="${package_name}"
package_version="0.9.5-git20160410"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/Pillar1989/mraa"
git_sha="0cd186cae431d2c8fec1665b353ef22f524897b4"
reprepro_dir="libm/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160410+1"
