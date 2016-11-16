#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="0.15.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy"

v12="v0.12.17"
 v4="v4.6.2"
 v6="v6.9.1"

           node_red="node-red-0.15.2-339aaae"
node_red_beaglebone="node-red-node-beaglebone-0.1.8-5c1edc6"
       node_red_upm="node-red-node-bb-upm-0.0.1-8d217ab"
   node_red_mongodb="node-red-node-mongodb-0.0.10-5c1edc6"

 debian_dl_1="${dl_mirror}/${node_red}-${v12}.tar.xz"
 debian_dl_2="${dl_mirror}/${node_red}-${v4}.tar.xz"
 debian_dl_3="${dl_mirror}/${node_red}-${v6}.tar.xz"
 debian_dl_4="${dl_mirror}/${node_red_beaglebone}-${v12}.tar.xz"
 debian_dl_5="${dl_mirror}/${node_red_beaglebone}-${v4}.tar.xz"
 debian_dl_6="${dl_mirror}/${node_red_beaglebone}-${v6}.tar.xz"
 debian_dl_7="${dl_mirror}/${node_red_upm}-${v12}.tar.xz"
 debian_dl_8="${dl_mirror}/${node_red_upm}-${v4}.tar.xz"
 debian_dl_9="${dl_mirror}/${node_red_upm}-${v6}.tar.xz"
debian_dl_10="${dl_mirror}/${node_red_mongodb}-${v12}.tar.xz"
debian_dl_11="${dl_mirror}/${node_red_mongodb}-${v4}.tar.xz"
debian_dl_12="${dl_mirror}/${node_red_mongodb}-${v6}.tar.xz"

jessie_version="~bpo80+20161116+1"
stretch_version="~bpo90+20161116+1"
xenial_version="~bpo1604+20161116+1"
