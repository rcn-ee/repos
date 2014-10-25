#!/bin/bash -e

#https://omahaproxy.appspot.com/

package_name="chromium"
debian_pkg_name="chromium-browser"
package_version="38.0.2125.101"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="http://gsdview.appspot.com/chromium-browser-official"

debian_version="${package_version}-4"
debian_patch=""
debian_diff=""

archive="enable"

wheezy_version="~bpo70+20141006+1"
jessie_version="~20141024+2"
