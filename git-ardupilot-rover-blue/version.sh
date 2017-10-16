#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot

package_name="ardupilot-rover-blue"
debian_pkg_name="${package_name}"
package_version="3.1.2-git20170315"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="0fa522b805b97c438aa3976e8bea45598c46d4a9"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20171016"
stretch_version="~stretch+20171016"
