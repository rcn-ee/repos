#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/plane3.8

package_name="ardupilot-plane-blue"
debian_pkg_name="${package_name}"
package_version="3.8.2-git20171005"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="d88dff98a63d3abb43dd1b812b0e223528ebf9c7"
git_branch="plane3.8"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171016"
stretch_version="~stretch+20171016"
