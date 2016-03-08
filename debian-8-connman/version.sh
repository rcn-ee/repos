#!/bin/bash -e

#https://git.kernel.org/cgit/network/connman/connman.git/

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.31-git20160308"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/network/connman/connman.git"
git_sha="9e96310aeef8aefc8de1b41ade21ad0cc1e17788"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160308+1"
stretch_version="~bpo90+20160308+1"
