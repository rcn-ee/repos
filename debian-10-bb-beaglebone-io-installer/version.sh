#!/bin/bash -e

package_name="bb-beaglebone-io-installer"
debian_pkg_name="${package_name}"
package_version="4.0.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee6"
debian_untar=""
debian_patch=""

#dl_mirror="https://github.com/rcn-ee/npm-package-node-red/raw/master/deploy/buster"
dl_mirror="http://gitlab.gfnd.rcn-ee.org/RobertCNelson/npm-package-node-red/raw/master/deploy/buster"

v10="v10.15.1"

node_red_bbio="beaglebone-io-4.0.0-5677917"

debian_dl_1="${dl_mirror}/${node_red_bbio}-${v10}.tar.xz"

buster_version="~buster+20190208"
