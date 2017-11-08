#!/bin/bash -e

#http://git.ti.com/gitweb/?p=pru-software-support-package/pru-software-support-package.git;a=summary

package_name="pru-software-support-package"
debian_pkg_name="${package_name}"
package_version="5.0.1-git20160907"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/pru-software-support-package/pru-software-support-package.git"
git_sha="5e08c1f7c1f1d642b508e8b9cea246d9d8ef54c8"
reprepro_dir="p/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171108"
stretch_version="~stretch+20171108"
buster_version="~buster+20171108"
xenial_version="~xenial+20171108"
