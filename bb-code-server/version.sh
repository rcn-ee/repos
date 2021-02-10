#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.8.1.20210205.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="38ffde13978e0b50236508bf7e9bb26a05ca51da"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee19"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.20.1-linux-armv7l.tar.xz"

buster_version="~buster+20210210"
