#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot

package_name="ardupilot-plane-blue"
debian_pkg_name="${package_name}"
package_version="3.8.0-git20170711"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="260412bf0f32bc316d5fbb57c43a105bf4d26194"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170712"
stretch_version="~stretch+20170712"
