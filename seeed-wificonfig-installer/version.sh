#!/bin/bash -e

package_name="seeed-wificonfig-installer"
debian_pkg_name="${package_name}"
package_version="0.1.5"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee7"
debian_untar=""
debian_patch=""
debian_dl_1="https://github.com/rcn-ee/npm-package-wificonfig/raw/master/deploy/wificonfig-0.1.5-2a7ba99-v0.12.15-bbgw-bone101-dir-change.tar.xz"

jessie_version="~bpo80+20160708+1"
