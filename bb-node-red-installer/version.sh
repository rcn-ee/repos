#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="0.13.4-git20160531"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""
#           NODERED="node-red-0.13.4-f1ce0fa-v0.12.13.tar.xz"
#NODERED_BEAGLEBONE="node-red-node-beaglebone-0.1.6-acb6fe5-v0.12.13.tar.xz"
#    NODERED_BB_UPM="node-red-node-bb-upm-0.0.0-67ff009-v0.12.13.tar.xz"
#   NODERED_MONGODB="node-red-node-mongodb-0.0.5-f91b7c4-v0.12.13.tar.xz"
#debian_dl_1="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/${NODERED}"
#debian_dl_2="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/${NODERED_BEAGLEBONE}"
#debian_dl_3="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/${NODERED_BB_UPM}"
#debian_dl_4="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/${NODERED_MONGODB}"

stretch_version="~bpo90+20160611+1"
xenial_version="~bpo1604+20160611+1"
jessie_version="~bpo80+20160612+1"
