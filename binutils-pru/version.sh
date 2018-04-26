#!/bin/bash -e

package_name="binutils-pru"
debian_pkg_name="${package_name}"
gnupru_release="2018.03-beta-rc3"
package_version="2.30.51.20180310"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee2"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20180425"
stretch_version="~stretch+20180425"
buster_version="~buster+20180425"
bionic_version="~bionic+20180425"
