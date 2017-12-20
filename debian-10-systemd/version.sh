#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="systemd"
debian_pkg_name="${package_name}"
package_version="236"
package_source="${package_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="s/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-1"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20171220"
