#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.1.4-git20161108"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

#git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_repo="https://github.com/RobertCNelson/Robotics_Cape_Installer"
git_sha="043935c056d7da432f704572c098149715d5900a"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20161108+1"
