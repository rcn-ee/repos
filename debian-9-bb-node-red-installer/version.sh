#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="0.17.5"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/stretch"

v6="v6.12.3"
v8="v8.9.4"

node_red="node-red-0.17.5-a3640bd"
node_red_mongodb="node-red-node-mongodb-0.0.13-9f290f6"
node_red_gpio="node-red-contrib-gpio-0.10.0"
node_red_serial="node-red-node-serialport-0.6.2"
node_red_can="node-red-contrib-can-1.0.6"

debian_dl_1="${dl_mirror}/${node_red}-${v8}.tar.xz"
debian_dl_2="${dl_mirror}/${node_red_mongodb}-${v8}.tar.xz"
debian_dl_3="${dl_mirror}/${node_red_gpio}-${v8}.tar.xz"
debian_dl_4="${dl_mirror}/${node_red_serial}-${v8}.tar.xz"
debian_dl_5="${dl_mirror}/${node_red_can}-${v8}.tar.xz"

debian_dl_6="${dl_mirror}/${node_red}-${v6}.tar.xz"
debian_dl_7="${dl_mirror}/${node_red_mongodb}-${v6}.tar.xz"
debian_dl_8="${dl_mirror}/${node_red_gpio}-${v6}.tar.xz"
debian_dl_9="${dl_mirror}/${node_red_serial}-${v6}.tar.xz"
debian_dl_10="${dl_mirror}/${node_red_can}-${v6}.tar.xz"

stretch_version="~stretch+20180112"
