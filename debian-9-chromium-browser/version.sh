#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="63.0.3239.84"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1~deb9u1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

stretch_version="~stretch+20171227"
