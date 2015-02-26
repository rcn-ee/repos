#!/bin/bash -e

mirror="http://ftp.de.debian.org/debian"

package_name="chromium-browser"
debian_pkg_name="chromium-browser"
package_version="40.0.2214.111"
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

wheezy_version="~bpo70+20141006+1"
jessie_version="~20150226+1"
