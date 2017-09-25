#!/bin/bash -e

package_name="binutils-pru"
debian_pkg_name="${package_name}"
gnupru_release="2017.09-beta-rc2.2"
package_version="2.28.51.20170530"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20170925"
stretch_version="~stretch+20170925"
