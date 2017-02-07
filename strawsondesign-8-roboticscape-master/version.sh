#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.3.1-git20170206"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="48619c4061163547346a7d7f77da0bdd03088e01"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20170207+1"
