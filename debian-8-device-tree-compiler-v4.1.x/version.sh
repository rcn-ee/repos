#!/bin/bash -e

#mirror="http://http.debian.net/debian"

package_name="device-tree-compiler"
debian_pkg_name="${package_name}"
package_version="1.4.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/RobertCNelson/dtc"
git_sha="1e75ebc95be2eaadf1e959e1956e32203a80432e"
reprepro_dir="d/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_patch=""
debian_diff=""
local_patch="rcnee1"

jessie_version="~bpo80+20160224+1"
xenial_version="~bpo1604+20160224+1"
