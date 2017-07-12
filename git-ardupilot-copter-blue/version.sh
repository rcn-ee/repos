#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.5

package_name="ardupilot-copter-blue"
debian_pkg_name="${package_name}"
package_version="3.5.0-git20170711"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="01a504ac368b59349d8c502c53d7b22da0065793"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170711"
stretch_version="~stretch+20170711"
