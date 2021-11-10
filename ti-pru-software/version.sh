#!/bin/bash -e

#http://git.ti.com/gitweb/?p=pru-software-support-package/pru-software-support-package.git;a=summary

package_name="ti-pru-software"
debian_pkg_name="${package_name}"
package_version="6.0.0-git20211019.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/pru-software-support-package/pru-software-support-package.git"
git_sha="acd8479d7f3bdbb4536ceca3cd6803662babaa5a"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211110"
