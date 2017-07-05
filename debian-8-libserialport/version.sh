#!/bin/bash -e

mirror="https://mentors.debian.net/debian"

package_name="libserialport"
debian_pkg_name="${package_name}"
package_version="0.1.1"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20170705"
stretch_version="~stretch+20170705"
