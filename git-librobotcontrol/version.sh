#!/bin/bash -e

#https://github.com/StrawsonDesign/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.4-git20181123.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/librobotcontrol"
git_sha="eae42efee7aec547d0aaef9026d8a96000caa771"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20181124"
buster_version="~buster+20181124"
bionic_version="~bionic+20181124"
