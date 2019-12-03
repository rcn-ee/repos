#!/bin/bash -e

package_name="bb-node-red-installer-test"
debian_pkg_name="${package_name}"
package_version="0.19.7"
package_source=""
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="b/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee4"
debian_untar=""
debian_patch=""

stretch_version="~stretch+20191203"
