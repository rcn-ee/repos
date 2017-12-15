#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.5

package_name="ardupilot-copter-blue"
debian_pkg_name="${package_name}"
package_version="3.5.4-git20171122"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="284349c33b274ef5bcd625ff89b57ff9f2993453"
git_branch="Copter-3.5"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171215"
stretch_version="~stretch+20171215"
buster_version="~buster+20171215"
