#!/bin/bash -e

mirror="http://snapshot.debian.org/archive/debian/20150831T093342Z"

package_name="libkscreen"
debian_pkg_name="${package_name}"
package_version="5.3.2"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="libk/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_patch="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_diff=""

jessie_version="~bpo80+20151110+1"
