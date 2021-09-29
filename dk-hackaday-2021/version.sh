#!/bin/bash -e

package_name="dk-hackaday-2021"
debian_pkg_name="${package_name}"
package_version="1.20210929.0"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="d/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_untar=""
debian_patch=""

bullseye_version="~bullseye+20210929"
