#!/bin/bash -e

package_name="gcc-pru"
debian_pkg_name="${package_name}"
gnupru_release="2017.09-beta-rc2.2"
package_version="8.0.0.20170530"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~jessie+20170925"
stretch_version="~stretch+20170925"
