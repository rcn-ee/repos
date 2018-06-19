#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="pygame"
debian_pkg_name="${package_name}"
package_version="1.9.3+dfsg2"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-1.9.3"

git_repo=""
git_sha=""
reprepro_dir="p/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20180619"
