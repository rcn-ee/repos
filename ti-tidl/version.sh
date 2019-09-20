#!/bin/bash -e

#https://github.com/rcn-ee/tidl-api/tree/v01.02.02-bb.org

package_name="ti-tidl"
debian_pkg_name="${package_name}"
package_version="01.02.02-bb.org-0.2"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/tidl-api.git"
git_sha="b7bc34215efeeb8b2a16bb6e2c7385875aeb539f"
reprepro_dir="o/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee2"
debian_patch=""
debian_diff=""

stretch_version="~stretch+20190919"
