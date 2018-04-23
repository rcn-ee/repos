#!/bin/bash -e

#https://github.com/StrawsonDesign/Robotics_Cape_Installer

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.4.1-git20180423"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="cccf35048afdb42c0cc93a35b33d65a91274b023"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20180423"
