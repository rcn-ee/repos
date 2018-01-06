#!/bin/bash -e

mirror="http://snapshot.debian.org/archive/debian/20151101T042306Z"

package_name="libsdl1.2"
debian_pkg_name="${package_name}"
package_version="1.2.15"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="SDL-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-11"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

jessie_version="~jessie+20180105"
