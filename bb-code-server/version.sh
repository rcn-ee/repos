#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.10.2.20210521.0"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="7a86f9602b06b37df24c6a09a234550f11fdc24d"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.22.1-linux-armv7l.tar.xz"

buster_version="~buster+20210526"
bullseye_version="~bullseye+20210526"
