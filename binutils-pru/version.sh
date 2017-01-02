#!/bin/bash -e

package_name="binutils-pru"
debian_pkg_name="${package_name}"
gnupru_release="2016.12-beta-rc2.1"
package_version="2.28.51.20170102"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

jessie_version="~bpo80+20170102+1"
