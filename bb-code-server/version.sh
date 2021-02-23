#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.9.0.20210212.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="3de6d830e3480b289df774a90ffbb5086c8bd400"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee9"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.21.0-linux-armv7l.tar.xz"

buster_version="~buster+20210223"
bullseye_version="~bullseye+20210223"
