#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="wpa"
debian_pkg_name="${package_name}"
package_version="2.3-git20141006"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/hostap"
git_sha="724fce8fff27e18dd4ebeec9481b958eb5628ee9"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""
local_patch="rcnee1"

jessie_version="~bpo80+20160426+1"
