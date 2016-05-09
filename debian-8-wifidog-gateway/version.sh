#!/bin/bash -e

#https://github.com/wifidog/wifidog-gateway

package_name="wifidog-gateway"
debian_pkg_name="${package_name}"
package_version="1.3.0-git20160426"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/wifidog/wifidog-gateway"
git_sha="628b7ea360fe4b5cb676d0659e3b25eb8693f347"
reprepro_dir="w/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee4"
debian_patch=""
debian_diff=""

jessie_version="~bpo80+20160505+1"
