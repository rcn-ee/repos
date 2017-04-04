#!/bin/bash -e

#https://github.com/ArduPilot/ardupilot

package_name="ardupilot-copter-test"
debian_pkg_name="${package_name}"
package_version="3.5.0-git20170324"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/diydrones/ardupilot.git"
git_sha="f240ab109c3232e1da7df612ec404f4e00af739d"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20170404"
