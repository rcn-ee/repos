#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.2.1-git20161121"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="0e831e375a1931fb4e79c047032af0358aa6136e"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20161121+1"
