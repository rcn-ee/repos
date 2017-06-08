#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot

package_name="ardupilot-plane-blue"
debian_pkg_name="${package_name}"
package_version="3.8.0-git20170607"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="a960c6526cdfde1be7213cbac96bfd7138614cc5"
reprepro_dir="a/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee1"
debian_patch=""
debian_diff=""

jessie_version="~jessie+20170608"
stretch_version="~stretch+20170608"
