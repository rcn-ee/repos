#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot
#https://github.com/ArduPilot/ardupilot/tree/Copter-3.5

package_name="ardupilot-copter-blue"
debian_pkg_name="${package_name}"
package_version="3.5.0-git20170716"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="633501f9724df8caf1f0749ddd3b98587baa334a"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170718"
stretch_version="~stretch+20170718"
