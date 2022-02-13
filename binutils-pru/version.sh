#!/bin/bash -e

package_name="binutils-pru"
debian_pkg_name="${package_name}"
package_version="2.38"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20200321"
buster_version="~buster+20200321"
bullseye_version="~bullseye+20200321"
bionic_version="~bionic+20200321"
