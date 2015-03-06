#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="chromium-browser"
debian_pkg_name="chromium-browser"
package_version="41.0.2272.76"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_patch="${debian_pkg_name}_${debian_version}.debian.tar.xz"
debian_diff=""

archive="enable"

jessie_version="~20150306+1"
