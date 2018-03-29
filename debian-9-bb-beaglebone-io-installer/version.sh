#!/bin/bash -e

package_name="bb-beaglebone-io-installer"
debian_pkg_name="${package_name}"
package_version="3.0.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/stretch"

v6="v6.14.0"
v8="v8.11.0"

node_red_bbio="beaglebone-io-3.0.0-cdc5ef2"

debian_dl_1="${dl_mirror}/${node_red_bbio}-${v6}.tar.xz"
debian_dl_2="${dl_mirror}/${node_red_bbio}-${v8}.tar.xz"

stretch_version="~stretch+20180329"
