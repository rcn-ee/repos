#!/bin/bash -e

package_name="board-firmware"
debian_pkg_name="${package_name}"
package_version="1.20200227.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20170130+1"
stretch_version="~stretch+20200227"
buster_version="~buster+20200227"
xenial_version="~xenial+20200227"
bionic_version="~bionic+20200227"
