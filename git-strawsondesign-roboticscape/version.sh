#!/bin/bash -e

#https://github.com/StrawsonDesign/Robotics_Cape_Installer

package_name="roboticscape"
debian_pkg_name="${package_name}"
package_version="0.3.4-git20170602"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/Robotics_Cape_Installer"
git_sha="1dfcf302a5f76e68dc005673d411002181b73ce9"
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee4"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171108"
stretch_version="~stretch+20171108"
buster_version="~buster+20171108"
xenial_version="~xenial+20171108"
