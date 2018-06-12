#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.6

package_name="ardupilot-copter-3.6-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.6.0-git20180605"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="2a4b780594bedffaca0a78e2b2a8b8f778fa0bb8"
git_branch="Copter-3.6"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180612"
stretch_version="~stretch+20180612"
buster_version="~buster+20180612"
bionic_version="~bionic+20180612"
