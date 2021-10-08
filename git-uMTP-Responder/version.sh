#!/bin/bash -e

#https://github.com/viveris/uMTP-Responder

#mirror="http://http.debian.net/debian"

package_name="umtp-responder"
debian_pkg_name="${package_name}"
package_version="1.4.3-git20210912.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/viveris/uMTP-Responder"
git_sha="e140e559edc914976e10bcab13d37a56c4c505b2"
reprepro_dir="u/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_patch=""
debian_diff=""

bullseye_version="~bullseye+20211008"
