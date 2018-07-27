#!/bin/bash -e

#https://github.com/StrawsonDesign/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.0-git20180726.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/librobotcontrol"
git_sha="f5aff296fb9c6287da227df8916f679f4262a0ca"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20180727"
buster_version="~buster+20180727"
bionic_version="~bionic+20180727"
