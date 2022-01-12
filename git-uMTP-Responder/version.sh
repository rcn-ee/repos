#!/bin/bash -e

#https://github.com/viveris/uMTP-Responder

#mirror="http://http.debian.net/debian"

package_name="umtp-responder"
debian_pkg_name="${package_name}"
package_version="1.6.2-git20211226.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/viveris/uMTP-Responder"
git_sha="73287dfd9d6ec187538d76c062a09d6757efea9d"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""

clear_changelog="enable"

bullseye_version="~bullseye+20220112"
