#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.8.1.20210205.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/cdr/code-server"
git_sha="41ad0c0c4c14df78e1bfa3a44d8b633ed2fc26e5"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee18"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.20.1-linux-armv7l.tar.xz"

buster_version="~buster+20210210"
