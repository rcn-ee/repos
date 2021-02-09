#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.8.1"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee5"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v12.x/node-v12.20.1-linux-armv7l.tar.xz"

bullseye_version="~bullseye+20210209"
