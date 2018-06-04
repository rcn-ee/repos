#!/bin/bash -e

mirror="http://archive.ubuntu.com/ubuntu"

package_name="npm"
debian_pkg_name="${package_name}"
package_version="3.5.2"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}_${package_version}.orig"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu4"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20180604"
