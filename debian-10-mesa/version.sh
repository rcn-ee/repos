#!/bin/bash -e

#https://snapshot.debian.org/package/mesa/
#https://snapshot.debian.org/archive/debian/20190508T162608Z/pool/main/m/mesa/mesa_19.0.3-1.diff.gz
mirror="https://snapshot.debian.org/archive/debian/20190511T144548Z"

package_name="mesa"
debian_pkg_name="${package_name}"
package_version="19.0.3"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="m/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar=""
debian_patch="${package_name}_${debian_version}.diff.gz"
local_patch="rcnee1"

buster_version="~buster+20200512"
