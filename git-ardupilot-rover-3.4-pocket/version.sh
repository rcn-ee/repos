#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.4

package_name="ardupilot-rover-3.4-pocket"
debian_pkg_name="${package_name}"
package_version="3.4.0-git20180601"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/ArduPilot/ardupilot.git"
git_sha="615d7afc3ad80b00da10b9e83e70c65bfcbc8a43"
git_branch="Rover-3.4"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180604"
stretch_version="~stretch+20180604"
buster_version="~buster+20180604"
bionic_version="~bionic+20180604"
