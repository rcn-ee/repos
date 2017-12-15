#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Rover-3.2

package_name="ardupilot-rover-blue"
debian_pkg_name="${package_name}"
package_version="3.2.0-git20171205"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="a830db7c4f99977d78b0cf6ffe4f8413935b0f79"
git_branch="Rover-3.2"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171215"
stretch_version="~stretch+20171215"
buster_version="~buster+20171215"
