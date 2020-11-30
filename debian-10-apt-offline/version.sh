#!/bin/bash -e

#https://packages.debian.org/source/buster-backports/apt-offline

mirror="http://http.debian.net/debian"

package_name="apt-offline"
debian_pkg_name="${package_name}"
package_version="1.8.2"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="a/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20201130"
