#!/bin/bash -e

#https://github.com/omapconf/omapconf

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.2.2-git20161122"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="8a6ec2d140cf718e7aa7f24b935c34edb7cf7cc3"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee9"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20161219+1"
