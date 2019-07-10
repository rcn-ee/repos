#!/bin/bash -e

package_name="bb-bbai-firmware"
debian_pkg_name="${package_name}"
package_version="1.20190710.4"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

buster_version="~buster+20190710"
