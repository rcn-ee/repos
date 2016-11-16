#!/bin/bash -e

package_name="gcp-iot-demo"
debian_pkg_name="${package_name}"
package_version="0.0.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="g/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""
sbuild_chroot="nodejs-v0.12.x"

dl_mirror="https://github.com/rcn-ee/npm-package-gcp-iot-demo/raw/master/deploy"

v12="v0.12.17"
 v4="v4.6.2"
 v6="v6.9.1"

node_gcp="gcp-iot-demo-0.0.1-fb406df"

debian_dl_1="${dl_mirror}/${node_gcp}-${v12}.tar.xz"
debian_dl_2="${dl_mirror}/${node_gcp}-${v4}.tar.xz"
debian_dl_3="${dl_mirror}/${node_gcp}-${v6}.tar.xz"


jessie_version="~bpo80+20161116+1"
