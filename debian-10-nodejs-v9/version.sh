#!/bin/bash -e

#mirror="https://deb.nodesource.com/node_9.x"

package_name="nodejs"
debian_pkg_name="${package_name}"
package_version="9.2.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="node-v${package_version}"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0rcnee1"
#debian_version="${package_version}-1nodesource1~stretch1"
#debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""

buster_version="~buster+20171130"
