#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.8.1.20210205.5"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="47576df67fa9ddfefca4800e8127432eb3e7035e"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee8"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.20.2-linux-armv7l.tar.xz"

buster_version="~buster+20210212"
bullseye_version="~bullseye+20210212"
