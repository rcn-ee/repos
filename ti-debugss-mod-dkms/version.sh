#!/bin/bash -e

#http://git.ti.com/gitweb/?p=sdo-emu/dsptop.git;a=summary

package_name="debugss-mod-dkms"
debian_pkg_name="${package_name}"
package_version="1.3.0-git20160314"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/sdo-emu/dsptop.git"
git_sha="4d92879b632ba70402b61fa65cc58f5373eb5217"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160324+1"
stretch_version="~bpo90+20160324+1"
wily_version="~bpo1510+20160324+1"
xenial_version="~bpo1604+20160324+1"
