#!/bin/bash -e

mirror="http://ports.ubuntu.com"

package_name="connman"
debian_pkg_name="${package_name}"
package_version="1.36"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

bionic_version="~bionic+20180517"
