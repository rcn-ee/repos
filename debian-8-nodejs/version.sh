#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="nodejs"
debian_pkg_name="${package_name}"
real_package_version="4.2.4"
package_version="${real_package_version}~dfsg"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="node-v${real_package_version}"

git_repo=""
git_sha=""
reprepro_dir="n/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch=""

jessie_version="~bpo80+20151229+1"
