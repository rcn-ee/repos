#!/bin/bash -e

package_name="binutils-pru"
debian_pkg_name="${package_name}"
gnupru_release="2016.07-beta-rc1.1"
package_version="2.27.51.20160801"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version=""
debian_untar=""
debian_patch=""

jessie_version="-1"
