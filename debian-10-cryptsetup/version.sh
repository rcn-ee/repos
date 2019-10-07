#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="cryptsetup"
debian_pkg_name="${package_name}"
epoch="2"
package_version="2.1.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.gz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="c/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-5+deb10u2"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee0"

buster_version="~buster+20191007"
