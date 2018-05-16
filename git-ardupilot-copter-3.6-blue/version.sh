#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.6

package_name="ardupilot-copter-3.6-blue"
debian_pkg_name="${package_name}"
package_version="3.6.0-git20180425"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="d846a122f0d807b1075467f7a4af78783b4c6003"
git_branch="Copter-3.6"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180516"
stretch_version="~stretch+20180516"
buster_version="~buster+20180516"
bionic_version="~bionic+20180516"
