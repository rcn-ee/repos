#!/bin/bash -e

#https://git.kernel.org/cgit/network/connman/connman.git/

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.34-git20170626"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.kernel.org/pub/scm/network/connman/connman.git"
git_sha="809e23b3a1a4e37f357cd46f65326c65dd4cfe23"
reprepro_dir="c/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20170629"
