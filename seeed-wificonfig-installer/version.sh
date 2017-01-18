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

debian_version="${package_version}-0rcnee17"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-wificonfig/raw/master/deploy"

v12="v0.12.17"
 v4="v4.6.2"
 v6="v6.9.1"

wificonfig="wificonfig-0.1.5-c59f06b"

debian_dl_1="${dl_mirror}/${wificonfig}-${v12}.tar.xz"
debian_dl_2="${dl_mirror}/${wificonfig}-${v4}.tar.xz"
debian_dl_3="${dl_mirror}/${wificonfig}-${v6}.tar.xz"

jessie_version="~bpo80+20170118+1"
