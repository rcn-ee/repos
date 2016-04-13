#!/bin/bash -e

#mirror="http://http.debian.net/debian"
mirror="http://ports.ubuntu.com"

package_name="wpa"
debian_pkg_name="${package_name}"
package_version="2.4"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}-${package_version}"

git_repo=""
git_sha=""
reprepro_dir="w/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0ubuntu6"
debian_untar="${package_name}_${debian_version}.debian.tar.xz"
debian_patch=""
local_patch="rcnee2"

jessie_version="~bpo80+20160413+1"
