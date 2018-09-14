#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.6

package_name="ardupilot-copter-3.6-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.6.0-git20180914"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="df360bb77a6624706b3df9ea41b072771004d43b"
git_branch="Copter-3.6"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180914"
stretch_version="~stretch+20180914"
buster_version="~buster+20180914"
bionic_version="~bionic+20180914"
