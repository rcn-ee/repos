#!/bin/bash -e

#https://github.com/StrawsonDesign/librobotcontrol

package_name="librobotcontrol"
debian_pkg_name="${package_name}"
package_version="1.0.0-git20180705.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/StrawsonDesign/librobotcontrol"
git_sha="a3265e6fedc5fa05444878739d5d46ad0f819edb"
reprepro_dir="l/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

buster_version="~buster+20180706"
