#!/bin/bash -e

#mirror="http://ftp.de.debian.org/debian"
mirror="http://ports.ubuntu.com"

package_name="chromium-browser"
debian_pkg_name="${package_name}"
package_version="42.0.2311.135"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="chromium-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/universe/${reprepro_dir}/"

debian_version="${package_version}-1ubuntu1.1160"
debian_patch="${debian_pkg_name}_${package_version}-1ubuntu1.1160.debian.tar.xz"
debian_diff=""

archive="enable"

jessie_version="~bpo80+20150515+1"
