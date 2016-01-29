#!/bin/bash -e

mirror="http://http.debian.net/debian"

package_name="libserialport"
debian_pkg_name="${package_name}"
package_version="0.1.1"
package_source="${package_name}_${package_version}.orig.tar.xz"
src_dir="${package_name}_${package_version}"

git_repo="git://sigrok.org/libserialport"
git_sha="348a6d353af8ac142f68fbf9fe0f4d070448d945"
reprepro_dir="libs/${package_name}"
dl_path="pool/main/${reprepro_dir}/"

debian_version="${package_version}-0"
debian_patch=""
local_patch="rcnee1"


jessie_version="~bpo80+20160128+1"
