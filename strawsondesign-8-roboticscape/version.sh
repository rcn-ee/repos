#!/bin/bash -e

#https://github.com/StrawsonDesign/Robotics_Cape_Installer

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.3.3-git20170306"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="4f2cd6ce95c2d518cb09f2df040b9a46b45c18cd"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee4"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20170306"
