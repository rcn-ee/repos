#!/bin/bash -e

package_name="bb-beaglebone-io-installer"
debian_pkg_name="${package_name}"
package_version="4.0.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
debian_untar=""
debian_patch=""

dl_mirror="http://git.gfnd.rcn-ee.org:82/cgit/npm-package-node-red-scripts/.git/plain/deploy/buster"

v10="v10.15.2"

node_red_bbio="beaglebone-io-4.0.1-5427c71"

debian_dl_1="${dl_mirror}/${node_red_bbio}-${v10}.tar.xz"

buster_version="~buster+20191024"
