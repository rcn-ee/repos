#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot

package_name="ardupilot-plane-bbbmini"
debian_pkg_name="${package_name}"
package_version="3.8.0-git20170608"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="45147af4553da0b19d7165a7c74ca56bd8f2b04b"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170609"
stretch_version="~stretch+20170609"
