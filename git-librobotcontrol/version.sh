#!/bin/bash -e

#https://github.com/StrawsonDesign/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.3-git20181005.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/librobotcontrol"
git_sha="f61b0ee50568939d96475d4acd934ef2edc7314a"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20181005"
buster_version="~buster+20181005"
bionic_version="~bionic+20181005"
