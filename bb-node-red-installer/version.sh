#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="1.2.9"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v10.x/node-v10.23.3-linux-armv7l.tar.xz"
debian_dl_2="https://nodejs.org/dist/latest-v12.x/node-v12.20.2-linux-armv7l.tar.xz"

stretch_version="~stretch+20210212"
buster_version="~buster+20210212"
bullseye_version="~bullseye+20210212"
bionic_version="~bionic+20210212"
