#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.2

package_name="ardupilot-rover-blue-librobotics"
debian_pkg_name="${package_name}"
package_version="3.2.3-git20180408"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="261f998fe08713b40353ed6974d00e038a2db30b"
git_branch="Rover-3.2"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180413"
stretch_version="~stretch+20180413"
