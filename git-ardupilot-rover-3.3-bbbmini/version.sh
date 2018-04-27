#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.3

package_name="ardupilot-rover-3.3-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.3.0-git20180419"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="42b4991f6cd1ed7cc6313b0144aab255a04ff2b7"
git_branch="Rover-3.3"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180427"
stretch_version="~stretch+20180427"
buster_version="~buster+20180427"
bionic_version="~bionic+20180427"
