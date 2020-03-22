#!/bin/bash -e

#http://security.debian.org/debian-security/pool/updates/main/c/chromium-browser/chromium-browser_69.0.3497.92-1~deb9u1.debian.tar.xz

#mirror="http://http.debian.net/debian"
mirror="http://security.debian.org/debian-security"
#https://snapshot.debian.org/archive/debian-security/20180701T010208Z/pool/updates/main/c/chromium-browser/chromium_67.0.3396.87-1~deb9u1_amd64.deb
mirror="https://snapshot.debian.org/archive/debian-security/20180701T010208Z/"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="67.0.3396.87"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/updates/main/${reprepro_dir}/"

debian_version="${package_version}-1~deb9u1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee1"

stretch_version="~stretch+20200321"
