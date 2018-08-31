#!/bin/bash -e

#https://packages.debian.org/source/buster/mesa
mirror="http://http.debian.net/debian"
#mirror="https://snapshot.debian.org/archive/debian/20180604T155423Z/"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="18.1.6"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"
local_patch="rcnee0"

stretch_version="~stretch+20180831"
