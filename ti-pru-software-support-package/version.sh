#!/bin/bash -e

#http://git.ti.com/gitweb/?p=pru-software-support-package/pru-software-support-package.git;a=summary

package_name="pru-software-support-package"
debian_pkg_name="${package_name}"
package_version="5.1.0-git20180102"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/pru-software-support-package/pru-software-support-package.git"
git_sha="9fdfd56c9f8c0b16d27c153892e53a6c061011fb"
reprepro_dir="p/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180514"
stretch_version="~stretch+20180514"
buster_version="~buster+20180514"
xenial_version="~xenial+20180514"
bionic_version="~bionic+20180514"
