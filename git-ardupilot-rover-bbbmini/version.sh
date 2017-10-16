#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.2

package_name="ardupilot-rover-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.2.0-git20170825"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="b1dafab91b6cdc1dd5c1e11d056ce273a47a126f"
git_branch="Rover-3.2"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171016"
stretch_version="~stretch+20171016"
