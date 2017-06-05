#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.5

package_name="ardupilot-copter-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.5.0-git20170524"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="a1654fa83dc6d350e75606bbad53ac4d4366b333"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170605"
stretch_version="~stretch+20170605"
