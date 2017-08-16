#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/plane3.8

package_name="ardupilot-plane-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.8.0-git20170803"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="e66f30eb90f75e52a3e37e25a65df4a532fdead2"
git_branch="plane3.8"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170816"
stretch_version="~stretch+20170816"
