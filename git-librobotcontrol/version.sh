#!/bin/bash -e

#https://github.com/beagleboard/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.5-git20200715.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/beagleboard/librobotcontrol"
git_sha="290e14f6de7d6e6b00766ab8af0595713c7e5c48"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20200716"
buster_version="~buster+20200716"
bionic_version="~bionic+20200716"
