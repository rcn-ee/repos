#!/bin/bash -e

package_name="gcc-pru"
debian_pkg_name="${package_name}"
package_version="10.1.0"
package_source=""
src_dir=""

newlib_version="3.3.0"

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

buster_version="~buster+20200321"
bullseye_version="~bullseye+20200321"
bionic_version="~bionic+20200321"
