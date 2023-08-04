#!/bin/bash -e

#https://tracker.debian.org/pkg/wpa

mirror="http://http.debian.net/debian"

package_name="wpa"
debian_pkg_name="${package_name}"
epoch="2"
package_version="2.10"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-2.10"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-12"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="bbbio1"

bullseye_version="~bullseye+20230406"
bookworm_version="~bookworm+20230406"
