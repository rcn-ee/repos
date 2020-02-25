#!/bin/bash -e

package_name="webthings-gateway"
debian_pkg_name="${package_name}"
package_version="0.11.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-1rcnee1"
debian_untar=""
debian_patch=""

buster_version="~buster+20200225"
