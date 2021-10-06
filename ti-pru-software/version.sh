#!/bin/bash -e

#http://git.ti.com/gitweb/?p=pru-software-support-package/pru-software-support-package.git;a=summary

package_name="ti-pru-software"
debian_pkg_name="${package_name}"
package_version="5.9.0-git20210915.2"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://git.ti.com/pru-software-support-package/pru-software-support-package.git"
git_sha="4e9676ee9ef9c332ab0ad40709fb5cb8944e72bc"
reprepro_dir="t/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211006"
