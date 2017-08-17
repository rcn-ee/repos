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

#node-red: v0.12.x = eol

dl_mirror_eol="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy"
dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/jessie"

v12="v0.12.17"
 v4="v4.8.4"
 v6="v6.11.2"

           node_red_eol="node-red-0.15.2-74f2180"
node_red_beaglebone_eol="node-red-node-beaglebone-0.1.8-7a39c6f"
       node_red_upm_eol="node-red-node-bb-upm-0.0.1-8d217ab"
   node_red_mongodb_eol="node-red-node-mongodb-0.0.11-7a39c6f"

           node_red="node-red-0.17.5-e09efba"
node_red_beaglebone="node-red-node-beaglebone-0.1.9-363bb55"
       node_red_upm="node-red-node-bb-upm-0.0.1-8d217ab"
   node_red_mongodb="node-red-node-mongodb-0.0.13-363bb55"

 debian_dl_1="${dl_mirror_eol}/${node_red_eol}-${v12}.tar.xz"
 debian_dl_2="${dl_mirror}/${node_red}-${v4}.tar.xz"
 debian_dl_3="${dl_mirror}/${node_red}-${v6}.tar.xz"
 debian_dl_4="${dl_mirror_eol}/${node_red_beaglebone_eol}-${v12}.tar.xz"
 debian_dl_5="${dl_mirror}/${node_red_beaglebone}-${v4}.tar.xz"
 debian_dl_6="${dl_mirror}/${node_red_beaglebone}-${v6}.tar.xz"
 debian_dl_7="${dl_mirror_eol}/${node_red_upm_eol}-${v12}.tar.xz"
 debian_dl_8="${dl_mirror}/${node_red_upm}-${v4}.tar.xz"
 debian_dl_9="${dl_mirror}/${node_red_upm}-${v6}.tar.xz"
debian_dl_10="${dl_mirror_eol}/${node_red_mongodb_eol}-${v12}.tar.xz"
debian_dl_11="${dl_mirror}/${node_red_mongodb}-${v4}.tar.xz"
debian_dl_12="${dl_mirror}/${node_red_mongodb}-${v6}.tar.xz"

jessie_version="~jessie+20170817"
