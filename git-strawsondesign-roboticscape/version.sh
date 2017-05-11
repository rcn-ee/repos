#!/bin/bash -e

#https://github.com/StrawsonDesign/Robotics_Cape_Installer

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.3.4-git20170324"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="5da76969737bb892ff31ed0294fc52c88b061d7d"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170511"
stretch_version="~stretch+20170511"
