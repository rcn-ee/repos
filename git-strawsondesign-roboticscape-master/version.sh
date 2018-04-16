#!/bin/bash -e

#https://github.com/StrawsonDesign/Robotics_Cape_Installer

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.4.0-git20180415"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="998c1a3f3db8117f3d57fff5f06b32d811a032a1"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20180416"
