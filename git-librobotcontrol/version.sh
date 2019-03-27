#!/bin/bash -e

#https://github.com/StrawsonDesign/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.4-git20190227.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

#git_repo="https://github.com/StrawsonDesign/librobotcontrol"
git_repo="https://github.com/rcn-ee/librobotcontrol"
git_sha="06c406de2c7b63a246a525f243d4e170ec0c664d"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190327"
buster_version="~buster+20190327"
bionic_version="~bionic+20190327"
