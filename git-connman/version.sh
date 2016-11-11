#!/bin/bash -e

#https://git.kernel.org/cgit/network/connman/connman.git/

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.32-git20160418"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/network/connman/connman.git"
git_sha="57a31db51504f52a83b004dc3c2d3e012731b841"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee2"

jessie_version="~bpo80+20161111+1"
stretch_version="~bpo90+20161111+1"
xenial_version="~bpo1604+20161111+1"
