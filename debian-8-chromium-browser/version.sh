#!/bin/bash -e

#mirror="http://http.debian.net/debian"
mirror="http://ports.ubuntu.com"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="55.0.2883.87"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu2.1328"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

jessie_version="~bpo80+20161220+1"
