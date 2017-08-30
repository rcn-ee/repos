#!/bin/bash -e

#mirror="http://http.debian.net/debian"
mirror="http://ports.ubuntu.com"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="60.0.3112.113"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu0.16.04.1298"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

jessie_version="~jessie+20170830"
