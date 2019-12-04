#!/bin/bash -e

package_name="bb-node-red-installer"
debian_pkg_name="${package_name}"
package_version="1.0.3"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_untar=""
debian_patch=""

bionic_version="~bionic+20191204"
