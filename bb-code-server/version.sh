#!/bin/bash -e

package_name="bb-code-server"
debian_pkg_name="${package_name}"
package_version="3.11.0.20210714.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="https://github.com/rcn-ee/code-server"
git_sha="999601fec88709e10c0950a517350de86fcf2188"
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

debian_dl_1="https://nodejs.org/dist/latest-v14.x/node-v14.17.3-linux-armv7l.tar.xz"

buster_version="~buster+20210715"
bullseye_version="~bullseye+20210715"
