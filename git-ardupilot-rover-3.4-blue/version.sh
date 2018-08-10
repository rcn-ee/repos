#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.4

package_name="ardupilot-rover-3.4-blue"
debian_pkg_name="${package_name}"
package_version="3.4.2-git20180729"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="318a941d15c9d5e4a76b73541eac15cd0f3d50f9"
git_branch="Rover-3.4"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180810"
stretch_version="~stretch+20180810"
buster_version="~buster+20180810"
bionic_version="~bionic+20180810"
