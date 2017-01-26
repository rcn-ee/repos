#!/bin/bash -e

package_name="rcn-ee-archive-keyring"
debian_pkg_name="${package_name}"
package_version="2017.01.27"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="r/${package_name}"
dl_path=""

debian_version="${package_version}"
debian_untar=""
debian_patch=""

zesty_version="~bpo1704+20170126+1"
