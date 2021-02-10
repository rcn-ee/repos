#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.8.1.20210205.4"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="8c7374c69a0ded2e9b98b9d92da350b533ce53ab"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0rcnee3"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.20.2-linux-armv7l.tar.xz"

buster_version="~buster+20210210"
