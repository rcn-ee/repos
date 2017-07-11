#!/bin/bash -e

mirror="https://mentors.debian.net/debian"

package_name="sigrok-cli"
debian_pkg_name="${package_name}"
package_version="0.7.0"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
#debian_untar="${package_name}_${debian_version}.debian.tar.xz"

jessie_version="~jessie+20170711"
stretch_version="~stretch+20170711"
