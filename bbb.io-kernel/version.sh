#!/bin/bash -e

package_name="bbb.io-kernel"
debian_pkg_name="${package_name}"
package_version="1.20211014.2"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path=""

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

buster_version="~buster+20211014"
bullseye_version="~bullseye+20211014"
