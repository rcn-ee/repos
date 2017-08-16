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

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/stretch"

 v6="v6.11.2"

           node_red="node-red-0.17.5-e09efba"
node_red_beaglebone="node-red-node-beaglebone-0.1.9-363bb55"
       node_red_upm="node-red-node-bb-upm-0.0.1-8d217ab"
   node_red_mongodb="node-red-node-mongodb-0.0.13-363bb55"

 debian_dl_1="${dl_mirror}/${node_red}-${v6}.tar.xz"
 debian_dl_2="${dl_mirror}/${node_red_beaglebone}-${v6}.tar.xz"
 debian_dl_3="${dl_mirror}/${node_red_upm}-${v6}.tar.xz"
 debian_dl_4="${dl_mirror}/${node_red_mongodb}-${v6}.tar.xz"

stretch_version="~stretch+20170816"
