#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.5

package_name="ardupilot-copter-blue"
debian_pkg_name="${package_name}"
package_version="3.5.3-git20170912"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="528d4d83d70d26dbca0f1e7e786a32a5a107ec7b"
git_branch="Copter-3.5"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170914"
stretch_version="~stretch+20170914"
