#!/bin/bash -e

package_name="gcc-pru"
debian_pkg_name="${package_name}"
gnupru_release="2016.12-beta-rc2"
package_version="7.0.0.20161219"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20161231+1"
