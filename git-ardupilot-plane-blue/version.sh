#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/plane3.8

package_name="ardupilot-plane-blue"
debian_pkg_name="${package_name}"
package_version="3.8.4-git20180108"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="e62e40a5c9f5e4a43712cd0767566f564cbd6911"
git_branch="plane3.8"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20180112"
stretch_version="~stretch+20180112"
buster_version="~buster+20180112"
