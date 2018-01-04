#!/bin/bash -e

#mirror="https://deb.nodesource.com/node_8.x"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="8.9.4"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir=""

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee0"
debian_patch=""

buster_version="~buster+20180103"
