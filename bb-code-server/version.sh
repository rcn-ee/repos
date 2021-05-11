#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.10.0.20210510.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="d528dabad82f8bb16bda6c01f8552ebdba785050"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.22.1-linux-armv7l.tar.xz"

buster_version="~buster+20210511"
bullseye_version="~bullseye+20210511"
