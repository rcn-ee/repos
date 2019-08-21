#!/bin/bash -e

#https://github.com/rcn-ee/tidl-api/tree/v01.02.02-bb.org

package_name="ti-tidl"
debian_pkg_name="${package_name}"
package_version="01.02.02-bb.org-0.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/tidl-api.git"
git_sha="e421bdacb6fdf78a2cfb20fb988163dafc09afb8"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190821"
