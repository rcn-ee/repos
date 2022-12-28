#!/bin/bash -e

#https://tracker.debian.org/pkg/wpa
#https://snapshot.debian.org/package/wpa/2%3A2.9.0-23/

#mirror="http://http.debian.net/debian"
mirror="https://snapshot.debian.org/archive/debian/20211019T151710Z/"

package_name="wpa"
debian_pkg_name="${package_name}"
epoch="2"
package_version="2.9.0"
package_source="${debian_pkg_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-2.9"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-23"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee2"

bullseye_version="~bullseye+20221228"
focal_version="~focal+20221228"
